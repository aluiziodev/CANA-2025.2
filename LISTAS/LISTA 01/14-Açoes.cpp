#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<pi, pi> pii;

int minV (const int V[], int i, int j){
    if(V[i]>V[j]) return j;
    else return i;
}
int maxV (const int V[], int i, int j){
    if(V[i]<V[j]) return j;
    else return i;
}


pii melhorAçao(int V[], int i, int f){
    if(i==f) return {{i, i},{i,i}};
    /* {{c, j}, {k, l}}
        c -> posiçao do menor elemento do subvetor V[i,...,f]
        j -> posiçao do maior elemento do subvetor V[i,...,f]
        {k, l} -> armazena o par correspondente ao dias da melhor açao possivel
        naquele subvetor
    */
    else{
        int meio = (i+f)/2;
        pii esq = melhorAçao(V, i, meio);
        pii dir = melhorAçao(V, meio+1, f);
        pii resp;
        resp.first = {minV(V, esq.first.first, dir.first.first),
                      maxV(V, esq.first.second, dir.first.second)};
        int aE = V[esq.second.second] - V[esq.second.first]; // melhor açao do subvetor esq
        int aD = V[dir.second.second] - V[dir.second.first]; // melhor açao do subvetor dir
        int aT = V[dir.first.second] - V[esq.first.first]; // açao do menor de esq com o maior de dir
        if(aT>aD && aT>aE) resp.second = { esq.first.first, dir.first.second};
        else if(aD>aT && aD>aE) resp.second = dir.second;
        else resp.second = esq.second;

        return resp;

    }
    
} // O(log n)


int main(){
    int V[] = {9, 1, 5};
    pii r = melhorAçao(V, 0, 2);
    printf("%d,%d\n", r.second.first, r.second.second);
}