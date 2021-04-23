#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int, long long> P;

int n, m;
int pos[100005];
int c[100005], tmp[100005];
vector<P> g[100005];
long long ln, rn;

void dfs(int u, int col, long long upp) {
    tmp[u] = col;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        long long val = g[u][i].second;
        if (val < upp || tmp[v] != -1) continue;
        dfs(v, col, upp);
    }
}

bool is_valid(long long upp) {
    for (int i = 1; i <= n; i++) {
        if (c[i] != -1 && c[i] < i) {
            if (tmp[i] != tmp[c[i]]) return false;
        }
        if (tmp[i] == -1) dfs(i, i, upp);
        //for (int i = 1; i <= n; i++) cout << tmp[i] << "\t";
        //cout << endl << endl;
    }
    return true;
}


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &pos[i]);
    for (int i = 0; i < m; i++) {
        int u, v; long long val;
        scanf("%d%d%lld", &u, &v, &val);
        if (i == 0 || ln > val) ln = val;
        if (i == 0 || rn < val) rn = val;
        g[u].push_back(P(v, val));
        g[v].push_back(P(u, val));
    }

    // check -1
    bool check_neg_one = true;
    for (int i = 1; i <= n; i++) if (pos[i] != i) {
        check_neg_one = false;
        break;
    }
    if (check_neg_one) {
        printf("-1\n");
        return 0;
    }

    memset(c, -1, sizeof(c));
    for (int i = 1; i <= n; i++) {
        if (pos[i] == i) continue; // don't need to switch
        if (c[i] != -1) continue; // has been visited
        int u = i;
        while (c[u] == -1) {
            c[u] = i;
            u = pos[u];
        }
    }

    // binary search
    ln--; rn++;
    while (rn - ln > 1) { // y y y .. n n n 
        //cout << ln << "\t" << rn << endl;
        long long mid = (ln + rn) >> 1;
        memset(tmp, -1, sizeof(tmp));
        if (is_valid(mid)) {
            ln = mid;
        } else {
            rn = mid;
        }
    }
    //memset(tmp, -1, sizeof(tmp));
    //cout << is_valid(500886639) << endl;
    printf("%lld\n", ln);
    return 0;
}

/*
./03-wormsort < testdata/wormsort_silver_jan20/10.in > real10.out
diff testdata/wormsort_silver_jan20/10.out real10.out
*/