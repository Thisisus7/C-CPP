#include <iostream>
using namespace std;
int F[51];  // calculate the 1st 51 elements in Fibonaci
int Fib(int n){
    if (n <= 1){
        return n;
    }
    if (F[n] != -1){
        return F[n];
    }
    F[n] = Fib(n-1) + Fib(n-2);
    return F[n];
}

int main(){
    for (int i=0; i<51; i++){
        F[i] = -1;
    }
    int n;
    cout<<"Give me a n: ";
    cin>>n;
    int result = Fib(n);
    cout<<result;
}
