class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int freq[26]={0};
       for(int i=0; i<s1.size(); i++){
        freq[s1[i]-'a']++;
       }
       int i=0;
       int j=0;
       int k = s1.size();
       while(j<s2.size()){
        freq[s2[j]-'a']--;
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1==k){
            bool found = true;
            for(int x =0; x<26; x++){
                if(freq[x] != 0){
                    found = false;
                    break;
                }
            }
            if(found){
                return true;
            }
            freq[s2[i]-'a']++;
            i++;
            j++;
        }
       }
       return false;
    }
};