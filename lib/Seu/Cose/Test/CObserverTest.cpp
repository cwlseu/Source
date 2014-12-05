#include "../DesignPattern/CObserver.h"
int main(int argc, char const *argv[])
{
	ISubject* subject = new CSubject();
	IObserver* observer;
	for (int i = 0; i < 10; ++i)
	{
		observer = new CObserver();
		subject->addObserver(observer);
	}
	std::cout<<"notify Ready Status:\n";
	subject->notify(Ready);
	subject->getobserversStatus();
	std::cout<<"notify Active Status:\n";
	subject->notify(Active);
	subject->getobserversStatus();
	delete subject; 
	return 0;
}