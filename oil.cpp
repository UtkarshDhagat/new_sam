#include <iostream>
#include <climits>
using namespace std;

int getMinDiff(int mines[], int m, int n, int index, int company, int currSum, int maxSum, int minSum) {
    // Base case: All mines distributed to all companies
    if (index == m && company == n)
        return maxSum - minSum;

    // If not enough elements or too many splits
    if (index >= m || company >= n)
        return INT_MAX;

    int sum = 0, result = INT_MAX;

    // Try all possible divisions from current index
    for (int i = index; i < m; i++) {
        sum += mines[i];
        int newMax = max(maxSum, sum);
        int newMin = (company == 0) ? sum : min(minSum, sum);

        result = min(result, getMinDiff(mines, m, n, i + 1, company + 1, 0, newMax, newMin));
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int mines[100];

        for (int i = 0; i < m; i++)
            cin >> mines[i];

        int result = getMinDiff(mines, m, n, 0, 0, 0, 0, INT_MAX);
        cout << result << endl;
    }

    return 0;
}
