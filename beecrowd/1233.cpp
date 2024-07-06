#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define float double

int phi(int n)
{
    float result = n; 
    for(int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;

            result *= (1.0 - (1.0 / (float)p));
        }
    }
    if (n > 1)
        result -= result / n;

    return (int)result;
}
int32_t main(){


    int numero;
    while(cin>>numero){
        cout<<phi(numero)/2<<"\n";
    }

    return 0;
}