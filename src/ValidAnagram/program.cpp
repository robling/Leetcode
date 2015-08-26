#include "../include/prevector.h"
#include <array>
using std::array;

array<int, 26> AlphabetCount;

bool isAnagram(string s, string t){
    if (s.size() != t.size()) return false;
    AlphabetCount.fill(0);
    for (char ch : s){
        AlphabetCount[ch - 'a']++;
    }
    for (char ch : t){
        if (AlphabetCount[ch - 'a'] == 0) return false;
        AlphabetCount[ch - 'a']--;
    }
    return true;
}

int Mymain()
{
    string s = "zar";//"anagram";
    string t = "zaz";//"nagaram";
    cout << isAnagram(s, t) << endl;
}
