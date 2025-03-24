#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of nodes
    int graph[100][100];

    // Read adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int color[100]; // To store color of each node
    for (int i = 0; i < n; i++) color[i] = -1; // -1 means unvisited

    // Handle disconnected graphs by checking all components
    for (int start = 0; start < n; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int i = 0; i < n; i++) {
                    if (graph[node][i]) {
                        if (color[i] == -1) {
                            color[i] = 1 - color[node]; // Color alternate
                            q.push(i);
                        } else if (color[i] == color[node]) {
                            cout << "-1" << endl; // Same color adjacent node found
                            return 0;
                        }
                    }
                }
            }
        }
    }

    // Print one of the color sets
    for (int i = 0; i < n; i++) {
        if (color[i] == 0)
            cout << i << " ";
    }
    cout << endl;

    return 0;
}
