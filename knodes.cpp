#include <iostream>
#include <string>
using namespace std;

int idx = 0;  // global index for parsing

// Function to extract an integer from the string at current index
int getNumber(const string& s) {
    int num = 0, sign = 1;
    if (s[idx] == '-') {
        sign = -1;
        idx++;
    }
    while (isdigit(s[idx])) {
        num = num * 10 + (s[idx++] - '0');
    }
    return num * sign;
}

// Recursive function to parse the tree and compute sum at level K
int getSumAtLevel(const string& s, int level, int K) {
    if (s[idx] != '(') return 0;
    idx++;  // skip '('

    if (s[idx] == ')') {
        idx++;  // skip ')'
        return 0;
    }

    int val = getNumber(s);
    int left = getSumAtLevel(s, level + 1, K);
    int right = getSumAtLevel(s, level + 1, K);

    idx++;  // skip ')'

    if (level == K) return val + left + right;
    return left + right;
}

int main() {
    int K;
    string tree;
    cin >> K;
    cin.ignore();           // ignore newline
    getline(cin, tree);     // read tree string
    idx = 0;                // reset index for fresh parsing
    cout << getSumAtLevel(tree, 0, K) << endl;
    return 0;
}
