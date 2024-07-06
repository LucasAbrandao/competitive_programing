#include <bits/stdc++.h>
using namespace std;

int mediaTeto(int sum, int n){
    int media;
    if(sum%n != 0){
        media = sum/n + 1;
    }else{
        media = sum/n;
    }
    return media;
}

int main(){


    int n, m; cin >> n >> m;
    int i = 30; int l = 30;
    deque<int> dq;

    int sum = 0;
    while(i--){
        int k; cin >> k;
        dq.push_back(k);
        sum+=k;
    }

    int media = mediaTeto(sum, l);

    //cout << "Ha media e " << media << endl;

    int d = 0;

    while(n < m){
        d++;
        //cout << n << endl;
        dq.push_back(media);
        sum += media;
        sum -= dq.front();
        dq.pop_front();
        n += media;
        media = mediaTeto(sum, l);
    }

    cout << d << endl;


    return 0;
}