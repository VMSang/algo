class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        vector<vector<int>> ans(r, vector<int>(c, -1));
        queue<pair<int, int>> q;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(isWater[i][j]){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int h = 1;
        while(!q.empty()){
            int cnt = q.size();
            for(int i = 0; i < cnt; i++){
                auto curr = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    pair<int, int> near = {curr.first + dx[j], curr.second + dy[j]};
                    if(near.first >= 0 && near.first < r && near.second < c  && near.second >= 0 
                    && ans[near.first][near.second] == -1){
                        ans[near.first][near.second] = h;
                        q.push(near);
                    }
                }

            }
            h++;
        }
        return ans;
    }
};