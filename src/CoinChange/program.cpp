#include "../include/pre.h"
#include <unordered_map>
class Solution {
private:
    vector<int>* coins_handle;
    std::unordered_map<int, int> mins;
    
    int coinChange_helper(int amount)
    {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if (mins.find(amount) != mins.end()) return mins[amount];
        int32_t min = -2;
        for (size_t i = 0; i != coins_handle->size(); i++)
        {
            uint32_t k = coinChange_helper(amount - coins_handle->at(i));
            if (k == -1) continue;
            min = std::min(static_cast<uint32_t>(min), k);
        }
        mins[amount] = min + 1;
        return min + 1;
    }
public:
    int coinChange(vector<int>& coins, int amount)
    {
        coins_handle = &coins;
        return coinChange_helper(amount);
    }
};

int main()
{
    TIC
    auto s = Solution();
    auto rst = s.coinChange(vector<int>{37,233,253,483}, 7163);
    cout << rst << endl;
    TOC
    return 0;
}