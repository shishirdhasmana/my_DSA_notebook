#include<bits/stdc++.h>
using namespace std;

void permute(string s,int l,int r,set<string>&per){
    if(l==r){
        per.insert(s);
        return;
    }
    for(int i=l;i<=r;i++){
        swap(s[i],s[l]);
        permute(s,l+1,r,per);
        swap(s[i],s[l]);
    }
}

int main(){
    string str;cin>>str;
    sort(str.begin(),str.end());
    set<string>per;
    permute(str,0,str.length()-1,per);
    for(auto it : per){
        cout<<it<<endl;
    }
}

