#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int n;
int isvisited[3005][3005];    // 0 means there is no cow in the grid
                              // 1 means there is cow
int dx[4] = {0, 0, 1, -1};    // check four directions for each grid
int dy[4] = {1, -1, 0, 0};

typedef pair<int, int> P;

P need_add(int x, int y) {
    if (isvisited[x][y] == 0) return P(-1, -1); // remember first to check if 
                                                // there is cow in the grid
    int near_num = 0;
    P ans;
    for (int k = 0; k < 4; k++) {
        int nearx = x + dx[k];
        int neary = y + dy[k];
        near_num += isvisited[nearx][neary];
        if (isvisited[nearx][neary] == 0) ans = P(nearx, neary);
    }
    if (near_num == 3) return ans;
    return P(-1, -1);
}

int main() {

    scanf("%d", &n);

    queue<P> q;
    int x, y;
    int sum = 0; // total num of cows

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        x+=1000; y+=1000;  // row/column of added cow could be negative
        q.push(P(x, y));

        while (!q.empty()) {
            P tmp = q.front(); q.pop();
            int ux = tmp.first;
            int uy = tmp.second;
            if (isvisited[ux][uy] == 1) continue;
            sum++; isvisited[ux][uy] = 1;
            
            P v = need_add(ux, uy);
            if (v.first != -1) q.push(v);
            for (int k = 0; k < 4; k++) {
                v = need_add(ux + dx[k], uy + dy[k]);
                if (v.first != -1) q.push(v);
            }
        }
        printf("%d\n", sum - i);
    }
    return 0;
}
