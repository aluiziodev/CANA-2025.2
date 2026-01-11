#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> Matriz;
typedef pair<int,int> pii;



int paradasMin(vi postos, int m, int L){
    int n = postos.size();
    int paradas = 0;
    int tanque = m;
    for(int i = 0; i<n-1; i++){
        if (i==0) tanque -= postos[i];
        else  tanque -= (postos[i] - postos[i-1]);
        if(tanque < (postos[i+1] - postos[i])){
            paradas++;
            tanque = m;
        }
    }
    if (tanque < (L - postos[n-1])){
        paradas++;
    }
    return paradas;
}

int main(){
    int L, M, N;
    cin >> L >> M >> N;
    vi postos(N);
    for(int i=0; i<N; i++){
        cin >> postos[i];
    }
    cout << paradasMin(postos, M, L) << "\n";
    return 0;
}