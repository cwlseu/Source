#include "../DesignPattern/CBuilder.h"
#include <assert.h>
int main(int argc, char const *argv[])
{
	CBuilder builder;
	Product pu= builder.buildProduct();
	Product p2(1,2,3);
	assert(pu==p2);
	return 0;
}