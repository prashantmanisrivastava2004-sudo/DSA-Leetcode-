class Solution {
public:
    void reverse(string &s, int i, int j){
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }
    string reverseStr(string s, int k) {
        int i=0;
        
        while(i<s.length()){
        int j = min(i+k-1, (int)s.length()-1) ;
        reverse(s,i,j);
        i += 2*k;
        }
        return s;
    }
};