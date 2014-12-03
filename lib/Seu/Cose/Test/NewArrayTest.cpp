#include <iostream>
#include "../Util/newArray.h"
using namespace Seu::Cose;
using namespace std;
void test()
{
	int ndim=2;
	int* arr = new int[2]{1,2};
	int init =3;

	int*** p = new3DimArray(4,4,4,init);
	print3DimArray(p,4,4,4);
	delete3DimArray(p,4,4,4);
	std::cout<<sizeof(p)<<"";
	reAlloc(arr,2,100);
	for (int i = 0; i <100; ++i)
	{
		std::cout<<arr[i]<<"\t";
		if(i%5==0)std::cout<<"\n";
	}
}
int main()
{
	test();
	return 0;
}