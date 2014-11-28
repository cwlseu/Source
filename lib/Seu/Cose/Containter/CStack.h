#include <iostream>
namespace Seu{
	namespace Cose{
		const unsigned int defaultsize = 0x10;
		template <class T>
		class CStack
		{
		public:
			CStack(int maxstacksize = defaultsize);
			bool isFull();
			void push(const T&);
			bool isEmpty();
			T* pop(T&);
		private:
			int top ;
			T* stack;
			int capability;
			void stackFull();
			void stackEmpty();
		};
	}
}