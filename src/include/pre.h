#ifndef _PRE_H_
#define _PRE_H_
#include <iostream>

#include <type_traits>

#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
#include <cstring>

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

template<typename _T>
std::ostream& operator<<(std::ostream& os, vector<_T> src)
{
    for (auto& s : src)
    {
        os << s << ", ";
    }
    return os;
}
template<typename _T1, typename _T2>
std::ostream& operator<<(std::ostream& os, std::pair<_T1, _T2> src)
{
    os << "(" << src.first << ", " << src.second << ")";
    return os;
}
#endif //_PRE_H_
