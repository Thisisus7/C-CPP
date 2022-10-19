#include <iostream>
using namespace std;
// Fibonacci
int Fib(int n){  // iterative
    if (n <= 1){
        return n;
    }
    int F1 = 0;
    int F2 = 0;
    int F;
    for (int i=2; i<=n;i++){
        F = F1+ F2;
        F1 = F2;
        F2 = F;
    }
    return F;
}

int Fib_rec(int n){  // recursive
    if (n <= 1){
        return n;
    }
    return Fib_rec(n-1) + Fib_rec(n-2);
}

int main(){
    int n;
    cout<<"Give me a n: ";
    cin>>n;
    // int result = Fib(n);
    int result = Fib_rec(n);
    cout<<result;
}
