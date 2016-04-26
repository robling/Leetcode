#include "../include/pre.h"

int maxCoins(vector<int>& nums)
{
    const int N = nums.size();
    vector<vector<int>> dp (N + 1, vector<int>(N + 1, 0));
    auto expandNums = [&nums, N](int k){return (k >= 0 && k < N) ? nums[k] : 1;};
    for (int l = 1; l != N + 1; l++) {
        for (int s = 0; s != N - l + 1; s++) {
            for (int k = 0; k != l; k++) {
                dp[s][l] = std::max(
                    dp[s][l],
                    dp[s][k] + expandNums(s + k) * expandNums(s - 1) * expandNums(s + l) + dp[s + k + 1][l - k - 1]
                );
            }
        }
    }
    return dp[0].back();
}
int main()
{
    vector<int> test = {3, 1, 5, 8};
    cout << maxCoins(test) << endl;
    return 0;
}