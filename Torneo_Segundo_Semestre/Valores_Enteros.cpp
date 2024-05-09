/*Make a program that reads five integer values. Count how many of these values ​​are even and  print this information like the following example.

**Input**
The input will be 5 integer values.

**Output**
Print a message like the following example with all letters in lowercase, indicating how many even numbers were typed.

**Input Samples      Output Samples**
7                        3 valores pares.
-5
6
-4
12
*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int valores[5],cont=0;

    for(int i=0;i<5;i++){
        cin>>valores[i];
        if (valores[i] % 2==0){
            cont++;
        }
    }

    cout<<"\n";
    cout<<cont<<" valores pares.";

}