#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
        int x;
        int y;
        int gcd;
};

Triplet extendedEuclid(int a, int b){
    //Base case
    if(b==0){
        Triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd = a;
        return ans;
    }
    Triplet tempAns = extendedEuclid(b, a%b);
    Triplet ans;
    ans.x = tempAns.y;
    ans.y=tempAns.x - (a/b)*tempAns.y;
    ans.gcd = tempAns.gcd;
    return ans;
}

int mmInverse(int a, int m){
    Triplet ans = extendedEuclid(a, m);
    return ans.x;
}
int main(){
    int a=5, m=12;
    int ans = mmInverse(a, m);
    cout<<"Multiplicative modulo inverse is: "<<ans<<endl;
    return 0;
}