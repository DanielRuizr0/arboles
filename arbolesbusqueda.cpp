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
void pre(Nodo *);
void ino(Nodo *);
void pos(Nodo *);
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
		cout<<"\n 2. Preorden\n";
		cout<<"\n 3. Inorden\n";
		cout<<"\n 4. Posorden\n";
		cout<<"\n 5. Salir\n";
		cin>>op;
		
		switch(op){
			case 1: cout<<"\nDigite un numero: ";
					cin>>dato;
					insertar(arb,dato);
					cout<<"\n";
					system("pause");
					break;
			case 2: cout<<"\n Imprimiendo en Preorden";
			        pre(arb);
			        cout<<"\n";
			    break;
			case 3: cout<<"\n Imprimiendo en Inorden";
			        ino(arb);
			        cout<<"\n";
			    break;
			case 4: cout<<"\n Imprimiendo en Posorden";
			        pos(arb);
			        cout<<"\n";
			    break;
			    
		}
	}while(op!=5);
	getch();
	return 0;
}

void pre(Nodo *arb) {
    if (arb != NULL) {
        printf("%d,", arb->dato);
        pre(arb->rda);
        pre(arb->cha);
    }
}

void ino(Nodo *arb){
    if(arb !=NULL){
        ino(arb->rda);
        printf("%d,",arb->dato);
        ino(arb->cha);
        
    }
}

void pos(Nodo *arb){
    if(arb !=NULL){
        pos(arb->rda);
        pos(arb->cha);
        printf("%d,",arb->dato);
    }
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