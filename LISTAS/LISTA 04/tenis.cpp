#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;




vector<pair<int, int>> menorDupla(vi &H, vi &M, int n){
    vector<pair<int, int>> duplas(n);
    vector<int> Indices(n);
    sort(H.begin(), H.end());
    sort(M.begin(), M.end());
    int i = 0;
    int j = n-1;
    while(i<n && j>=0){
        duplas[i] = {H[i], M[j]};
        Indices[i] = (H[i] + M[j])/2;
        i++;
        j--;
    }

    return duplas;
    
}


int main(){
    int n; cin >> n;
    vi H(n), M(n);
    for(int i=0; i<n; i++){
        cin >> H[i];
    }
    for(int i=0; i<n; i++){
        cin >> M[i];
    }
    vector<pair<int, int>> resultado = menorDupla(H, M, n);
    for(int i=0; i<n; i++){
        cout << resultado[i].first << " " << resultado[i].second << endl;
    }
}
