#include <iostream>
#include <string>
using namespace std;

int main() {
    int k;
    string str_input;

    cin >> k;           // Read level 'k'
    cin >> str_input;   // Read the tree string like: (1(4(6)))

    int binary_tree[1050] = {0};   // Store tree values by index
    bool visited[1050] = {false};  // Keep track of used positions

    int counter = 1;  // Start from root node
    int i = 1;        // Start parsing from second character (after first '(')

    while (i < str_input.length()) {
        if (str_input[i] == '(') {
            counter = counter * 2;           // Move to left child
            if (visited[counter]) {
                counter = counter + 1;       // If already used, go to right child
            }
            visited[counter] = true;
        } else if (str_input[i] == ')') {
            counter = counter / 2;           // Go back to parent
        } else if (isdigit(str_input[i])) {
            binary_tree[counter] = binary_tree[counter] * 10 + (str_input[i] - '0');
        }
        i++;
    }

    // Calculate the range for level 'k'
    int l = 1;
    for (int d = 0; d < k; d++) {
        l = l * 2;
    }
    int r = l * 2;

    // Compute sum of nodes at level k
    int total_sum = 0;
    for (int j = l; j < r; j++) {
        total_sum += binary_tree[j];
    }

    cout << total_sum << endl;
    return 0;
}
