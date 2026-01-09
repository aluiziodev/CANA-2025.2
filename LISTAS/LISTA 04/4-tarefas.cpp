#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> Matriz;


int menorCusto(vi &dias, vi &multas, int n){
    vi alocaçao(n, 0);
    vector<pair<int,int>> sortMultas(n);
    for(int i=0; i<n; i++){
        sortMultas[i] = {multas[i], i};
    }
    sort(sortMultas.begin(), sortMultas.end(), greater<pair<int,int>>());
    vi multasPagas;
    int custo = 0;
    for(int i=0; i<n; i++){
        bool pago = false;
        for(int j=dias[sortMultas[i].second]-1; j >= 0; j--){  
            if(alocaçao[j]==0 && !pago){
                alocaçao[j] = sortMultas[i].first;
                pago = true;
                break;
            }
        }
        if(!pago){
            custo += sortMultas[i].first;
        }
    }
    return custo;

}

int main(){
    int n; cin >> n;
    vi dias(n);
    vi multas(n);
    for(int i=0; i<n; i++){
        cin >> dias[i] >> multas[i];
    }
    cout << menorCusto(dias, multas, n) << endl;
}