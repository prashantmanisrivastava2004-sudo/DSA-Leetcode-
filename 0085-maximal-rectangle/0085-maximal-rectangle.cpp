class Solution {
public:
    vector<int> prev_small(vector<int>& prefix) {
        vector<int> ans(prefix.size());
        stack<int> st;
        for (int i = 0; i < prefix.size(); i++) {
            while (st.size() > 0 && prefix[st.top()] >= prefix[i]) {
                st.pop();
            }
            if (st.empty())
                ans[i] = -1;
            else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> next_small(vector<int>& prefix) {
        vector<int> ans(prefix.size());
        stack<int> st;
        for (int i = prefix.size() - 1; i >= 0; i--) {
            while (st.size() > 0 && prefix[st.top()] > prefix[i]) {
                st.pop();
            }
            if (st.empty())
                ans[i] = prefix.size();
            else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largest_hist(vector<int>& prefix) {
        vector<int> prev = prev_small(prefix);
        vector<int> next = next_small(prefix);
        long long mx = 0;
        for (int i = 0; i < prefix.size(); i++) {
            int width = next[i] - prev[i] - 1;
            long long area = width * prefix[i] * 1LL;
            mx = max(mx, area);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(),0);
        long long int mx = 0;
        for (int i = 0; i<matrix.size(); i++) {
            for (int j = 0; j<matrix[0].size(); j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j] += 1;
            }
            mx = max(mx, (long long)largest_hist(heights));
        }

        return mx;
    }
};