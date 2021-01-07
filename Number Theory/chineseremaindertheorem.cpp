#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int d, x, y;

void exteuclid(int A, int B)
{
    if (B == 0)
    {
        d = A;
        x = 1;
        y = 0;
    }
    else
    {
        exteuclid(B, A % B);
        int temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

int modinverse(int A, int M)
{
    exteuclid(A, M);
    return (x + M) % M;
}

ll chineseremaindertheorem(vector<ll> num, vector<ll> rem)
{
    vector<ll> pp;
    pp.clear();

    ll prod = 1ll;
    for (ll i = 0; i < num.size(); ++i)
        prod *= num[i];
    for (ll i = 0; i < num.size(); ++i)
        pp.push_back(prod / num[i]);

    // find inv[] vector
    // inv[i] is modular inverse of pp[i] with respect to num[i]

    vector<ll> inv;
    inv.clear();
    for (ll i = 0; i < pp.size(); ++i)
        inv.push_back(modinverse(pp[i], num[i]));

    ll ans = 0ll;
    for (ll i = 0; i < pp.size(); ++i)
    {
        ans = ans % prod + (((rem[i] * pp[i]) % prod) * (inv[i]) % prod) % prod;
        ans %= prod;
    }
    return ans;
}

int main()
{
    vector<ll> num = {4, 5};
    vector<ll> rem = {1, 3};
    cout << chineseremaindertheorem(num, rem);
}