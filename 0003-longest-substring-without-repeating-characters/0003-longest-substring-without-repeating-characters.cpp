class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0, r=0;
        int maxlen =0;
        while(r<s.size()){
            if(mp[s[r]]<1){
               mp[s[r]]++;
               maxlen = max(maxlen,r-l+1);
               r++;
            }else{
                mp[s[l]]--;
                l++;
            }
        }
     return maxlen;
    }
};