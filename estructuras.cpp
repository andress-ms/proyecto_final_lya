#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "auxx.h"
#define MAX 1000  // Constante
#define MAXEMP 10 // Constante
#define MAXC 100
#define color SetConsoleTextAttribute // Constante para no poner una funcion grande todo el tiempo

HANDLE salida = GetStdHandle(STD_OUTPUT_HANDLE); // Color
int i = 0, reg = 0, pos = 0, reg_ing = 0;
int opEMP = 0, op = 0, opADM = 0;         // Opciones
int datoC;                                // Comparador
int comp;                                 // Comparador
bool band = false, administrador = false; // Valor logico
int num_rand;                             // Numero aleatorio
std::string cedula, contraseña, usuario;

FILE *registros; // Archivo
struct adm
{ // Estructura de administrador
    std::string usuario_adm = "Christian";
    std::string contraseña_adm = "123";
} adm;

struct empleado
{ // Estructura de empleado
    std::string nombre_empleado;
    std::string apellido_empleado;
    std::string cedula_empleado;
    std::string contraseña_empleado;
} emp[MAXEMP];

struct cita
{ // Estructura para todos los datos de la cita
    char cita[MAXC];
    char hora_cita_inicio[MAXC];
    char hora_cita_final[MAXC];
    bool cita_t = false;
};

typedef struct
{ // Estructura para todos los datos del cliente con una estructura anidada que corresponden a los datos de cita
    char nombre_cliente[MAXC];
    char apellido_cliente[MAXC];
    char nombre_apellido[MAXC];
    char email_cliente[MAXC];
    char numero_celular[MAXC];
    int codigo_cliente;
    struct cita cit;
} cliente;

cliente clt[MAX];

int randd();
void AgregarCliente();
void VerDatosCliente();
void EditarCliente();
void AgendarCita();
void VerDatosCita();
void CancelarCita();

// Modificar
int MenuEMP();  // done
int MenuADM();  // done
void Ingreso(); // done (Modify anyway)
// Modificar
// Nuevos
void GuardarCliente(); // done
void LeerCliente();    // done
void BorrarCliente();  // done
void ReinicioCliente(int x);
void GuardarCliente();                      // done
int CalcularRegistroCliente(FILE *archivo); // done
void Busqueda(int i);
void M1();                  // done
void M2();                  // done
void NombreApellido(int x); // done
void LeerEmpleados();
void BorrarEmpleado();
void CalcularRegistrosEmpleado();
void ActualizarListaCliente();
void ActualizarListaEmpleado();
void MenuF();
void DatoT();
// Nuevos

int randd()
{ // Numero aleatorio
    srand(time(NULL));
    int inf = 100000, sup = 1000000, num;

    num = inf + rand() % (sup + 1 - inf); /* Estableciendo limite inferior y superior de los numeros (100000 y 1000000)*/

    return num; // Retornar valor
}

void GenerarCodigoCliente()
{
    clt[reg].codigo_cliente = randd(); // Importante mencionar que randd() ya no es una funcion, sino el valor retornado de la funcion
    std::cout << "Tu codigo de cliente es: " << clt[reg].codigo_cliente << std::endl;
    color(salida, 4);
    std::cout << "Ten en cuenta que NO se puede cambiar" << std::endl;
    color(salida, 15);
}

void AgregarCliente()
{
    fflush(stdin);
    std::cout << "Ingresa los siguientes campos: " << std::endl;
    std::cout << "Nombre: ";
    std::cin.getline(clt[reg].nombre_cliente, MAXC, '\n');
    std::cout << "Apellido: ";
    std::cin.getline(clt[reg].apellido_cliente, MAXC, '\n');
    std::cout << "Email: ";
    std::cin.getline(clt[reg].email_cliente, MAXC, '\n');
    std::cout << "Numero de celular: ";
    std::cin.getline(clt[reg].numero_celular, MAXC, '\n');
    NombreApellido(reg);
    GenerarCodigoCliente();
    std::cout << "Cliente Agregado con exito." << std::endl;
    reg++;
}
void VerDatosCliente()
{
    fflush(stdin);
    std::cout << "Ingrese su codigo de cliente: ";
    std::cin >> comp; // Ingresa el codigo de cliente
    Busqueda(i);      // Busqueda por seleccion
    if (band == false)
    { // Indica que el bucle no paso por el proceso de mostrar los datos del cliente
        std::cout << "El codigo de cliente no coincide con ningun cliente. Volver a intentar" << std::endl;
    }
    else if (band)
    {
        std::cout << "Datos del cliente " << clt[pos].nombre_apellido << std::endl;
        std::cout << "Nombre: " << clt[pos].nombre_cliente << std::endl;
        std::cout << "Apellido: " << clt[pos].apellido_cliente << std::endl;
        std::cout << "Email: " << clt[pos].email_cliente << std::endl;
        std::cout << "Numero de celular: " << clt[pos].numero_celular << std::endl;
        std::cout << "Codigo de cliente: " << clt[pos].codigo_cliente << std::endl;
        if (clt[pos].cit.cita_t)
        {
            std::cout << "Fecha de la cita: " << clt[pos].cit.cita << std::endl;
            std::cout << "Hora de inicio: " << clt[pos].cit.hora_cita_inicio << std::endl;
            std::cout << "Hora de finalizacion: " << clt[pos].cit.hora_cita_final << std::endl;
        }
    }
    band = false;
}

void DatoT()
{
    if (reg != 0)
    {
        for (i = 0; i < reg; i++)
        { // Muestra todos los datos de todos los clientes
            std::cout << "Datos del cliente ";
            color(salida, 14);
            std::cout << clt[i].nombre_apellido;
            color(salida, 15);
            std::cout << "\n\nNombre: " << clt[i].nombre_cliente << std::endl;
            std::cout << "Apellido: " << clt[i].apellido_cliente << std::endl;
            std::cout << "Email: " << clt[i].email_cliente << std::endl;
            std::cout << "Numero de celular: " << clt[i].numero_celular << std::endl;
            std::cout << "Codigo de cliente: " << clt[i].codigo_cliente << std::endl;
            if (clt[i].cit.cita_t)
            {
                std::cout << "Fecha de la cita: " << clt[i].cit.cita << std::endl;
                std::cout << "Hora de inicio: " << clt[i].cit.hora_cita_inicio << std::endl;
                std::cout << "Hora de finalizacion: " << clt[i].cit.hora_cita_final << std::endl;
            }
            std::cout << "============================================================\n"
                      << std::endl;
        }
    }
    else
    {
        std::cout << "No hay ningun registro." << std::endl;
    }
    band = false;
}
void EditarCliente()
{
    fflush(stdin);
    std::cout << "Para cambiar los datos del cliente, ingrese su codigo de cliente: ";
    std::cin >> comp; // Ingresa codigo de cliente
    Busqueda(i);
    if (band)
    {
        std::cout << clt[pos].nombre_apellido << ", ingrese el nombre del dato que quiere cambiar: " << std::endl;
        std::cout << "1. Nombre \n2. Apellido \n3. Email \n4. Numero de celular \n5. Todos" << std::endl;
        std::cout << "\n\n\nIngresar numero: ";
        std::cin >> datoC;
        fflush(stdin);
        if (datoC == 1)
        { // Para cambiar nombre
            std::cout << "Ingrese su nuevo nombre: ";
            std::cin.getline(clt[pos].nombre_cliente, MAXC, '\n'); // Ingresar nuevo nombre
            strcpy(clt[pos].nombre_apellido, "");                  // Vaciar el valor de la variable

            NombreApellido(pos); // Nombre y apellido en una sola cadena
            std::cout << "Hola, " << clt[pos].nombre_apellido << std::endl;
            band = false;
        }
        else if (datoC == 2)
        { // Para cambiar apellido
            std::cout << "Ingrese su nuevo apellido: ";
            std::cin.getline(clt[pos].apellido_cliente, MAXC, '\n'); // Ingresar nuevo apellido
            strcpy(clt[pos].nombre_apellido, "");                    // Vaciar el valor de la variable

            NombreApellido(pos);
            std::cout << "Hola, " << clt[pos].nombre_apellido << std::endl;
            band = false;
        }
        else if (datoC == 3)
        { // Para cambiar email
            std::cout << "Ingrese su nuevo email: ";
            std::cin.getline(clt[pos].email_cliente, MAXC, '\n'); // Ingresar nuevo email
            std::cout << "Email cambiado." << std::endl;
            band = false;
        }
        else if (datoC == 4)
        { // Para cambiar Numero de celular
            std::cout << "Ingrese su nuevo numero de celular: ";
            std::cin.getline(clt[pos].numero_celular, MAXC, '\n'); // Ingresar nuevo numero de celular
            std::cout << "Numero de celular cambiado." << std::endl;
            band = false;
        }
        else if (datoC == 5)
        { // Para cambiar todo
            std::cout << "Has elegido la opcion para cambiar todos los datos.\n"
                      << std::endl;
            std::cout << "Ingrese el nuevo nombre: ";
            std::cin.getline(clt[pos].nombre_cliente, MAXC, '\n'); // Ingresar nuevo nombre
            std::cout << "Ingrese el nuevo apellido: ";
            std::cin.getline(clt[pos].apellido_cliente, MAXC, '\n'); // Ingresar nuevo apellido
            std::cout << "Ingrese el nuevo email: ";
            std::cin.getline(clt[pos].email_cliente, MAXC, '\n'); // Ingresar nuevo email
            std::cout << "Ingrese el nuevo numero de celular: ";
            std::cin.getline(clt[pos].numero_celular, MAXC, '\n'); // Ingresar nuevo numero de celular
            strcpy(clt[pos].nombre_apellido, "");

            NombreApellido(pos); // Nombre y apellido en una sola cadena
            std::cout << "Hola, " << clt[pos].nombre_apellido << ". TODOS tus datos han sido modificados. " << std::endl;
            band = false;
        }
        else
        {
            std::cout << "El parametro ingresado es invalido.";
            band = false;
        } // Cuando el usuario digita un parametro invalido
    }
    else
    {
        std::cout << "El codigo de cliente no se encuentra en nuestra base de datos. " << std::endl;
    }
    band = false;
}

void AgendarCita()
{
    fflush(stdin);
    std::cout << "Para agendar una cita, debes escribir el codigo de cliente del usuario: ";
    std::cin >> comp; // Digitar codigo de cliente
    Busqueda(i);      // Busqueda por seleccion
    if (band)
    {
        std::cout << "Ingrese el dia en que desea realizar su cita (formato: dd/MM/yyyy)";
        std::cin >> clt[pos].cit.cita;
        std::cout << "Ingrese la hora de inicio de su cita: ";
        std::cin >> clt[pos].cit.hora_cita_inicio;
        std::cout << "Ingrese la hora de finalizacion de su cita: ";
        std::cin >> clt[pos].cit.hora_cita_final;
        std::cout << "Cita agregada con exito. " << std::endl;
        clt[pos].cit.cita_t = true;
    }
    else
    {
        std::cout << "El codigo de cliente no coincide con ningun cliente." << std::endl;
    }
    band = false;
}
void VerDatosCita()
{
    std::cout << "Para ver los datos de la cita, debes ingresar tu codigo de cliente: ";
    std::cin >> comp;
    Busqueda(i); // Busqueda por seleccion
    if (band)
    {
        std::cout << "Hola, " << clt[pos].nombre_apellido << ". Estos son los datos de tu cita: \n";
        std::cout << "Dia de la cita: " << clt[pos].cit.cita << std::endl;
        std::cout << "Hora de inicio de la cita: " << clt[pos].cit.hora_cita_inicio << std::endl;
        std::cout << 'Hora de finalizacion de la cita: ' << clt[pos].cit.hora_cita_final << std::endl;
    }
    else
    {
        std::cout << "El codigo de cliente ingresado no coincide. ";
    }
    band = false;
}
void CancelarCita()
{
    std::cout << "Para cancelar tu cita, debes escribir tu codigo de cliente: ";
    std::cin >> comp;
    Busqueda(i);
    if (band && clt[pos].cit.cita_t)
    {
        std::cout << "Hola, " << clt[i].nombre_apellido << ". Tu cita ha sido cancelada." << std::endl;
        clt[i].cit.cita_t = false;
        strcpy(clt[i].cit.hora_cita_final, "");
        strcpy(clt[i].cit.hora_cita_inicio, "");
        strcpy(clt[i].cit.cita, "");
    }
    else if (band == false)
    {
        std::cout << "El codigo de cliente no coincide con ningun cliente." << std::endl;
    }
    else if (clt[pos].cit.cita_t == false)
    {
        std::cout << "No has ingresado los datos para tu cita." << std::endl;
    }
    band = false;
}

int MenuEMP()
{
    int opEMP;

    std::cout << "Cantidad de clientes añadidos: " << reg << std::endl;
    SetConsoleTextAttribute(salida, 10);

    std::cout << "1. Agregar cliente. " << std::endl;
    std::cout << "2. Ver datos de cliente con código de cliente. " << std::endl;
    SetConsoleTextAttribute(salida, 4);
    std::cout << "3. Editar datos de cliente con código de cliente. " << std::endl;
    std::cout << "4. Borrar cliente por codigo de cliente" << std::endl;
    SetConsoleTextAttribute(salida, 10);
    std::cout << "5. Agendar cita con código de cliente. " << std::endl;
    std::cout << "6. Ver datos de cita con código de cliente. " << std::endl;
    std::cout << "7. Cancelar cita con código de cliente. " << std::endl;
    std::cout << "8. Cerrar sesion." << std::endl;
    std::cout << "9. Salir." << std::endl;
    color(salida, 8);
    std::cout << "\n\n\nIngresar numero:";
    color(salida, 7);
    std::cin >> opEMP;
    SetConsoleTextAttribute(salida, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return opEMP;
}

int MenuADM()
{
    int opADM = 0;
    std::cout << "Cantidad de clientes añadidos: ";
    color(salida, 9);
    std::cout << reg << std::endl;
    ;
    color(salida, 10);
    std::cout << "\n\n1. Agregar cliente. " << std::endl;
    std::cout << "2. Ver datos de cliente con código de cliente. " << std::endl;
    std::cout << "3. Editar datos de cliente con código de cliente. " << std::endl;
    std::cout << "4. Borrar cliente con código de cliente. " << std::endl;
    std::cout << "5. Agendar cita con código de cliente " << std::endl;
    std::cout << "6. Ver datos de cita con código de cliente " << std::endl;
    std::cout << "7. Cancelar cita  " << std::endl;
    std::cout << "8. Cerrar sesion." << std::endl;
    std::cout << "9. Ver datos de todos los clientes" << std::endl;
    std::cout << "10. Salir del sistema" << std::endl;
    color(salida, 8);
    std::cout << "\n\n\nIngresar numero: ";
    color(salida, 7);
    std::cin >> opADM;
    color(salida, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return opADM;
}

void Ingreso()
{
principio1:
    M1();
    std::cin >> op;
    color(salida, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    if ((op == 1) && (emp[0].cedula_empleado.empty()))
    {
        M2();
        goto principio1;
    }
    else if ((op == 1) && (!emp[0].cedula_empleado.empty()))
    {
        system("cls");
        std::cout << "\n1. Registrar empleado \n2. Ingresar con empleado registrado \n ";
        std::cin >> op;
        if (op == 1)
        {
            system("cls");
            M2();
            goto principio1;
        }
        else if (op == 2)
        {
            system("cls");
            administrador = false;
            std::cout << "Escriba su cedula de identidad: ";
            std::cin >> cedula;
            std::cout << "Escriba su contraseña: ";
            std::cin >> contraseña;
            for (i = 0; i < reg_ing; i++)
            {
                if ((emp[i].cedula_empleado == cedula) && (emp[i].contraseña_empleado == contraseña))
                {
                    band = true;
                    pos = i;
                    break;
                }
            }
            if (band)
            {
                std::cout << "Hola, " << emp[pos].nombre_empleado << ".\n\n\n"
                          << std::endl;
                LeerCliente();
                do
                {
                    band = false;
                    fflush(stdin);
                    opEMP = MenuEMP();
                    band = false;
                    switch (opEMP)
                    {
                    case 1:
                        std::system("cls");
                        AgregarCliente();
                        std::system("pause");
                        break;
                    case 2:
                        std::system("cls");
                        VerDatosCliente();
                        std::system("pause");
                        break;
                    case 3:
                        if (administrador == false)
                        {
                            std::system("cls");
                            std::cout << "Esta funcion solo es valida para administradores..." << std::endl;
                        }
                        system("pause");
                        break;
                    case 4:
                        if (administrador == false)
                        {
                            system("cls");
                            std::cout << "Esta función solo es valida para administradores..." << std::endl;
                        }
                        system("pause");
                        break;
                    case 5:
                        std::system("cls");
                        AgendarCita();
                        system("pause");
                        break;
                    case 6:
                        system("cls");
                        VerDatosCita();
                        system("pause");
                        break;
                    case 7:
                        system("cls");
                        CancelarCita();
                        system("pause");
                        break;
                    case 8:
                        std::cout << "Has cerrado de sesion correctamente. " << std::endl;
                        system("pause");
                        system("cls");
                        goto principio1;

                    case 9:
                        system("cls");
                        std::cout << "Sistema detenido... ";
                        system("pause");
                        break;
                    default:
                        std::cout << "Opcion invalida. Volver a intentar. \n";
                        system("pause");
                        break;
                    }
                    system("cls");
                } while (opEMP != 9);
                GuardarCliente();
            }
            else
            {
                std::cout << "Su cedula de identidad o contraseña no coinciden.";
                system("pause");
                system("cls");
                goto principio1;
            }
        }
    }
    else if (op == 2)
    {
        system("cls");
        std::cout << "Ingrese su usuario: ";
        std::cin >> usuario;
        std::cout << "Ingrese su contraseña: ";
        std::cin >> contraseña;
        if ((adm.usuario_adm == usuario) && (adm.contraseña_adm == contraseña))
        {
            color(salida, 12);
            system("cls");
            std::cout << "\n\nBienvenido Christian." << std::endl;
            administrador = true;
            LeerCliente();
            do
            {
                opADM = MenuADM();
                switch (opADM)
                {
                case 1:
                    system("cls");
                    AgregarCliente();
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    VerDatosCliente();
                    system("pause");
                    break;
                case 3:
                    if (administrador)
                    {
                        EditarCliente();
                        std::system("pause");
                    }
                    system("pause");
                    break;
                case 4:
                    if (administrador)
                    {
                        BorrarCliente();
                        system("pause");
                    }
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    AgendarCita();
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    VerDatosCita();
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    CancelarCita();
                    system("pause");
                    break;
                case 8:
                    std::cout << "Has cerrado de sesion correctamente. " << std::endl;
                    administrador = false;
                    system("pause");
                    system("cls");
                    goto principio1;
                case 9:
                    system("cls");
                    DatoT();
                    std::system("pause");
                    break;
                case 10:
                    system("cls");
                    std::cout << "Sistema detenido...";
                    break;
                default:
                    std::cout << "Opcion invalida. Volver a intentar. \n";
                    system("pause");
                    break;
                }
                system("cls");
                GuardarCliente();
            } while (opADM != 10);
        }
        else
        {
            std::cout << "El usuario o la contraseña son incorrectos." << std::endl;
            system("pause");
            system("cls");
            goto principio1;
        }
    }
    else
    {
        std::cout << "El valor ingresado no coincide. " << std::endl;
        system("pause");
        system("cls");
        goto principio1;
    }
}

void GuardarCliente()
{
    registros = fopen("data.bin", "wb");
    fwrite(clt, sizeof(cliente), reg, registros);
    fclose(registros);
}
void LeerCliente()
{
    registros = fopen("data.bin", "rb");
    if (registros == NULL)
    {
        return;
    }
    reg = CalcularRegistroCliente(registros);
    fread(clt, sizeof(cliente), MAX, registros);
    fclose(registros);
}

int CalcularRegistroCliente(FILE *archivo)
{
    int length, numClientes;
    fseek(archivo, 0, SEEK_END);
    length = ftell(archivo);
    rewind(archivo);

    numClientes = length / sizeof(cliente);
    return numClientes;
}

void NombreApellido(int x)
{
    strcpy(clt[x].nombre_apellido, clt[x].nombre_cliente);
    strcat(clt[x].nombre_apellido, " ");
    strcat(clt[x].nombre_apellido, clt[x].apellido_cliente);
}

void M1()
{
    color(salida, 14);
    gotoxy(15, 4);
    std::cout << "Bienvenido al sistema 'Boomy Nails' Creado para generar citas. Desea ingresar como: \n\n"
              << std::endl;
    color(salida, 12 | FOREGROUND_INTENSITY);
    gotoxy(17, 6);
    std::cout << "1. Empleado \n";
    gotoxy(17, 7);
    std::cout << "2. Administrador \n\n\n";
    color(salida, 11);
    gotoxy(17, 10);
    std::cout << "Ingresar numero: ";
}
void M2()
{
    system("cls");
    std::cout << "Antes de empezar, debes digitar tus datos" << std::endl;
    fflush(stdin);
    std::cout << "Nombre: ";
    getline(std::cin, emp[reg_ing].nombre_empleado);
    std::cout << "Apellido: ";
    getline(std::cin, emp[reg_ing].apellido_empleado);
    std::cout << "Cedula de identidad: ";
    getline(std::cin, emp[reg_ing].cedula_empleado);
    std::cout << "Contraseña: ";
    getline(std::cin, emp[reg_ing].contraseña_empleado);
    reg_ing++;
    std::cout << "\nEl empleado ha sido añadido al sistema. " << std::endl;
    system("pause");
    system("cls");
}

void BorrarCliente()
{
    int aux;
    std::cout << "Para borrar un usuario, digite su codigo de cliente: ";
    std::cin >> comp;
    for (i = 0; i < reg; i++)
    { // Busqueda por seleccion para encontrar algun cliente con el codigo de cliente digitado
        if (clt[i].codigo_cliente == comp)
        {
            band = true;
            pos = i;
            break;
        }
    }
    if (band)
    {
        std::cout << "Estas a punto de ELIMINAR TODOS los datos de " << clt[pos].nombre_apellido << ". ¿Estas seguro?" << std::endl;
        std::cout << "1. Eliminar" << std::endl;
        std::cout << "2. No Eliminar\n\n"
                  << std::endl;
        color(salida, 14);
        std::cout << "Ingresar número: ";
        std::cin >> comp;
        color(salida, 15);

        if (comp == 1)
        {
            for (i = pos; i < reg - 1; i++)
            {

                clt[i] = clt[i + 1];
            }
            reg--;
            ReinicioCliente(reg);
            std::cout << "Datos borrados exitosamente." << std::endl;
            system("pause");
            system("cls");
        }
        else if (comp == 2)
        {
            std::cout << "Cliente no borrado. " << std::endl;
            system("pause");
            system("cls");
        }
        else
        {
            std::cout << "Parámetro incorrecto. " << std::endl;
            system("pause");
            system("cls");
        }
    }
    else
    {
        std::cout << "Código de cliente invalido. " << std::endl;
    }
}

void ReinicioCliente(int x)
{ // Vaciar todos los datos del cliente que se va a borrar
    strcpy(clt[x].apellido_cliente, "");
    clt[x].codigo_cliente = 0;
    strcpy(clt[x].email_cliente, "");
    strcpy(clt[x].nombre_apellido, "");
    strcpy(clt[x].nombre_cliente, "");
    strcpy(clt[x].numero_celular, "");
}

void Busqueda(int i)
{
    for (i = 0; i <= reg; i++)
    { // Busqueda por seleccion
        if (clt[i].codigo_cliente == comp)
        {
            band = true;
            pos = i; // Valor encontrado
            break;
        }
    }
}
