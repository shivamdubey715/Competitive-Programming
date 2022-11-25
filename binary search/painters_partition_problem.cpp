#include <bits/stdc++.h>
using namespace std;

int feasible(vector<int> boards, int n, int limit){
    int sum=0, painters = 1;
    for(int i=0;i<n;i++){
        sum += boards[i];
        if(sum > limit){
            sum = boards[i]++;
            painters++;
        }
    }
    return painters;
}

int partition(vector<int> boards, int no_of_painters){
    int n = boards.size();
    int totalLen = 0, k=0;
    for(int i=0;i<n;i++){
        k = max(k, boards[i]);
        totalLen += boards[i];
    }

    int lo = k, hi = totalLen;
    while(lo<hi){
        int mid = (lo+hi)/2;
        int painters = feasible(boards, n, mid);
        if(painters <= no_of_painters){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main(){
    int n;
    cout<<"Enter the number of boards: ";
    cin>>n;
    int m;
    cout<<"Enter the number of painters: ";
    cin>>m;
    vector<int> boards(n);
    for(int i=0;i<n;i++){
        cin>>boards[i];
    }
    cout<<partition(boards, m)<<endl;
    return 0;
}