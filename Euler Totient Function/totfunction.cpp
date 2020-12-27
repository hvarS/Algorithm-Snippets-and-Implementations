#include <bits/stdc++.h>
using namespace std;

// This algorithm works in O(sqrt(n)) time.

int phi(int n)
{
    int ans = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans /= i;
            ans *= (i - 1);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        ans /= n;
        ans *= (n - 1);
    }

    return ans;
}

int main()
{
    cout << phi(500) << endl;
}