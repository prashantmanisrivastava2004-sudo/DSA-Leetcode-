class Solution {
public:
    void reverse(string& s) {
        int st = 0;
        int end = s.size() - 1;
        while (st < end) {
            swap(s[st], s[end]);
            st++;
            end--;
        }
    }
    string removeKdigits(string s, int k) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            while (st.size() > 0 && k > 0 && (st.top() - '0') > (s[i] - '0')) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        if (st.empty())
            return "0";
        string result = "";
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        while (result.size() != 0 && result.back() == '0') {
            result.pop_back();
        }
        reverse(result);
        if (result.length() == 0)
            return "0";
        return result;
    }
};