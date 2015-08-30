#include "../include/pre.h"

bool isUgly(int num) {
    if (num <= 0) return false;
    auto loopdiv = [&num](int baseNum){
        while (num % baseNum == 0) {
            num /= baseNum;
        }
    };
    loopdiv(2);
    loopdiv(3);
    loopdiv(5);
    if (num == 1) return true;
    return false;
}

int main()
{
    std::vector<int> tests {68, 6, 30, };
    for (auto x : tests) {
        cout << x << ":  " << isUgly(x) << "\n";
    }
    return 0;
}
