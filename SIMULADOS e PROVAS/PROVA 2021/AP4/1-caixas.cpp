#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> Matriz;
typedef pair<int,int> pii;


/* a) Ordenar as caixas por ordem crescente de peso 
considere as seguites caixas:
1 - k=10, p=3
2 - k=4, p=4
3 - k=2, p=3
4 - k=1, p=3
ordenando por p:
4 - k=1, p=3
3 - k=2, p=3
1 - k=10, p=4
2 - k=4, p=4
total = 187

agora, troque 1 por 4, a pilhas fica:

1 - k=10, p=4
3 - k=2, p=3
4 - k=1, p=3
2 - k=4, p=4
total = 124

ou seja, formamos uma pilha com menor esforço, logo, ordenar por peso 
crescente nao minimiza o esforço total.



*/

/* b) Ordenar as caixas por ordem decrescente de k (capacidade) 
essa escolha gulosa minimiza o esforço total, pois ao colocar as caixas de maior
capacidade no topo da pilha, elas irão contribuir menos para o esforço total,
pois o esforço é calculado como a soma dos pesos de cada caixa acima dela
multiplicado pela sua capacidade. (PROVA ESCRITA NO PAPEL)

Algoritmo:
*/

int esforço(int K[], int P[], int n){
    vector<pair<int, int>> qtdItens(n);
    for(int i=0; i<n; i++){
        qtdItens[i] = {K[i], i};
    }
    sort(qtdItens.rbegin(), qtdItens.rend());
    int esforço = 0;
    int i = 0;
    while(i<n){
        int idx = qtdItens[i].second;
        int sum = 0;
        for(int j = i; j>=0; j--){
            int idj = qtdItens[j].second;
            sum += P[idj];
        }
        esforço += sum * K[idx];
        i++;
    }
    
    return esforço;
}

int main(){
    int n; cin >> n;
    int K[n], P[n];
    for(int i=0; i<n; i++){
        cin >> K[i] >> P[i];
    }
    cout << esforço(K, P, n) << endl;
}