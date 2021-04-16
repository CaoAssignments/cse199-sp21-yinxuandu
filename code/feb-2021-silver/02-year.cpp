#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
int year[65536];
int maxi;       // largest possible interval
int itv[65536], n_itv;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &year[i]);
    sort(year, year + n);
    maxi = (year[n - 1] - 1) / 12 + 1;

    if (year[0] >= 12) {
        itv[n_itv++] = (year[0] - 1) / 12;
    }

    for (int i = 1; i < n; i++) {
        int it_now = (year[i] - 1) / 12 + 1;
        int it_pre = (year[i - 1] - 1) / 12 + 1;
        if (it_now - it_pre <= 1) continue;
        itv[n_itv++] = it_now - it_pre - 1;
    }
    sort(itv, itv + n_itv);

    int s = 0; // remove intervals in decreasing order
    for (int i = n_itv - 1; i >= n_itv - k + 1; i--) {
        s += itv[i];
    }
    
    printf("%d\n", 12 * (maxi - s));
    return 0;
}

// ./02-year < testdata/prob2_silver_feb21/1.in > 1real.out
// diff 1real.out testdata/prob2_silver_feb21/1.out  

// ./02-year < testdata/prob2_silver_feb21/7.in > 7real.out
// diff 7real.out testdata/prob2_silver_feb21/7.out  