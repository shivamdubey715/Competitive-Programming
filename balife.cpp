//https:www.spoj.com/problems/BALIFE

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    int n, i, val, diff=0;
    int max_load=0, load = 0;

    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
        load+=arr[i];
    }
    if(load%n){
        cout<<-1<<endl;
        return 0;
    }
    load/=n;
    for(int i=0;i<n;i++){
        diff+=(arr[i]-load);
        if(diff<0){
            max_load = max(max_load, -1*diff);
        }
        else{
            max_load = max(max_load, diff);
        }
    }
    cout<<max_load<<endl;
    return 0;
}