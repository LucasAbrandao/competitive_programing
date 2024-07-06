#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define float double

bool sortis(pair<string,int> a ,pair<string,int> b){
    string sobrea = a.first.substr(3,a.first.size()-2);
    string sobreb = b.first.substr(3,b.first.size()-2);
    if(sobrea.compare(sobreb) <0){
        return true;
    }
    else if(sobrea.compare(sobreb) >0){
        return false;
    }
    else{
        if(a.first[0]<= b.first[0]){
            return true;
        }
        else{
            return false;
        }
    }
}

int32_t main(){

    int quant;
    int contador =1;
    while(cin>>quant){
        if(quant ==0)
            break;
        cout<<"Teste "<<contador<<"\n";
        contador++;

        unordered_map<int,set<string>> artigo_autor;
        unordered_map<string, set<int> > autor_artigo; 
        unordered_map<string,int> distancia;
        set<string> autores;
        string linha;
        getline(cin,linha);
        for(int x=0;x<quant;x++){
            getline(cin,linha);
            linha.pop_back();
            linha.push_back(',');
            linha.push_back(' ');
            int pos=0;string toke;
            while((pos = linha.find(", ")) != string::npos ){
                toke = linha.substr(0,pos);
                    artigo_autor[x].insert(toke);
                    autor_artigo[toke].insert(x);
                    autores.insert(toke);
                linha.erase(0,pos + 2);
            }
        }

        queue<pair<string,int>> fila;
        fila.push({"P. Erdos",0});
        distancia["P. Erdos"]=-1;

        while(!fila.empty()){
            pair<string,int> atual = fila.front();
            fila.pop();
            for(auto att : autor_artigo[atual.first]){
                for(auto it: artigo_autor[att]){
                    if(distancia[it] == 0){
                        distancia[it] = atual.second+1;
                        fila.push({it,distancia[it]});
                    }
                }
            }
        }
        vector<pair<string,int>> autdist;
        autores.erase("P. Erdos");
        for(auto at : autores){
            autdist.push_back({at,distancia[at]});
        }
        sort(autdist.begin(),autdist.end(),sortis);
        for(auto at : autdist){
            cout<<at.first<<": ";
            at.second ==0 ? cout<<"infinito\n" :cout<<at.second<<"\n";
            
        }
        cout<<"\n";

    }

    return 0;
}