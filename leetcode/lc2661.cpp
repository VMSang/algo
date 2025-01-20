class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> c(m), r(n);
        vector<pair<int, int>> st(n*m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                st[mat[i][j] - 1] = {i, j};
            }
        }

        int sz = arr.size();
        for(int i = 0; i < sz; i++){
            auto [row, col] = st[arr[i] - 1];
            if(++c[col] == n || ++r[row] == m) return i;
        }

        return -1;
    }
};