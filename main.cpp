#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "stdio.h"
using namespace std;
struct Datos
{
    string usr;
    char clave[8];
} cli;
struct Fecha
{
    int dia, mes, anio;
};
struct Cliente
{
    char cod_per[4];
    char nom_persona[30];
    char dir[30];
    char cioruc[13];
    char tel[13];
    Fecha fech;
} cliente;
struct Proveedor
{
    char cod_pro[4];
    char nom_prove[30];
    char dir[30];
    char cioruc[13];
    char tel[13];
    Fecha fech;
} prov;
struct Producto
{
    char cod_p[5];
    char nom_prod[20];
    char descrip[20];
    float costo, pvp;
    int cantidad;
    Fecha fec_comp;

} produc;

struct Entrada
{
    char cod_p[5];
    char nom_prod[20];
    char descrip[20];
    float costo, pvp;
    int cantidad;
    Fecha fec_comp;

} produc;

int menuGeneral();
int menu2();
int menu3();
void leerPasw(char frase[]);
void listarProductos();
void guardarDatos(Datos dat);
void guardarDatosCli(Cliente cli);
void guardaDatosProd(Producto prod);
int verificaUsuario(string nombre, string clave);
int main()
{

    ifstream archivo;
    FILE *fi;

    int op, op2, po3, op3;
    int us = 0;
    do
    {
        op = menuGeneral();
        switch (op)
        {
        case 0:
            cout << "Gracias por usar nuestros servicios" << endl;
            break;
        case 1:
        {
            cout.flush();
            cout << "Usuario: ";
            cin >> cli.usr;
            cout << "Clave: ";
            leerPasw(cli.clave);
            cout << endl;
            us = verificaUsuario(cli.usr, string(cli.clave));
            if (us == 1)
            {
                do
                {
                    op2 = menu2();
                    switch (op2)
                    {
                    case 1:
                        do
                        {
                            op3 = menu3();
                            switch (op3)
                            {
                            case 1:
                                cout.flush();
                                system("cls");
                                cout << "\n Lista de productos\n";
                                cout << "========================" << endl;
                                listarProductos();
                                system("pause");
                                break;
                            case 2:
                                cout.flush();
                                system("cls");
                                cout << "\n Entradas\n";
                                cout << "=========================================" << endl;
                                system("pause");
                                break;
                            case 3:
                                cout.flush();
                                system("cls");
                                cout << "\n Salidas\n";
                                cout << "=========================================" << endl;
                                system("pause");
                                break;
                            case 4:
                                cout.flush();
                                system("cls");
                                cout << "\n Comprar mercaderia\n";
                                cout << "=========================================" << endl;
                                guardaDatosProd(produc);
                                system("pause");
                                break;
                            default:
                                cout << "\n Opcion no existe \n"
                                     << endl;
                                system("pause");
                            }
                        } while (op3 != 0);
                        break;
                    case 2:
                        cout.flush();
                        system("cls");
                        cout << "\n Generar Venta \n";
                        system("pause");
                        break;
                    case 3:
                        cout.flush();
                        system("cls");
                        cout << "\n Reportes ..... \n";
                        system("pause");
                        break;
                    default:
                        cout << "\n Opcion no existe \n"
                             << endl;
                        system("pause");
                    }
                } while (op2 != 0);
            }
            else
                cout << "usuario no encontrado no puede ingresar al sistema" << endl;
            system("pause");
            break;
        }
        case 2:
            cout.flush();
            guardarDatos(cli);
            system("pause");
            break;
        default:
            cout << "\n Opcion no existe \n"
                 << endl;
            system("pause");
        }
    } while (op != 0);
}

int menu2()
{
    int op;
    cout.flush();
    system("cls");
    cout << "\n Bienvenido al sistema de COMPRAS Y VENTAS" << endl;
    cout << "==========================================" << endl;
    cout << "              Menu 2                    " << endl;
    cout << "=========================================" << endl;
    cout << "1.- Inventario " << endl;
    cout << "2.- Venta " << endl;
    cout << "3.- Reportes " << endl;
    cout << "0.- Regresar Menu anterior " << endl;
    cout << "========================" << endl;
    cout << "Ingrese la opcion: ";
    cin >> op;
    return op;
}

int menu3()
{
    int op;
    cout.flush();
    system("cls");
    cout << "\n Inventario del sistema de COMPRAS Y VENTAS" << endl;
    cout << "==========================================" << endl;
    cout << "              Menu 3                    " << endl;
    cout << "=========================================" << endl;
    cout << "1.- Lista de mercaderia disponible " << endl;
    cout << "2.- Entradas " << endl;
    cout << "3.- Salidas " << endl;
    cout << "4.- Comprar mercaderia " << endl;
    cout << "0.- Regresar Menu anterior " << endl;
    cout << "========================" << endl;
    cout << "Ingrese la opcion: ";
    cin >> op;
    return op;
}
int menuGeneral()
{
    int opcion;
    cout.flush();
    system("cls");
    cout << "========================" << endl;
    cout << "    Menu principal     " << endl;
    cout << "========================" << endl;
    cout << "1.- Ingresar al Sistema" << endl;
    cout << "2.- Crear Nuevos Usuarios" << endl;
    cout << "0.- Salir del programa" << endl;
    cout << "========================" << endl;
    cout << "Ingrese la opcion: ";
    cin >> opcion;

    return opcion;
}

int verificaUsuario(string nombre, string clave)
{
    FILE *fi;
    int i = 0;
    int respuesta = 0;
    string nombreClave = nombre + " " + clave;
    string carc;
    cout.flush();
    ifstream archivo;
    archivo.open("usuario.txt", ios::in);
    while (!archivo.eof())
    { //aqui deben cambiar para que busque de usuario en usuario
        getline(archivo, carc);
        if (strcmp(nombreClave.c_str(), carc.c_str()) == 0)
        {
            cout << "usuario autorizado" << endl;
            return 1;
        }
        else
        {
            continue;
        }
    }
    cout << "usuarios DIFERENTES..... " << endl;
    return 0;
}

void leerPasw(char frase[])
{
    int i = 0;
    cout.flush();

    do
    {
        frase[i] = (unsigned char)getch();

        if (frase[i] != 8) // no es retroceso
        {
            cout << '*'; // muestra por pantalla
            i++;
        }
        else if (i > 0) // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--; //el caracter a borrar e el backspace
        }
        cout.flush();

    } while (frase[i - 1] != 13); // si presiona ENTER

    frase[i - 1] = NULL;
    cout << endl;
}

void guardarDatos(Datos dat)
{ //guarda claves en archivo usaurio.txt
    string usuario, pwd;
    fstream archivo;
    archivo.open("usuario.txt", ios::app);
    if (archivo.fail())
    {
        cout << "Error, no se pudo abrir archivo" << endl;
        exit(1);
    }
    else
    {
        cout << "ingrese el usuario= ";
        cin >> dat.usr;
        cout << "ingrese el password= ";
        cin >> dat.clave;
        archivo << dat.usr << " ";
        archivo << dat.clave << endl;
    }
    archivo.close();
}

void guardarDatosCli(Cliente cli)
{ //guarda datos del cliente hacer otro para proveedor y otro producto
    //Persona pe;
    Fecha fech;
    fstream archivo;
    archivo.open("cliente.txt", ios::app);
    if (archivo.fail())
    {
        cout << "Error, no se pudo abrir archivo" << endl;
        exit(1);
    }
    else
    {
        cout << "  Ingrese el codigo del Cliente:  ";
        cin.getline(cli.cod_per, 4);
        archivo << cli.cod_per << " ";
        cout << "  Ingrese el nombre del Cliente:  ";
        cin.getline(cli.nom_persona, 30);
        archivo << cli.nom_persona << " ";
        //aqui deben poner los datos del cliente dir,tel,ci o ruc
        cout << "  Ingrese la direccion del Cliente:  ";
        cin.getline(cli.dir, 30);
        archivo << cli.dir << " ";
    }
    archivo.close();
}
// lo que esta para cliente sera �para proveedor

void guardaDatosProd(Producto prod)
{
    fstream archivo;
    //deben cambiar por los datos que tiene la estrcutura producto
    archivo.open("producto.txt", ios::app);
    if (archivo.fail())
    {
        cout << "Error, no se pudo abrir archivo" << endl;
        exit(1);
    }
    else
    {
        cout << "  Ingrese el codigo del Producto:  ";
        cin >> prod.cod_p;
        cout << "  Ingrese el nombre del producto:  ";
        cin >> prod.nom_prod;
        cout << "  Ingrese la cantidad:  ";
        cin >> prod.cantidad;
        cout << "  Ingrese el costo $:  ";
        cin >> prod.costo;
        archivo << prod.cod_p << " ";
        archivo << prod.nom_prod << " ";
        archivo << prod.cantidad << " ";
        archivo << prod.costo << endl;
    }
    archivo.close();
}
void listarProductos()
{
    FILE *fi;
    int i = 0;
    int contador = 0;
    string producto;
    cout.flush();
    ifstream archivo;
    archivo.open("producto.txt", ios::in);
    if (archivo.fail())
    {
        cout << "Error, no se pudo abrir archivo" << endl;
        exit(1);
    }
    else
    {
        while (!archivo.eof())
        {
            getline(archivo, producto);
            cout << ++contador << " " << producto << "\n";
            cout << "==========================================" << endl;
        }
    }
}
void listarEntradas()
{
    FILE *fi;
    int i = 0;
    int contador = 0;
    string producto;
    cout.flush();
    ifstream archivo;
    archivo.open("entrada.txt", ios::in);
    if (archivo.fail())
    {
        cout << "Error, no se pudo abrir archivo" << endl;
        exit(1);
    }
    else
    {
        while (!archivo.eof())
        {
            getline(archivo, producto);
            cout << ++contador << " " << producto << "\n";
            cout << "==========================================" << endl;
        }
    }
}
void listarSalidas()
{
    FILE *fi;
    int i = 0;
    int contador = 0;
    string producto;
    cout.flush();
    ifstream archivo;
    archivo.open("salida.txt", ios::in);
    if (archivo.fail())
    {
        cout << "Error, no se pudo abrir archivo" << endl;
        exit(1);
    }
    else
    {
        while (!archivo.eof())
        {
            getline(archivo, producto);
            cout << ++contador << " " << producto << "\n";
            cout << "==========================================" << endl;
        }
    }
}