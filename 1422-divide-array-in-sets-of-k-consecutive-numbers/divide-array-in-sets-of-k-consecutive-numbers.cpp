class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()% k != 0){
            return false;
        }
       map<int,int>mp;
       for(int x: nums){
        mp[x]++;
       }
        while(!mp.empty()){
            int start = mp.begin()->first;
            for(int i=0; i<k; i++){
                int x = start+i;
                if(mp[x]==0){
                    return false;
                }
                mp[x]--;
                if(mp[x]==0){
                    mp.erase(x);
                }
            }
        }
        return true;
    }
};