class Solution {
public:
    vector<int> left(int N, vector<int>& arr) {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            while (st.size() > 0 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                ans.push_back(-1);
            } else {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> right(int N, vector<int>& arr) {
        stack<int> st;
        vector<int> ans;
        for (int i = N - 1; i >= 0; i--) {
            while (st.size() > 0 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                ans.push_back(N);
            } else {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& A) {
        int N = A.size();
        vector<int> left_small = left(N, A);
        vector<int> right_small = right(N, A);
        vector<int> ans;
        long long mx = 0;
        for (int i = 0; i < N; i++) {
            long long width = (right_small[i] - left_small[i] - 1);
            long long area = (long long)A[i] * width;
            mx = max(mx, area);
        }

        return mx;
    }
};