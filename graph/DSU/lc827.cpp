/* Friday, 31.01.2025 09:26 PM (GMT+7) */
class dsu {
public:
    vector<int> parent;
    vector<int> sz;
    dsu(int n) {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i  < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int src, int tar) {
        int u = find(src);
        int v = find(tar);

        if (u == v) return;

        if (sz[u] < sz[v]) {
            parent[u] = v;
            sz[v] += sz[u];
        } else {
            parent[v] = u;
            sz[u] += sz[v];
        }
    }
}

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid;
        dsu ds(n);
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        // make island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int crrNode = n * i + j;
                for (int k = 0; k < 4; k++) {
                    if (i + dx[k] < n && i + dy[k] < n && i + dx[k] >= 0 && i + dy[k] >= 0 && grid[i][j]) {
                        int Nodeneighbor = n * (i + dx[k]) + (j + dy[k]);
                        ds.Union(crrNode, neighborNode);
                    }
                }
            }
        }

        bool checkAllZero = false;
        int MAX = 0;

        // flip 0 -> 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                unordered_set<int> root;
                if (!grid[i][j]) {
                    checkAllZero = true;

                    for (int k = 0; k < 4; k++) {
                        if (i + dx[k] < n && i + dy[k] < n && i + dx[k] >= 0 && i + dy[k] >= 0 && grid[i][j]) {
                            int neighborNode = n * (i + dx[k]) + (j + dy[k]);
                            root.insert(ds.find(neighborNode));
                        }
                    }
                }

                // sum island
                int sum = 0;
                for (int x : root) {
                    sum += ds.sz[x];
                }

                MAX = max(MAX, sum);
            }
        }

        if (!checkAllZero) return 1;
        return MAX;
    }
};