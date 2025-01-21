class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sum1 = 0;
        for(int i = 0; i < grid[0].size(); i++){
            sum1 += grid[0][i];
        }

        long long sum2 = 0;
        long long MIN = LONG_LONG_MAX;
        for(int i = 0; i < grid[0].size(); i++){
            sum1 -= grid[0][i];
            MIN = min(MIN, max(sum1, sum2));
            sum2 += grid[1][i];
        }
        return MIN;
    }
};