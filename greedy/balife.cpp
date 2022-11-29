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
    if(load%n){  //if we cannot divide the load equally
        cout<<-1<<endl;
        return 0;
    }
    load/=n; //load that is to be divided equally
    for(int i=0;i<n;i++){
        /*
        at each iteration, find the value_compare
        of difeerence between final to be assigned
        and current load
        keep adding this difference in diff
        */
        diff+=(arr[i]-load);
        // if the net diff is negative i.e 
        // we need diff amount till ith index

        if(diff<0){
            max_load = max(max_load, -1*diff);
        }
        // if the diff is positive i.e we have to give diff amount to n-1 processors
        else{
            max_load = max(max_load, diff);
            // calculate max of load that can be given or taken at each iteration
        }
    }
    cout<<max_load<<endl;
    return 0;
}