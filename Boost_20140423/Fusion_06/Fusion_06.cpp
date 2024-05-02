//√‚√≥: http://faithandbrave.hateblo.jp/entry/20101115/1289804239

#include <boost/assert.hpp>
#include <boost/fusion/include/map.hpp>
#include <boost/fusion/include/at_key.hpp>

namespace fusion = boost::fusion;

struct x {};
struct y {};
struct z {};

typedef fusion::map<
	fusion::pair<x, int>,
	fusion::pair<y, int>,
	fusion::pair<z, int>
> vec;

int main()
{
	const vec v = { 3, 1, 4 };
	BOOST_ASSERT(fusion::at_key<x>(v) == 3);
	BOOST_ASSERT(fusion::at_key<y>(v) == 1);
	BOOST_ASSERT(fusion::at_key<z>(v) == 4);

	return 0;
}


