class Solution {
public:
    int mySqrt(int x) {
        int st = 1;
        int end = x/2+1;
        int result = 0;
        while(st <= end){
            long long mid = st+(end-st)/2;

            if(mid*mid == x){
                return mid;
            }
            if(mid*mid > x){
                end = mid-1;
            }else{
                result = mid;
                st = mid+1;
            }
        }
        return result;
    }
};