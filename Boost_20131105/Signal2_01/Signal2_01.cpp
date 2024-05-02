// 슬롯으로 클래스 멤버 함수 사용

#include <iostream>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>

struct Point
{
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

class Button
{
public:
	boost::signals2::signal<void(const Point&)> clicked;

	void click()
	{
    	clicked(Point(10, 10));
	}
};

class MainView
{
public:
	void on_clicked(const Point& p)
	{
    	std::cout << "MainView : clicked" << std::endl;
	}
};

class SubView
{
public:
	void on_clicked(const Point& p)
	{
    	std::cout << "SubView : clicked" << std::endl;
	}
};


int main()
{
	MainView mainView;
	SubView subView;
	Button button;
	
	// 슬롯 등록
	button.clicked.connect(boost::bind(&MainView::on_clicked, &mainView, _1));
	button.clicked.connect(boost::bind(&SubView::on_clicked, &subView, _1));
	
	// 시그널 발생
	button.click();

	return 0;
}

