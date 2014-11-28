namespace Seu{
	namespace Cose{
#ifndef __SEU_COSE_ICOMPARABLE_H_
#define __SEU_COSE_ICOMPARABLE_H_	
		template<class T>
		class IComparable
		{
		public:
			virtual bool compare(T& a,T& b)=0;
		};
#endif
	}
}
