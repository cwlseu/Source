#ifndef __SEU_COSE_NEWARRAY_H
#define __SEU_COSE_NEWARRAY_H
#include "newArray.h"
#include <iostream>
#include <algorithm>
typedef unsigned int size_t;
namespace Seu{
	namespace Cose{
		template<typename T>
		static T* newArray(size_t size,T init=0)
		{
			T* ret = new T[size];
			for(int i=0;i<size;i++)ret[i]=init;
			return ret;
		}
		template<class T>
		static void deleteArray(T* arr)
		{
			delete[] arr;
			//arr=0;
		}

		template<class T>
		static T** new2DimArray(size_t rownum,size_t colnum,T init=0)
		{

			T** ret = new T*[rownum];
			for(int i=0;i<rownum;i++)
			{
				ret[i]= new T[colnum];
				for(int j=0;j<colnum;j++)ret[i][j]=init;
			}
			return ret;
		}
		template<class T>
		static void delete2DimArray(T** arr,size_t rownum,size_t colnum)
		{
			for(int i = 0; i < rownum; i++) delete [] arr[i]; 
			delete [] arr;
			//arr=0;
		}
		/**
		 *	初始化n维的数组，初始值为init值，
		 * @param ndim
		 * @param dimarr[] 数组包含每个维度的大小值
		 * @param init 
		 * @return void*
		 */
		template<typename T>
		static T*** new3DimArray(size_t dim1,size_t dim2,size_t dim3,T init=0)
		{
			
			T*** ret = new T**[dim1];
			for(int i=0;i<dim1;i++)
			{
				
				ret[i]= new2DimArray(dim2,dim3,init);
			}
			return ret;
		}
		template<typename T>
		static void delete3DimArray(T***arr ,size_t dim1,size_t dim2,size_t dim3)
		{
			for(int i=0;i<dim1;i++)	delete2DimArray(arr[i],dim2,dim3);
			delete[] arr;
			//arr=0;
		}
		template<class T>
		static void printArray(T* arr,size_t n)
		{
			for(int i=0;i<n;i++)std::cout<<arr[i]<<" ";
		}
		template<class T>
		static void print2DimArray(T** arr,size_t n,size_t m)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
					std::cout<<arr[i][j]<<" ";
				std::cout<<'\n';
			}	
		}
		template<class T>
		static void print3DimArray(T*** arr,size_t dim1,size_t dim2,size_t dim3)
		{
		    std::cout<<"3DimArray is\n";
			for(int i=0;i<dim1;i++)
			{
				std::cout<<"array["<<i<<"]=\n";
				print2DimArray(arr[i],dim2,dim3);
			}	
		}
		template<class T>
		static bool inRange(T in,T l,T r)
		{
			return ((in>=l)&& (in<=r));
		}
		
	}//end namespace Cose
}//namespace Seu
#endif 