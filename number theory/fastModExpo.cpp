
#include<bits/stdc++.h>
using namespace std;


int fastModExpo(int a, int b, int mod){
    int res = 1;
    while(b>0){
        if(b&1){
            res = (res*a);
        }
        a = a*a;
        b = b>>1;
    }
    return res;

}

int main(){
    int a, b;
    cin>>a>>b;
    cout<<fastModExpo(a, b, 100)<<endl;;
    return 0;
}