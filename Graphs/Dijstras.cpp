#include<bits/stdc++.h>
using namespace std;

vector<int>Dijstra(int V,vector<vector<int>>adj[],int S){
    vector<int>dist(V+1,1e9);
    dist[S]=0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,S});

    while(!pq.empty()){
        auto it = pq.top();
        int p_wt=it.first;
        int p_node=it.second;
        pq.pop();
        for(auto it : adj[p_node]){
            int adj_wt=it[0];
            int adj_node=it[1];
            if(p_wt + adj_wt < dist[adj_node]){
                dist[adj_node] = p_wt + adj_wt;
                pq.push({dist[adj_node],adj_node});
            }
        }
    }
    return dist;
}

int main(){
    int V,E,S;
    cin>>V>>E>>S;
    vector<vector<int>>adj[V+1];
    for(int i=1;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({wt,v});
        adj[v].push_back({wt,u});
    }
    vector<int>dist=Dijstra(V,adj,S);
    for(int i=1;i<=V;i++){
        cout<<dist[i]<<" ";
    }
}
