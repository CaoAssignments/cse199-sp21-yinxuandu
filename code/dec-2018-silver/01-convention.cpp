#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, c;
int a[100005];

bool f(int sep) {
    int tot_m = 1; // current number of buses we use
    int pre_i = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[pre_i] > sep || i - pre_i + 1 > c) {
            tot_m++;
            pre_i = i;
            if (tot_m > m) return false;
        }
    }
    return true;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &c);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);

    int ln = -1; int rn = a[n - 1] - a[0] + 1;
    while (rn - ln > 1) {
        int mid = (ln + rn) >> 1;
        if (f(mid)) {
            rn = mid;
        } else {
            ln = mid;
        }
    }

    printf("%d\n", rn);
    return 0;
}