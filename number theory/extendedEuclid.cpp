// this theorem is used to find value of x and y
// if ax + by = gcd(a, b)


// #include<bits/stdc++.h>
// using namespace std;

// int x, y, GCD;
// void extendEuclid(int a, int b){
//     //Base case
//     if(b==0){
//         x=1;
//         y=0;
//         GCD=a;
//         return;
//     }
//     extendEuclid(b, a%b);
//     int ex = y;
//     int ey = x - (a/b)*y;

//     x = ex;
//     y = ey;

// }

// int main(){
//     int a, b;
//     cin>>a>>b;
//     extendEuclid(a, b);
//     cout<<x<<", "<<y<<endl;
//     return 0;
// }


//USing clasess

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
int main(){
    int a, b;
    cin>>a>>b;
    Triplet ans = extendedEuclid(a, b);
    cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;
    return 0;
}