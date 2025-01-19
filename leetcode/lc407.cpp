class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> visit(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            visit[i][0] = 1; visit[i][m-1] = 1;
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m-1], {i, m-1}});
        }
        for(int i = 0; i < m; i++){
            visit[0][i] = 1; visit[n-1][i] = 1;
            pq.push({heightMap[0][i], {0, i}});
            pq.push({heightMap[n-1][i], {n-1, i}});
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int ans = 0;
        while(!pq.empty()){
            int h = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && visit[nr][nc] == 0){
                    ans += max(0, h - heightMap[nr][nc]);
                    pq.push({max(h, heightMap[nr][nc]), {nr, nc}});
                    visit[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};