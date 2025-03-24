#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int dx[] = {-1, 1, 0, 0}; // Up, Down
int dy[] = {0, 0, -1, 1}; // Left, Right

int bfs(int grid[22][22], int n, int startX, int startY, int rare[5][2], int r) {
    int visited[22][22] = {0};
    int dist[22][22] = {0};
    queue<pair<int, int>> q;

    q.push({startX, startY});
    visited[startX][startY] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && !visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    int maxD = 0;
    for (int i = 0; i < r; i++) {
        int rx = rare[i][0];
        int ry = rare[i][1];
        if (!visited[rx][ry]) return INT_MAX;
        if (dist[rx][ry] > maxD) maxD = dist[rx][ry];
    }
    return maxD;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, r;
        cin >> n >> r;
        int grid[22][22], rare[5][2];

        for (int i = 0; i < r; i++)
            cin >> rare[i][0] >> rare[i][1];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> grid[i][j];

        int ans = INT_MAX;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (grid[i][j] == 1)
                    ans = min(ans, bfs(grid, n, i, j, rare, r));

        cout << "# " << t << " " << ans << endl;
    }
    return 0;
}
