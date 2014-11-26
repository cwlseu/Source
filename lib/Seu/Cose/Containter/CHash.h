#include <iostream>
namespace Seu{
	namespace Cose{
		class CHash;
		template<typename T>
		class CHash
		{
		public:
			CHash(arguments);
			~CHash();
		private:
			size_t size;
			size_t capability;
			T* hashTable;
		};
	}
}