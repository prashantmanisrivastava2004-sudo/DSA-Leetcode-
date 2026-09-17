class Solution {
public:
    int maximum_ele(vector<int>& bloomday){
        int mx = INT_MIN;
        for(int i=0; i<bloomday.size(); i++){
            mx = max(mx, bloomday[i]);
        }
        return mx;
    }

    int minimum_ele(vector<int>& bloomday){
        int mn = INT_MAX;
        for(int i=0; i<bloomday.size(); i++){
            mn = min(mn, bloomday[i]);
        }
        return mn;
    }

    bool ispossible(vector<int>& bloomday,int el, int m, int k){
        int count=0;
        int bouquet=0;
        for(int i=0; i<bloomday.size(); i++){
            if((bloomday[i]) <= el){
                count++;
                if(count % k==0){
                    bouquet++;
                    count=0;
                }
            }else{
                count=0;
            }
        }
        if(bouquet>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomday, int m, int k) {
        
        int st = minimum_ele(bloomday);
        int end = maximum_ele(bloomday);
        int result= -1;
        while(st <= end){
            int mid = st+(end-st)/2;

            if(ispossible(bloomday,mid,m,k)){
                result = mid;
                end = mid-1;
            }else{
                st =  mid+1;
            }
        }
        return result;
    }
};