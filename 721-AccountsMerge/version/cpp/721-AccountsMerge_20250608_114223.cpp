// Last updated: 6/8/2025, 11:42:23 AM
class DisjointSet
{

public:
    vector<int> rank, parent, size;
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

    void unionByRank(int u, int v)
    {
        int ultp_u = findPar(u);
        int ultp_v = findPar(v);
        if (ultp_u == ultp_v)
            return;
        if (rank[ultp_u] < rank[ultp_v])
        {
            parent[ultp_u] = ultp_v;
        }
        else if (rank[ultp_v] < rank[ultp_u])
        {
            parent[ultp_v] = ultp_u;
        }
        else
        {
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // make an adjaceny list
        // overlap accross all the mails
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;
        // mail to the node, iterate over all the mails
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};