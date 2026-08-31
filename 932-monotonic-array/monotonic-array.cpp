class Solution {
public:
    bool increasing(vector<int>&nums){
      
         for(int i=0; i<nums.size()-1; i++){
           if(nums[i] > nums[i+1]){
            return false;
           }
        }
        return true;
    }

     bool decreasing(vector<int>&nums){
        
         for(int i=0; i<nums.size()-1; i++){
           if(nums[i] < nums[i+1]){
             return false;
           }
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        if(increasing(nums)==1 || decreasing(nums)==1){
            return 1;
        }
        return 0;
    }
};