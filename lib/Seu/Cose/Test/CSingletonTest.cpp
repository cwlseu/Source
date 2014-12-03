#include "../DesignPattern/CSingleton.h"
#include <iostream>
int main(int argc, char const *argv[])
{
	CSingleton* csingleton[10];
	for (int i = 0; i < 10; ++i)
	{
		csingleton[i] = new CSingleton();
	}
	for (int i = 0; i < 10; ++i)
	{
		std::cout<<sizeof(csingleton[i]->getInstance())<<"\n";
	}
	
	return 0;
}