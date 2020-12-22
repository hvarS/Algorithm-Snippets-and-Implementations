#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int d, x, y;

// Equation Solving for A*x + B*y = d

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

int main()
{
    exteuclid(9, 6);
    cout << x << " " << y << " " << d << endl;
}