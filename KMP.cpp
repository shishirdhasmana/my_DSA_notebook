#include<bits/stdc++.h>
using namespace std;
vector<int>pi_function(string s){
    int n=s.size();
    vector<int>pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        if(s[i]==s[j]){
            j++;
        }
        while(j>0 && s[i] != s[j]){
            j=pi[j-1];
        };
        pi[i]=j;
    }
    return pi;
}
int main(){
    string toFind;cin>>toFind;
    vector<int>pi=pi_function(toFind);
    string str;cin>>str;
    int pos=-1;
    int i(0),j(0);
    while(i<str.size()){
        if(str[i]==toFind[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=pi[j-1];
            }
            else{
                i++;
            }
        }
        if(j == toFind.size()){
            pos= i - toFind.size();
            break;
        }
    }
    cout<<pos;
}
