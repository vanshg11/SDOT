#include <iostream>
#include <unordered_set>

using namespace std;

int longestSubstring(string s) {
    int maxLength = 0;
    int left = 0, right = 0;
    unordered_set<char> charSet;

    while (right < s.length()) {
        char c = s[right];
        if (charSet.count(c) == 0) {
            charSet.insert(c);
            maxLength = max(maxLength, right - left + 1);
            right++;
        } else {
            charSet.erase(s[left]);
            left++;
        }
    }

    return maxLength;
}

int main() {
    string s;
    cin >> s;

    int length = longestSubstring(s);
    cout << "Length of the longest substring with each character at most once: " << length << endl;

    return 0;
}
