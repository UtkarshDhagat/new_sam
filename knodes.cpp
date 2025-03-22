#include <iostream>
#include <string>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s; // Read depth k and the nested string s

    int level = -1;     // Current nesting level (starts from -1 so first '(' brings it to 0)
    int sum = 0;        // Final sum of numbers at depth k
    int num = 0;        // To store the current number being read
    bool reading = false; // Indicates if we're currently reading a number
    bool neg = false;     // Indicates if the current number is negative

    // Loop through each character in the string
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == '(') {
            level++;       // Going one level deeper
            reading = false; // Reset reading state
        } else if (c == ')') {
            // If a number was being read and we are at the target depth
            if (reading && level == k) {
                if (neg == true) {
                    sum = sum - num;
                } else {
                    sum = sum + num;
                }
            }
            // Reset state for next potential number
            reading = false;
            num = 0;
            neg = false;
            level--;       // Exiting one level
        } else if (c == '-') {
            neg = true; // Mark that the next number is negative
        } else if (c >= '0' && c <= '9') {
            if (reading == false) {
                reading = true;          // Start reading a new number
                num = c - '0';           // Convert char to int
            } else {
                num = num * 10 + (c - '0'); // Continue building multi-digit number
            }
        }
    }

    // Output the final sum
    cout << sum << endl;

    return 0;
}
