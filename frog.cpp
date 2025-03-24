#include <iostream>      // for input and output
#include <queue>         // for using queue in BFS
using namespace std;

// Maximum matrix size (as per constraints)
const int MAX = 105;

// Function to perform BFS and return the minimum jump cost
int bfs(int mat[MAX][MAX], int n, int sx, int sy, int tx, int ty) {
    int dis[MAX][MAX] = {0};           // Stores minimum jump cost to reach each cell
    bool visited[MAX][MAX] = {false};  // Marks visited cells so we don't repeat

    queue<pair<int, int>> q;           // BFS queue to store cells (i,j)
    q.push({sx, sy});                  // Start from the source cell
    visited[sx][sy] = true;            // Mark source as visited
    dis[sx][sy] = 0;                   // No jump needed to be at source

    while (!q.empty()) {
        // Get the current cell
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); // Remove the front element from the queue

        // Move horizontally (left/right) within the same row at 0 cost
        for (int j = 0; j < n; j++) {
            // If cell (x,j) is on a 1, not visited, and in same row
            if (mat[x][j] == 1 && !visited[x][j]) {
                visited[x][j] = true;              // Mark as visited
                dis[x][j] = dis[x][y];             // No jump cost for horizontal
                q.push({x, j});                    // Add to BFS queue
            }
        }

        // Move vertically (up/down) within the same column at +1 cost
        for (int i = 0; i < n; i++) {
            // If cell (i,y) is on a 1, not visited, and in same column
            if (mat[i][y] == 1 && !visited[i][y]) {
                visited[i][y] = true;              // Mark as visited
                dis[i][y] = dis[x][y] + 1;         // Add 1 jump for vertical
                q.push({i, y});                    // Add to BFS queue
            }
        }
    }

    return dis[tx][ty]; // Return minimum jumps needed to reach destination
}

int main() {
    int n;
    cin >> n; // Read size of the matrix (n x n)

    int mat[105][105]; // Matrix to store 0s and 1s (1 = frog can go)

    // Read the matrix values
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty; // Read source and destination coordinates

    // Call the BFS function to get the minimum jumps
    int result = bfs(mat, n, sx, sy, tx, ty);

    // Print the answer
    cout << result << endl;

    return 0;
}
