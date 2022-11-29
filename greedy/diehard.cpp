// https : // www.spoj.com/problems/DIEHARD/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1001, vector<int>(1001, -1));

int solve(int h, int a, int i)
{
    if (h <= 0 || a <= 0)
    {
        return 0;
    }
    if (dp[h][a] != -1)
    {
        return dp[h][a];
    }
    int x, y, z;
    x = y = z = 0;
    if (i != 1)
    {
        x = 1 + solve(h + 3, a + 2, 1);
    }
    if (i != 2)
    {
        y = 1 + solve(h - 5, a - 10, 2);
    }
    if (i != 3)
    {
        z = 1 + solve(h - 20, a + 5, 3);
    }
    dp[h][a] = max({x, y, z});
    return dp[h][a];
}

void solve2()
{
    int h, a, res = 1;
    cin >> h >> a;
    h += 3;
    a += 2;
    while (1)
    {
        if (h > 20 && a > -5)
        {
            h = h - 20;
            a = a + 5;
        }
        else if (h > 5 && a > 10)
        {
            h = h - 5;
            a = a - 10;
        }
        else if (h <= 0 || a <= 0)
        {
            cout << res << endl;
            break;
        }
        else
        {
            h = h + 3;
            a = a + 2;
        }
        res++;
    }
}
void solve2(int h, int a)
{
    long long int time = 0;
    while (1)
    {
        if (time % 2 == 0)
        {
            h += 3;
            a += 2;
        }

        else
        {
            if (a > 10)
            {
                h -= 5;
                a -= 10;
            }

            else
            {
                h -= 20;
                a += 5;
            }
        }

        if (a > 0 && h > 0)
            time++;

        else
            break;
    }

    cout << time << endl;
}

int main()
{
    int h, a;
    cin >> h >> a;
    cout << max({solve(h + 3, a + 2, 1), solve(h - 5, a - 10, 2), solve(h - 20, a + 5, 3)}) << endl; // Solved using Dynamic Programming
    solve2(h ,a);                                                                                        // Solved using greedy method

    return 0;
}