#include<bits/stdc++.h>
using namespace std;

int Prims(int V,vector<vector<int>>adj[],int S){
    vector<int>vis(V,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vis[S]=1;
    pq.push({0,S});
    int mst=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(vis[node]==1)continue;
        vis[node]=1;
        mst+=wt;
        for(auto it : adj[node]){
            int adjNode=it[1];
            int adjWt=it[0];
            if(!vis[adjNode]){
                pq.push({adjWt,adjNode});
            }
        }
    }
    return mst;
}
