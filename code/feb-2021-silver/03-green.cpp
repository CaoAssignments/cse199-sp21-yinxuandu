#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[505][505];
int val[505]; // minimum value of the current width
int sub[505]; // value >=100 from sub[i] to i; -1 if current value <100
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int lo = 0; lo < n; lo++) {
        // initialize val starting from row lo
        for (int j = 0; j < n; j++) val[j] = a[lo][j];

        for (int up = lo; up < n; up++) {
            // consider all sub-grids with width [lo, up]
            if (up > lo) {
                // update val
                for (int j = 0; j < n; j++)
                    if (val[j] > a[up][j]) val[j] = a[up][j];
            }

            // notice that sub[j] is monotonously non-decreasing (ignore -1)
            for (int j = 0; j < n; j++) {
                if (val[j] < 100) sub[j] = -1;
                else {
                    if (j == 0 || sub[j - 1] == -1) sub[j] = j;
                    else sub[j] = sub[j - 1];
                }
            }

            long long tmp = 0;
            int lst = -1; // the index of last 100 by far
            for (int j = 0; j < n; j++) {
                if (val[j] == 100) lst = j;
                if (lst != -1 && sub[j] != -1 && sub[j] <= lst) {
                    tmp += (long long)(lst - sub[j] + 1);
                }
            }
            ans += tmp; //
        }
    }
    printf("%lld\n", ans);
    return 0;
}

// ./03-green < testdata/prob3_silver_feb21/1.in > 1real.out
// diff 1real.out testdata/prob3_silver_feb21/1.out 

/*
5
101 100 99 102 100
101 56 100 101 107
101 100 78 99 106
100 102 103 104 105
101 102 70 100 99
*/