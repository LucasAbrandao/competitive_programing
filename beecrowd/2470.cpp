#include <bits/stdc++.h>

using namespace std;

/*
    Problema: questao de RMQ(ranged mininum queries)

    LCA usando o algoritmo de lowest comum acenstor com segmented tree :
    preprocessamento O(n) + busca O(log(n));
    algoritmos utilizados para a construção dele
    - dfs 
    - arvore de euler usando dfs para criação da leitura do grafo
    - segmented tree para guardar os resultados do preprocessamento
    -
*/

struct LCA {
    vector<int> profundidade, euler, first, segtree;
    vector<bool> visitados;
    int n;

    LCA(vector<vector<int>>& lista_adj,int raiz =0){
        n=lista_adj.size();
        profundidade.resize(n);
        first.resize(n);
        euler.reserve(n*2);  
        visitados.assign(n,false);
        dfs(lista_adj,raiz);
        int m = euler.size();
        segtree.resize(m*4);
        construir(1,0,m-1);

    }
    void dfs(vector<vector<int>> &lista_adj,int no ,int prof=0){
        visitados[no] =true;
        profundidade[no]= prof;
        first[no] = euler.size();
        euler.push_back(no);
        for(int vizinho : lista_adj[no]){
            if(!visitados[vizinho]){
                dfs(lista_adj,vizinho,prof+1);
                euler.push_back(no);
            }
        }
    }

    void construir(int no,int base,int teto){
        if(base == teto){
            segtree[no]=euler[base];
        }
        else{
            int meio = (base + teto)/2;
            construir(no << 1,base,meio);
            construir(no << 1 | 1,meio +1,teto);
            int esq = segtree[no<<1],dir = segtree[no<<1|1];
            segtree[no] = (profundidade[esq] < profundidade[dir]) ? esq : dir;
        }
    }

    int query(int no,int base,int teto,int esq,int dir){
        // printf("no=%d | base=%d | teto=%d | esq=%d | dir=%d (%d) \n",no,base,teto,esq,dir,segtree[no]);
        if(base > dir || teto < esq){
            return -1;
        }
        if(base >= esq && teto <= dir){
            return segtree[no];
        }
        int meio =(base + teto)>>1;

        int esq_nov = query(no<<1,base,meio,esq,dir);
        int dir_nova= query(no<<1 |1,meio+1,teto,esq,dir);
        if(esq_nov ==-1)
            return dir_nova;
        if(dir_nova ==-1)
            return esq_nov;
        
        return (profundidade[esq_nov]<profundidade[dir_nova]) ? esq_nov :dir_nova; 
    }
    int lca(int no1,int no2){
        int esq = first[no1],dir = first[no2];
        // printf("l=%d | r=%d ",esq,dir);
        if(esq>dir){
            swap(esq,dir);
        }
        return query(1,0,euler.size()-1,esq,dir);
    }
};

long long int resolve(LCA &a,int tamanho,unordered_map<int,int> inseridas){
    long long int resposta=0;
    int dist_comun=0;
    for(int x=1;x<=tamanho/2;x++){
        dist_comun = a.profundidade[a.lca(inseridas[x]-1,inseridas[x+tamanho]-1)] ;
        // printf("dist=%d  | prof[%d]=%d | prof2[%d]=%d \n",dist_comun,inseridas[x]-1,a.profundidade[inseridas[x]-1],inseridas[x+tamanho]-1,a.profundidade[inseridas[x+tamanho]-1]);
        // printf("dist =%d | c1 =%d  | c2 =%d \n",dist_comun,inseridas[x]-1,inseridas[x+tamanho]-1);
        resposta+= a.profundidade[inseridas[x]-1]+ a.profundidade[inseridas[x+tamanho]-1] - 2*dist_comun;
    }
    return resposta;
}

int main(){
    int tamanho, carry, carry2;
    vector<int> vec_cartas;
    vector<vector<int>> caminhos;
    unordered_map<int,int> inseridas;

    cin >> tamanho;
    caminhos.resize(tamanho);
    for(int x=1;x<=tamanho;x++){
        scanf("%d",&carry);
        if(inseridas[carry] ==0){
            vec_cartas.push_back(carry);
            inseridas[carry]=x;
        }
        else{
            vec_cartas.push_back(carry+tamanho);
            inseridas[carry+tamanho]=x;
        }
    }
    for(int x=0;x<tamanho-1;x++){
        scanf("%d %d",&carry,&carry2);
        caminhos[carry-1].push_back(carry2-1);
        caminhos[carry2-1].push_back(carry-1);
    }
    LCA a(caminhos,0);
    cout << resolve(a,tamanho,inseridas) << "\n";

    return 0;
}