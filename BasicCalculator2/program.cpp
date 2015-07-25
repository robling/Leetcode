#include "../include/prevector.h"
#include <sstream>
#include <functional>
#include <queue>
#include <stack>

using std::stringstream;

//Really Really Slow!
int calculate_slow(string s)
{
    vector<char> ops;
    int i = 0;
    std::for_each(s.begin(), s.end(), [&](char& ch){
        if (ch >= 42 && ch <= 47)
        {
            ops.push_back(ch);
            ch = ' ';
        }
    });
    stringstream ss(s);
    std::vector<int> nums;
    for (int i = 0; i <= ops.size(); i++){
        int n;
        ss >> n;
        nums.push_back(n);
    }
    auto st = ops.begin();
    for (auto it = ops.begin(); it != ops.end(); )
    {
        switch (*it){
        case '*':
            nums[it - st] = nums[it - st] * nums[it - st + 1];
            nums.erase(nums.begin() + (it - st + 1));
            break;
        case '/':
            nums[it - st] = nums[it - st] / nums[it - st + 1];
            nums.erase(nums.begin() + (it - st + 1));
            break;
        default:
            it++;
            continue;
        }
        it = ops.erase(it);
    }
    for (auto it = ops.begin(); it != ops.end(); )
    {
        switch (*it){
        case '+':
            nums[it - st] = nums[it - st] + nums[it - st + 1];
            nums.erase(nums.begin() + (it - st + 1));
            break;
        case '-':
            nums[it - st] = nums[it - st] - nums[it - st + 1];
            nums.erase(nums.begin() + (it - st + 1));
            break;
        default:
            it++;
            continue;
        }
        it = ops.erase(it);
    }
    return nums[0];
}

int calculate(string s)
{
    vector<char> ops;
    int i = 0;
    std::for_each(s.begin(), s.end(), [&](char& ch){
        if (ch >= 42 && ch <= 47)
        {
            ops.push_back(ch);
            ch = ' ';
        }
    });
    stringstream ss(s);
    if (ops.size() == 0) {
        int n;
        ss >> n;
        return n;
    }
    std::vector<int> nums;
    for (int i = 0; i <= ops.size(); i++){
        int n;
        ss >> n;
        while (i < ops.size() && ops[i] != '+' && ops[i] != '-'){
            int tmp;
            ss >> tmp;
            switch (ops[i]) {
            case '*':
                n *= tmp;break;
            case '/':
                n /= tmp;break;
            }
            i++;
        }
        nums.push_back(n);
    }

    int rst = nums[0];
    int num_i = 1;
    for (int i = 0; i <= ops.size(); i++){
        if (ops[i] != '*' && ops[i] != '/'){
            switch (ops[i]) {
            case '+':
                rst += nums[num_i];break;
            case '-':
                rst -= nums[num_i];break;
            }
            num_i ++;
        }
    }
    return rst;
}

int Mymain()
{
    vector<string> tests = {
        "0",
        "2 + 4 * 90 - 87",
        " 6 / 45 + 90  * 56",
        "666 * 54 / 12 - 67"
    };
    TIC
    for (string& s : tests){
        cout << s << ": \t" << calculate(s) << endl;
    }
    TOC
    return 0;
}
