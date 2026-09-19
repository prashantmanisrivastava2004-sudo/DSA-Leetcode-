class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int>pq;
        queue<int>nq;
        int n = nums.size();
        vector<int>arr;
        for(int i=0; i< n; i++){
            if(nums[i]>= 0){
                pq.push(nums[i]);
            }else{
                nq.push(nums[i]);
            }
        }
       while(!pq.empty() && !nq.empty()){
           arr.push_back(pq.front());
           pq.pop();
           arr.push_back(nq.front());
           nq.pop();
       }
       return arr;
    }
};