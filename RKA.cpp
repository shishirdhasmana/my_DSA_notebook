#include<bits/stdc++.h>
using namespace std;
int PRIME =100;
int calculateHash(string str){
    int hashf = 0;

    for(int i=0 ; i < str.length() ;i++){
        hashf += str[i] * pow(PRIME,i);
    }
    return hashf;
}

int updateHash(int oldHash,char oldChar,char newChar,int patterLength){
    int newHash = (oldHash - oldChar) / PRIME;
    newHash += newChar * pow(PRIME , patterLength -1);
    return newHash;
}
int main(){
    string text = "aaabcdaacd";
    string pattern = "cd";

    int patterHash = calculateHash(pattern);
    int textHash = calculateHash(text.substr(0,pattern.length()));

    for(int i=0;i<=text.length() - pattern.length();i++){
        if(textHash = patterHash){
            if(text.substr(i,i+pattern.length()) == pattern){
                cout<<"PATTERN FOUND AT: "<<i<<endl;
            }
        }

        if(i < text.length() - pattern.length()){
            textHash = updateHash(textHash,text[i],text[i + pattern.length()],pattern.length());
        }
    }
}
