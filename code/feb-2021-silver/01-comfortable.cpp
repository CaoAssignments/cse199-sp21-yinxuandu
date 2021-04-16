#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int n;
int isvisited[1005][1005];    // 0 means there is no cow in the grid
                              // 1 means there is cow and it is orginially in the pasture
                              // 2 means there is cow but it is later added to avoid "comfort"
                              // 4 means cow has 4 neighbors
int dx[4] = {0, 0, 1, -1};    // check four directions for each grid
int dy[4] = {1, -1, 0, 0};

typedef pair<int, int> P;

int main() {

    scanf("%d", &n);

    queue<P> q;
    int x, y;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        x++; y++;              // row/column of added cow could be -1
        if (isvisited[x][y] == 2) {
            ans--;
            isvisited[x][y] = 1;
        } else {
            isvisited[x][y] = 1; // ?

            q.push(P(x, y));
            for (int k = 0; k < 4; k++) {
                int nearx = x + dx[k];
                int neary = y + dy[k];
                if (nearx < 0 || neary < 0) continue;
                q.push(P(nearx, neary));
            }

            while (!q.empty()) {
                P tmp = q.front(); q.pop();
                int ux = tmp.first;
                int uy = tmp.second;
                int near_num = 0;  // number of cows near (ux, uy)
                int blankx, blanky;

                for (int k = 0; k < 4; k++) {
                    int nearx = ux + dx[k];
                    int neary = uy + dy[k];
                    if (nearx < 0 || neary < 0) continue;
                    if (isvisited[nearx][neary] != 0) near_num++;
                    else {
                        blankx = nearx;
                        blanky = neary;
                    }
                }

                if (near_num == 4) isvisited[ux][uy] = 4;

                if (near_num == 3) {
                    ans++;
                    isvisited[blankx][blanky] = 2;
                    q.push(P(blankx, blanky));
                    for (int k = 0; k < 4; k++) {
                        int nearx = blankx + dx[k];
                        int neary = blanky + dy[k];
                        if (nearx < 0 || neary < 0) continue;
                        if (isvisited[nearx][neary] == 4) continue;
                        q.push(P(nearx, neary));
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
