#include <bits/stdc++.h>
using namespace std;
typedef long long int int64;

/* Ordena por horário de término */

bool ordena(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int main(){
    int N; cin >> N;
    vector<pair<int, int>> v;
    pair<int, int> aux;
    int i, f;
    while(N--){
        cin >> i >> f;
        aux.first = i; aux.second = f;
        v.push_back(aux);
    }
    sort(v.begin(), v.end(), ordena);
    int atividades = 0;
    int ultima = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].first > ultima){
            atividades++;
            ultima = v[i].second;
        }
    }
    cout << atividades << endl;
}