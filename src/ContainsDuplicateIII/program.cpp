#include "../include/pre.h"

inline size_t diff(size_t l, size_t r) {
    if (l < r) return r - l;
    else return l - r;
}
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    auto N = nums.size();
    vector<std::pair<long, size_t>> join;
    int index = 0;
    for (auto n : nums) join.push_back(std::make_pair(n, index++));
    std::sort(join.begin(), join.end());
    for (int i = 0; i != N; i++) {
        for (int j = 1; j + i < N; j++) {
            if (join[j + i].first - join[i].first <= t) {
                if (diff(join[j + i].second, join[i].second) <= k) return true;
                continue;
            }
            break;
        }
    }
    return false;
}

int main()
{
    auto rst = containsNearbyAlmostDuplicate(vector<int>{1, 2}, 1, 1);
    cout << rst << endl;
    return 0;
}