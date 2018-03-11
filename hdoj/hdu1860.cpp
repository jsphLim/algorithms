#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[10], b[100];
    while (gets(a) && a[0] != '#') {
        gets(b);
        for (int i = 0; a[i] != 0; i++) {
            printf("%c %d\n", a[i], std::count(b, b + strlen(b), a[i]));
        }
    }
}
