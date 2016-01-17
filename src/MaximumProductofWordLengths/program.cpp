#include "../include/pre.h"
#include <bitset>

int maxProduct(vector<string>& words)
{
    typedef std::bitset<26> alphabet;
    typedef std::pair<int, alphabet> wordlist;
    auto N = words.size();
    vector<wordlist> words_;
    for (auto& s : words) {
        alphabet a;
        for (auto c : s) a[c - 'a'] = true;
        words_.emplace_back(s.size(), a);
    }
    int max = 0;
    std::sort(words_.begin(), words_.end(), [](wordlist& l, wordlist& r){return l.first > r.first;});
    for (size_t i = 0; i < N; i++) {
        for (size_t j = i + 1; j < N; j++) {
            if (max > words_[i].first * words_[j].first) break;
            if ((words_[i].second & words_[j].second).any()) continue;
            max = std::max(max, words_[i].first * words_[j].first);
        }
    }
    return max;
}
int main()
{
    vector<string> test = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << maxProduct(test) << endl;
    return 0;
}