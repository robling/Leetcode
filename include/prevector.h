#ifndef _PREVECTOR_H_
#define _PREVECTOR_H_
#include "pre.h" 
#include <vector>
using std::vector;

template<typename _T>
void PrintVector(std::vector<_T> list, string splitMark = ", ")
{
	for (_T elem : list)
	{
		cout << elem << splitMark;
	}
	cout << endl;
}
#endif //_PREVECTOR_H_