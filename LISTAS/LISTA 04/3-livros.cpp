#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


int menorCusto(vi &dias){
    sort(dias.begin(), dias.end());
    int custo = 0;
    int currDias = 0;
    for(int i=0; i< (int) dias.size(); i++){
        custo += dias[i] + currDias;
        currDias += dias[i];
    }
    return custo;
}

int main(){
    int n; cin >> n;
    vi dias(n);
    for(int i=0; i<n; i++){
        cin >> dias[i];
    }
    cout << menorCusto(dias) << endl;
}