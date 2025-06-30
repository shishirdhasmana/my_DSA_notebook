#include<bits/stdc++.h>
using namespace std;
int MCM(int i,int j,vector<int>&dim){
    if(i==j)return 0;
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=dim[i-1]*dim[k]*dim[j] + MCM(i,k,dim) + MCM(k+1,j,dim);
        mini=min(steps,mini);
    }
    return mini;
}
int main(){
    int n;cin>>n;
    vector<int>dim;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(i==0)dim.push_back(a);
        dim.push_back(b);
    }
    cout<<MCM(1,n,dim);
}
