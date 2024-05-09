#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main() {
	double salary;
	double taxesg;
	double taxes;
	cin.precision(2);cin >> salary;
	if (salary <= 2000.00) {
		cout << "Exento de pago." << endl;
	}
	if (salary > 2000.00 && salary <= 3000.00)
	{
			taxesg = (salary - 2000.00)*0.08;
			cout << "R$ " << taxesg;
	}
	//
	if (salary > 3000.00 && salary < 4500.00) 
	{
		    taxes = salary - 2000.00;
			if (taxes >1000.00) {
				taxesg= ((taxes - 1000.00)*0.18)+80;
			}
			else {
				taxesg = 80;
			}
			cout << "R$ " << taxesg;
	}
	if (salary > 4500.00) {
		taxes = salary - 3000.00;
		taxesg = 350 + (taxes * 0.028);
		cout << "R$ " << taxesg;
	}
}