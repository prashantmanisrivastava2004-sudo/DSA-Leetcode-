class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = INT_MIN;
        int rightmax = INT_MIN;
        int left =0;
        int right = height.size()-1;
        int ans=0;
        while(left <= right){
           leftmax = max(leftmax, height[left]);
           rightmax = max(rightmax, height[right]);

           if(leftmax < rightmax){
            ans += leftmax-height[left];
            left++;
           }else{
            ans += rightmax-height[right];
            right--;
           }
        }
        return ans;
    }
};