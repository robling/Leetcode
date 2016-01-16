#include "../include/pre.h"

int bulbSwitchSlow(int n)
{
    std::vector<bool> bulbs(n);
    for (auto& i : bulbs) i = false;
    int t = 0;
    while (++t <= n) {
        for (size_t i = 0; i != bulbs.size(); i++)
            if ((i + 1) % t == 0) bulbs[i] = !bulbs[i];
    }
    return std::count_if(bulbs.begin(), bulbs.end(), [](bool v){return v;});
}

int bulbSwitch(int n)
{
    //return static_cast<int>(std::sqrt(n));
    return static_cast<int>(std::ceil(std::sqrt(n + 1) - 1));
}
int main()
{
    int n = 0;
    //while (++n != 200) cout << n << ":\t" << bulbSwitchSlow(n) << endl;
    while (++n != 1000)
    {
        if (bulbSwitchSlow(n) != bulbSwitch(n)) {
            cout << n << "\tERROR";
            return 1;
        }
    }
    return 0;
}