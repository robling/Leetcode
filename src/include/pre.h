#ifndef _PRE_H_
#define _PRE_H_
#include <iostream>

#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <algorithm>
#include <functional>

#include <cassert>

#include <cstdint>
#include <limits>

#include <vector>
using std::vector;

#include <array>
using std::array;

#ifdef _MSC_VER
static_assert(_MSC_VER >= 1600, "C++ 11 fetures required");
#endif

#define Mymain main

#include <ctime>
#define TIC std::clock_t myTimeCounter = std::clock(); cout << "\n=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n";
#define TOC cout << "=============================\nTime : " \
				 << (( std::clock() - myTimeCounter ) / (double) CLOCKS_PER_SEC) \
				 << " s" \
				 << endl;

template<typename _T>
void PrintToBinary(_T num)
{
	for (size_t i = (sizeof(_T) * 8 - 1); i != -1; i--)
	{
		cout << ((num >> i) & 1);
	}
	cout << endl;
}

#endif //_PRE_H_
