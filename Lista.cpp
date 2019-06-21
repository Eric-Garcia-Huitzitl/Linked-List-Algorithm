/*Implementacion de Lista Ligada en C++ ICC Eric Garcia Huitzitl*/
#include <iostream>
using namespace std; 

typedef int Type;

class Nodo
{
public:
	Nodo();
	Nodo(Type _dato); //constructor
	~Nodo(); //destructor
	//Un nodo contiene el dato que sera almacenado y un apuntador al nodo siguiente.
	Type dato; 
	Nodo * ptrSig; 
	inline Type getData(){return dato;}
};
//Definicion de constructores y destructores.
Nodo::Nodo(){}
Nodo::Nodo(Type _dato){dato=_dato; ptrSig = NULL;} //Cada qie iniciamos un nodo asignamos el dato y su apuntador lo inicializamos en NULL
Nodo::~Nodo(){}

class Lista
{
public:
	Lista();
	~Lista();
	void push_back(Type _dato);
	void push_front (Type _dato);
	void pop_back(); 
	void pop_front(); 
	void showList();
	inline bool empty();	
	Nodo *head; 

};

Lista::Lista(){head=NULL;}
Lista::~Lista(){delete head;}
bool Lista::empty(){return (head==NULL);} //Decvuelve 1 si esta vacia 0 si no.

void Lista::push_front(Type _dato){
if(empty()){head = new Nodo(_dato);}
else{
	  Nodo* iterator_pt = head;
	  while(iterator_pt->ptrSig!=NULL){
	  	iterator_pt= iterator_pt->ptrSig;
	  }
	  iterator_pt->ptrSig= new Nodo(_dato);
	}
}//Fin de funcion push_front

void Lista::push_back(Type _dato){
	if(empty()){head = new Nodo(_dato);}
	else{
		Nodo *aux = new Nodo(_dato);
		aux->ptrSig = head;
		head=aux;
	}
} //Fin de la funcion push_back 
void Lista::showList(){
	Nodo *iterator_pt = head; 
	while(iterator_pt!=NULL){
		cout<<iterator_pt->dato<<"->";
		iterator_pt = iterator_pt->ptrSig;
	}
	cout<<"NULL"<<endl;
}
void Lista::pop_back(){
	if(empty()==true){cout <<"Lista vacia"<<endl;}else{
	Nodo *aux=head;
	head=head->ptrSig;
	delete aux; 
	}
}
void Lista::pop_front(){
	if(empty()==true){cout <<"Lista vacia"<<endl;}
	else{
	Nodo *iterator_pt = head; 
	while(iterator_pt->ptrSig->ptrSig!=NULL){
		iterator_pt= iterator_pt->ptrSig;}
	delete iterator_pt->ptrSig->ptrSig;
	iterator_pt->ptrSig=NULL;
	}
}

int main(int argc, char const *argv[])
{
	Lista _p; 
	_p.push_front(1);
	_p.push_front(2);
	_p.push_back(3);
	_p.push_back(8);
	_p.pop_front();
	_p.pop_back();
	_p.push_front(4);
	_p.push_front(8);
	_p.push_front(9);
	_p.showList(); 

	return 0;
}