#include <iostream>
#include <climits>
using namespace std;

int maxJewels = 0;

// Directions: down, right, up, left
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y, int n, int maze[10][10], bool visited[10][10]) {
    return x >= 0 && y >= 0 && x < n && y < n && maze[x][y] != 1 && !visited[x][y];
}

void dfs(int x, int y, int n, int maze[10][10], bool visited[10][10],
         int jewels, int path[10][10], int bestPath[10][10]) {
    if (x == n - 1 && y == n - 1) {
        if (jewels >= maxJewels) {
            maxJewels = jewels;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    bestPath[i][j] = path[i][j];
        }
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (isValid(nx, ny, n, maze, visited)) {
            visited[nx][ny] = true;
            path[nx][ny] = 3;
            int add = (maze[nx][ny] == 2) ? 1 : 0;
            dfs(nx, ny, n, maze, visited, jewels + add, path, bestPath);
            path[nx][ny] = maze[nx][ny];  // backtrack
            visited[nx][ny] = false;
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
        maxJewels = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
                path[i][j] = maze[i][j];
                bestPath[i][j] = maze[i][j];
            }

        visited[0][0] = true;
        path[0][0] = 3;
        int startJewels = (maze[0][0] == 2) ? 1 : 0;

        dfs(0, 0, n, maze, visited, startJewels, path, bestPath);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << bestPath[i][j] << " ";
            cout << endl;
        }
        cout << maxJewels << endl << endl;
    }
    return 0;
}
