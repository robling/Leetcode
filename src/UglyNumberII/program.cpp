#include "../include/pre.h"
#include <queue>
using std::priority_queue;

bool isUgly(int num) {
    if (num <= 0) return false;
    auto loopdiv = [&num](int baseNum){
        while (num % baseNum == 0) {
            num /= baseNum;
        }
    };
    loopdiv(2);
    loopdiv(3);
    loopdiv(5);
    if (num == 1) return true;
    return false;
}

template<typename T, typename... Args>
int min(T arg, Args... args)
{
    return std::min(arg, min(args...));
}
template<typename T>
int min(T arg)
{
    return arg;
}

int nthUglyNumber(int n) {
    int index[] = {0, 0, 0, };
    int base[] = {2, 3, 5, };
    vector<int> seq {1};
    seq.reserve(n);
    int rst = 1;
    while (--n)
    {
        rst = min(base[0] * seq[index[0]], base[1] * seq[index[1]], base[2] * seq[index[2]]);
        seq.push_back(rst);
        for (auto x : array<int, 3>{0, 1, 2}) { index[x] += (base[x] * seq[index[x]] == rst); }
    }
    return rst;
}

int main()
{
    vector<int> tests;
    for (int i = 1; i <= 40; i++) {tests.push_back(i);}
    for (auto x : tests) {
        cout << x << ": " << nthUglyNumber(x) << "\n";
    }
    cout << nthUglyNumber(60);
    return 0;
}
