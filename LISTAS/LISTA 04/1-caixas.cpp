#include <bits/stdc++.h>
using namespace std;

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