#include <iostream>
using namespace std;

// Check if a move is valid
bool isValid(int x, int y, int n, int maze[10][10], bool visited[10][10]) {
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] != 1 && !visited[x][y]);
}

// DFS to find best path collecting max jewels
void findPath(int x, int y, int n, int maze[10][10], bool visited[10][10],
              int jewels, int &maxJewels, int path[10][10], int bestPath[10][10]) {

    if (x == n - 1 && y == n - 1) {  // reached exit
        if (jewels > maxJewels) {   // found better path
            maxJewels = jewels;

            // Save current path as best path
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    bestPath[i][j] = path[i][j];
        }
        return;
    }

    // Move in 4 directions
    int dx[] = {1, 0, -1, 0};  // down, right, up, left
    int dy[] = {0, 1, 0, -1};

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (isValid(nx, ny, n, maze, visited)) {
            visited[nx][ny] = true;
            path[nx][ny] = 3;  // mark path
            int extra = 0;
            if (maze[nx][ny] == 2) extra = 1;  // found jewel

            findPath(nx, ny, n, maze, visited, jewels + extra, maxJewels, path, bestPath);

            visited[nx][ny] = false;  // backtrack
            path[nx][ny] = maze[nx][ny];  // restore cell
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int maze[10][10], path[10][10], bestPath[10][10];
        bool visited[10][10] = {false};
        int maxJewels = 0;

        // Read maze and prepare path arrays
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
                path[i][j] = maze[i][j];
                bestPath[i][j] = maze[i][j];
            }

        // Start from (0,0)
        visited[0][0] = true;
        path[0][0] = 3;
        int startJewels = (maze[0][0] == 2) ? 1 : 0;

        findPath(0, 0, n, maze, visited, startJewels, maxJewels, path, bestPath);

        // Output path
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << bestPath[i][j] << " ";
            cout << endl;
        }
        cout << maxJewels << endl << endl;
    }

    return 0;
}
