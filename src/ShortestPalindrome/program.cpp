#include "../include/prevector.h"

//Time exceed!
string shortestPalindrome(string s)
{
    auto testPal = [&s](int mid, int totalOffset){
        for (int i = mid ; i >= 0; i--){
            if (!(s[i] == s[totalOffset - i])) return false;
        }
        return true;
    };
    size_t originalOffset = s.size() - 1;
    size_t offset = originalOffset;
    int i = offset / 2;
    for ( ; i >= 0; i--)
    {
        // cout << "i: " << i << ", offset: " << offset << "  OK? :" << testPal(i, offset) << endl;
        // offset--;
        // cout << "i: " << i << ", offset: " << offset << "  OK? :" << testPal(i, offset) << endl;
        // offset--;
        if (testPal(i, offset)) break;
        offset--;
        if (testPal(i, offset)) break;
        offset--;
    }
    string rst(originalOffset * 2 - offset + 1, '\0');
    int ii = 0;
    for (int i = originalOffset; i >= 0; i--, ii++){
        rst[ii] = s[i];
    }
    for ( ;ii < rst.size(); ii++){
        rst[ii] = rst[rst.size() - ii - 1];
    }
    //cout << "i: " << i << ", offset: " << offset << endl;
    //cout << endl << rst.size() << endl;
    return rst;
}


int Mymain()
{
    TIC
    string tests[] = {"s", "aacecaa", "aacecaaa", "abcd", "ccbb", ""};
    tests[5] = string(400000, 'a');
    for (const auto& str : tests){
        //cout << str << ":\n\t";
        //cout << shortestPalindrome(str) << endl;
        shortestPalindrome(str);
    }
    TOC
}
