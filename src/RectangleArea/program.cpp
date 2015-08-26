#include "../include/pre.h"
#include <cmath>

//    |    _________
// H D|   |         |
//    |   |         |
//    |   |         |
// F B|   |_________|
//    |___________________
//        A         C
//        E         G
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int S = (C - A) * (D - B) + (G - E) * (H - F);
    if (G <= A || E >= C || H <= B || F >= D) return S; //no overlay
    return S - (std::min(C, G) - std::max(A, E)) * (std::min(D, H) - std::max(B, F));
}

int Mymain()
{
    cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
