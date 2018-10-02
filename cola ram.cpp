// Desarrollo de un menu que administra una cola, tambien puede ordenar esa cola de numeros de menor a mayor o biseversa

#include <stdlib.h>
#include <stdio.h>
#include <time.h>



struct nodo{
	int numero;
	struct nodo *siguiente;
};


typedef struct nodo *Puntero;



void Encolar(int);
int Desencolar(void);
bool ColaVacia(void);
void MostrarCola(void);
void VaciarCola(void);
		

Puntero delante;
Puntero atras;


int vec[1000],l=0;
int* pvec = vec;


bool  ColaVacia(){
	if(delante==NULL){
		return true;
	}else{
		return false;
	}
}
void Encolar(int x){
	
	Puntero p_aux;
	
	p_aux = new(struct nodo);
	p_aux->numero = x;
	p_aux->siguiente = NULL;
	
	if(delante == NULL){
		delante = p_aux;
		
	}else {
		atras->siguiente = p_aux;
	}
	
	atras = p_aux;
}

int Desencolar(){
	int n;
	Puntero p_aux;
	
	p_aux = delante;
	n = p_aux->numero;
	delante = (delante)->siguiente;
	delete(p_aux);
	return n;
}


void MostrarCola(){
	
	Puntero p_aux;
	p_aux = delante;
	while(p_aux != NULL){
		printf("\n\t");
		printf("%d\n",p_aux->numero);
		p_aux = p_aux->siguiente;
	}
} 

void VaciarCola(){
	
	Puntero p_aux,r_aux;
	p_aux = delante;
	while(p_aux != NULL){
		r_aux = p_aux;
		p_aux = p_aux ->siguiente;
		delete (r_aux);
	}
	delante = NULL;
	atras = NULL;
}


int menu(){
	
	printf("\n\n\t---------------------------------\n");
	printf("\t|    IMPLEMENTACION DE UNA COLA     |\n");
	printf("\t| ----------------------------------|\n");
	printf("\t|                                   |\n");
	printf("\t|  1. ENCOLAR                       |\n");
	printf("\t|  2. DESENCOLAR                    |\n");
	printf("\t|  3. MOSTRAR COLA                  |\n");
	printf("\t|  4. VACIAR COLA                   |\n");
	printf("\t|  5. MOSTRAR COLA DE MENOR A MAYOR |\n");
	printf("\t|  6. MOSTRAR COLA DE MAYOR A MENOR |\n");
	printf("\t|  7. SALIR                         |\n");
	printf("\t|                                   |\n");
	printf("\t|-----------------------------------|\n");
	printf("\t Ingrese una opcion:  ");
	
}

int main(){
	system("color 1c");
	nodo* delante = NULL;
	nodo* atras = NULL;
	int x,p,temp=0;
	int op;
	
	do{
		
	menu();
	scanf("%d",&op);
	switch(op){
		case 1: system("cls");
			srand(time(NULL));
			printf("\n\t INGRESE CUANTOS NUMEROS VA ENCONLAR\n");
			printf("\t "); scanf("%d",&p);
			//generando los numeros de la cola de manera aleatoria
			for(int i = 0 ; i < p ; i++){
			x=rand()%101;
			//paso el para metro de x a un vector que me almacene la cola
			vec[i]=x;
			//agregando los numeros  a la cola
			Encolar(x);
			printf("\n\n\t Agregando numero %d\n",x);
			l++;
		}
			break;
		case 2: system("cls");
			if(ColaVacia()==true ){
				printf("\n\n\t Cola vacia...!\n");
			}else{
				x = Desencolar();
				printf("\n\n\t Eliminando numero %d\n",x);
				printf("\n\n\t");
				
			}
			break;
		case 3: system("cls");
			printf("\n\n\t MOSTRASNDO COLA\n");
			printf("\n\n");
			if(ColaVacia()!=true){
				MostrarCola();
			}else{
				printf("\n\n\t Cola vacia...!\n");
				printf("\n\n");
				
			}
			break;
		case 4: system("cls");
		VaciarCola();
		printf("\n\n\t Cola eliminada...\n");
		printf("\n\n");
		break;
		case 5: system("cls");
			printf("La cola se ordeno de menor a mayor");
			
			//En este ciclo saco de la cola todo los numeros que pido el usuario
		for(int j =0 ; j < l ; j++){
				Desencolar();
			}
		// este metodo de burbuja organizo de menor a mayor el vector	
			for (int i=1;i<l;i++)
			{
      	 for (int j=0; j < l-i ;j++) 
       		{
         	 if (vec[j] > vec[j+1])
          	{
            temp=vec[j];
            vec[j]=vec[j+1];
            vec[j+1]=temp;
          		}
       		}
		}
		//En este ciclo paso el vector a la cola ordenada de manera acendente
			for(int j =0 ; j < l ; j++){
				x=vec[j];
				Encolar(x);
			}
			break;
			
		case 6: system("cls");
			printf("La cola se ordeno de mayor a menor");
			//En este ciclo saco de la cola todo los numeros que pido el usuario
			for(int j =0 ; j < l ; j++){
				Desencolar();
			}
			// este metodo de burbuja organizo de menor a mayor el vector	
			for (int i=1;i<l;i++)
			{
      	 for (int j=0; j < l-i ;j++) 
       		{
         	 if (vec[j] < vec[j+1])
          	{
            temp=vec[j];
            vec[j]=vec[j+1];
            vec[j+1]=temp;
          		}
       		}
		}
		//En este ciclo paso el vector a la cola ordenada de manera decendente 
			for(int j =0 ; j < l ; j++){
				x=vec[j];
				Encolar(x);
			}
			break;
			
			
		default:
			printf("\n\n");
			printf("\n\n\t Ingrese una opcion valida.......!\n");
	}
	system("pause"); system("cls");
	}while(op!=7);
	
	return 0;
}
