class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for(int i=1; ; i++){
           if(find(nums.begin(),nums.end(), k*i) == nums.end()){
            return k*i;
           }
        }
        return 0;
    }
};