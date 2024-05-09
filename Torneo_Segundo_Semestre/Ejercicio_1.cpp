#include <bits/stdc++.h>

using namespace std;

int main(){

    char num[255]="";
    int dec;
    cin >> dec;

    while (dec>0){
        switch(dec%16){
            case 0:{
                strcat (num,"0");
                break;
            }
            case 1: {
                strcat (num,"1");
                break;
            }
            case 2:{
                strcat (num,"2");
                break;
            }
            case 3:{
                strcat (num,"3");
                break;
            }
            case 4:{
                strcat (num,"4");
                break;
            }
            case 5:{
                strcat (num,"5");
                break;
            }
            case 6:{
                strcat (num,"6");
                break;
            }
            case 7:{
                strcat (num,"7");
                break;
            }
            case 8:{
                strcat (num,"8");
                break;
            }
            case 9:{
                strcat (num,"9");
                break;
            }
            case 10:{
                strcat (num,"A");
                break;
            }
            case 11:{
                strcat (num,"B");
                break;
            }
            case 12:{
                strcat (num,"C");
                break;
            }
            case 13:{
                strcat (num,"D");
                break;
            }
            case 14:{
                strcat (num,"E");
                break;
            }
            case 15:{
                strcat (num,"F");
                break;
            }
        }
        dec = dec / 16;
    }

    

    for(int i=sizeof(num)-1;i>=0;i--){
      cout<<num[i];
    }
   
    


    return 0;
}