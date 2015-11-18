#include "../include/pre.h"
#include <set>
#include <tuple>
#include <list>
#include <sstream>

template<typename ForwardIterator>
vector<typename ForwardIterator::value_type> subVector(ForwardIterator it_start, ForwardIterator it_end)
{
    vector<typename ForwardIterator::value_type> rst;
    while(it_start != it_end) rst.push_back(*it_start++);
    return rst;
}

std::tuple<std::vector<int>, std::vector<char>> parser(string& input)
{
    std::vector<int> nums;
    std::vector<char> ops;
    std::stringstream ss(input);
    int k;
    ss >> k;
    nums.push_back(k);
    while(!ss.eof())
    {
        int i;
        char ch;
        ss >> ch;
        ss >> i;
        ops.push_back(ch);
        nums.push_back(i);
    }
    return std::tie(nums, ops);
}
int solve(int a, int b, char op)
{
    switch(op){
    case '-':
        return a - b;
    case '+':
        return a + b;
    case '*':
        return a * b;
    default:
        assert(false);
        return 0;
    }
}

namespace allPossibleEvaluation{
template<typename _T>
vector<_T> without(const vector<_T>& input, size_t n)
{
    vector<_T> rst;
    rst.reserve(input.size() - 1);
    for (size_t i = 0; i != input.size(); i++)
    {
        if (i != n) rst.push_back(input[i]);
    }
    return rst;
}

void diffWaysToCompute_helper(std::vector<int>& nums, std::vector<char>& ops, std::set<int>& rst)
{
    if (ops.size() == 0) {
        rst.insert(nums[0]);
        return;
    }
    for (int i = 0; i != ops.size(); i++) {
        auto k = solve(nums[i], nums[i + 1], ops[i]);
        auto nextNums = without(nums, i);
        nextNums[i] = k;
        diffWaysToCompute_helper(nextNums, without(ops, i), rst);
    }
}

vector<int> diffWaysToCompute(string input)
{
    std::set<int> rst;
    auto data = parser(input);
    diffWaysToCompute_helper(std::get<0>(data), std::get<1>(data), rst);
    vector<int> rst_;
    for (auto i : rst)
    {
        rst_.push_back(i);
    }
    return rst_;
}
} //namespace

vector<int> helper (const vector<int> & nums, const vector<char> & ops)
{
    if (ops.size() == 0) return { nums };
    if (ops.size() == 1) return { solve(nums[0], nums[1], ops[0]) };
    vector<int> rst;
    for (size_t i = 0; i != ops.size(); i++) {
        auto sub1 = helper(
            subVector(nums.begin(), nums.begin() + i + 1), 
            subVector(ops.begin(), ops.begin() + i)
        );
        auto sub2 = helper(
            subVector(nums.begin() + i + 1, nums.end()), 
            subVector(ops.begin() + i + 1, ops.end())
        );
        for (auto s1 : sub1) {
            for (auto s2 : sub2) {
                rst.push_back(solve(s1, s2, ops[i]));
            }
        }
    }
    return rst;
}

vector<int> diffWaysToCompute(string input)
{
    vector<int> nums;
    vector<char> ops;
    std::tie(nums, ops) = parser(input);
    return helper(nums, ops);
}

int main()
{
    using namespace std;
    vector<string> tests = {
        "2*3-4*5", 
        "2-1-1",
        };
    for (auto& s : tests)
    {
        cout << "A:" << diffWaysToCompute(s) << endl;
    }
    return 0;
}