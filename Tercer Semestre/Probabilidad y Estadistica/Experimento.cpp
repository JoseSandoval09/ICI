#include<iostream>

using namespace std;


#include <iostream>
#include <string>
using namespace std;

string conversor(int a);

int main() {
	
	const int Word_letters = 8;
	string binary;
    int n = 8;
	string word[] = {"aaa","aas","asa","ass","saa","sas","ssa","sss"};

	for(int i=0;i<=255;i++){
		binary = conversor(i);
		cout<<binary<<" - {";
		for(int i=0;i<n;i++){
			if(binary[i]=='1'){
				cout<<word[i]<<", ";
			}
		}
		cout<<"}\n";
	}
}

string conversor(int c){
	string b;
    int binario[8];
    for (int i = 0;i < 8;i++)
    {
        binario[i] = c % 2;
        c /= 2;
    }
    for (int i = 7; i >= 0; i--)
    {
        b+=binario[i]+'0';
    }
    return b;
}