#include "../include/pre.h"

int reverse(int x)
{
    int flag = x < 0 ? 1 : 0;
    auto willOverflow = [=](int rst, int next){
        const int MAX = std::numeric_limits<int>::max();
        rst = std::abs(rst);
        if (rst > MAX / 10) return true;
        //It is of no use to check this condition since the INT32_MAX is 2147483647
        //      2 < 7 or 2 < 8 when negative
        //However, to make sure for other platform relevantd int, I think it is integral.
        //      e.g. int64 : 9,223,372,036,854,775,807
        if (rst == MAX / 10 && next > x % 10 + flag) return true;
        return false;
    }; 
    int rst = 0;
    int i = 0;
    do
    {
        if (++i > std::numeric_limits<int>::digits10 - 1 && willOverflow(rst, x % 10)) return 0;
        rst = rst * 10 + x % 10;
        x /= 10;
    }
    while (x);
    return rst;
}

int main()
{
    cout << reverse(2147483647);
    return 0;
}