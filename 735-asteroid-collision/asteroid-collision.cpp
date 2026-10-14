class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>st;
        for(int i=0; i<a.size(); i++){
            if(a[i]>0) st.push_back(a[i]);
            else{
                while(st.size()>0 && st.back()>0 && st.back()<abs(a[i])){
                    st.pop_back();
                }
                if(st.size()>0 && st.back()==abs(a[i])){
                    st.pop_back();
                }
                else if(st.size()==0 || st.back()<0){
                    st.push_back(a[i]);
                }
            }
        }
        return st;
    }
};