class Solution {
public:
    int minRotations(string s) {
        int minrotation = INT_MAX;
        int ans =0;
        int prev =0;
        for(int i=0; i<s.length(); i++){
            int digit = s[i]-'0';
            int right = digit-prev;
            int left = prev-digit;
           if(left<0){
               left += 10;
           }
            if(right < 0){
                right += 10;
            }
           minrotation = min(left,right);
           ans += minrotation;
           prev = digit;
        }
        return ans;
    }
};