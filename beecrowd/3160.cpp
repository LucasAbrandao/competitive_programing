
#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main(){


    string a, b;
    getline(cin, a);
    getline(cin, b);

    vector<string> friends = split(a, ' ');
    vector<string> new_friends = split(b, ' ');

    string c;
    getline(cin, c);

    if(c == "nao"){
        friends.insert(friends.end(), new_friends.begin(), new_friends.end());
    }else{

        int it;

        for(int i = 0; i < friends.size(); i++){
            if(friends[i] == c){
                it = i;
                break;
            }
        }

        friends.insert(friends.begin() + it, new_friends.begin(), new_friends.end());

    }


    for(int i = 0; i < friends.size(); i++){
                    cout << friends[i];

            if(i != friends.size() - 1){
                cout << " ";
            }
        }

        cout << endl;





    return 0;
}