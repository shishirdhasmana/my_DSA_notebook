#include<bits/stdc++.h>
using namespace std;
int jobSequencing(vector<vector<int>>&arr,int n){
    int profit=0,cnt=0;
    sort(arr.begin(),arr.end(),[&](vector<int>&a,vector<int>&b){
            return a[2] > b[2];
    });
    int maxDeadline=INT_MIN;
    for(auto it : arr){
        if(it[1]>maxDeadline){
            maxDeadline=it[1];
        }
    }
    vector<int>vis(maxDeadline+1,-1);
    for(auto it : arr){
        for(int i=it[1];i>=1;i++){
            if(vis[i]==-1){
                vis[i]=it[0];
                profit+=it[2];
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
    return profit;

}
int main(){
    vector<vector<int>>arr;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int id,deadline,profit;
        cin>>id>>deadline>>profit;
        arr.push_back({id,deadline,profit});
    }
    cout<<jobSequencing(arr,n);
}
