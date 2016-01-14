#include "../include/pre.h"
#include <iterator>
#include <deque>
#include <set>

std::deque<int> cur;
vector<vector<int>> rst;
void helper(std::vector<std::pair<int, size_t>>& candidateCount, size_t used,int target)
{
    if (target == 0) {
        rst.emplace_back();
        for (auto i : cur) rst.rbegin()->push_back(i);
        return;
    }
    if (target < 0) return;
    for (auto i = candidateCount.begin() + used; i != candidateCount.end(); i++) {
        if (i->second != 0) {
            cur.push_back(i->first);
            i->second--;
            helper(candidateCount, used, target - i->first);
            cur.pop_back();
            i->second++;
        }
        used++;
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    cur = {}, rst = {};
    std::sort(candidates.begin(), candidates.end());
    vector<std::pair<int, size_t>> candidateCount;
    int tmp = candidates[0] - 1;
    for (auto n : candidates) {
        if (tmp != n) candidateCount.emplace_back(n, 1);
        else candidateCount.rbegin()->second++;
        tmp = n;
    }
    helper(candidateCount, 0, target);
    return rst;
}
int main()
{
    //auto r = combinationSum2(vector<int>{10,1,2,7,6,1,5,}, 8);
    auto r = combinationSum2(vector<int>{4,1,1,4,4,4,4,2,3,5}, 10);
    for (auto& l : r) cout << l << endl;
    return 0;
}