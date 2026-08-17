class Solution {
public:

bool is_palindrome(int l , int r, string&s){
    while(l<r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

   void solve(string &s, int index, vector<string>&temp, vector<vector<string>>&ans){
    if(index==s.size()){
        ans.push_back(temp);
        return;
    }

    for(int i=index; i<s.size(); i++){
        if(is_palindrome(index,i,s)){
            temp.push_back(s.substr(index, i-index+1));
            solve(s, i+1, temp, ans);
            temp.pop_back();
        }
    }
   }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,0,temp,ans);
        return ans;
    }
};