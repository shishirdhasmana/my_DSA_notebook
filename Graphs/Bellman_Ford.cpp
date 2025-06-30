#include<bits/stdc++.h>
using namespace std;

vector<int>bellman_ford(int V,vector<vector<int>>&edges,int S){
    vector<int>dist(V,1e9);
    dist[S]=0;
    for(int i=0;i<V-1;i++){
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e9 && dist[u]+wt < dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    return dist;
}

int main(){
    int V,E,S;
    cin>>V;
    cin>>E;
    cin>>S;
    vector<vector<int>>edges;
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    vector<int>dist=bellman_ford(V,edges,0);
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
}
