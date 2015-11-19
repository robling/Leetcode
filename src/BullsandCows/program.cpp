#include "../include/pre.h"

string getHint(string secret, string guess)
{
    array<int, 10> hashMap_s = {0};
    array<int, 10> hashMap_g = {0};
    int bulls = 0;
    int cows = 0;
    for (size_t i = 0; i != secret.size(); i ++) {
        if (secret[i] == guess[i]) {
            bulls++;
            continue;
        }

        hashMap_s[secret[i] - '0']++;
        hashMap_g[guess[i] - '0']++;
    }
    for (int i = 0; i != 10; i++) {
        cows += std::min(hashMap_g[i], hashMap_s[i]);
    }
    stringstream ss;
    ss << bulls << 'A' << cows << 'B';
    return ss.str();
}

int main()
{
    cout << getHint("1807", "7810") << "\n";
    cout << getHint("1123", "0111") << "\n";
    return 0;
}