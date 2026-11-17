class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // create a empty result string
        string res = "";
        // traverse for the whole 1st string.
        for (int i = 0; i < strs[0].size(); i++) {
            // check for other strings.
            for (auto s : strs) {
                if (s[i] != strs[0][i]) {
                    return res;
                }
            }
            // if equal elements found add it to the result.
            res += strs[0][i];
        }
        return res;
    }
};