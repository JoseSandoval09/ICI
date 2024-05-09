#include<iostream>

using namespace std;

int F(int n);

int main(){

   cout<<F(6);


}

int F(int n){
    int x,i;
    if(n<=1){
        return 1;
    }
    else{
        for(i=1;i<=n;i++){
            x=1;
            while(x<n){
                x=x*2;
            }
           return(F(n/2)+F(n/2)); 
        }
    }
}