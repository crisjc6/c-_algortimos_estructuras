#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "stdio.h"
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <cstring>
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
    int factura;
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
    char cod_p[10];
    char nom_prod[20];
    char descrip[20];
    float costo, pvp;
    int cantidad;
    Fecha fec_comp;

} produc;

struct Entrada
{
    char factura_n[10];
    char cod_prod[20];
    char descrip[20];
    int cantidad;
    Fecha fechaEntrada;

} entrada;

struct Salida
{
    char factura_n[5];
    char fecha_entrada[20];
    char cod_prod[20];
    char descrip[20];
    int cantidad;
    Fecha fechaEntrada;

} salida;

int menuGeneral();
int menu2();
int menu3();
int menu4();
int numeroFactura = 0;
void leerPasw(char frase[]);
void listarProductos();
void listarEntradas();
void listarSalidas();
void guardarDatos(Datos dat);
void guardarDatosCli(Cliente cli);
void guardaDatosProd(Producto prod);
void guardarVenta(Producto prod, Cliente cli);
int verificaUsuario(string nombre, string clave);
int verificarProducto(Producto prod, string clave);
void listarProducto(Producto prod);
string getDate();
int main()
{

    ifstream archivo;
    FILE *fi;
    char su[5];

    int op, op2, po3, op3,op4;
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
                                cout << "========================" << endl;
                                cout << "\n Agregar producto al inventario\n";
                                cout << "========================" << endl;
                                cout<<"\n Productos existentes \n";
                                cout << "===============================-==========================" << endl;
                                cout << "|codigo|nombre|descripcion|cantidad|costo|PVP|Año|mes|dia|" << endl; 
                                cout << "==========================================================" << endl;
                                listarProducto(produc);
                                system("pause");
                                guardaDatosProd(produc);
                                system("pause");
                                break;
                            case 2:
                                cout.flush();

                                cout << "2.- Eliminar producto " << endl;
                                listarProducto(produc);
                                system("pause");

                                break;
                            case 3:
                                cout.flush();
                                system("cls");
                                cout << "3.- Actualizar producto " << endl;
                                listarProducto(produc);
                                system("pause");
                                break;
                            case 0:
                                cout.flush();
                                menu2();
                                system("pause");
                                break;
                            default:
                                cout << "\n Opcion no existe \n"<< endl;
                                system("pause");
                            }
                        } while (op3 != 0);
                        break;
                    case 2:
                        cout.flush();
                        system("cls");
                        cout << "\n Generar Venta \n";
                        listarProductos();
                        guardarVenta(produc,cliente);
                        system("pause");
                        break;
                    case 3:
                        cout.flush();
                        system("cls");
                        cout << "\n Reportes ..... \n";
                        op4=menu4();
                        switch (op4){
                            case 0:
                                cout.flush();
                                menu3();
                                system("pause");
                                break;
                            case 1:
                                system("pause");
                                break;
                         default:
                                cout << "\n Opcion no existe \n"<< endl;
                                system("pause");

                        }

                        system("pause");
                        break;
                    case 0:
                        cout.flush();
                        menuGeneral();

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
            cout<< "ingrese la clave de super usuario =";
            leerPasw(su);
            if (strcmp(su,"12345")==0)
                guardarDatos(cli);
            else
                cout<<"Clave incorrecta de super usuario\n";
            system("pause");
            break;
        default:
            cout << "\n Opcion no existe \n"
                 << endl;
            system("pause");
        }
    } while (op != 0);
}

int menu4()
{
    int op;
    cout.flush();
    system("cls");
     cout << "\n " << endl;
    cout << "==========================================" << endl;
    cout << " REPORTES" << endl;
    cout << "=========================================" << endl;
    cout << "1.- REPORTE DE USUARIOS " << endl;
    cout << "2.- REPORTE DE VENTAS " << endl;
    cout << "3.- REPORTE DE PROVEEDORES " << endl;
    cout << "4.- REPORTE DE VENTAS " << endl;
    cout << "0.- Regresar Menu anterior " << endl;
    cout << "========================" << endl;
    cout << "Ingrese la opcion: ";
    cin >> op;
    return op;
}

int menu2()
{
    int op;
    cout.flush();
    system("cls");
     cout << "\n " << endl;
    cout << "==========================================" << endl;
    cout << " Bienvenido al sistema de COMPRAS Y VENTAS" << endl;
    cout << "=========================================" << endl;
    cout << "1.- Ingresar Inventario " << endl;
    cout << "2.- Generar Venta " << endl;
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
    cout << "\n " << endl;
    cout << "==========================================" << endl;
    cout << "  Inventario del Sistema de COMPRAS Y VENTAS                 " << endl;
    cout << "=========================================" << endl;
    cout << "1.- Agregar producto " << endl;
    cout << "2.- Elimar producto " << endl;
    cout << "3.- Actualizar producto " << endl;
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
        cout.flush();
        cout << "  Ingrese el codigo del Clientes:  ";
        cin.getline(cli.cod_per, 4);
        cout << "  Ingrese el nombre del Cliente:  ";
        cin.getline(cli.nom_persona, 30);
       //aqui deben poner los datos del cliente dir,tel,ci o ruc
        cout << "  Ingrese la direccion del Cliente:  ";
        cin.getline(cli.dir, 30);
         archivo << cli.nom_persona << " ";
        archivo << cli.cod_per << " ";
        archivo << cli.dir << " ";
    }
    archivo.close();
}
// lo que esta para cliente sera ?para proveedor

void guardaDatosProd(Producto prod)
{
    fstream archivoProductos;
    fstream archivoEntradas;

   //deben cambiar por los datos que tiene la estrcutura producto
    archivoProductos.open("producto.txt", ios::app);
    //archivoEntradas.open("entrada.txt", ios::app);
    if (archivoProductos.fail() || archivoEntradas.fail() )
    {
        cout << "Error, no se pudo abrir archivo" << endl;
        exit(1);
    }
    else
    {
        system("cls");
        cout.flush();
        cout << "  Ingrese el codigo del Producto:  ";
        cin >> prod.cod_p;
        if(verificarProducto(produc,string(prod.cod_p))!=0){
        system("pause");
        }else{
        cout.flush();    
        cout << "  Ingrese el nombre del producto:  ";
        cin >> prod.nom_prod;
        cout.flush();
        cout << "  Ingrese el descripcion del producto:  ";
        cin >> prod.descrip;
        cout.flush();
        cout << "  Ingrese la cantidad a comprar:  ";
        cin >> prod.cantidad;
        cout.flush();
        cout << "  Ingrese el costo $:  ";
        cin >> prod.costo;
        cout.flush();
        cout << "  Ingrese el PVP $:  ";
        cin >> prod.pvp;
        cout.flush();
        cout << "  Ingrese anio:  ";
        cin >>prod.fec_comp.anio;
        cout.flush();
        cout << "  Ingrese mes:  ";
        cin >>prod.fec_comp.mes;
        cout.flush();
        cout << "  Ingrese dia:  ";
        cin >>prod.fec_comp.dia;
        cout.flush();
        archivoProductos << prod.cod_p << " ";
        archivoProductos << prod.nom_prod << " ";
        archivoProductos << prod.descrip << " ";
        archivoProductos << prod.cantidad << " ";
        archivoProductos << prod.costo << " ";
        archivoProductos << prod.pvp << " ";
        archivoProductos << prod.fec_comp.anio << " ";
        archivoProductos << prod.fec_comp.mes << " ";
        archivoProductos << prod.fec_comp.dia <<endl;
        cout<< "\n Datos gradados con exito \n";
        };


    }
    archivoProductos.close();
    archivoEntradas.close();
}
void guardarVenta(Producto prod, Cliente cli)
{
    char op;
    int nfac=1;
    double subtotal=0, iva, total;
    fstream archivoProductos;
    fstream archivoCliente;
    fstream archivoFactura;

    //deben cambiar por los datos que tiene la estrcutura producto
    archivoProductos.open("producto.txt", ios::app);
    archivoFactura.open("factura.txt", ios::app);

   // archivoEntradas.open("cliente.txt", ios::app);
    if (archivoProductos.fail() || archivoFactura.fail() )
    {
        cout << "Error, no se pudo abrir archivo" << endl;
        exit(1);
    }
    else
    {
        //system("pause");
            system("cls");
            cout.flush();/*
            cout << "  Ingrese Nombres del cliente :  ";
            cin >> cli.nom_persona;
            cout.flush();
            cout << "  Ingrese Direccion :  ";
            cin >> cli.dir;
            cout.flush();
            cout << "  Ingrese Ci o Ruc  :  ";
            cin >> cli.cioruc;
            cout.flush();
            cout << "  Ingrese telefono :  ";
            cin >> cli.tel;*/
            guardarDatosCli(cli);

            archivoFactura << cli.factura<< " ";
            archivoFactura << cli.nom_persona<< " ";
            archivoFactura << cli.dir << " ";
            archivoFactura << cli.tel << " ";

            archivoCliente << cli.factura<< " ";
            archivoCliente << cli.nom_persona<< " ";
            archivoCliente << cli.dir << " ";
            archivoCliente << cli.tel << " ";
            cli.factura=nfac;
        do{

            cout.flush();
            // agregar fecha getdate

            cout << "\n Listado de Productos en Venta \n";
            listarProducto(prod);
            cout << "  Ingrese el codigo del Producto:  ";
            cin >> prod.cod_p;
            cout.flush();
            cout << "  Ingrese la cantidad:  ";
            cin >> prod.cantidad;
            cout.flush();
            cout << "  Ingrese el nombre del producto:  ";
            cin >> prod.nom_prod;
            cout.flush();

            cout << "  Ingrese el PVP $:  ";   //deberas traer del sistema
            cin >> prod.pvp;
            cout.flush();


            archivoFactura<< prod.cod_p << " ";
            archivoFactura<< prod.cantidad << " ";
            archivoFactura<< prod.nom_prod<< " ";
            archivoFactura<< prod.pvp<< " ";
            subtotal=subtotal+prod.pvp;

             cout << "Desea ingresar otro producto s/n=  ";
             cin>>op;
        }while(op=='s');

            cout << "==========================================" << endl;
            iva=subtotal*0.12 ;
            cout << "  Subtotal a cobrar: " << subtotal << "\n";;
            cout << "            Iva 12%: " << iva << "\n";;
            total=subtotal+iva;
            cout << "     Total a cobrar: " << total << "\n";;
            archivoFactura<< subtotal<< " ";
            archivoFactura<< iva<< " ";
            archivoFactura<< total<<endl;
    }
    archivoProductos.close();
    archivoCliente.close();
    archivoFactura.close();
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
            cout << "==================================================" << endl;
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
string getDate()
{
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);

    stringstream ss_year;
    ss_year << timePtr->tm_year + 1900;
    string Year = ss_year.str();

    stringstream ss_month;
    ss_month << timePtr->tm_mon + 1;
    string Month = ss_month.str();
    if (atoi(Month.c_str()) < 10)
        Month = "0" + Month;

    stringstream ss_day;
    ss_day << timePtr->tm_mday;
    string Day = ss_day.str();
    if (atoi(Day.c_str()) < 10)
        Day = "0" + Day;

    stringstream ss_hour;
    ss_hour << timePtr->tm_hour;
    string Hour = ss_hour.str();
    if (atoi(Hour.c_str()) < 10)
        Hour = "0" + Hour;

    stringstream ss_min;
    ss_min << timePtr->tm_min;
    string Min = ss_min.str();
    if (atoi(Min.c_str()) < 10)
        Min = "0" + Min;

    stringstream ss_sec;
    ss_sec << timePtr->tm_sec;
    string Sec = ss_sec.str();
    if (atoi(Sec.c_str()) < 10)
        Sec = "0" + Sec;

    string Fecha = Year + "/" + Month + "/" + Day;

    return Fecha;
}

void listarProducto(Producto prod){
    ifstream archivo;

    string frase;

    archivo.open("producto.txt",ios::in); //Abrir el archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }else{
       while(!archivo.eof()){
            getline(archivo,frase);
            cout<<frase<<endl;

       }
      //  system("pause");
    }

    archivo.close();
}

int verificarProducto(Producto prod,string codigo){
    ifstream archivo;

    char tab2[1024];
    char *ptr;
    string frase2;

    archivo.open("producto.txt",ios::in); //Abrir el archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }else{
       while(!archivo.eof()){

            getline(archivo,frase2);
            strcpy(tab2, frase2.c_str());
            ptr = strtok(tab2," ");
            if (strcmp(ptr, codigo.c_str()) == 0)
            {
                cout << "Este articulo ya existe" << endl;
                cout << ptr << endl;
                return 1;
            }
            else
            {
            continue;
            }
       }
       return 0;
      //  system("pause");
    }
}

void ElimnarProducto(){
    
    char linea[1280];
    int IncNums = 0;
    string cadena1;
    ifstream Lectura("Lectura.txt");
    ofstream Escritura("Escritura.txt");
    Lectura.getline(linea, 1280);
    string p1;
    vector<string> GuardaDatos(0);
 
    while (!Lectura.eof()) {
        p1 = linea[0];
        cadena1 = linea[1];
        IncNums++;
 
        if (p1=="a"){
            if (cadena1=="c"){
                Escritura << linea << endl; // esta linea la guardo en un txt pero tambien es la que quiero eliminar del archivo original
            }
        }
        else if (p1=="b"){
            if (cadena1=="m"){
                Escritura << linea << endl;// esta linea la guardo en un txt pero tambien es la que quiero eliminar del archivo original
            }
        }
        else if (p1=="c"){
            if (cadena1=="g"){
                Escritura << linea << endl;// esta linea la guardo en un txt pero tambien es la que quiero eliminar del archivo original
            }
        }
        else {
            GuardaDatos.push_back(linea);
        }
        Lectura.getline(linea, 1280);
    }
 
    Escritura.close();
    Lectura.close();
 
    ofstream Escritura1("Lectura.txt");
    int Nums1 = 0;
    int TotalPals = GuardaDatos.size();
 
    while (Nums1 < TotalPals) {
        Escritura1 << GuardaDatos[Nums1] << endl;
        Nums1++;
    }
    Escritura1.close();
}