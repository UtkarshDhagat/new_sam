#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int matrix[15][15];  // As per constraint (1 < n,m < 15)

    // Read the matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    int maxRows = 0;

    // Loop through each row
    for (int i = 0; i < n; ++i) {
        int zeroCount = 0;

        // Count number of 0s in current row
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0)
                zeroCount++;
        }

        // Check if this row is eligible
        if (zeroCount <= k && (k - zeroCount) % 2 == 0) {
            int matchCount = 0;

            // Compare with all rows to count identical ones
            for (int r = 0; r < n; ++r) {
                bool same = true;
                for (int c = 0; c < m; ++c) {
                    if (matrix[r][c] != matrix[i][c]) {
                        same = false;
                        break;
                    }
                }
                if (same)
                    matchCount++;
            }

            if (matchCount > maxRows)
                maxRows = matchCount;
        }
    }

    cout << maxRows << endl;
    return 0;
}
