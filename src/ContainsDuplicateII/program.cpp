#include "../include/pre.h"
#include <unordered_map>

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    std::unordered_map<int, int> uni;
    int i = 0;
    for (auto n : nums) {
        if (uni.find(n) != uni.end() && i - uni[n] <= k) return true;
        uni[n] = i++;
    }
    return false;
}
int main()
{
    //cout << containsNearbyDuplicate(vector<int>{1, 5, 1, 13, 17, 19}, 1) << endl;
    cout << containsNearbyDuplicate(vector<int>{1, 2,}, 2) << endl;
    return 0;
}