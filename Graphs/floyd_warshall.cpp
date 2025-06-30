#include<bits/stdc++.h>
using namespace std;

void multi_source_shortest_path(vector<vector<int>>&matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1)matrix[i][j]=1e9;
            if(i==j)matrix[i][j]=0;
        }
    }

    for(int val=0;val<n;val++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                matrix[u][v]=min(matrix[u][v],matrix[u][val]+matrix[val][v]);
            }
        }
    }
}

int main(){
    vector<vector<int>>matrix={
        {0,2,-1,-1},
        {1,0,3,-1},
        {-1,-1,0,-1},
        {3,5,4,0}
    };
    int n=matrix.size();
    multi_source_shortest_path(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9)matrix[i][j]=-1;
            if(i==j)matrix[i][j]=0;
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
