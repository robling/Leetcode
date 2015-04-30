#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

#ifdef _MSC_VER
static_assert(_MSC_VER >= 1600, "\
C++ 11 fetures required");
#endif

#define Mymain main

template<typename _T>
void PrintToBinary(_T num)
{
	for (size_t i = (sizeof(_T) * 8 - 1); i != -1; i--)
	{
		cout << ((num >> i) & 1);
	}
	cout << endl;
}