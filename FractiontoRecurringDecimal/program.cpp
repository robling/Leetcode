#include "../include/prevector.h"

#include <map>
using std::map;
using std::pair;

const int BITSOFINT = sizeof(int) * 8;

string fractionToDecimal(int numerator, int denominator)
{
    // x / y
    int64_t x = (int64_t)numerator;
    int64_t y = (int64_t)denominator;
    if (y == 0) return "NAN";
    stringstream ss, sp;
    map<int64_t, int> dividends;
    if (x != 0 && ((x > 0) ^ (y > 0 )) == 1)
        ss << '-';
    x = abs(x); y = abs(y);
    ss << static_cast<int64_t>(x / y);
    if (x%y != 0) ss << ".";
    int i = 0;
    for (; ; i++)
    {
        x %= y; x *= 10;
        if (x == 0) break;
        if (dividends.count(x))
            break;
        dividends.insert(pair<int64_t, int>(x, i));
        sp << static_cast<int64_t>(x / y);
    }
    string str = sp.str();
    for (int k = 0; k != str.length(); k++)
    {
        if (x != 0 && k == dividends[x]) ss << "(";
        ss << str[k];
    }
    if (x != 0) ss << ")";
    return ss.str();
}

int Mymain()
{
    cout << "-12         : " << typeid(-12).name() << endl;
    cout << " 2147483648 : " << typeid(2147483647 + 1).name() << endl;
    cout << "-2147483648 : " << typeid(-2147483648).name() << endl;
    cout << "-2147483648 : " << (-2147483648) << endl;
    cout << "-2147483648 : " << (abs((-2147483647 - 1))) << endl;
    cout << "-2147483648 : " << (abs(2147483647 + 1)) << endl;
    vector<pair<int, int>> test = {
        std::make_pair(1, 19),
        std::make_pair(0, -19),
        std::make_pair(-2147483647 - 1, -1),
        std::make_pair(-1, -2147483648),
        std::make_pair(1, 11),
        std::make_pair(1, 3),
        std::make_pair(6785, 5),
        std::make_pair(4, 0),
        std::make_pair(5, 2),
        std::make_pair(0, 4),
    };
    for (auto p : test)
    {
        cout << '(' << p.first << ", " << p.second << ')' << " : ";
        cout << fractionToDecimal(p.first, p.second) << endl;
    }
    return 0;
}
