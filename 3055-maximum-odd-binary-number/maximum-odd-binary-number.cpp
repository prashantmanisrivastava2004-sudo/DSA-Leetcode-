class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int start=0; 
        int end = s.size()-1;
        while(start<=end){
            if(s[end]=='0'){
                end--;
            }
            else if(s[start]=='0' && s[end]=='1'){
                swap(s[start], s[end]);
                start++;
                end--;
            }
            else{
                start++;
            }
        }
       swap(s[start-1], s[s.size()-1]);
        return s;
    }
};