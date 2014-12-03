#include "IComparable.h"
class Test : 
	public Seu::Cose::IComparable<int>
{
private:

	bool compare(int& a,int&b)
	{
		return true;
	}
};

int main(int argc, char const *argv[])
{
	Test test;
	return 0;
}