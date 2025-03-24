#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// BFS from (startX, startY), return the max distance to all rare elements
int bfs(int n, int grid[22][22], int startX, int startY, int rare[5][2], int r) {
    int visited[22][22] = {0};
    int dist[22][22] = {0};
    queue<pair<int, int>> q;

    q.push(make_pair(startX, startY));
    visited[startX][startY] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // Valid cell check
            if (nx >= 1 && ny >= 1 && nx <= n && ny <= n &&
                !visited[nx][ny] && grid[nx][ny] == 1) {
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    // Find max distance to all rare elements
    int maxDist = 0;
    for (int i = 0; i < r; i++) {
        int rx = rare[i][0];
        int ry = rare[i][1];
        if (!visited[rx][ry]) return INT_MAX; // can't reach
        if (dist[rx][ry] > maxDist)
            maxDist = dist[rx][ry];
    }
    return maxDist;
}

int main() {
    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        int n, r;
        cin >> n >> r;

        int grid[22][22];
        int rare[5][2];

        // Read rare-element positions (1-based)
        for (int i = 0; i < r; i++) {
            cin >> rare[i][0] >> rare[i][1];
        }

        // Read grid
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> grid[i][j];

        int answer = INT_MAX;

        // Try placing research center at every road cell
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i][j] == 1) {
                    int maxDistance = bfs(n, grid, i, j, rare, r);
                    if (maxDistance < answer)
                        answer = maxDistance;
                }
            }
        }

        cout << "# " << test << " " << answer << endl;
    }

    return 0;
}
