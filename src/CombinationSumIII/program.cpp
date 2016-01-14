#include "../include/pre.h"
#include <deque>
const int MAX_NUM = 9;

std::deque<int> cur;
vector<vector<int>> rst;
void helper(int target, int n, int used)
{
    if (target == 0 && n == 0) {
        rst.emplace_back();
        rst.rbegin()->assign(cur.begin(), cur.end());
        return;
    }
    if (target <= 0 || n < 0) return; //cut
    for (; used != MAX_NUM; ) {
        cur.push_back(++used);
        helper(target - used, n - 1, used);
        cur.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    cur = {}, rst = {};
    helper(n, k, 0);
    return rst;
}
int main()
{
    auto r = combinationSum3(3, 9);
    for (auto& l : r) cout << l << endl;
    return 0;
}