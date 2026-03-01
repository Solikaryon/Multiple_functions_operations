#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ===================== PROTOTIPOS =====================
double sumaNumeros(int n, double arr[]);             // A (con parametros) - suma los elementos de un arreglo
void potencia();                                     // B (sin parametros) - calcula base^exponente sin pow
int contarCaracteres(char texto[]);                  // C (con parametros) - cuenta caracteres ignorando espacios y saltos de línea
void contarVocalesConsonantes();                     // D (sin parametros) - cuenta vocales y consonantes de un texto
void parImpar(int n);                                // E (con parametros) - indica si un número es par o impar
void traductorBinario4();                            // F (sin parametros, con apuntadores) - convierte un número 0-15 a binario de 4 bits
int deseaContinuar();                                // Control de bucle - pregunta al usuario si desea continuar

// ===================== FUNCIONES =====================

// A) Suma de numeros
double sumaNumeros(int n, double arr[]) {
    double suma = 0;                                 // Inicializa acumulador en 0
    for (int i = 0; i < n; i++) {                    // Recorre cada elemento del arreglo
        suma += arr[i];                               // Suma el valor actual al acumulador
    }
    return suma;                                     // Retorna la suma total
}

// B) Potencia (a mano, sin pow)
void potencia() {
    int base, exp;                                   // Variables para la base y exponente
    long resultado = 1;                              // Inicializa resultado en 1 (identidad multiplicativa)

    printf("Ingrese la base (entero): ");
    while (scanf("%d", &base) != 1) {               // Validación de entrada para un número entero
        printf("Error. Ingrese un numero entero: ");
        while (getchar() != '\n');                  // Limpia buffer de entrada si se ingresó algo incorrecto
    }

    printf("Ingrese el exponente (entero >=0): ");
    while (scanf("%d", &exp) != 1 || exp < 0) {     // Validación de entrada para exponente no negativo
        printf("Error. Ingrese un exponente entero no negativo: ");
        while (getchar() != '\n');                  // Limpia buffer de entrada
    }

    for (int i = 0; i < exp; i++) {                 // Multiplica la base consigo misma 'exp' veces
        resultado *= base;
    }

    printf("%d ^ %d = %ld\n", base, exp, resultado); // Muestra el resultado de la potencia
}

// C) Contar caracteres (sin espacios)
int contarCaracteres(char texto[]) {
    int contador = 0;                                // Inicializa contador
    for (int i = 0; texto[i] != '\0'; i++) {        // Recorre el texto hasta el fin de cadena
        if (texto[i] != ' ' && texto[i] != '\n')    // Ignora espacios y saltos de línea
            contador++;                              
    }
    return contador;                                 // Retorna la cantidad de caracteres válidos
}

// D) Contar vocales y consonantes
void contarVocalesConsonantes() {
    char texto[200];                                 // Arreglo para almacenar texto ingresado
    int vocales = 0, consonantes = 0;               // Contadores inicializados

    printf("Ingrese una cadena de texto: ");
    getchar();                                       // Limpia buffer antes de fgets
    fgets(texto, sizeof(texto), stdin);             // Lee cadena completa incluyendo espacios

    for (int i = 0; texto[i] != '\0'; i++) {       // Recorre cada carácter
        char c = tolower(texto[i]);                 // Convierte a minúscula para simplificar comparación
        if (isalpha(c)) {                           // Verifica que sea letra
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') // Vocales
                vocales++;
            else
                consonantes++;                      // Resto de letras son consonantes
        }
    }

    printf("Vocales: %d\n", vocales);              // Muestra número de vocales
    printf("Consonantes: %d\n", consonantes);      // Muestra número de consonantes
}

// E) Par o impar
void parImpar(int n) {
    if (n % 2 == 0)                                 // Si el resto de dividir entre 2 es 0
        printf("%d es PAR\n", n);                   // Es par
    else
        printf("%d es IMPAR\n", n);                 // Si no, es impar
}

// F) Traductor a binario 4 bits con apuntadores
void traductorBinario4() {
    int num;                                         // Número ingresado por el usuario
    int *ptr = &num;                                 // Puntero que apunta a 'num'

    printf("Ingrese un numero entero (0-15): ");
    while (scanf("%d", &num) != 1) {                // Validación de entrada
        printf("Error. Ingrese un numero entero: ");
        while (getchar() != '\n');                  // Limpia buffer
    }

    if (*ptr < 0 || *ptr > 15) {                    // Verifica si el número cabe en 4 bits
        printf("No se puede representar en binario 4\n");
        return;
    }

    printf("Binario (4 bits): ");
    for (int i = 3; i >= 0; i--) {                  // Recorre cada bit de mayor a menor
        printf("%d", (*ptr >> i) & 1);              // Desplaza y obtiene bit correspondiente
    }
    printf("\n");
    printf("Direccion de memoria: %p\n", &num);     // Muestra la dirección de memoria del número
}

// Preguntar si se desea continuar
int deseaContinuar() {
    char opcion;
    printf("\nDesea continuar? (A = Si, B = No): ");
    scanf(" %c", &opcion);                          // Lee opción del usuario
    if (opcion == 'B' || opcion == 'b') {
        printf("Cerrando la aplicacion...\n");     // Mensaje de salida
        return 0;                                   // Retorna 0 para terminar bucle
    }
    if (opcion == 'A' || opcion == 'a') {
        printf("Opcion valida...\n");              // Mensaje de confirmación
        return 1;                                   // Retorna 1 para continuar bucle
    } else {
        printf("Opcion invalida...\n");            // Manejo de entrada incorrecta
        system("cls");                              // Limpia pantalla
        deseaContinuar();                           // Llamada recursiva para nueva opción
    }
    return 1;                                       // Por defecto retorna 1 para seguir
}

// ===================== MAIN =====================
int main() {
    char opcion;                                    // Almacena opción de menú
    int continuar = 1;                              // Control del bucle principal
    do {
        system("cls");                              // Limpia pantalla antes de mostrar menú
        printf("Luis Fernando Monjaraz Briseno\n\n"); // Título
        printf("\n===== MENU =====\n");            // Encabezado de menú
        printf("A. Suma de numeros\n");           
        printf("B. Potencia de un numero\n");
        printf("C. Contar caracteres (sin espacios)\n");
        printf("D. Contar vocales y consonantes\n");
        printf("E. Par o impar\n");
        printf("F. Traductor a binario de 4 bits\n");
        printf("G. Salir\n");
        printf("Seleccione una opcion: ");
        scanf(" %c", &opcion);                      // Captura la opción del usuario

        switch (opcion) {                            // Manejo de opciones con switch
            case 'A': 
            case 'a': {                              // A o a
                int n;
                printf("Cuantos numeros desea sumar? ");
                while (scanf("%d", &n) != 1 || n <= 0) { // Validación de número positivo
                    printf("Error. Ingrese un entero positivo: ");
                    while (getchar() != '\n');       // Limpia buffer
                }

                double arr[n];                        // Arreglo dinámico para almacenar números
                for (int i = 0; i < n; i++) {
                    printf("Ingrese numero %d: ", i + 1);
                    while (scanf("%lf", &arr[i]) != 1) { // Validación de números decimales
                        printf("Error. Ingrese un numero decimal: ");
                        while (getchar() != '\n');   // Limpia buffer
                    }
                }

                printf("La suma es: %.2lf\n", sumaNumeros(n, arr)); // Llama a función de suma
                continuar = deseaContinuar();         // Pregunta si desea continuar
                break;
            }
            case 'B':
            case 'b':
                potencia();                           // Llama función potencia
                continuar = deseaContinuar();          // Pregunta si desea continuar
                break;
            case 'C':
            case 'c': {
                char texto[200];
                printf("Ingrese un texto: ");
                getchar();                             // Limpia buffer
                fgets(texto, sizeof(texto), stdin);    // Captura texto con espacios
                printf("Numero de caracteres (sin espacios): %d\n", contarCaracteres(texto)); // Llama a función
                continuar = deseaContinuar();          // Pregunta si desea continuar
                break;
            }
            case 'D':
            case 'd':
                contarVocalesConsonantes();             // Llama función contar vocales y consonantes
                continuar = deseaContinuar();
                break;
            case 'E':
            case 'e': {
                int num;
                printf("Ingrese un numero entero: ");
                while (scanf("%d", &num) != 1) {      // Validación de número entero
                    printf("Error. Ingrese un numero entero: ");
                    while (getchar() != '\n');
                }
                parImpar(num);                          // Llama función par o impar
                continuar = deseaContinuar();
                break;
            }
            case 'F':
            case 'f':
                traductorBinario4();                     // Llama función traductor a binario
                continuar = deseaContinuar();
                break;
            case 'G':
            case 'g':
                printf("Cerrando la aplicacion...\n"); // Mensaje de salida
                continuar = 0;                           // Termina bucle
                break;
            default:
                printf("Opcion invalida, intente de nuevo.\n"); // Manejo de opción incorrecta
                continuar = deseaContinuar();           // Pregunta si desea continuar
        }
    } while (continuar);                                // Se repite mientras continuar sea 1
    return 0;                                          // Fin del programa
}
