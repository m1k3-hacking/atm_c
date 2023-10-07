/* ========================================================================== */
/* Proyecto: U3 AI4. Ejercicio: Programando funcionalidad Retiros.            */
/* -------------------------------------------------------------------------- */
/* Autor: Michel. Reyes                                                       */
/* ========================================================================== */

/*
 * La funcionalidad muestra un mensaje de bienvenida y presentación de uso.
 * La funcionalidad deberá solicitar usuario y contraseña, comparar con los datos ya almacenados y permitir pasar al siguiente proceso.
 *La funcionalidad solicitará la cantidad a entregar, la cantidad no puede ser mayor al 40% del total y sólo se puede retirar en los primeros 5 días del mes.
 *La funcionalidad mostrará un desglose de billetes a entregar con cantidad y denominación separados por un salto de línea.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//Variables globales
char usuarioAlmacenado[] = "paco";
char contrasenaAlmacenada[] = "1234";
float saldoDisponible = 1000.0;
float cantidadDeposito = 0.0;
int billetesDisponibles[] = {100, 50, 20, 10, 5};
int cantidadBilletes[] = {10, 20, 30, 40, 50};

//Prototipos de funciones
bool inicioSesion();
void menuPrincipal();
void menuRetiro();
void menuDeposito();
void menuConsulta();
void exit(int i) {}
void exit(int i);
void salir();

//Funcion principal

 void menuPrincipal () {
        int opcion = 0;
     printf("\n\n");
     printf("Bienvenido %s\n", usuarioAlmacenado);
        printf("Menu del cajero automatico\n");
        printf("1. Retiro\n");
        printf("2. Deposito\n");
        printf("3. Consulta\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                menuRetiro();
                break;
            case 2:
                menuDeposito();
                break;
            case 3:
                menuConsulta();
                break;
            case 4:
                salir();
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }

 }


//Funciones

bool inicioSesion () {
     int intentos = 0;
    do {
        printf("Por favor ingrese su usuario y password\n");
        printf("Usuario: ");
        scanf("%s", &usuarioAlmacenado);
        printf("Password: ");
        scanf("%s", &contrasenaAlmacenada);
        if (strcmp(usuarioAlmacenado, "paco") == 0 && strcmp(contrasenaAlmacenada, "1234") == 0 ) {
            return true;
        } else
            printf("Usuario o password incorrectos\n");
        intentos++;
     } while(intentos < 3);
         printf("Usuario bloqueado, contacte al administrador\n");
            exit(0);

}

void menuRetiro () {
    float cantidadRetiro = 0.0;
    int dia = 0;
    printf("\n\n");
    printf("Bienvenido al retiro\n");
    printf("Su saldo disponible es: %f\n", saldoDisponible);
    printf("Ingrese la cantidad a retirar: ");
    scanf("%f", &cantidadRetiro);
    printf("Ingrese el dia del mes: ");
    scanf("%d", &dia);
    if (cantidadRetiro > saldoDisponible || cantidadRetiro > (0.40 * saldoDisponible) || dia > 5) {
        printf("Transaccion no disponible\n");
    } else {
        saldoDisponible = saldoDisponible - cantidadRetiro;
        printf("Su nuevo saldo en su cuenta es: %f\n", saldoDisponible);
        printf("Su retiro es de: %f\n", cantidadRetiro);
        printf("Desglose de billetes entregados:\n");
        for (int i = 0; i < 5; i++) {
            int billetesEntregados = cantidadRetiro / billetesDisponibles[i];
            if (billetesEntregados > 0 && cantidadBilletes[i] > 0) {
                if (billetesEntregados > cantidadBilletes[i]) {
                    billetesEntregados = cantidadBilletes[i];
                }
                cantidadRetiro -= billetesEntregados * billetesDisponibles[i];
                cantidadBilletes[i] -= billetesEntregados;
                printf("%d billete(s) de %d\n", billetesEntregados, billetesDisponibles[i]);
            }
        }
        if (cantidadRetiro > 0) {
            printf("Entregando pesos de: %.2f\n", cantidadRetiro);
        }
    }
    system("pause");
}

void menuDeposito () {

    printf("\n\n");
    printf("Bienvenido al deposito\n");
    printf("Su saldo disponible es: %f\n", saldoDisponible);
    printf("Ingrese la cantidad a depositar: ");
    scanf("%f", &cantidadDeposito);
    saldoDisponible = saldoDisponible + cantidadDeposito;
    printf("Su nuevo saldo es: %f\n", saldoDisponible);
    system("pause");
}

void menuConsulta () {
    printf("\n\n");
    printf("Bienvenido a la consulta de saldo\n");
    printf("Su saldo disponible es: %f\n", saldoDisponible);
    system("pause");
}

void salir () {
    printf("Gracias por usar el cajero automatico\n");
    exit(0);

}


int main() {

     int modo_operacion = 0;

     modo_operacion = inicioSesion();



    if (modo_operacion == true) {
        while (1)    {
            menuPrincipal();
        }
    } else {
        printf("Usuario bloqueado, contacte al administrador\n");
        exit(0);
    }
    return 0;
}


