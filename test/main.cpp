/**
 * @Brief: 
 * @file : $Id://Source/main.cpp
 * @author : Charles
 * @Date : 2014-11-26
 */
#include <assert.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
const static int size=1000000;
int main(int argc, char const *argv[])
{
	clock_t t,end; 
	int a[size]={0};
	int b[size]={10};
	t = clock();
	memcpy(b,a,size*sizeof(int));
	end = clock();
	printf("memcpy takes time: %d ms\n",end-t);
	t = clock();
	for (int i = 0; i < size; ++i)
	{
		a[i] = b[i];
	}
	end = clock();
	printf("memcpy takes time: %d ms\n",end-t);
	return 0;
}