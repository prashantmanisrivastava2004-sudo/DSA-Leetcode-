class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans="";
        if (s.size() == 1)
            return s; 
        for (int i = 0; i < s.size(); i++) {
            if(st.size()>0 && abs(st.top()-s[i])== 32){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};