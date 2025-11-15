#include <bits/stdc++.h>

using namespace std;



double popular(double V[], int n){



    if(n>=2){ 
        double cand1 = V[0];
        double cand2 = V[1];
        int cont1 = 0;
        int cont2 = 0;
        for(int i = 2; i<n; i++){
            if(V[i]==cand1) cont1++;
            else if(V[i]==cand2) cont2++;
            else if(cont1==0) cand1 = V[i];
            else if(cont2==0) cand2 = V[i];
            else{
                cont1--; cont2 --;
            }

        }
        cont1 = 0;
        cont2 = 0;
        for(int i = 0; i<n; i++){
            if(V[i]==cand1) cont1++;
            else if(V[i]==cand2) cont2++;
        }
        if(cont1>(n/3)) return cand1;
        else if(cont2>(n/3)) return cand2;
        else return -1;


    }
    return V[0];

}


int main(){
    
    double V[] = {1.2, 6.3, 2.1, 4.3, 1.2, 7.9, 1.2};
    cout << popular(V, 7) << endl;
    
}