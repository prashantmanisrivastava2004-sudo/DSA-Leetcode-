class StockSpanner {
public:
    stack<int>st;
    vector<int>prices;
    int idx =0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
    
     while(st.size()>0 && prices[st.top()]<=price){
        st.pop();
     }
     int span=0;
     if(st.empty()){
       span = idx+1;
     }else{
        span = idx-st.top();
     }
     st.push(idx);
     idx++;

     return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */