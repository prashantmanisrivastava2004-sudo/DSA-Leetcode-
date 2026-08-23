class Solution {
public:
    bool isPalindromic(string s) {
        string ascii = "";

        for (char ch : s) {
            for (int i = 7; i >= 0; i--) {
                ascii += ((ch >> i) & 1) + '0';
            }
        }

        int l = 0;
        int r = ascii.length() - 1;
        while (l < r) {
            if (ascii[l] != ascii[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};