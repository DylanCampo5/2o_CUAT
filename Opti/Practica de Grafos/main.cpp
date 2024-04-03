 /*
 *  Programa principal.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Cursos  : 2012-2021
 */

#include <string.h>
#include "grafo.h"

void pressanykey() {

    cout << "Presiona Enter para continuar...";
    getchar(); // Espera a que el usuario ingrese un carácter
    cin.ignore(); // Limpia el buffer de entrada
    
}

void clrscr() {

     cout << "\033[2J\033[1;1H"; // Secuencia de escape ANSI para limpiar la pantalla
}


void menu (unsigned dirigido, char &opcion)
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{
    cout << "Optimiza!cion en Grafos, 2023-2024 Dylan Gonzalo Campo Bedoya" << endl;
    cout << "c. [c]argar grafo desde fichero" << endl;
    if (dirigido == 0) //Grafo no dirigido
            {
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            cout << "a. Mostrar la lista de [a]dyacencia del grafo" << endl;
            cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo" << endl;
            cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo" << endl;
	    //Aqu  se a aden m s opciones al men  del grafo no dirigido
            }
    else
            {
            cout << "i. Mostrar [i]nformacion basica del grafo" << endl;
            cout << "s. Mostrar la lista de [s]ucesores del grafo" << endl;
            cout << "p. Mostrar la lista de [p]redecesores del grafo" << endl;
            cout << "y. Mostrar la matriz de ad[y]acencia del grafo" << endl;
            cout << "m. Realizar un recorrido en a[m]plitud del grafo desde un nodo por sucesores" << endl;
            cout << "r. Realizar un recorrido en p[r]ofundidad del grafo desde un nodo por sucesores" << endl;
	    //Aqu  se a aden m s opciones al men  del grafo dirigido
            };
    cout << "q. Finalizar el programa" << endl;
    cout << "Introduce la letra de la accion a ejecutar  > ";
    cin >> opcion;
};


// El principal es simplemente un gestor de menu, diferenciando acciones para dirigido y para no dirigido, y un men  inicial si no hay un grafo cargado
int main(int argc, char *argv[])
{
    int error_apertura;
    char nombrefichero[85], opcion;
    clrscr();
    //Si tenemos el nombre del primer fichero por argumento, es una excepcion, y lo intentamos cargar, si no, lo pedimos desde teclado
    if (argc > 1)
    {
	cout << "Cargando datos desde el fichero dado como argumento" << endl;
        strcpy(nombrefichero, argv[1]);
    }
    else
    {
        cout << "Introduce el nombre completo del fichero de datos" << endl;
        cin >> nombrefichero;
    };
    GRAFO G(nombrefichero, error_apertura);
    if (error_apertura == 1)
    {
        cout << "Error en la apertura del fichero desde argumento: revisa nombre y formato" << endl;
        pressanykey();
        clrscr();
    }
    else
    {
        cout<< "Grafo cargado desde el fichero " << nombrefichero << endl;
        pressanykey();
        clrscr();
        do
        {
            menu(G.Es_dirigido(), opcion);
            switch (opcion)
            {
                case 'c':
                    clrscr();
         	        std::cout << "Introduce el nombre completo del fichero de datos" << std::endl;
                    std::cin >> nombrefichero;
                    G.actualizar(nombrefichero, error_apertura);
                    if (error_apertura == 1) {
                        std::cout << "Error en la apertura del fichero: revisa nombre y formato : puedes volver a intentarlo" << std::endl;
                    } else {
                        std::cout << "Fichero cargado correctamente desde " << nombrefichero << std::endl;
                    }
                    pressanykey();
                    clrscr();
                    break;

                case 'i':
                    clrscr();
		            std::cout << "Grafo cargado desde " << nombrefichero << std::endl;
                    G.Info_Grafo();
                    pressanykey();
                    clrscr();
                    break;

                case 'a':
                    clrscr();
                    std::cout << "Lista de adyacencia del grafo:" << std::endl;
                    G.Mostrar_Listas(0);
                    pressanykey();
                    clrscr();
                    break;

                case 's':
                    clrscr();
                    std::cout << "Lista de sucesores del grafo:" << std::endl;
                    G.Mostrar_Listas(1);
                    pressanykey();
                    clrscr();
                    break;

                case 'p':
                    clrscr();
                    std::cout << "Lista de predecesores del grafo:" << std::endl;
                    G.Mostrar_Listas(-1);
                    pressanykey();
                    clrscr();
                    break;

                case 'y':
                    clrscr();
                    std::cout << "Matriz de adyacencia del grafo:" << std::endl;
                    G.Mostrar_Matriz();
                    pressanykey();
                    clrscr();
                    break;

                case 'm':
                    clrscr();
                    std::cout << "Recorrido en amplitud del grafo desde un nodo:" << std::endl;
                    G.RecorridoAmplitud();
                    pressanykey();
                    clrscr();
                    break;

                case 'r':
                    clrscr();
                    std::cout << "Recorrido en profundidad del grafo desde un nodo:" << std::endl;
                    G.RecorridoProfundidad();
                    pressanykey();
                    clrscr();
                    break;
		 //Situar aqu  el resto de opciones del men 
            }
    }
    while (opcion != 'q');
    }
    cout << "Fin del programa" << endl;
	return(0);
};
