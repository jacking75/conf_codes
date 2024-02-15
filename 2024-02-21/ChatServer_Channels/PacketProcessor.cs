using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Channels;
using System.Threading.Tasks;

using System.Threading.Tasks.Dataflow;

using CSBaseLib;

namespace ChatServer
{
    class PacketProcessor
    {
        bool IsThreadRunning = false;
        System.Threading.Thread ProcessThread = null;

        Channel<ServerPacketData> MsgChannel = Channel.CreateUnbounded<ServerPacketData>();

        UserManager UserMgr = new UserManager();

        Tuple<int,int> RoomNumberRange = new Tuple<int, int>(-1, -1);
        List<Room> RoomList = new List<Room>();

        Dictionary<int, Action<ServerPacketData>> PacketHandlerMap = new Dictionary<int, Action<ServerPacketData>>();
        PKHCommon CommonPacketHandler = new PKHCommon();
        PKHRoom RoomPacketHandler = new PKHRoom();
                

        //TODO MainServer를 인자로 주지말고, func을 인자로 넘겨주는 것이 좋다
        public void CreateAndStart(List<Room> roomList, MainServer mainServer)
        {
            var maxUserCount = MainServer.ServerOption.RoomMaxCount * MainServer.ServerOption.RoomMaxUserCount;
            UserMgr.Init(maxUserCount);

            RoomList = roomList;
            var minRoomNum = RoomList[0].Number;
            var maxRoomNum = RoomList[0].Number + RoomList.Count() - 1;
            RoomNumberRange = new Tuple<int, int>(minRoomNum, maxRoomNum);
            
            RegistPacketHandler(mainServer);

            IsThreadRunning = true;
            ProcessThread = new System.Threading.Thread(this.Process);
            ProcessThread.Start();
        }
        
        public void Destory()
        {
            IsThreadRunning = false;
            MsgChannel.Writer.Complete();
        }
              
        public void InsertPacket(ServerPacketData data)
        {
            MsgChannel.Writer.TryWrite(data);
        }

        
        void RegistPacketHandler(MainServer serverNetwork)
        {            
            CommonPacketHandler.Init(serverNetwork, UserMgr);
            CommonPacketHandler.RegistPacketHandler(PacketHandlerMap);                
            
            RoomPacketHandler.Init(serverNetwork, UserMgr);
            RoomPacketHandler.SetRooomList(RoomList);
            RoomPacketHandler.RegistPacketHandler(PacketHandlerMap);
        }

        void Process()
        {
            while (IsThreadRunning)
            {
                try
                {
                    ServerPacketData packet;

                    if(MsgChannel.Reader.TryRead(out packet) == false)
                    {
                        System.Threading.Thread.Sleep(1);
                        continue;
                    }


                    if (PacketHandlerMap.ContainsKey(packet.PacketID))
                    {
                        PacketHandlerMap[packet.PacketID](packet);
                    }
                    else
                    {
                        System.Diagnostics.Debug.WriteLine("세션 번호 {0}, PacketID {1}, 받은 데이터 크기: {2}", packet.SessionID, packet.PacketID, packet.BodyData.Length);
                    }
                }
                catch (Exception ex)
                {
                    IsThreadRunning.IfTrue(() => MainServer.MainLogger.Error(ex.ToString()));
                }
            }
        }


    }
}
