#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *cha;
	Nodo *rda;
};
Nodo *creNo(int);

void insertar(Nodo *&,int);

Nodo *arb = NULL;

Nodo *creNo(int x){
	Nodo *nue = new Nodo();
	nue -> dato = x;
	nue->cha = NULL;
	nue->rda = NULL;
	
	return nue;
}
int main(){
	int dato,op;
	
	do{
		cout<<"\t.:MENU:. \n";
		cout<<"\n 1. Insertar un nuevo dato\n";
		cout<<"\n 2. Salir\n";
		cin>>op;
		
		switch(op){
			case 1: cout<<"\nDigite un numero: ";
					cin>>dato;
					insertar(arb,dato);
					cout<<"\n";
					system("pause");
					break;
		}
	}while(op!=2);
	getch();
	return 0;
}

void insertar(Nodo *&arb,int x){
	if(arb==NULL){
		Nodo *nue = creNo(x);
		arb = nue;
	}
	else{
		int raiz= arb->dato;
		if(x < raiz){
			insertar(arb->rda,x);
		}
		else{
			insertar(arb->cha,x);
		}
	}
}
