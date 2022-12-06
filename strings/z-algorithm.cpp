#include<bits/stdc++.h>
using namespace std;

void zArray(string str, int* Z){
    int l=0, r=0;

    int n = str.size();
    for(int i=1;i<n;i++){
        if(i>r){
            l=i, r=i;
            while(r<n && str[r-l] == str[r]){
                r++;
            }
            Z[i] = r-l;
            r--;
        }
        else{
            int k = r-l;
            if(Z[k] <= r-i){
                Z[i] = Z[k];
            }else{
                l=i;
                while(r<n && str[r-l] == str[r]){
                    r++;
                }
                Z[i] = r-l;
                r--;
            }

        }
    }
}

void searchString(string txt, string pattern){
    string str = pattern + "$" + txt;
    int n = str.size();
    int* Z = new int[n];
    zArray(str, Z);
    for(int i=0;i<n;i++){
        // cout<<Z[i]<<endl;
        if(Z[i] == pattern.size()){
            cout<<i-pattern.size()-1<<endl;
        }
    }
}

int main(){
    string txt = "abcdsafbcdfasbcda";
    string pattern = "bcd";
    // cout<<pattern.length()<<endl;
    searchString(txt, pattern);
    return 0;
}