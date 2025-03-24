#include <iostream>
using namespace std;

// Function to check if number is valid
bool isValid(int num, int del[], int n, int k) {
    int freq[10] = {0};  // Count digits

    while (num > 0) {
        int digit = num % 10;
        freq[digit]++;
        num /= 10;
    }

    // Count total appearances of deleted digits
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += freq[del[i]];
    }

    return count < k;
}

int main() {
    int a, b, k, n;
    cin >> a >> b >> k >> n;

    int del[10];
    for (int i = 0; i < n; i++) {
        cin >> del[i];
    }

    int ans = 0;
    for (int i = a; i <= b; i++) {
        if (isValid(i, del, n, k)) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
