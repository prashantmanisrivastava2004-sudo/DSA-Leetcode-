class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
           vector<int> ans;
        unordered_map<int, int> mp;

        unordered_set<int> s1;
        unordered_set<int> s2;
        unordered_set<int> s3;

       
        for (int x : nums1)
            s1.insert(x);

        for (int x : nums2)
            s2.insert(x);

        for (int x : nums3)
            s3.insert(x);

        
        for (int x : s1)
            mp[x]++;

        for (int x : s2)
            mp[x]++;

        for (int x : s3)
            mp[x]++;

       
        for (auto x : mp) {
            if (x.second >= 2)
                ans.push_back(x.first);
        }

        return ans;
    }
};