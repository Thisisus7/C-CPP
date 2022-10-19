#include <stdio.h>
#include <iostream>

using namespace std;
int Factorial(int n){
    cout<<"I am calculating f("<<n<<")\n";
    if (n == 0){ // 1
        return 1;
    }
    int f =  n * Factorial(n-1); // recursive call  1+1
    cout<<"Done! f("<<n<<") = "<<f<<"\n";
    return f;
}

int main(){
    int n;
    cout<<"Give me an n:";
    cin>>n;

    int result = Factorial(n);
    cout<<result;
}
