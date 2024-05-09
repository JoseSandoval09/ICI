#include<iostream>

using namespace std;


int a[1000];

int main(){

    for (int i=0;i<1000;i++){
        a[i]= i;
    }

    for(int j=0;j<1000;j++){
        cout<<a[j]<<endl;
    }



}