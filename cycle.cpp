#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> graph[10];
bool visited[10];
int parent[10];
vector<int> bestCycle;
int minSum = 1e9;

// Reconstruct cycle using parent array
vector<int> getCycle(int start, int end) {
    vector<int> cycle;
    int temp = start;
    cycle.push_back(end);
    while (temp != end) {
        cycle.push_back(temp);
        temp = parent[temp];
    }
    sort(cycle.begin(), cycle.end());
    return cycle;
}

void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
        } else {
            // Cycle detected from u -> v
            vector<int> cycle = getCycle(u, v);
            int sum = 0;
            for (int x : cycle) sum += x;

            if (sum < minSum || (sum == minSum && cycle < bestCycle)) {
                minSum = sum;
                bestCycle = cycle;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) visited[j] = false;
        parent[i] = -1;
        dfs(i);
    }

    for (int x : bestCycle) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
