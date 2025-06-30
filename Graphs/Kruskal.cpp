#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>parent,rank;
public:
    DisjointSet(int n){
    parent.resize(n+1);
    rank.resize(n+1,0);
    for(int i=0;i<=n;i++)parent[i]=i;
    }

    int findUpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);

        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
int Kruskal(int V,vector<vector<int>>adj[]){
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            int wt=it[0];
            int v=it[1];
            if(i < v)
            edges.push_back({wt,{i,v}});
        }
    }
    sort(edges.begin(),edges.end());
    int mst=0;
    DisjointSet ds(V);
    for(auto it : edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUpar(u) != ds.findUpar(v)){
            mst+=wt;
            ds.unionByRank(u,v);
        }
    }
    return mst;
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>>adj[V];
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({wt,v});
        adj[v].push_back({wt,u});
    }
    int mstWt=Kruskal(V,adj);
    cout<<mstWt;
}
