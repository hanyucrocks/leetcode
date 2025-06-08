// Last updated: 6/8/2025, 1:05:30 PM
class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultp_u = findPar(u);
        int ultp_v = findPar(v);
        if (ultp_u == ultp_v)
            return;
        if (rank[ultp_u] < rank[ultp_v]) {
            parent[ultp_u] = ultp_v;
        } else if (rank[ultp_v] < rank[ultp_u]) {
            parent[ultp_v] = ultp_u;
        } else {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ultp_u = findPar(u);
        int ultp_v = findPar(v);
        if (ultp_u == ultp_v)
            return;
        if (size[ultp_u] < size[ultp_v]) {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        } else {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, -1, 0, +1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n &&
                        grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjacentNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjacentNodeNo);
                    }
                }
            }
        }

        // step 2
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, -1, 0, +1};
                set<int> comps;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n) {
                        if (grid[newr][newc] == 1) {
                            comps.insert(ds.findPar(newr * n + newc));
                        }
                    }
                }
                int sizetotal = 0;
                for(auto it : comps){
                    sizetotal += ds.size[it];
                }
                mx = max(mx, sizetotal + 1);
            }
        }
        for(int cellNo = 0; cellNo < n * n; cellNo++){
            mx = max(mx, ds.size[ds.findPar(cellNo)]);
        }
        return mx;
    }
};