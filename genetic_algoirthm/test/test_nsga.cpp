#include <gtest/gtest.h>
#include "../src/nsga.h"


TEST(a,b)
{
	EXPECT_EQ(3,3);
	NSGA ns(20);
	ns.display();
	ns.SelectionOperator();
}
