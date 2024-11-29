#include<bits/stdc++.h>
using namespace std;

int KP(){
    for(int i=0; i<=n; i++){
        for(int l=0; l<= L; l++){
            if(i==0 || l==0) KP[i][l] = 0;
            if(w[i] > l) KP[i][l] = KP[i-1][l];
            else KP[i][l] = max(KP[i-1][l], v[i] + KP[i-1][l-w[i]);
        }
    }
}
