#include "Share_Ptr.h"
#include <stdexcept>
using std::runtime_error;
using std::exception;
#include <utility>
using std::swap;
namespace Seu{
	namespace Cose{
		template<typename T>
		Seu::Cose::Share_Ptr<T>::Share_Ptr(T*p):
		px(p),pn(1)
		{}
		template<typename T>
		Seu::Cose::Share_Ptr<T>::Share_Ptr(const Share_Ptr& rhs)
		{
			pn++;
		}
		template<typename T>
		Seu::Cose::Share_Ptr<T>& Seu::Cose::Share_Ptr<T>::operator=(const Share_Ptr<T>& rhs)
		{
			if(*this==rhs)
			{
				return (*this);
			}
			 ++rhs.pn;
			this->pn = rhs.use_count();
			this->px = rhs.get();
			return (*this);
		}
		template<typename T>
		Seu::Cose::Share_Ptr<T>& Seu::Cose::Share_Ptr<T>::operator=(Share_Ptr<T>& rhs)
		{
			if(*this==rhs)
			{
				return (*this);
			}
			 ++rhs.pn;
			this->pn = rhs.use_count();
			this->px = rhs.get();
			return (*this);
			
			
		}
		template<typename T>
		bool Seu::Cose::Share_Ptr<T>::operator==(const Share_Ptr<T>& rhs)
		{
			if(rhs.get()==this->px 
			&& rhs.use_count()==this->pn)
				return true;
			return false;
		}
		template<typename T>
		bool Seu::Cose::Share_Ptr<T>::operator==(Share_Ptr<T>& rhs)
		{
			if(rhs.get()==this->px 
			&& rhs.use_count()==this->pn)
				return true;
			return false;
		}
		template<typename T>
		T* Seu::Cose::Share_Ptr<T>::get()const
		{
			if(this->px)
				return this->px;
			throw std::runtime_error("dereference of NULL pointer");
		}
		
		template<typename T>
		T& Seu::Cose::Share_Ptr<T>::operator*()const
		{
			if (px)
            	return (*px);
        	throw std::runtime_error("dereference of NULL pointer");
		}
		template<typename T>
		T* Seu::Cose::Share_Ptr<T>::operator->()const
		{
			if (px)
            	return px;
        	throw std::runtime_error("dereference of NULL pointer");
		}
		
		template<typename T>
		void Seu::Cose::Share_Ptr<T>::swap(Share_Ptr<T>& rhs)
		{
			std::swap(rhs->px,this->px);
			std::swap(rhs->pn,this->pn);
		}
		template<typename T>
		shared_count Seu::Cose::Share_Ptr<T>::use_count()const
		{
			return this->pn;
		}
		template<typename T>
		bool Seu::Cose::Share_Ptr<T>::unique()const
		{
			if(this->pn==1)
				return true;
			return false;
		}
		template<typename T>
		Seu::Cose::Share_Ptr<T>::~Share_Ptr()
		{
			this->clean();
		}
		template<typename T>
		void Seu::Cose::Share_Ptr<T>::clean()
		{

			if(--(this->pn)<=0)
			{
				delete px;
				pn = 0;
			}
		}

	}
}
#include <iostream>
int main(int argc, char const *argv[])
{
    int* test = new int(3);
	Seu::Cose::Share_Ptr<int> share(test);
	Seu::Cose::Share_Ptr<int> share2(share);
	Seu::Cose::Share_Ptr<int> share3(new int(1));
	share3 = share2;
	std::cout<<share.use_count()<<" \n"
	<<share2.use_count()<<"\n"
	<<share3.use_count()<<"\n";
	return 0;
}
