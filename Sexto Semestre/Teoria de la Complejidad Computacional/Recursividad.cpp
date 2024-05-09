#include<iostream>

using namespace std;

int factorial(int n) {
   
  if (n < 10) {
    factorial(n+1);
    cout<<endl;
  }
   cout<<n;
}

int main() {
  int n=1;

    factorial(n);

  return 0;
}