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

int main()
{
    cout << modinverse(5, 12) << endl;
}