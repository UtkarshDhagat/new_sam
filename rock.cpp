#include <iostream>
#include <climits>
#include <queue>
#include <cmath>
using namespace std;

bool canreach(int level, int n, int m, int grid[50][50], bool visited[50][50]) {
    // Reset visited
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;

    queue<pair<int, int>> q; // 
    q.push({n - 1, 0});
    visited[n - 1][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (grid[x][y] == 3) return true;

        // Vertical moves (same column)
        for (int i = 0; i < n; i++) {
            if (!visited[i][y] && grid[i][y] > 0 && abs(i - x) <= level) {
                visited[i][y] = true;
                q.push({i, y});
            }
        }

        // Left move
        if (y > 0 && grid[x][y - 1] > 0 && !visited[x][y - 1]) {
            visited[x][y - 1] = true;
            q.push({x, y - 1});
        }

        // Right move
        if (y + 1 < m && grid[x][y + 1] > 0 && !visited[x][y + 1]) {
            visited[x][y + 1] = true;
            q.push({x, y + 1});
        }
    }

    return false;
}

int main() {
    int n, m; 
    cin >> n >> m;

    int grid[50][50];
    bool visited[50][50]; 

    for (int i = 0; i < n; i++)           
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int level = 0; level < n; level++) {
        if (canreach(level, n, m, grid, visited)) {
            cout << level << endl;
            break; 
        }
    }

    return 0;
}
