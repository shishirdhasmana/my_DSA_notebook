#include<bits/stdc++.h>
using namespace std;
int fractional_napsack(vector<vector<int>>&weights,int wt){
    sort(weights.begin(),weights.end(),[&](vector<int>&a,vector<int>&b){
         return a[0]/a[1] > b[0]/b[1];
         });
    int totalVal=0;
    int n=weights.size();
    for(auto it : weights){
        if(it[1] <= wt){
            totalVal+=it[0];
            wt-=it[1];
        }
    }
    return totalVal;
}
int main(){
    vector<vector<int>>weights;
    int n;cin>>n;
    int w;cin>>w;
    for(int i=0;i<n;i++){
        int value,wt;
        cin>>value>>wt;
        weights.push_back({value,wt});
    }
    cout<<fractional_napsack(weights,w);
}
