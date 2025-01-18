class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int> (m, INT_MAX));
        ans[0][0] = 0;
        while(1){
            vector<vector<int>> prvans = ans;

            // forward
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    // above
                    if(i > 0){
                        ans[i][j] = min(ans[i][j], ans[i-1][j] + 
                        ((grid[i-1][j] == 3) ? 0 : 1));
                    }
                    // left
                    if(j > 0){
                        ans[i][j] = min(ans[i][j], ans[i][j-1] + 
                        ((grid[i][j-1] == 1) ? 0 : 1));
                    }
                }
            }

            // back
            for(int i = n-1; i >= 0; i--){
                for(int j = m-1; j >= 0; j--){
                    // bottom
                    if(i < n-1){
                        ans[i][j] = min(ans[i][j], ans[i+1][j] + 
                        ((grid[i+1][j] == 4) ? 0 : 1));
                    }
                    // right
                    if(j < m-1){
                        ans[i][j] = min(ans[i][j], ans[i][j+1] + 
                        ((grid[i][j+1] == 2) ? 0 : 1));
                    }
                }
            }

            if(ans == prvans){
                break;
            }
        }
        return ans[n-1][m-1];
    }
};