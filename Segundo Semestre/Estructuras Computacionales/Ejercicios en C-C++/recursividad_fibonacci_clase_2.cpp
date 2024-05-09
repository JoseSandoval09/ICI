#include<iostream>

using namespace std;

int fib(int n){
    int res;
    if(n==0 || n==1){
        res= n;
    }
    else{
        res= fib(n-1) + fib(n-2);

    }
    return res;
}

int main(){

    for(int x=0;x<7;x++){
        cout<<fib(x)<<", ";
    }
    return 0;
}