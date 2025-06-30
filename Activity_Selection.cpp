#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int>start(n),deadline(n);
    for(int i=0;i<n;i++)cin>>start[i];
    for(int i=0;i<n;i++)cin>>deadline[i];
    vector<vector<int>>v;
    vector<int>ans;
    for(int i=0;i<n;i++){
        v.push_back({start[i],deadline[i]});
    }
    sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
            return a[1] < b[1];
         });
    int take=1;
    int endd=v[0][1];
    ans.push_back(v[0][0]);
    for(int i=1;i<n;i++){
        if(v[i][0]>=endd){
            take++;
            endd=v[i][1];
            ans.push_back(v[i][0]);
        }
    }
    cout<<take<<endl;
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";

}
