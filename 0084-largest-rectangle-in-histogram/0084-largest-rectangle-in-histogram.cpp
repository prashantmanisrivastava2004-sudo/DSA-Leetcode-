class Solution {
public:
    vector<int> prev_small(vector<int>& heights){
        vector<int>ans(heights.size());
        stack<int>st;
        for(int i=0; i<heights.size(); i++){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()==0){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
     vector<int> next_small(vector<int>& heights){
        vector<int>ans(heights.size());
        stack<int>st;
        for(int i=heights.size()-1; i>=0; i--){
            while(st.size()>0 && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(st.size()==0){
                ans[i] = heights.size();
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev = prev_small(heights);
        vector<int>next = next_small(heights);
        long long mx = 0;
        for(int i=0; i<heights.size(); i++){
            int width = next[i]-prev[i]-1;
            long long area = heights[i]*width*1LL;
            mx = max(area,mx);
        }
        return mx;
    }
};