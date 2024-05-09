#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int x=0;
	int y=0;
	int i=0;
	

	
	cout<<"Ingresa el primer numero mayor a cero: "<<endl;
	cin>>x;
	while(x<=0){
		cout<<"INGRESA DE NUEVO VALOR: ";
		cin>>x;
	}

	cout<<"Ingresa el segundo numero mayor a cero: "<<endl;
	cin>>y;
	while(y<=0){
		cout<<"Ingresa valor de nuevo: ";
		cin>>y;
	}
	
	if(y>x){
		
	
	if(x%2==0){
		cout<<"Los numero pares entre el "<<x<<" y el "<<y<<" son:"<<endl;
		for(i=x; i<=y; i=i+2){
        	cout<<i<<", ";
		}cout<<endl;
		cout<<"Los numero impares entre el "<<x<<" y el "<<y<<" son:"<<endl;
		for(int i=x+1; i<=y; i=i+2){
			cout<<i<<", ";
		}cout<<endl;
			
	}else {
	if(x%2==1){
	    cout<<"Los numeros impares entre el "<<x<<" y el "<<y<<" son:"<<endl;
		for(i=x; i<=y; i=i+2){
        	cout<<i<<", ";
		}cout<<endl;
			cout<<"Los numeros pares entre el "<<x<<" y el "<<y<<" son:"<<endl;
		for(i=x+1; i<=y; i=i+2){
			cout<<i<<", ";
	}cout<<endl;
	}
	}
	}
	else{
	int z=x;
	x=y;
	y=z;
	if(x%2==0){
		cout<<"Los numero pares entre el "<<x<<" y el "<<y<<" son:"<<endl;
		for(i=x; i<=y; i=i+2){
        	cout<<i<<", ";
		}cout<<endl;
		cout<<"Los numero impares entre el "<<x<<" y el "<<y<<" son:"<<endl;
		for(int i=x+1; i<=y; i=i+2){
			cout<<i<<", ";
		}cout<<endl;
			
	}else {
	if(x%2==1){
	    cout<<"Los numero impares entre el "<<x<<" y el "<<y<<" son:"<<endl;
		for(i=x; i<=y; i=i+2){
        	cout<<i<<", ";
		}cout<<endl;
			cout<<"Los numero pares entre el "<<x<<" y el "<<y<<" son:"<<endl;
		for(i=x+1; i<=y; i=i+2){
			cout<<i<<", ";
	}cout<<endl;
}
}
}
 
	return 0;
}
