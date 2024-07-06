#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;

int a, b;



void solve() {

//    vector<pair<int,char>> times = {{0,'A'},{0,'B'},{0,'C'},{0,'D'},{0,'E'},{0,'F'},{0,'G'},{0,'H'},{0,'I'},{0,'J'},{0,'K'},{0,'L'},{0,'M'},{0,'N'},{0,'O'},{0,'P'}};

    vector<int> times={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80};

    int aux=0;
    while (times.size() > 1){
        
        int a,b;
        cin >> a >> b;

        if (a > b){//a ganhou
            times.erase(times.begin()+0+aux);
        }else{
            times.erase(times.begin()+1+aux);
        }

        if (times.size() > (8)){
            aux++;
        }else{
            aux = 0;
        }
        
        if (times.size() > 4){
            aux++;
        }else{
            aux = 0;
        }
        
        if (times.size() > 2){
            aux++;
        }else{
            aux = 0;
        }


    }

    cout << static_cast<char>(times[0]) << endl;

}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) 
	//while(cin >> a >> b)
		solve();


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}