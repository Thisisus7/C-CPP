#include <iostream>
using namespace std

int Mod(x, n, M){
    if (n == 0){
        return 1;
    }
    else if (n % 2 == 0){
        y = Mod(x, n/2, M);
        return (y*y) % M;
    }
    else{
        return ((x%M) * Mod(x,n-1,M)) % M;
    }
}

int main(){
    
}
