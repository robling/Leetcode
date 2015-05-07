#include "../include/prevector.h"
#include <sstream>
#include <algorithm>

using std::stringstream;


string largestNumber(vector<int>& nums) 
{
    sort(nums.begin(), nums.end(), [](int a, int b)->bool{
        /// \return true if a is 'larger' than b
        stringstream so, sp;
        so << a << b;
        sp << b << a;
        std::istream_iterator<char> inputo(so), end;
        std::istream_iterator<char> inputp(sp);
        while (inputo != end && *inputo == *inputp)
            inputo++, inputp++;
        return (*inputo > *inputp);
    });
    stringstream ss;
    /*
    // elegant output methot, but will output "00" with input {0, 0}
    for (auto i : nums)
    {
        ss << i;
    }
    */
    // HATE IT! 
    int k = nums.size();
    int count = 0;
    for (int j = 0; j != k - 1; j++){
        if (count == 0 && nums[j] == 0)
            continue;
        ss << nums[j];
        ++count;
    }
    ss << nums[k - 1];
    return ss.str();
}

int Mymain()
{
    TIC
    vector<vector<int>> test = {
        {830, 8308},
        {121, 12},
        {12, 121},
        {41,23,87,55,50,53,18,9,39,63,35,33,54,25,26,49,74,61,32,81,97,99,38,96,22,95,35,57,80,80,16,22,17,13,89,11,75,98,57,81,69,8,10,85,13,49,66,94,80,25,13,85,55,12,87,50,28,96,80,43,10,24,88,52,16,92,61,28,26,78,28,28,16,1,56,31,47,85,27,30,85,2,30,51,84,50,3,14,97,9,91,90,63,90,92,89,76,76,67,55},
        {3, 30, 3336, 5, 9, 0}, 
        {3, 78, 98, 5, 9, 0}, 
        {824,938,1399,5607,6973,5703,9609,4398,8247},
        {9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519}
        };
    for (auto list : test)
    {
        PrintVector(list);
        cout << "\nResult : " << largestNumber(list) << endl;
    }
    TOC
}