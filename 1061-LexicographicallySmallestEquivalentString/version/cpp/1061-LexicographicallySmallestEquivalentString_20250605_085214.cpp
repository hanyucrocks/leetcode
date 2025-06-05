// Last updated: 6/5/2025, 8:52:14 AM
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = i;
        }
    }
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByLex(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    if (u == v) return;
    if (u < v)
        parent[v] = u;
    else
        parent[u] = v;
}

    void unionBySize(int u, int v)
    {
        int ultp_u = findPar(u);
        int ultp_v = findPar(v);
        if (ultp_u == ultp_v)
            return;
        if (size[ultp_u] < size[ultp_v])
        {
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else
        {
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }
};


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(25);
        for(int i = 0; i < s1.size(); i++){
            ds.unionByLex(s1[i] - 'a', s2[i] - 'a');
        }
        string ans = "";
        for(char c : baseStr){
            ans += (char)(ds.findPar(c-'a') + 'a');
        }
        return ans;
    }
};