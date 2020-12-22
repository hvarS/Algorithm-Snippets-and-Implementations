#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Important Condition Mod Number M must be prime

ll binmod(ll x, ll n, ll M)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        return binmod((x * x) % M, n / 2, M);
    }
    else
    {
        return (x * binmod((x * x) % M, (n - 1) / 2, M)) % M;
    }
}

ll fmodinverse(ll A, ll M)
{
    ll num = binmod(A, M - 2, M);
    return num;
}

int main()
{
    cout << fmodinverse(5, 11) << endl;
}