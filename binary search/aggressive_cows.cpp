#include <bits/stdc++.h>
using namespace std;

bool canKeepCow(vector<int> arr, int limit, int cows, int n)
{
    int cows_cord = arr[0], cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - cows_cord >= limit)
        {
            cows_cord = arr[i];
            cnt++;
        }
        if (cnt >= cows)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    cout << "Enter the size of array: ";
    int n;
    cin >> n;
    cout << "Enter the number of cows: ";
    int cows;
    cin >> cows;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int lo = 1, hi = arr[n - 1] - arr[0];

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (canKeepCow(arr, mid, cows, n))
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << hi << endl;

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;
// bool isPossible(int a[], int n, int cows, int minDist)
// {
//     int cntCows = 1;
//     int lastPlacedCow = a[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (a[i] - lastPlacedCow >= minDist)
//         {
//             cntCows++;
//             lastPlacedCow = a[i];
//         }
//     }
//     if (cntCows >= cows)
//         return true;
//     return false;
// }
// int main()
// {
//     int n = 5, cows = 3;
//     int a[] = {1, 2, 8, 4, 9};
//     sort(a, a + n);

//     int low = 1, high = a[n - 1] - a[0];

//     while (low <= high)
//     {
//         int mid = (low + high) >> 1;

//         if (isPossible(a, n, cows, mid))
//         {
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }
//     cout << "The largest minimum distance is " << high << endl;

//     return 0;
// }