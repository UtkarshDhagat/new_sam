#include <iostream>
#include <queue>
using namespace std;

// Movement directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0}; // Row change: move up/down
int dy[4] = {0, 0, -1, 1}; // Column change: move left/right

// Pipe connectivity rules (for pipe type 1 to 7)
// Each row = {up, down, left, right}, 1 means that direction is allowed
int pipeDir[8][4] = {
    {0, 0, 0, 0}, // 0: no pipe
    {1, 1, 1, 1}, // 1: up, down, left, right
    {1, 1, 0, 0}, // 2: up, down
    {0, 0, 1, 1}, // 3: left, right
    {1, 0, 0, 1}, // 4: up, right
    {0, 1, 0, 1}, // 5: down, right
    {0, 1, 1, 0}, // 6: down, left
    {1, 0, 1, 0}  // 7: up, left
};

// BFS function to count reachable pipes
int bfs(int grid[50][50], bool visited[50][50], int N, int M, int R, int C, int L) {
    queue<pair<pair<int, int>, int>> q;  // Stores ((x, y), depth)
    q.push({{R, C}, 1});                 // Start from (R, C) at depth 1
    visited[R][C] = true;               // Mark starting cell as visited
    int count = 1;                      // Starting pipe is counted

    while (!q.empty()) {
        int x = q.front().first.first;   // Current row
        int y = q.front().first.second;  // Current column
        int time = q.front().second;     // Current length used
        q.pop();

        if (time >= L) continue;         // Stop going deeper if length limit reached

        int pipeType = grid[x][y];       // Current pipe type

        // Try all 4 directions
        for (int d = 0; d < 4; d++) {
            if (!pipeDir[pipeType][d]) continue; // Skip if current pipe doesn't allow this direction

            int nx = x + dx[d];  // Next row
            int ny = y + dy[d];  // Next column

            // Check if next cell is valid and has a pipe
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == 0) continue;

            int nextPipe = grid[nx][ny];
            // Determine opposite direction (needed for bidirectional check)
            int opposite = (d == 0) ? 1 : (d == 1) ? 0 : (d == 2) ? 3 : 2;

            // Check if next pipe allows movement back into current cell
            if (!pipeDir[nextPipe][opposite]) continue;

            // All checks passed → mark and add to queue
            visited[nx][ny] = true;
            count++;
            q.push({{nx, ny}, time + 1});
        }
    }

    return count; // Return total reachable pipes
}

int main() {
    int T;
    cin >> T; // Read number of test cases

    while (T--) {
        int N, M, R, C, L;
        cin >> N >> M >> R >> C >> L; // Grid size, start point, length limit

        int grid[50][50];          // Pipe map
        bool visited[50][50] = {}; // Visited map (all false)

        // Read the pipe map
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> grid[i][j];

        // Call BFS and print result
        int result = bfs(grid, visited, N, M, R, C, L);
        cout << result << endl;
    }

    return 0;
}
