class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(st.size()>0 && st.top()>prices[i]){
                st.pop();
            }
            if(st.size()==0){
                ans[i]=prices[i];
            }else{
                ans[i] = prices[i]-st.top();
            }
            st.push(prices[i]);
        }
        return ans;
    }
};