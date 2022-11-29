// http:www.spoj.com/problems/EXPEDI/

#include <bits/stdc++.h>
using namespace std;

bool cmpr(pair<int, int> l, pair<int, int> r)
{
    return l.first > r.first;
}

int main()
{
    int n, x, F, D, f, prev = 0, d;
    int flag = 0, ans = 0;

    vector<pair<int, int>> v;
    priority_queue<int> pq;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> f;
        v.push_back(make_pair(d, f));
    }
    sort(v.begin(), v.end(), cmpr);
    cin >> D >> F;
    for (int i = 0; i < n; i++)
    {
        v[i].first = D - v[i].first;
        // cout<<v[i].first<<endl;
    }
    prev = 0;
    x = 0;
    while (x < n)
    {
        if (v[x].first - prev <= F)
        {
            F -= (v[x].first - prev);
            pq.push(v[x].second);
            prev = v[x].first;
        }
        else
        {
            if (pq.empty())
            {
                flag = 1;
                break;
            }
            F += pq.top();
            pq.pop();
            ans++;
            continue;
        }
        x++;
    }
    if (flag)
    {
        cout << -1 << endl;
        return 0;
    }
    D = D - v[n - 1].first;
    if (F >= D)
    {
        cout << ans << endl;
        return 0;
    }
    while (F < D)
    {
        if (pq.empty())
        {
            flag = 1;
            break;
        }
        F += pq.top();
        pq.pop();
        ans++;
    }
    if (flag)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}