#include <iostream>
using namespace std;

// Function to calculate probabilities recursively
void findProb(double graph[15][15], int n, int time, int node, double prob, double result[15]) {
    // If time is up, add the current probability to this node
    if (time == 0) {
        result[node] += prob;
        return;
    }

    bool hasEdge = false;

    // Try all possible outgoing paths
    for (int next = 1; next <= n; next++) {
        if (graph[node][next] > 0) {
            hasEdge = true;
            // Move to next node after 10 minutes
            findProb(graph, n, time - 10, next, prob * graph[node][next], result);
        }
    }

    // If no outgoing edges, doctor stays here and exits
    if (!hasEdge) {
        result[node] += prob;
    }
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n, e, time;
        cin >> n >> e >> time; // number of nodes, edges, time

        double graph[15][15] = {0}; // Graph with probabilities

        for (int i = 0; i < e; i++) {
            int from, to;
            double p;
            cin >> from >> to >> p;
            graph[from][to] = p; // Fill the graph
        }

        double result[15] = {0}; // To store final probabilities of each node

        // Start from node 1 with probability 1.0
        findProb(graph, n, time, 1, 1.0, result);

        // Find the node with max probability
        double maxProb = 0.0;
        int answerNode = 0;

        for (int i = 1; i <= n; i++) {
            if (result[i] > maxProb) {
                maxProb = result[i];
                answerNode = i;
            }
        }

        // Print the answer
        cout << answerNode << " " << maxProb << endl;
    }

    return 0;
}
