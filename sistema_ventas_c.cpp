/*
* @Autor: <jCarlos:Mendoza/>
* 
* Proyecto: sistema_ventas_c
* Código: sistema_sentas_c.cpp
* Fecha: 22/04/2017
*/

/*Directivas de preprocesador*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*Declaración de la estructura cliente*/
struct cliente{
	int numCli;
	char nomCli[30];
	char apPat[30];
	char apMat[30];

} usu;

/* Prototipos de las funciones */
float cobrarCliente (float val1, float val2);
float cambioCliente(float a, float b);
float descuentos(float suma);
int sugerenciaCambio(int cambio);

/*funcion principal main*/
int main(void){

/*Declaración de variables locales de main*/
	int opc,a=1;
	float nCom,suma=0,descuento, cobrar, pago, cambio;
	int cantidad ;
	double sugerencia;


/* arreglo de tienda*/
	char supNom[30]="King's  Market";
	char supLem[30]="Donde el cliente manda";
	char supDir[200]="\n\t\t\t* Sucursal 2144:\n\t\t\t*Insurgentes Sur 3579, DF Tel:5878414* *";
	char supVen[50]="\n\t\t\t* Le atendio 1454 Carlos Fuentes *\n\n\n";

/*arreglo de cajero*/
	int numCaj=1454;
	char nomCaj[20]="Carlos";
	char apCaj[30]="Fuentes Fuentes";
	char mensaje[50]="\n\n\t\t***Gracias por su preferencia***";
/*-------------------------------------------------------------------------------------------------------------*/



system("cls"); /* limpiador de pantalla*/
/* Datos de super mercado*/
	printf("\n\t\t\t\t\t%s\n\n",supNom);
	printf("\t\t\t\t``%s``\n\n",supLem);
	printf("\t\t\t\t\tHola Usuario...\n\n");


/*Menu del programa*/
	printf("Menu\n1-Caja\n2-Salir\n\n\tElige una opcion: ");
	scanf("%d",&opc);
	switch(opc) /* seleccion multimple */
	{
case 1:
			system("cls");
			printf("Captura de datos del cliente...\n\nId_cliente: ");
			scanf("%d",&usu.numCli);
			printf("\nIngresa nombre: ");
			scanf("%s",&usu.nomCli);
			printf("\nIngresa Apellido paterno: ");
			scanf("%s",&usu.apPat);
			printf("\nIngresa Apellido materno: ");
			scanf("%s",&usu.apMat);
			printf("\n");
			system("pause>null");
			system("cls");

do{ /*ciclo hacer mientras*/
			printf("Captura de compras...");
			printf("\n\n\t\tSuma de compras es: $%.2f pesos/centavos\n\n",suma);
			printf("\n\nIngrese 00 para terminar\n\n\tIngrese $compra número %d: ",a++);
			scanf("%f",&nCom);
			printf("\n\n\t\tSuma de compras es: $%.2f pesos/centavos",suma);
			suma=suma+nCom; /* Acomulador de compras*/
			system("cls");
			}
while(nCom != 00);
printf("\n\n\t\tSuma de compras es: $%.2f pesos/centavos\n\n",suma);


/*Toma de decición sobre descuento invocando al modulo descuentos*/
descuento=descuentos(suma);

/* Calculo de cobro invocando al módulo cobrarCliente*/
cobrar=cobrarCliente(suma, descuento);
			/* Mensaje de cobro*/
			printf("\n\n\t\tCobrar $%.2f",cobrar);
			/* Mensaje para ingresar pago*/
			printf("\n\nIngrese pago: ");
			scanf("%f",&pago);

/* calculo de cambio invocando al modulo cambioCliente*/
cambio=cambioCliente(pago, cobrar);
		printf("\n\n El monto de su cambio es %.2f\n",cambio);
/*sugerencia de cambio con rendondeo invocando al módulo sugerenciaCambio*/
sugerencia=sugerenciaCambio(cambio);
		system("pause>nul");



/* Ticket*/
		system("cls");
		printf("\t*****************************************************************");
		printf("\n\n\t\t\t***** %s *****\n\n",supNom);
	    printf("\n\n\t\t* Cliente:\n\t\t%d  %s  %s  %s *",usu.numCli,usu.nomCli,usu.apPat,usu.apMat);
		printf("\n\n\t\t* Suma de compras es: $%.2f *",suma);
		printf("\n\t\t* Descuento aplicado es: $%.2f *",descuento);
		printf("\n\t\t* Se le cobro: $%.2f *",cobrar);
		printf("\n\t\t* Efectivo: $%.2f *",pago);
		printf("\n\t\t* Su cambio es: $%.2f *",cambio);
		puts(mensaje);/* impresion de cadena puts*/
		printf("%s",supDir);
		printf("\n\t\t\t* Le atendio %d %s %s *\n\n\n",numCaj,nomCaj,apCaj);
		printf("\t*****************************************************************\n\n");
		system("pause>null"); /* hace una pausa */
		return(main()); /* regresa al Menu*/
break;

case 2:
			system("cls"); /* Limpia pantalla*/
			/* Mensaje de salida*/
			printf("\n\n\n\t\t*****************************************");
			printf("\n\n\n\t\t*   Un placer servirle...Hasta Pronto    *\n");
			printf("\n\n\n\t\t*****************************************\n\n\n");
			return(0); /* cierra programa*/
break;

default:
			system("cls"); /* Limpia pantalla*/
			/* Mensaje de erro*/
			printf("\n\n\n\t\t******************************************");
			printf("\n\n\n\t\t* Opcion invalida...Intentelo nuevamente *\n");
			printf("\n\n\n\t\t******************************************\n\n\n");
			system("pause>null"); /* hace una pausa*/
			return (main());/* regresa al Menu*/

	}/* fin switch*/

}/* fin main*/

/* Definición de funciones */

float cobrarCliente (float val1, float val2){	/* parametros val1 y val2 de tipo float*/
	return val1-val2;	/* regresa operacion de cobrar*/
}/* fin cobrarCliente*/

/*---------------------------------------------------------*/
float cambioCliente(float a, float b){
	return a-b;		/* regresa operacion de cambio*/
}/* fin CambioCliente*/

/*----------------------------------------------------------*/
float descuentos(float suma){ /*parametro suma de tipo float*/
	float descuento; /* variable local descuento*/
	/* decicion de descuento*/
	if(suma<= 499){
			descuento=suma*.5;
			printf("\n\n\t\tTu descuento de 5% es $%.2f pesos/centavos",descuento); }
	if(suma>= 500 && suma<= 999){
			descuento=suma*.10;
			printf("\n\n\t\tTu descuento de 10% es $%.2f pesos/centavos",descuento); }
	if(suma>=1000)	{
			descuento=suma*.15;
			printf("\n\n\t\tTu descuento de 15% es $%.2f pesos/centavos",descuento);
			}
	return descuento; /* regresa a descuento*/
}/* fin descuentos*/

int sugerenciaCambio(int cambio){ /* parametro cambio de tipo int*/
/*Calculamos el cambio y lo devolvemos*/
printf("\n\n Sugerencia de cambio con redondeo %d",cambio);
printf("\n");
printf("\n\t%d billetes de $200", cambio/200);
cambio = cambio%200;
printf("\n\t%d billetes de $100", cambio/100);
cambio = cambio%100;
printf("\n\t%d billetes de $50", cambio/50);
cambio = cambio%50;
printf("\n\t%d billetes de $20", cambio/20);
cambio = cambio%20;
printf("\n\t%d monedas de $10", cambio/10);
cambio = cambio%10;
printf("\n\t%d monedas de $5", cambio/5);
cambio = cambio%5;
printf("\n\t%d monedas de $2", cambio/2);
cambio = cambio%2;
printf("\n\t%d monedas de $1", cambio );
printf("\n");
	return cambio; /* regresa a cambio*/
}/* Fin sugerenciaCambio*/


