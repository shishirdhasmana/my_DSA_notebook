#include<bits/stdc++.h>
using namespace std;
int func(vector<int>values,int k){
    int n=values.size();
    int total=0;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        values[i]%=k;
        mpp[values[i]]++;
    }
    for(int i=0;i<n;i++){
        if(values[i]==0){
            total=mpp[0]-1;
            continue;
        }
        int diff=k-values[i];
        total+=mpp[diff];
        if(diff==values[i]){
            total--;
        }
    }
    return total/2;
}
int main(){
    int n;cin>>n;
    int k;cin>>k;
    vector<int>values(n);
    for(int i=0;i<n;i++)cin>>values[i];
    cout<<func(values,k);
}
