class Solution {
public:
    void reverse(string& s, int l, int r) {

        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }

    void reverse_words(string& s) {

        string temp = "";
        for (int i = 0; i < s.size(); i++) {

            if (s[i] != ' ') {
                temp += s[i];
            } else if (!temp.empty() && temp.back() != ' ') {
                temp += ' ';
            }
        }

        if (!temp.empty() && temp.back() == ' ') {
            temp.pop_back();
        }

        s = temp;
        int l = 0;
        int r = 0;

        reverse(s, 0, s.size() - 1);
        while (r < s.size()) {
            if (s[r] == ' ') {
                r++;
                l = r;
                continue;
            }
            while (r < s.size() && s[r] != ' ') {
                r++;
            }
            reverse(s, l, r - 1);
            l = r;
        }
    }
    string reverseWords(string s) {
        reverse_words(s);
        return s;
    }
};