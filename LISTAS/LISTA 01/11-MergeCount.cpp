#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vii;


void printVetor(vii v){
    for(auto x : v){
        printf("{%d, %d} ", x.first, x.second);
    } cout << "\n";
}


int mergeCount(vii &V, int i, int f){
    if(i==f) return 0;

    int meio = (i+f)/2;
    int q1 = mergeCount(V, i, meio);
    int q2 = mergeCount(V, meio+1, f);

    vii aux(f-i+1, pi());
    int k = 0;
    int it = i;
    int j = meio+1;
    int l = 0;
    while(it<=meio || j<=f){
        if(it>meio){
            aux[l] = V[j];
            j++;
        }
        else if(j>f){
            aux[l] = V[it];
            it++;
        }
        else if(V[it].first>V[j].second){
            aux[l] = V[it];
            it++;
            k += f-j+1;
        }
        else{
            aux[l] = V[j];
            j++;
        }
        l++;
    }

    l = 0;
    it = i;
    while(it<=f){
        V[it] = aux[l];
        it++; l++;
    }
    return q1 + q2 + k;

}

int main(){
    vii V = {{9,10}, {6,7}, {4,5}, {2,3}, {11, 12}};
    cout << mergeCount(V, 0, 4) << "\n"; 
}