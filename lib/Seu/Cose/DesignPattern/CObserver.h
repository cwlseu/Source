#include <vector>
#include <iterator>
#include <iostream>
//Status declear for IObserver to update status
enum Status{
		Sleep=1,
		Active,
		Idel,
		Ready
	};
//IObserver to define for 
class IObserver
{
	friend class ISubject; // declear friend class ISubject to access IObserver attribute
public:
	virtual void updateStatus(Status s)
	{
		status = s;
	}
	//over write == operator
	bool operator==(const IObserver& obs)
	{
		return(obs.status==status&& *this==obs);
	}
protected:
	Status status;//attribute for Observer status
};
//
class ISubject{
	protected:
		std::vector<IObserver>* observers; // observers for save observer
	public:
		virtual void notify(Status){} //notify all observers
		virtual void addObserver(IObserver* observer) {} //insert observer into  observers
		virtual void removeObserver(IObserver& observer) {} //remove observer from observers
		//method to show all observer's status
		void getobserversStatus()
		{
			for (std::vector<IObserver>::iterator i =observers->begin(); 
			i != observers->end(); ++i)
			{
				std::cout<<(*i).status<<"\n";
			}
		}
		~ISubject()
		{
			if(observers)
				delete observers;
		}
};


class CObserver:
	public IObserver
{
public:
	void otherOperation(){}
};
class CSubject:
	public ISubject
{
public:
	CSubject()
	{
		observers = new std::vector<IObserver>();
	}
	virtual void notify(Status s)
	{
		for (std::vector<IObserver>::iterator i = observers->begin(); i != observers->end(); ++i)
		{
			(*i).updateStatus(s);
		}
	}
	virtual void addObserver(IObserver* observer)
	{
		observers->push_back(*observer);
	}
	virtual void removeObserver(IObserver observer)
	{
		for (std::vector<IObserver>::iterator i = observers->begin(); i != observers->end(); ++i)
		{
			if((*i)==observer)
			{
				observers->erase(i);
				break;
			}
		}
	}
};
