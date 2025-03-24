#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

struct worm {
    int ex, ey;   // Entry
    int exx, eyy; // Exit
    int cost;
};

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// DFS function to explore all paths
void dfs(int sx, int sy, int tx, int ty, int value, int &mincost,
         vector<worm> &wormhole, vector<bool> &visited) {

    // Try direct path to destination
    mincost = min(mincost, value + manhattan(sx, sy, tx, ty));

    for (int i = 0; i < wormhole.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;

            // Try entry -> exit
            int cost1 = value + manhattan(sx, sy, wormhole[i].ex, wormhole[i].ey) + wormhole[i].cost;
            dfs(wormhole[i].exx, wormhole[i].eyy, tx, ty, cost1, mincost, wormhole, visited);

            // Try exit -> entry (reverse)
            int cost2 = value + manhattan(sx, sy, wormhole[i].exx, wormhole[i].eyy) + wormhole[i].cost;
            dfs(wormhole[i].ex, wormhole[i].ey, tx, ty, cost2, mincost, wormhole, visited);

            visited[i] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;

        vector<worm> wormholes(n);
        for (int i = 0; i < n; ++i) {
            cin >> wormholes[i].ex >> wormholes[i].ey
                >> wormholes[i].exx >> wormholes[i].eyy
                >> wormholes[i].cost;
        }

        vector<bool> used(n, false);
        int minCost = INT_MAX;

        dfs(sx, sy, dx, dy, 0, minCost, wormholes, used);
        cout << minCost << endl;
    }
    return 0;
}
