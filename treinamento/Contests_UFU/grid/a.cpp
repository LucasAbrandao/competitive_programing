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


void printfGrid(vector<vector<char>> grid) {
	for(int i = 0; i < grid.size(); i++) {
		for(int j = 0; j < grid[i].size(); j++) {
			cout << grid[i][j];
			if(j != grid[i].size() - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}


void solve() {


	int tests,size, buildings,bombs;
	int coordXBuilding, coordYBuilding, coordXBomb, coordYBomb, rangeBomb;


	cin >> tests;
		
	for(int i = 0; i < tests; i++){

		vector<vector<char>> grid;

		cin >> size;
		grid.resize(size, vector<char>(size, '.'));	

		for(int i = 0; i < size; i++) {
			for(int j = 0; j < size; j++) {
				grid[i][j] = '.';
			}
		}

		cin >> buildings;

		for(int i = 0; i < buildings; i++) {
			cin >> coordXBuilding >> coordYBuilding;
			grid[coordXBuilding][coordYBuilding] = 'o';
		}

		cin >> bombs;

		for(int i = 0; i < bombs; i++) {
			cin >> coordXBomb >> coordYBomb >> rangeBomb;

			for(int x = coordXBomb - rangeBomb; x <= coordXBomb + rangeBomb; x++) {
				for(int y = coordYBomb - rangeBomb; y <= coordYBomb + rangeBomb; y++) {
					if (x >= 0 && x < size && y >= 0 && y < size &&
						(x - coordXBomb) * (x - coordXBomb) + (y - coordYBomb) * (y - coordYBomb) <= rangeBomb * rangeBomb) {
						if (grid[x][y] == 'o') {
							grid[x][y] = '#'; 
						} else {
							grid[x][y] = '*'; 
						}
					}
				}
			}

		}


		printfGrid(grid);

	}

	
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