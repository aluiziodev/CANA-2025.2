#include <bits/stdc++.h>
using namespace std;
typedef long long int int64;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;


/* Ordena por horário de término */

bool ordena(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int salasMax(vii &v){
    sort(v.begin(), v.end(), ordena);
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < (int) v.size(); i++){
        if(!heap.empty() && v[i].first >= heap.top()){
            heap.pop();   
        }
        heap.push(v[i].second);
    }
    return (int) heap.size();
}

int main(){
    int n; cin >> n;
    vii v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    cout << salasMax(v) << endl;
}