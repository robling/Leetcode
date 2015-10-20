#include "../include/pre.h"

//Without counting
void sortColors(vector<int>& nums)
{
    if (nums.empty()) return;
    auto it_s = nums.begin();
    auto it_m = nums.begin();
    auto it_e = nums.end() - 1;
    while((it_e - it_m) >= 0) {
        //cout << nums << "======" << it_m - nums.begin() << endl;
        switch (*it_m)
        {
        case 0:
            std::swap(*it_s, *it_m);
            it_s++;
            it_m++;
            break;
        case 1:
            it_m++;
            break;
        case 2:
            std::swap(*it_m, *it_e);
            it_e--;
            break;
        }
    }
}

int main()
{
    vector<int> test = {0, 2, 1, 2, 1, 0, 2, };
    cout << test << endl;
    sortColors(test);
    cout << test;
    return 0;
}
