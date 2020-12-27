#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000007
typedef long long ll;

// Segmented Sieve is used where we need prime numbers in range L to R  which can be really large but
// R-L+1 <= 1e6

vector<int> seive(MAXN, 0);

// If seive[i] = 0 , then i + l is a prime number;

void generateseive(ll l, ll r)
{
    set<int> primes;
    ll temp = r;
    for (int i = 2; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            primes.insert(i);
            while (temp % i == 0)
            {
                temp /= i;
            }
        }
    }
    if (temp > 1)
    {
        primes.insert(temp);
        temp = 1;
    }
    for (auto prime : primes)
    {
        ll starter = ceil((l * 1.0) / prime) * prime;
        for (ll j = starter; j <= r; j += prime)
        {
            seive[j - l] = 1;
        }
    }
    return;
}

int main()
{
    ll l, r;
    l = 20;
    r = 30;
    generateseive(l, r);
    for (ll i = 0; i <= r - l; i++)
    {
        cout << seive[i] << " ";
    }
}