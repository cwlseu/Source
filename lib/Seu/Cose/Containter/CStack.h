#include <iostream>
#include <algorithm>
#include <stdexcept>
using std::copy;
#include "../Util/newArray.h"
namespace Seu{
	namespace Cose{
		const unsigned int defaultsize = 0x10;
		template<class T>
		static void reAlloc(T* a,const int oldsize,const int newsize)
		{
			if(newsize<0)
				throw new std::exception();
			T* tmp = new T[newsize];
			int num = std::min(newsize,oldsize);
			std::copy(a,a+num,tmp);
			delete[] a;
			a = tmp;
		}
		template <typename T>
		class CStack
		{
		public:
			CStack(int maxstacksize = defaultsize);
			bool isFull();
			void push(const T&);
			bool isEmpty();
			T topValue()
			{
				if(!isEmpty())
					return stack[top];
			}
			int getCapability(){return this->capability;}
			void pop(T& rhs); //pop top data to rhs
			~CStack();
		private:
			int top ;//
			T* stack;
			int capability;
			void stackFull() throw();
			void stackEmpty();
		};
		template<typename T>
		CStack<T>::CStack(int maxstacksize):
			capability(maxstacksize)
		{
			stack = new int[maxstacksize];
			top = -1;
		}
		template<typename T>
		bool CStack<T>::isFull()
		{
			return (top==capability-1);
		}
		template<typename T>
		bool CStack<T>::isEmpty()
		{
			return top==-1;
		}
		template<typename T>
		void CStack<T>::push(const T& rhs)
		{
			if(this->isFull())
			{
				std::cout<<"Stack double "<<this->getCapability()<<"\n";
				this->stackFull();
			}
			stack[++top] = rhs;	
		}
		template<typename T>
		void CStack<T>::pop(T& rhs)
		{
			if(this->isEmpty())
			{
				std::cout<<"Stack clean\n";
				stackEmpty();
			}else{
				rhs  = stack[top--];
			}
		}
		template<typename T>
		void CStack<T>::stackFull() throw()
		{
			try{
				reAlloc(stack,capability,capability*2);
				capability*=2;
			}catch(std::bad_alloc e)
			{
				throw e;
			}catch(std::runtime_error e)
			{
				throw e;
			}
		}
		template<typename T>
		void CStack<T>::stackEmpty()
		{
			if(capability>defaultsize)
			{
				reAlloc(stack,capability,defaultsize);
			}
		}
		template<typename T>
		CStack<T>::~CStack()
		{
			try{
				delete[] stack;
			}catch(std::exception e)
			{

			}
			
		}
		
	}
}
