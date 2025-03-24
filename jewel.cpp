#include <iostream>
#include <climits>
using namespace std;

const int OPEN = 0;
const int PATH = 3;
const int WALL = 1;
const int JEWEL = 2;
const int MAX = 10;

int maxJewels = 0;
int minDepth = INT_MAX;

// Movement directions: right, down, left, up
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// Recursive DFS function
void dfs(int i, int j, int N, int maze[MAX][MAX], int path[MAX][MAX], int bestPath[MAX][MAX],
         int jewels, int depth) {

    // Base case: reached destination
    if (i == N - 1 && j == N - 1) {
        if (jewels > maxJewels || (jewels == maxJewels && depth < minDepth)) {
            maxJewels = jewels;
            minDepth = depth;

            // Save the best path
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    bestPath[r][c] = path[r][c];
                }
            }
        }
        return;
    }

    // Explore 4 directions
    for (int d = 0; d < 4; d++) {
        int r = i + dx[d];
        int c = j + dy[d];

        // Check if move is valid
        if (r >= 0 && r < N && c >= 0 && c < N && maze[r][c] != WALL && path[r][c] == OPEN) {
            path[r][c] = PATH;

            int collect = 0;
            if (maze[r][c] == JEWEL) {
                collect = 1; // If this cell has a jewel, collect it
            }

            dfs(r, c, N, maze, path, bestPath, jewels + collect, depth + 1);

            path[r][c] = OPEN; // Backtrack
        }
    }
}

int main() {
    int N;
    cin >> N;

    int maze[MAX][MAX];
    int path[MAX][MAX] = {0};
    int bestPath[MAX][MAX] = {0};

    // Input maze
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    // Start at (0,0)
    path[0][0] = PATH;
    int startJewels = 0;
    if (maze[0][0] == JEWEL) {
        startJewels = 1;
    }

    // Run DFS
    dfs(0, 0, N, maze, path, bestPath, startJewels, 0);

    // Print best path
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << bestPath[i][j] << " ";
        }
        cout << endl;
    }

    // Print total jewels collected
    cout << maxJewels << endl;

    return 0;
}
