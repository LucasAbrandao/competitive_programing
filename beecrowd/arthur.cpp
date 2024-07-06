#include <bits/stdc++.h>
using namespace std;

int main()
{
    double m[12][12], resultado;
    int c;
    char t;
    cin >> c >> t;
    for (int i=0; i< 12; i++){
        for (int j=0; j< 12; j++){
            cin >> m[i][j];
        }
    }
    resultado = 0;
    for(int i=0; i < 12; i++){
        resultado += m[i][c];
    }
    if (t == 'M'){
        resultado /= 12;
    }
    cout << fixed << setprecision(1) << resultado << endl;

    return 0;
}