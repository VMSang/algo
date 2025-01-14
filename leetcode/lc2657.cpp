class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());
        unordered_set<int> s;
        s.insert(A[0]); 
        s.insert(B[0]);
        if(s.size() == 1) ans[0] = 1;
        else ans[0] = 0;

        for(int i = 1; i < A.size(); i++){
            int sz = s.size();
            s.insert(A[i]); 
            s.insert(B[i]);
            if(s.size() == sz) ans[i] = ans[i-1] + 2;
            else if (s.size() == (sz+1)) ans[i] = ans[i - 1] + 1;
            else ans[i] = ans[i-1];
        }

        return ans;
    }
};