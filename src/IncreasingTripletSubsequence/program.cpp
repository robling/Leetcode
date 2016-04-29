#include "../include/pre.h"

bool increasingTriplet(vector<int>& nums)
{
    int min[] = {std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};
    for (auto n : nums)
    {
        if (n > min[1]) return true;
        if (n <= min[0]) {
            min[0] = n;
            continue;
        }
        if (n < min[1]) min[1] = n;
    }
    return false;
}

int main()
{
    cout << std::boolalpha << increasingTriplet(vector<int>{1, 2, 3, 4, 5}) << endl;
    return 0;
}