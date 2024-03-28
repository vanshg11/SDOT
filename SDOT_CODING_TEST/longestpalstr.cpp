#include <iostream>
#include <string>

using namespace std;

string longestPalindromicSubstring(string s) {
    if (s.empty()) return "";

    int start = 0, maxLength = 1;
    int n = s.length();
    bool dp[n][n] = {false};

    // Initialize base cases: single characters are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check for palindromes of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for palindromes of length greater than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string s;
    cin >> s;

    string longestPalindrome = longestPalindromicSubstring(s);
    cout << "Longest palindromic substring: " << longestPalindrome << endl;

    return 0;
}
