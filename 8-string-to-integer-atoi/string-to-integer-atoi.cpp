class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n = s.size();

        //skip spaces that is leading....
        while(i<n && s[i]==' '){
            i++;
        }

        //check sign...
        int sign = 1;

        if(i<n && (s[i]=='+'||s[i]=='-')){
            if(s[i]=='-'){
                sign = -1;
            }
            i++;
        }

        if(i>=n || !isdigit(s[i])){
            return 0;
        }

        //convert into digits...
        long long ans =0;
        while(i<n && isdigit(s[i])){
            ans = ans*10 + (s[i]-'0');

            //handle overflow...
            if(sign==1 && ans>INT_MAX){
                return INT_MAX;
            }
            if(sign==-1 && -ans < INT_MIN){
                return INT_MIN;
            }
            i++;
        }
     return (sign*ans);
    }
};