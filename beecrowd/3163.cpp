#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<string> fo, fl, fn, fs;
    bool o,l,n,s;
    o = l = n = s = false;
    string in;

    while (true) {
        cin >> in;
        cin.ignore();
        char c = in[0];

        if (c == '0') {
            break;
        }

        if (c != 'A') {
            c = in[1];
            o = l = n = s = false;

            if (c == '1') {
                o = true;
            } else if (c == '2') {
                s = true;
            } else if (c == '3') {
                n = true;
            } else {
                l = true;
            }
        } else {
            if (o) {
                fo.push(in);
                //cout << "Adicionei " << in << " no oeste\n";
            } else if (l) {
                fl.push(in);
                //cout << "Adicionei " << in << " no leste\n";
            } else if (n) {
                fn.push(in);
               // cout << "Adicionei " << in << " no norte\n";
            } else if (s) {
                fs.push(in);
               // cout << "Adicionei " << in << " no sul\n";
            }
        }
    }

    int i = 0;
    vector<string> r;

    while (!fo.empty() || !fl.empty() || !fn.empty() || !fs.empty()) {
        if (i == 0) {
            if (!fo.empty()) {
                r.push_back(fo.front());
                fo.pop();
            }
        } else if (i == 1) {
            if (!fn.empty()) {
                r.push_back(fn.front());
                fn.pop();
            }
        } else if (i == 2) {
            if (!fs.empty()) {
                r.push_back(fs.front());
                fs.pop();
            }
        } else if (i == 3) {
            if (!fl.empty()) {
                r.push_back(fl.front());
                fl.pop();
            }
        }

        i = (i + 1) % 4;
    }

    int nr = r.size();
    for (int i = 0; i < nr; i++) {
        cout << r[i];
        if (i != nr - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}