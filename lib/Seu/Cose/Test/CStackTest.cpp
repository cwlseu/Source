#include "../Containter/CStack.h"
#include <iostream>
int main(int argc, char const *argv[])
{
	Seu::Cose::CStack<int> * cstack  = new Seu::Cose::CStack<int>(2);
	cstack->push(2);
	std::cout<<"top: "<<cstack->topValue()<<"\n";
	cstack->push(3);
	std::cout<<"top: "<<cstack->topValue()<<"\n";
	int b;
	cstack->pop(b);
	std::cout<<"top: "<<cstack->topValue()<<"\n";

	for (int i = 20; i >0; --i)
	{
		cstack->push(i);
	}
	std::cout<<cstack->getCapability()<<"\n";
	int a= 0;
	std::cout<<"Pop data"<<"\t"<<"parameter"<<"\n";
	for (int i = 1; i <22; ++i)
	{
		cstack->pop(a);
		std::cout<<"\t"<<a<<"\n";
	}
	cstack->pop(a);
	//std::cout<<"top: "<<(*(cstack->pop(a)))<<"\n";
	system("Pause");
	return 0;
}