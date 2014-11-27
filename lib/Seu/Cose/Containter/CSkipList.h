#include <iostream>
namespace Seu{
	namespace Cose{
		template<class T>
		struct ListNode
		{
			ListNode* next;
			T data;

		}LNode;
		template<class T>
		class CSkipList:public SortedSequence
		{
		public:
			CSkipList(arguments);
			~CSkipList();
		
			int search();
		private:
			T* data;

		};
	}
}