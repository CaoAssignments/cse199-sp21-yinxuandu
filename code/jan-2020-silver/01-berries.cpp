#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k;
int a[1005], max_a;
int num[1005];
int ans;

int min (int x, int y) {
    return x < y ? x : y;
}

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i == 0 || max_a < a[i]) max_a = a[i];
    }

    for (int upp = 1; upp <= max_a; upp++) {
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) {
            num[upp] += a[i] / upp;
            if (a[i] % upp != 0) {
                num[a[i] % upp]++;
            }
        }

        int tmp = 0;
        int half_tmp = 0;
        int k_tmp = 0;
        for (int cnt = upp; cnt >= 1; cnt--) {
            if (k_tmp < k / 2) {
                half_tmp += cnt * (min(k / 2, k_tmp + num[cnt]) - k_tmp);
            }
            if (k_tmp < k) {
                tmp += cnt * (min(k, k_tmp + num[cnt]) - k_tmp);
            }
            k_tmp += num[cnt];
            if (k_tmp >= k) break;
        }
        //cout << endl << "upp=" << upp << "\t" << tmp << "\t" << half_tmp << endl;
        if (ans == 0 || ans < tmp - half_tmp) ans = tmp - half_tmp;
    }
    
    printf("%d\n", ans);
    return 0;
}

/*
./01-berries < testdata/berries_silver_jan20/1.in > real1.out
diff real1.out testdata/berries_silver_jan20/1.out

./01-berries < testdata/berries_silver_jan20/10.in > real10.out
diff real10.out testdata/berries_silver_jan20/10.out
*/