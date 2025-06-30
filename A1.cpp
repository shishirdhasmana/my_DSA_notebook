#include<bits/stdc++.h>
using namespace std;
char nextChar(char ch){
    if(ch == 'z')return 'a';
    return ch+1;
}
bool isSimilar(string &newPass,string &oldPass){
    int i=0,j=0;
    while(i<newPass.length() && j < oldPass.length()){
        char orignal = newPass[i];
        char changed = nextChar(orignal);

        if(orignal == oldPass[j] || changed == oldPass[j])j++;
        i++;
    }
    return j== oldPass.length();
}
int main(){
    int n;cin>>n;
    vector<string>newPass(n),oldPass(n);
    for(int i=0;i<n;i++)cin>>newPass[i];
    for(int i=0;i<n;i++)cin>>oldPass[i];

    for(int i=0;i<n;i++){
        if(isSimilar(newPass[i],oldPass[i])){
            cout<<"Yes";
        }
        else cout<<"No";
    }
}
