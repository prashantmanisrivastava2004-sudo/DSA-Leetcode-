class Solution {
public:
    void solve(vector<int>& arr, int index, int target, vector<int>& ans,
               vector<vector<int>>& ds, int k) {
        if (k == 0) {
            if (target == 0) {
                ds.push_back(ans);
            }
            return;
        }
        if (index == arr.size() || target < 0) {
            return;
        }
        for (int i = index; i < arr.size(); i++) {

            if (arr[i] > target) {
                break;
            }
            ans.push_back(arr[i]);
            solve(arr, i + 1, target - arr[i], ans, ds, k - 1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        vector<int> ans;
        vector<vector<int>> ds;

        int target = n;
        solve(arr, 0, target, ans, ds, k);
        return ds;
    }
};