#include<bits/stdc++.h>
using namespace std;

int* Lps(string pattern){
    int len = pattern.size();
    int* lps = new int[len];

    lps[0] = 0;
    int i=1, j=0;

    bool isFound = false;
    while(i<len){
        if(pattern[i] == pattern[j]){
            lps[i] = j+1;
            j++;
            i++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main(){
    string pattern;
    cin>>pattern;
    for(int i=0;i<pattern.size();i++){
        cout<<Lps(pattern)[i]<<" ";
    }
    cout<<endl;
    return 0;
}