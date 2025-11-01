#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

void printVetor(vi &V, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    cout << endl;   
}
void mergeOcorrAux(vii &V, vi &O, int i, int f){
    if(i==f) O[i]++;
    if(i!=f){
        int meio = (i+f)/2;
        mergeOcorrAux(V, O, i, meio);
        mergeOcorrAux(V, O, meio+1, f);


        vii A(f-i+1); 
        int it = i;
        int j = meio+1;
        int l = 0;

        while(it<=meio || j<=f){
            if(it>meio){
                A[l] = V[j];
                j++;
            }
            else if(j>f){
                A[l] = V[it];
                it++;
            }
            else if(V[it].first > V[j].first){
                A[l] = V[j];
                j++;
            }
            else if(V[it].first == V[j].first){
                int value = V[it].first;
                int total = O[V[it].second] + O[V[j].second];
                O[V[it].second] = total;
                A[l] = V[it]; it++;
                
                while(it<=meio && V[it].first==value){
                    O[V[it].second] = total;
                    A[++l] = V[it];
                    it++;
                }
                while(j<=f && V[j].first==value){
                    O[V[j].second] = total;
                    A[++l] = V[j];
                    j++;
                }

            }
            else{
                A[l] = V[it]; it++; 
            }
            l++;
        }

        l = 0;
        it = i;
        while(it<=f){
            V[it] = A[l];
            it++; l++;
        }


    } 
}

vi mergeOcorr(vi &V, int n){
    vi O; O.assign(n, 0);
    vii K(n);
    for(int i = 0; i<n; i++){
        K[i] = {V[i], i};
    }
    mergeOcorrAux(K, O, 0, n-1);
    return O;
}

int main(){
    vi V = {1,2,1,3,2,1};
    vi O = mergeOcorr(V, 6);
    printVetor(O, 6);
}


