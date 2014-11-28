#ifndef __SEU_COSE_ISORTEDSEQUENCE_H_
#define __SEU_COSE_ISORTEDSEQUENCE_H_
namespace Seu{
	namespace Cose{
#ifndef __SEU_COSE_ICOMPARABLE_H_
#include "IComparable.h"
#endif
		template<class T>
		class ISortedSequence: 
			public Seu::Cose::IComparable
		{
		public:
			virtual bool compare(T& a,T& b)=0;
		private:
		 	virtual void autoSort() = 0; //sorted the data sequence automated
		};


	} //Cose
}//Seu
#endif

