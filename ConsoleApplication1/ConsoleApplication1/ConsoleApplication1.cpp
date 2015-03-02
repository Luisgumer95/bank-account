// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
struct BankM

{
	int Ncuenta;
	float Saldo;
}CB[10];

float RM, DM;
int i, j, RD, AN, opc;
void Retiro();
void Deposito();
void ingresarD();
void Cabecera();
void OrdenarPorSaldo();
void OrdenarPorCuenta();
void BuscarCuenta();
void Menu();

int _tmain(int argc, _TCHAR* argv[])
{
	Cabecera();
	ingresarD();
	system("clr");
	Menu();
	return 0;
}
void Retiro()
{
	printf("Ingrese el Monto que desea retirar: ");
	scanf_s("%f", &RM);
	if (RM < CB[i].Saldo)
	{
		CB[i].Saldo -= RM;
		printf("Su saldo es: %.2f\n", CB[i].Saldo);
	}
	else
	{
		printf("Su saldo es insuficiente:\n");
	}
	system("PAUSE");
	Menu();
}
void Deposito()
{
	printf("Ingrese el monto a depositar: ");
	scanf_s("%f", &DM);
	CB[i].Saldo = CB[i].Saldo + DM;
	printf("Su saldo es: %.2f\n", CB[i].Saldo);
	system("PAUSE");
	Menu();
}
void ingresarD()
{
	for (i = 0; i < 10; i++)
	{
		printf("Ingrese Numero de Cuenta: ");
		scanf_s("%d", &CB[i].Ncuenta);
		printf("Ingrese el Saldo: ");
		scanf_s("%f", &CB[i].Saldo);
		break;
	}

}

void Cabecera()
{
	printf("\t\t=================================\n");
	printf("\t\t          Banco BankM\n");
	printf("\t\t=================================\n\n");
}
void BuscarCuenta()
{
	system("cls");
	printf("Ingrese Numero de Cuenta:\n");
	scanf_s("%d", &AN);
	for (i = 0; i < 10; i++)
	{
		if (CB[i].Ncuenta == AN)
		{
			printf("Su saldo es: %.2f\n", CB[i].Saldo);
			printf("1.-Retiro\n");
			printf("2.-Deposito\n");
			printf("3.-Volver al Menu Principal\n");
			printf("Opcion:  ");
			scanf_s("%d", &RD);
			switch (RD)
			{
			case 1: Retiro();
				break;
			case 2: Deposito();
				break;
			case 3: Menu();
				break;
			default: printf("Opcion no valida");
				system("pause");
				Menu();
				break;
			}
		}

	}
	if (CB[i].Ncuenta != AN)
	{
		printf("No Hay Resultados\n");
		system("pause");
		Menu();
	}
}
void OrdenarPorCuenta()
{
	Cabecera();
	struct BankM R;

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (CB[i].Ncuenta>CB[j].Ncuenta)
			{
				R = CB[i];
				CB[i] = CB[j];
				CB[j] = R;
			}

		}
	}
	system("cls");
	for (i = 0; i < 10; i++)
	{
		printf("Numero de Cuenta: %d\n", CB[i].Ncuenta);
		printf("Saldo: %.2f\n", CB[i].Saldo);
		printf("\n");
	}
	system("pause");
}
void OrdenarPorSaldo()
{
	Cabecera();
	struct BankM R;

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (CB[i].Saldo>CB[j].Saldo)
			{
				R = CB[i];
				CB[i] = CB[j];
				CB[j] = R;
			}

		}
	}
	system("cls");
	for (i = 0; i < 10; i++)
	{
		printf("Numero de Cuenta: %d\n", CB[i].Ncuenta);
		printf("Saldo: %.2f\n", CB[i].Saldo);
		printf("\n");
	}
	system("pause");
}
void Menu()
{
	do{
		system("cls");
		Cabecera();
		printf("1.- Ordenar cuentas por Saldo\n");
		printf("2.- Ordenar por Numeros de cuentas\n");
		printf("3.- Buscar un Numero de cuenta\n");
		printf("4.- Salir\n");
		scanf_s("%d", &opc);
		switch (opc){
		case 1: OrdenarPorSaldo();
			break;
		case 2: OrdenarPorCuenta();
			break;
		case 3: BuscarCuenta();
			break;
		case 4: exit(0);
			break;
		default: printf("Opcion no valida ");
			break;
		}
	} while (opc != 0);
}


