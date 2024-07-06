#include <bits/stdc++.h>
using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define pii	         pair<int,int>
#define endl         "\n"
#define print_v(a)   for(auto x : a)cout<<x<<" ";cout<<endl
#define print_vp(a)  for(auto x : a)cout<<x.first<<" "<<x.second<< endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n)
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n)
#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 1e9;    // 2^31-1
const int LLINF = 4e18; // 2^63-1
const double EPS = 1e-9;
const int MAX = 1e6+10; // 10^6 + 10


void calculate_score(vector<int>& cards) {
    sort(cards.begin(), cards.end()); // Ordena as cartas em ordem crescente

    int score = 0;

    // sequencia
    if (cards[1] == cards[0] + 1 && cards[2] == cards[0] + 2 && cards[3] == cards[0] + 3 && cards[4] == cards[0] + 4) {
        score = cards[0] + 200;
    }
  
    //  quadra
    else if ((cards[0] == cards[1] && cards[1] == cards[2] && cards[2] == cards[3])
     ||      (cards[1] == cards[2] && cards[2] == cards[3] && cards[3] == cards[4])) {
        score = cards[2] + 180;
    }
   
    // trinca e um par
    else if ((cards[0] == cards[1] && cards[1] == cards[2] && cards[3] == cards[4]) ||
             (cards[0] == cards[1] && cards[2] == cards[3] && cards[3] == cards[4])) {
        score = cards[2] + 160;
    }
    
    //  trinca
    else if ((cards[0] == cards[1] && cards[1] == cards[2]) 
    ||       (cards[1] == cards[2] && cards[2] == cards[3])
    ||       (cards[2] == cards[3] && cards[3] == cards[4])) {
        score = cards[2] + 140;
    }
    
    //  dois pares
    else if ((cards[0] == cards[1] && cards[2] == cards[3])
    ||       (cards[0] == cards[1] && cards[3] == cards[4])
    ||       (cards[1] == cards[2] && cards[3] == cards[4])) {
        score = 3 * cards[3] + 2 * cards[1] + 20;
    }
    
    // um par sozinho
    else if (cards[0] == cards[1]) {
        score = cards[0];
    }
    else if (cards[1] == cards[2]) {
        score = cards[1];
    }
    else if (cards[2] == cards[3]) {
        score = cards[2];
    }
    else if (cards[3] == cards[4]) {
        score = cards[3];
    }
   
    else if (cards[0] != cards[1] && cards[1] != cards[2] && cards[2] != cards[3] && cards[3] != cards[4]) {
        score = 0;
    }
    

    cout << score << endl << endl;
}

void solve() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        vector<int> cards(5);
        for (int j = 0; j < 5; j++) {
            cin >> cards[j];
        }

        cout << "Teste " << i << "\n";
        calculate_score(cards);
    }
}



int32_t main() { _
	
	clock_t z = clock();
	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}
	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
