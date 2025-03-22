#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

// Check if destination is reachable under given difficulty level
bool canReach(int n, int m, int grid[10][10], int level) {
    queue<pair<int, int>> q;
    bool visited[10][10]; // Tracks visited cells
    memset(visited, false, sizeof(visited));

    // Start from bottom-left
    q.push({n - 1, 0});
    visited[n - 1][0] = true;

    while (!q.empty()) {
        int x = q.front().first; // current row
        int y = q.front().second; // current column
        q.pop();

        if (grid[x][y] == 3) return true; // reached goal

        // Move vertically in same column if within height difference
        for (int i = 0; i < n; i++) {
            if (!visited[i][y] && grid[i][y] > 0 && abs(i - x) <= level) {
                visited[i][y] = true;
                q.push({i, y});
            }
        }

        // Move left
        if (y - 1 >= 0 && grid[x][y - 1] > 0 && !visited[x][y - 1]) {
            visited[x][y - 1] = true;
            q.push({x, y - 1});
        }

        // Move right
        if (y + 1 < m && grid[x][y + 1] > 0 && !visited[x][y + 1]) {
            visited[x][y + 1] = true;
            q.push({x, y + 1});
        }
    }

    return false; // goal not reachable at this level
}

int main() {
    int n, m;
    cin >> n >> m;

    int grid[10][10]; // Input grid
    for (int i = 0; i < n; i++)         // Read each row
        for (int j = 0; j < m; j++)     // Read each column
            cin >> grid[i][j];

    // Try difficulty levels from 0 to n-1
    for (int level = 0; level < n; level++) {
        if (canReach(n, m, grid, level)) {
            cout << level << endl; // Print minimum level that works
            break;
        }
    }

    return 0;
}
