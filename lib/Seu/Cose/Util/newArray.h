#ifndef __SEU_COSE_NEWARRAY_H
#define __SEU_COSE_NEWARRAY_H
namespace Seu
{
	namespace Cose{
		typedef unsigned int size_t;
		#ifndef ARRAY
		#define ARRAY
			template<typename T>
			static T* newArray(size_t size,T init=0);
			template<class T>
			static void deleteArray(T* arr);
			template<class T>
			static T** new2DimArray(size_t rownum,size_t colnum,T init=0);
			template<class T>
			static void delete2DimArray(T** arr,size_t rownum,size_t colnum);
			template<typename T>
			static T*** new3DimArray(size_t dim1,size_t dim2,size_t dim3,T init=0);
			template<typename T>
			static void delete3DimArray(T***arr ,size_t dim1,size_t dim2,size_t dim3);
			template<class T>
			static void printArray(T* arr,size_t n);
			template<class T>
			static void print2DimArray(T** arr,size_t n,size_t m);
			template<class T>
			static void print3DimArray(T*** arr,size_t dim1,size_t dim2,size_t dim3);
		#endif
		#ifndef RANGE
		#define RANGE
		template<class T>
		static bool inRange(T in,T l,T r);
		#endif
	}
	
}
#endif