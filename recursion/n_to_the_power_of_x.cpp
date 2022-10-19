#include <iostream>
using namespace std;

int power(int x, int n){
    int y;
    if (n == 0){
        return 1;
    }
    else if (n%2 == 0){
        y = power(x, n/2);
        return y*y;
    }
    else{
        return x*power(x, n-1);
    }
}

 int main(){
     int n, x;
     cout<<"Give me a n: ";
     cin>>n;
     cout<<"Give me a x: ";
     cin>>x;
     int result = power(x, n);
     cout<<result;
 }
