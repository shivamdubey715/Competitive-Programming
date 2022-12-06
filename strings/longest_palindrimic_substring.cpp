#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestPalindromicSubstring(string str)
{
    int maxi = 0;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {

        // Odd Length
        int l = i, r = i;
        while (l >= 0 && r < n && str[l] == str[r])
        {
            int currentLen = r - l + 1;
            maxi = max(maxi, currentLen);
            l--;
            r++;
        }

        // Even Length
        l = i, r = i + 1;
        while (l >= 0 && r < n && str[l] == str[r])
        {
            int currentLen = r - l + 1;
            maxi = max(maxi, currentLen);
            l--;
            r++;
        }
    }
    return maxi;
}

int main()
{
    string str;
    cin>>str;
    cout<<lengthOfLongestPalindromicSubstring(str)<<endl;
    return 0;
}