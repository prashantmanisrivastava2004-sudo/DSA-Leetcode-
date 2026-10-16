class Solution {
public:
    vector<int> prev_small(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = 0; i < arr.size(); i++) {
            while (st.size() > 0 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> prev_great(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = 0; i < arr.size(); i++) {
            while (st.size() > 0 && arr[st.top()]<= arr[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> next_small(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (st.size() > 0 && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
       vector<int> next_great(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (st.size() > 0 && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long minimum(vector<int>& arr) {
        long long sum = 0;
        const int MOD = (1e9 + 7);
        vector<int> prev = prev_small(arr);
        vector<int> next = next_small(arr);
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + left * right * arr[i]);
        }
        return sum;
    }

    long long maximum(vector<int>&arr){
        long long sum = 0;
        const int MOD = (1e9 + 7);
        vector<int> prev = prev_great(arr);
        vector<int> next = next_great(arr);
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + left * right * arr[i]);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return (maximum(nums)-minimum(nums));
    }
};     