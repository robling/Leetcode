#include "../include/pre.h"
#include <deque>

std::deque<int> cur;    //submission : 50673467
//std::vector<int> cur; //submission : 50673497
vector<vector<int>> rst;
void helper(const vector<int>& orderedCandidate, size_t used,int target)
{
    if (target == 0) {
        rst.emplace_back();
        for (auto i : cur) rst.rbegin()->push_back(i);
        return;
    }
    
    if (target < 0) return;
    for (int i = used; i < orderedCandidate.size(); i++) {
        cur.push_back(orderedCandidate[i]);
        helper(orderedCandidate, used, target - orderedCandidate[i]);
        cur.pop_back();
        used++;
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    cur = {}, rst = {};
    std::sort(candidates.begin(), candidates.end());
    helper(candidates, 0, target);
    return rst;
}
int main()
{
    //auto r = combinationSum(vector<int>{1, 3, 4, 5, 6, }, 10);
    auto r = combinationSum(vector<int>{1, 2, }, 4);
    for (auto& l : r) cout << l << endl;
    return 0;
}