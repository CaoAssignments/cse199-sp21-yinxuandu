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

    for (int lo = 0; lo < n - 1; lo++) {
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

            long long tmp = 0; //
            int k = 0; // iterator
            for (int j = 0; j < n; j++) {
                if (k >= n) break;
                if (val[j] != 100) continue;

                while (k < n) {
                    if (sub[k] > j) break;
                    if (sub[k] != -1) tmp += (long long)(k - sub[k] + 1);
                    k++;
                }
            }

            //cout << lo << ", " << up << "\t" << tmp << endl;

            ans += tmp; //
        }
    }
    printf("%lld\n", ans);
    return 0;
}

// ./03-green < testdata/prob3_silver_feb21/1.in > 1real.out
// diff 1real.out testdata/prob3_silver_feb21/1.out 