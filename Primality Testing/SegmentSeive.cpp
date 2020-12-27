#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000007
typedef long long ll;

// Segmented Sieve is used where we need prime numbers in range L to R  which can be really large but
// R-L+1 <= 1e6

vector<int> seive(MAXN, 0);

// If seive[i] = 0 , then i + l is a prime number;
vector<int> primes;
vector<int> p(1000008, 0);

void primegen()
{
    p[0] = 1;
    p[1] = 1;
    for (int i = 2; i <= MAXN; i++)
    {
        if (p[i] == 0)
        {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAXN; j += i)
            {
                p[j] = 1;
            }
        }
    }
    return;
}

void generateseive(ll l, ll r)
{
    if (l == 1)
        l++;
    for (auto prime : primes)
    {
        if (prime * prime <= r)
        {
            ll starter = (l / prime) * prime;
            if (starter < l)
                starter += prime;
            for (ll j = starter; j <= r; j += prime)
            {
                if (j != prime)
                    seive[j - l] = 1;
            }
        }
    }
    return;
}

int main()
{
    ll l, r;
    cin >> l >> r;
    primegen();
    generateseive(l, r);
    for (ll i = 0; i <= r - l; i++)
    {
        if (seive[i] == 0)
            cout << i + l << " ";
    }
}