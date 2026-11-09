class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> s;
        vector<int> ans;
        int count = 0;

        for(int i = 0; i < A.size(); i++) {
            if(s.count(A[i])) count++;
            else s.insert(A[i]);

            if(s.count(B[i])) count++;
            else s.insert(B[i]);

            ans.push_back(count);
        }

        return ans;
    }
};