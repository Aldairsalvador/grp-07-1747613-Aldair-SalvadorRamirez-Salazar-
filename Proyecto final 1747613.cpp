#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>// funcion new y delete punteros
#include <fstream>//archivos

using namespace std;

//declaracion de variables

int* producto, * year, *registros, *decision, n = 1, *iteam;
string* nombre, * clasificacion, * caracteristicas, * descripcion, * genero;
float* precio, * iva, * total, subtotal;

//funciones void
void alta();
void eliminar();
void modificar();
void lista();
void archivo();

int main()
{
	int opcion;
	printf("\t ***Block buster tienda en linea*** \n");
	printf("1.-Agregar articulo \n 2.-Modificar articulo \n 3.-Eliminar articulo \n 4.-Lista de Articulos \n 5.-Limpiar Pantalla \n 6.-archivo \n 7.-salir ");
	scanf_s("d%", &opcion);

	switch (opcion)
	{
	case 1:
		alta();
		system("pause");
		return main();
		break;

	case 2:
		modificar();
		system("pause");
		return main();
		break;

	case 3:
		eliminar();
		system("pause");
		return main();
		break;

	case 4:
		lista();
		system("pause");
		return main();
		break;

	case 5:
		//Limpiar Pantalla
		system("cls");
		return main();
		break;

	case 6:
		archivo();
		system("cls");
		return main();
		break;

	case 7:
		//Salir
		exit(1);
		break;
	default:
		printf("opcion invalida \n");
		return main();
	}
}

void alta()
{
	printf("Cuantos registros desea dar de alta");
	scanf_s("%d", &registros);
	
	producto = new int[registros];
	year = new int[registros];
	nombre = new string[registros];
	caracteristicas = new string[registros];
	clasificacion = new string[registros];
	descripcion = new string[registros];
	genero = new string[registros];
	precio = new float[registros];
	iva = new float[registros];
	total = new float[registros];
	//arreglo
	for (int i = 0; i < registros; i++)
	{
		printf("ingrese el producto \n");
		scanf_s("%d", &producto[i]);
		do
		{
			if (producto[i] != producto[i - n])
			{
				n = n + 1;
			}
			else
			{
				printf("el articulo ya existe\n");
				printf("Ingrese el articul\n");
				scanf_s("%d", &iteam[i]);
			}
		} while (n < registros);
		printf("ingrese el nombre \n");
		getline(cin, nombre[i]);
		printf("ingrese las caracteristicas \n");
		getline(cin, caracteristicas[i]);
		printf("ingrese la clasificacion \n");
		getline(cin, clasificacion[i]);
		printf("ingrese la descripcion \n");
		getline(cin, descripcion[i]);
		printf("ingrese el genero \n");
		getline(cin, genero[i]);
		printf("ingrese el precio \n");
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i] * .16;
		total[i] = precio[i] + iva[i];
		if ((registros - 1) == i)
		{
			printf("Quieres dar de alta otro registro");
			scanf_s("%d", decision);
			if (decision == 1)
			{
				registros = registros + 1;
			}
		}
	}
}

void modificar()
{
	int modificar;
	do
	{
		printf("ingrese el numero del articulo a modificar \n");
		scanf_s("%d", &modificar);
	} while (modificar < 0);


	for (int i = 0; i < registros; i++)
	{
		if (modificar == iteam[i])
		{
			printf("ingrese el nombre \n");
			getline(cin, nombre[i]);
			printf("ingrese las caracteristicas \n");
			getline(cin, caracteristicas[i]);
			printf("ingrese la clasificacion \n");
			getline(cin, clasificacion[i]);
			printf("ingrese la descripcion \n");
			getline(cin, descripcion[i]);
			printf("ingrese el genero \n");
			getline(cin, genero[i]);
			printf("ingrese el precio \n");
			scanf_s("%f", &precio[i]);
			iva[i] = precio[i] * .16;
			total[i] = precio[i] + iva[i];
		}
	}
}

void eliminar()
{
	int eliminar;
	printf("ingrese el numero del articulo a eliminar \n");
	scanf_s("%d", &eliminar);

	for (int i = 0; i < registros; i++)
	{
		if (eliminar == producto[i])
		{
			 iteam[i] = 0;
		}
	}

}

void lista()
{
	int op2;
	int i = 0;
	string buscar;
	printf("1.-Clasificacion \n 2.-Genero \n");
	scanf_s("&d", &op2);
	switch (op2)
	{
	case 1:

		printf("Ingrese la clasificacion a buscar\n");
		cin.ignore();
		getline(cin, buscar);
		for (int i = 0; i < registros; i++)
		{
			if (clasificacion[i] == buscar)
			{
				if (producto[i] != 0)
				printf("articulo: %d", producto[i]);
				printf("año: %d", year[i]);
				printf("videojuego: %d", nombre[i].c_str());
				printf("clasificacion: %d", clasificacion[i].c_str());
				printf("genero: %d", genero[i].c_str());
				printf("caracteristicas: %d", caracteristicas[i].c_str());
				printf("descripcion: %d", descripcion[i].c_str());
				printf("subtotal: %f", precio[i]);
				printf("iva: %f", iva[i]);
				printf("total: %f", total[i]);
			}
		}
		break;

	case 2:
		printf("Ingrese la clasificacion a buscar\n");
		cin.ignore();
		getline(cin, buscar);
		for (int i = 0; i < registros; i++)
		{
			if (clasificacion[i] == buscar)
			{
				printf("articulo: %d", producto[i]);
				printf("año: %d", year[i]);
				printf("videojuego: %d", nombre[i].c_str());
				printf("clasificacion: %d", clasificacion[i].c_str());
				printf("genero: %d", genero[i].c_str());
				printf("caracteristicas: %d", caracteristicas[i].c_str());
				printf("descripcion: %d", descripcion[i].c_str());
				printf("subtotal: %f", precio[i]);
				printf("iva: %f", iva[i]);
				printf("total: %f", total[i]);
			}
		}
		break;
	}
}

void archivo()
{
	ofstream archivo;
	string nombre;

	nombre = "PROYECTO final";
	archivo.open(nombre.c_str(), ios::out);

	if (archivo.fail()) {

		printf("ERROR NO SE GENERO EL ARCHIVO");
		system("pause");
		exit(1);

	}
	archivo << "informacion ";
	for (int i = 0; i < registros; i++)
	{
		archivo << ("Articulo: %d" << iteam[i]);
		archivo << ("year: %d" << year[i]);
		archivo << ("videojuego: %s" << nombre[i].c_str());
		archivo << ("clasificacion: %s", clasificacion[i].c_str());
		archivo << ("genero: %s", genero[i].c_str());
		archivo << ("caracteristicas: %s", caracteristicas[i].c_str());
		archivo << ("descripcion: %s", descripcion[i].c_str());
		archivo << ("subtotal: %f", precio[i]);
		archivo << ("iva: %f", iva[i]);
		archivo << ("total: %f", total[i]);
	}
	archivo.close();
}

