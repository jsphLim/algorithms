
#include <iostream>

#include <math.h>

using namespace std;

int main(void) {

    for (double dNum, dPow; cin >> dPow >> dNum;

        cout << (int)(pow(dNum, 1.0 / dPow) + 0.5) << endl);

    return 0;

}