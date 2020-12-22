#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

ll binpow(ll x, ll n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        return binpow(x * x, n / 2);
    }
    else
    {
        return x * binpow(x * x, (n - 1) / 2);
    }
}

int main()
{
    cout << binpow(2, 9) << endl;
    cout << binmod(2, 100, 1000000007);
}