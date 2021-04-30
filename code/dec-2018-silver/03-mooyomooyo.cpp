#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, k;
char c[102][11];
int label[102][15];
int num_label[1003];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j, int label_val) {
    label[i][j] = label_val;
    num_label[label_val]++;
    for (int k = 0; k < 4; k++) {
        int ii = i + dx[k];
        int jj = j + dy[k];
        if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
        if (c[i][j] != c[ii][jj] || label[ii][jj] != -1) continue;
        dfs(ii, jj, label_val);
    }
}

bool chk() {
    memset(label, -1, sizeof(label));
    int n_label = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '0' || label[i][j] != -1) continue;
            num_label[n_label] = 0;
            dfs(i, j, n_label);
            n_label++;
        }
    }
    for (int i = 0; i < n_label; i++) {
        if (num_label[i] >= k) return true;
    }
    return false;
}

void update() {
    for (int j = 0; j < m; j++) {
        int curi = n - 1; int i = n - 1;
        while (i >= 0) {
            while (i >= 0 && (c[i][j] == '0' || num_label[label[i][j]] >= k)) {
                i--;
            }
            if (i < 0) break;
            c[curi][j] = c[i][j];
            curi--;
            i--;
        }
        
        while (curi >= 0) {
            c[curi][j] = '0';
            curi--;
        }
    }
}

int main() {
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);
    m = 10;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%s", c[i]);

    //for (int i = 0; i < n; i++) printf("%s\n", c[i]);

    //while (1) {
    for (int q = 0; q < 10; q++) {
        if (!chk()) break;
        update();

       // for (int i = 0; i < n; i++) printf("%s\n", c[i]);

       /* cout << "=====" << endl << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << label[i][j] << ' ';
            cout << endl;
        }

        cout << "=====" << endl << endl;*/
    }

    for (int i = 0; i < n; i++) printf("%s\n", c[i]);
    return 0;
}