#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct worm {
    int ex, ey;   // Entry
    int exx, exy; // Exit
    int cost;
};

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(int x, int y, int dx, int dy, vector<worm>& wormholes, vector<bool>& used, int cost, int& minCost) {
    // Base case: try walking directly from current position to destination
    minCost = min(minCost, cost + manhattan(x, y, dx, dy));

    int n = wormholes.size();
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            used[i] = true;

            // Try entering from ex, ey → exit to exx, exy
            int toEntry = manhattan(x, y, wormholes[i].ex, wormholes[i].ey);
            dfs(wormholes[i].exx, wormholes[i].exy, dx, dy, wormholes, used,
                cost + toEntry + wormholes[i].cost, minCost);

            // Try entering from exx, exy → exit to ex, ey
            int toExit = manhattan(x, y, wormholes[i].exx, wormholes[i].exy);
            dfs(wormholes[i].ex, wormholes[i].ey, dx, dy, wormholes, used,
                cost + toExit + wormholes[i].cost, minCost);

            used[i] = false; // backtrack
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
                >> wormholes[i].exx >> wormholes[i].exy
                >> wormholes[i].cost;
        }

        vector<bool> used(n, false);
        int minCost = INT_MAX;
        dfs(sx, sy, dx, dy, wormholes, used, 0, minCost);
        cout << minCost << endl;
    }
    return 0;
}
