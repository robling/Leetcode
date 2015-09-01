#include "../include/pre.h"

string single[] = {
    ""," One"," Two"," Three"," Four"," Five"," Six"," Seven"," Eight"," Nine",
    " Ten"," Eleven"," Twelve"," Thirteen"," Fourteen"," Fifteen"," Sixteen"," Seventeen"," Eighteen"," Nineteen"
};
string tens[] = { "",""," Twenty"," Thirty"," Forty"," Fifty"," Sixty"," Seventy"," Eighty"," Ninety" };
string indexs[] = {"", " Thousand", " Million", " Billion"};
string generateHundred(array<int, 3>& digits)
{
    string rst;
    if (digits[2] != 0) rst = rst + single[digits[2]] + " Hundred";
    if (digits[1] >= 2) rst = rst + tens[digits[1]] + single[digits[0]];
    else rst += single[digits[0] + digits[1] * 10];
    return rst;
}
string numberToWords(int num)
{
    if (num == 0) return "Zero";
    array<int, 3> buf;
    string rst;
    for (int i = 0; i != 4; i++) {
        for (int i = 0; i != 3; i++) {
            buf[i] = num % 10;
            num /= 10;
        }
        auto tmp = generateHundred(buf);
        if (tmp != "") rst = tmp + indexs[i] + rst;
    }
    return rst.substr(1);
}

int main()
{
    vector<int> tests { 0, 19, 111111, 123, 1234567, 100010, 2000100100};
    for (auto x : tests) {
        cout << x << ":\n\t:" << numberToWords(x) << ":\n";
    }
    return 0;
}
