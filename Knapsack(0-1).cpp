#include<bits/stdc++.h>
using namespace std;
int func(int ind,int W,vector<int>&val,vector<int>&weight,vector<vector<int>>&dp){
    if(ind==0){
        if(weight[ind]<=W)return val[ind];
        else return 0;
    }
    if(dp[ind][W] != -1)return dp[ind][W];
    int take=INT_MIN;
    int notTake= 0 + func(ind-1,W,val,weight,dp);
    if(weight[ind]<=W){
        take= val[ind] + func(ind-1,W-weight[ind],val,weight,dp);
    }
    return dp[ind][W]=max(take,notTake);
}
int main(){
    int n;cin>>n;
    int maxWeight;cin>>maxWeight;
    vector<int>val(n),weight(n);
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    for(int i=0;i<n;i++)cin>>val[i];
    for(int i=0;i<n;i++)cin>>weight[i];
    cout<<func(n-1,maxWeight,val,weight,dp);

}
