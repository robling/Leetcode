#include "../include/pre.h"

int nthSuperUglyNumber(int n, vector<int>& primes)
{
    vector<int> uglys { 1 };
    vector<int> powers(primes.size(), 0);
    while (uglys.size() != n)
    {
        int min = std::numeric_limits<int>::max();
        for (int i = 0; i != primes.size(); i++) min = std::min(min, primes[i] * uglys[powers[i]]);
        for (int i = 0; i != primes.size(); i++) powers[i] += (primes[i] * uglys[powers[i]] == min);
        uglys.push_back(min);
    }
    cout << uglys << endl;
    return uglys.back();
}

int main()
{
    //cout << nthSuperUglyNumber(60, vector<int>{2, 3, 4});
    cout << nthSuperUglyNumber(10, vector<int>{3,5,7,13,17,19,29,31,37,41,47,59,71,73,79,83,97,127,131,137});
    return 0;
}