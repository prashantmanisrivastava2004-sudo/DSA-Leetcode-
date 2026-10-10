class Solution {
public:
    int count_set(int n){
        int count =0;
        while(n>0){
            count += (n)&(1);
            n>>=1;
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans =0;
        for(int i=0; i<nums.size(); i++){
            if(count_set(i)==k){
                ans += nums[i];
            }
        }
        return ans;
    }
};