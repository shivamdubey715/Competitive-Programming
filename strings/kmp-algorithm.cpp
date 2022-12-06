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
bool KmpSearch(string str, string pat){
    int lens = str.size();
    int lenp = pat.size();

    int* lps = Lps(pat);
    int i=0, j=0;
    while(i<lens &&  j<lenp){
        if(str[i] == pat[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j == lenp){
        return true;
    }
    return false;
    
}

int main(){
    string str, pat;
    cin>>str>>pat;
    cout<<KmpSearch(str, pat)<<endl;
    return 0;
}