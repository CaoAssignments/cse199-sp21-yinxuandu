#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct node {
    int idx;
    long long st; // starting time
    long long l; // duration
};

int n;
node a[100005];
long long st[100005], ll[100005];
long long ans;

bool cmp(node x, node y) {
    return x.st < y.st || (x.st == y.st && x.idx < y.idx);
}

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &st[i], &ll[i]);
        a[i].idx = i;
        a[i].st = st[i];
        a[i].l = ll[i];
    }

    // sort a[i] by increasing order of st
    sort(a, a + n, cmp);

    //long long t = a[0].st + a[0].l; // first cow should be the cow with earliest start time
    //int curi = 1;

    long long t = 0;
    int curi = 0;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int k = 1; k < n; k++) { // find out with cow eat grass next
        while (curi < n && a[curi].st <= t ) {
            q.push(a[curi].idx);
            curi++;
        }
        if (!q.empty()) {
            int tmp = q.top(); q.pop();
            if (t - st[tmp] > ans) ans = t - st[tmp];
            t += ll[tmp];
        } else {
            t = a[curi].st + a[curi].l;
            curi++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}