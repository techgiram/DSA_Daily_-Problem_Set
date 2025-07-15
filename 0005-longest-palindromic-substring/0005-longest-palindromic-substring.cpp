/*class Solution {
public:
    Helper function to check if a string is palindrome
    bool isPalindrome(const string& str) {
        int left = 0;
        int right = str.length() - 1;
        while (left < right) {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

     Main function to return longest palindromic substring
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLength = 0;
        string result = "";

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                string sub = s.substr(i, j - i + 1);
                if (isPalindrome(sub) && sub.length() > maxLength) {
                    maxLength = sub.length();
                    result = sub;
                }
            }
        }

        return result;
    }
}; */

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string result = "";

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            int l1 = i, r1 = i;
            while (l1 >= 0 && r1 < n && s[l1] == s[r1]) {
                if (r1 - l1 + 1 > result.length()) {
                    result = s.substr(l1, r1 - l1 + 1);
                }
                l1--;
                r1++;
            }

            // Even length palindrome
            int l2 = i, r2 = i + 1;
            while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                if (r2 - l2 + 1 > result.length()) {
                    result = s.substr(l2, r2 - l2 + 1);
                }
                l2--;
                r2++;
            }
        }

        return result;
    }
};

