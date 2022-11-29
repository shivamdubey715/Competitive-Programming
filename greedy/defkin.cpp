// http:www.spoj.com/problems/DEFKIN/

#include <bits/stdc++.h>
using namespace std;
int pointx[40000 + 10], pointy[40000 + 10];

int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pointx[i] >> pointy[i];
    }
    // sort the x coordinate of the list
    sort(pointx, pointx + n);

    // sort the y coordinate of the list
    sort(pointy, pointy + n);

    int dx = pointx[0], dy = pointy[0];
    for (int i = 1; i < n; i++)
    {
        dx = max(dx, pointx[i] - pointx[i - 1]);
        dy = max(dy, pointy[i] - pointy[i - 1]);
    }
    dx = max(dx, w + 1 - pointx[n - 1]);
    dy = max(dy, h + 1 - pointy[n - 1]);
    cout << (dx - 1) * (dy - 1) << endl;
    return 0;
}