#include "../include/prevector.h"
#define CALC_INT_LIMITS
#ifdef CALC_INT_LIMITS
    const int INT_MAX = std::numeric_limits<int>::max();
    const int INT_MIN = std::numeric_limits<int>::min();
#endif
int myAtoi(string str)
{
    int rst = 0, j = 0;
    bool negetive = false;
    while(str[j] == ' ') j++;
    if(str[j] == '+' || str[j] == '-') {
        negetive = (str[j] == '-');
        j++;
    }
    for(int i = j; i < str.size(); i++) {
        if(str[i] < '0' || str[i] > '9') break;
        int digit = (str[i] - '0');
        if (!negetive) {
            if(rst > INT_MAX / 10 || rst * 10 > INT_MAX - digit) {
                if(negetive) return INT_MIN;
                return INT_MAX;
            }
            rst = rst * 10 + digit;
        }
        else{
            if(rst < INT_MIN / 10 || rst * 10 < INT_MIN + digit) {
                if(negetive) return INT_MIN;
                return INT_MAX;
            }
            rst = rst * 10 - digit;
        }
    }
    return rst;
}


int Mymain()
{
    cout << (int)'+' << (int)'-' << endl;
    vector<std::string> tests = {
        "   -12kjhsdg8972",
        "   +010",
        "+-4646",
        "45fds5",
        "+12",
        "1",
        "+2147483648",
        "2147483648",
        "-2147483649",
        "2147483647",
        "-2147483648",
        "",
        "-",
        "0",
        "009",
        "-9898",
        "4665446465464541",
        "-45243325543436",
        "123567",
        "-19283"
    };
    for (auto& str : tests)
    {
        cout << str << "\t:\t" << myAtoi(str) << endl;
    }
}
