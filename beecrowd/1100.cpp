#include <bits/stdc++.h>
using namespace std;
pair<int, int> mov[] = {{2,1}, {2,-1}, {1,2}, {-1,2}, {-2,-1}, {-2,1}, {1,-2}, {-1,-2}};
int dist[8][8];

bool valid(int i, int j){
    if(i < 0 || i >= 8 || j < 0 || j >= 8){
        return false;
    }
    return true;
}

void bfs(pair<int, int> o, pair<int, int>d){

    dist[o.first][o.second] = 0;
    queue<pair<int,int>> q;
    q.push(o);

    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();

        for(auto m : mov){
            pair<int,int> u;
            u.first = cur.first + m.first;
            u.second = cur.second + m.second;
            if(valid(u.first,u.second)){
                if(dist[u.first][u.second] == -1){
                    dist[u.first][u.second] = dist[cur.first][cur.second]+1;
                    q.push(u);

                    if(u == d){
                        q = queue<pair<int,int>>();
                        break;
                    }
                }
            }
        }
    }

}

int main(){

    string s;

    while(getline(cin,s)){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            dist[i][j] = -1;
        }
    }


    pair<int,int> a, b;
    a.second = abs(97-s[0]);
    a.first = abs(56-s[1]);
    //cout << a.first << " - " << a.second << endl;

    b.second = abs(97-s[3]);
    b.first = abs(56-s[4]);

    bfs(a,b);

    cout << "To get from " << s[0] << s[1] << " to " << s[3] << s[4] << " takes " << dist[b.first][b.second] << " knight moves." << endl;



    }





    return 0;
}