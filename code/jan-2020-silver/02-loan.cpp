#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

long long n, k, m; // n water required, k days, m minimum water per day

bool is_valid(long long x) { // optimized
    long long g, sub, rmn;
    g = 0;
    long long i = k;
    while (i >= 0) {
        sub = (n - g) / x;
        if (sub <= m) {
            return (i * m) >= (n - g);
        }
        rmn = (n - g) % x;
        i -= rmn / sub + 1;
        g += sub * (rmn / sub + 1);
        if (g >= n) return true;
    }
    return false;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &k, &m);
    long long ln, rn;
    ln = 0; rn = n + 1; // binary search
    while (rn - ln > 1) {
        long long mid = (ln + rn) >> 1;
        if (is_valid(mid)) {
            ln = mid;
        } else {
            rn = mid;
        }
        //cout << endl;
    }
    printf("%lld\n", ln);
    return 0;
}

/*
./02-loan < testdata/loan_silver_jan20/10.in > real10.out
diff testdata/loan_silver_jan20/10.out real10.out
*/