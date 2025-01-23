class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> cntr(r);
        vector<int> cntc(c);

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j]){
                    cntr[i]++;
                    cntc[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j]){
                    if(cntr[i] > 1 || cntc[j] > 1) ans++;
                }
            }
        }
        return ans;
    }
};