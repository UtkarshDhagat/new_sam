#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0}; // directions: down, up, right, left
int dy[4] = {0, 0, 1, -1};

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m; // columns, rows

        int grid[105][105]; // grid size max 100x100
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> grid[i][j];

        int r, c;
        cin >> r >> c; // start row, col

        queue<pair<pair<int, int>, int>> q; // ((x, y), level)
        q.push({{r, c}, 1});
        grid[r][c] = 2; // mark visited

        int maxLevel = 1;

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int level = q.front().second;
            q.pop();
            maxLevel = max(maxLevel, level);

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({{nx, ny}, level + 1});
                }
            }
        }

        cout << "Case #" << t << endl;
        cout << maxLevel - 1 << endl;
    }

    return 0;
}
