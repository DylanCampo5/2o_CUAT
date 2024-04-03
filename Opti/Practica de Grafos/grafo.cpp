 /*
 *  GRAFO.CPP - Plantilla para la implementaci n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"

// Método para liberar la memoria dinámica y limpiar las listas de adyacencia y aristas del grafo
void GRAFO::destroy() {
    for (unsigned i = 0; i < n; i++) {
        LS[i].clear(); // Limpiamos la lista de sucesores
        if (dirigido == 1) {
            LP[i].clear(); // Si el grafo es dirigido, también limpiamos la lista de predecesores
        }
    }
    LS.clear(); // Limpiamos la lista de sucesores completa
    LP.clear(); // Limpiamos la lista de predecesores completa
    A.clear();  // Limpiamos la matriz de adyacencia
}

// Método para construir el grafo a partir de un archivo de texto
void GRAFO::build(char nombrefichero[85], int &errorapertura) {
    ElementoLista dummy; // Nodo auxiliar para almacenar temporalmente la información de las aristas
    ifstream textfile(nombrefichero);
    if (textfile.is_open()) {
        textfile >> n >> m >> dirigido; // Leemos el número de nodos, aristas y si el grafo es dirigido
        LS.resize(n); // Redimensionamos la lista de sucesores según el número de nodos
        LP.resize(n); // Siempre redimensionamos la lista de predecesores
        if (dirigido == 1) {
            // Si el grafo es dirigido, realizamos alguna acción adicional si es necesario
        }

        // Leemos cada arista del archivo de texto y la agregamos a las listas de sucesores y, en su caso, predecesores
        for (unsigned k = 0; k < m; k++) {
            unsigned i, j;
            int c;
            textfile >> i >> j >> c;
            i--; // Ajustamos el índice del nodo i para que comience desde 0
            j--; // Ajustamos el índice del nodo j para que comience desde 0
            dummy.j = j; // Establecemos el sucesor en el nodo j
            dummy.c = c; // Agregamos el costo de la arista al dummy
            LS[i].push_back(dummy); // Agregamos la arista a la lista de sucesores del nodo i
            if (dirigido == 1) {
                // Si el grafo es dirigido, agregamos el nodo i a la lista de predecesores del nodo j
                dummy.j = i;
                LP[j].push_back(dummy); // Agregamos la arista a la lista de predecesores del nodo j
            }
            if (dirigido == 0) {
                // Si el grafo es no dirigido, agregamos una arista de j a i
                dummy.j = i;
                LS[j].push_back(dummy); // Agregamos la arista a la lista de sucesores del nodo j
            }
        }

        textfile.close(); // Cerramos el archivo
        errorapertura = 0; // Marcamos que no hubo error en la apertura del archivo
    } else {
        errorapertura = 1; // Marcamos que hubo un error en la apertura del archivo
    }
}

// Destructor de la clase GRAFO
GRAFO::~GRAFO() {
    destroy(); // Llamamos al método destroy para liberar la memoria dinámica utilizada por el grafo
}

// Constructor de la clase GRAFO
GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) {
    build(nombrefichero, errorapertura); // Llamamos al método build para construir el grafo a partir del archivo de texto
}

// Método para actualizar el grafo con nuevos datos desde un archivo de texto
void GRAFO::actualizar(char nombrefichero[85], int &errorapertura) {
    // Limpiamos la memoria dinámica asumida en la carga previa, como haría el destructor
    destroy();
    // Leemos del fichero y actualizamos el grafo con nuevas listas de sucesores y, en su caso, predecesores
    build(nombrefichero, errorapertura);
}

// Método para determinar si el grafo es dirigido o no
unsigned GRAFO::Es_dirigido() {
    return dirigido; // Devolvemos el valor de la variable dirigido
}

// Método para mostrar información básica del grafo
void GRAFO::Info_Grafo() {
    if (dirigido == 1) {
        cout << "Grafo dirigido "; // Si el grafo es dirigido, mostramos un mensaje indicándolo
    } else {
        cout << "Grafo no dirigido "; // Si el grafo es no dirigido, mostramos un mensaje indicándolo
    }
    cout << "| nodos: " << n << " | "; // Mostramos el número de nodos del grafo
    if (dirigido == 1) {
        cout << "arcos: " << m << endl; // Si el grafo es dirigido, mostramos el número de arcos
    } else {
        cout << "aristas: " << m << endl; // Si el grafo es no dirigido, mostramos el número de aristas
    }
}

// Método para mostrar la lista de adyacencia, predecesores o sucesores del grafo según el parámetro l
void GRAFO::Mostrar_Listas(int l) {
    if (l == 1) {
        // Mostrar la lista de sucesores de un grafo dirigido
        cout << "|Dirigido|" << endl;
        cout << "|Nodos sucesores|" << endl;
        for (auto i = 0; i < LS.size(); ++i) {
            cout << "[" << i + 1 << "]: "; // Mostrar el índice del nodo actual más 1 para ajustarlo al rango de 1 a n
            for (auto j = 0; j < LS[i].size(); ++j) {
                cout << LS[i][j].j + 1 << "|"; // Mostrar el índice del nodo sucesor más 1
            }
            cout << endl; // Salto de línea para separar las listas de sucesores
        }
        cout << endl;
    }
    if (l == 0 || l == -1) {
        // Mostrar la lista de adyacencias o predecesores de un grafo no dirigido o dirigido
        string tipo_lista = (l == 0) ? "No dirigido" : "Dirigido";
        string tipo_nodos = (l == 0) ? "Lista de adyacencias" : "Lista de predecesores";
        cout << "|" << tipo_lista << "|" << endl;
        cout << "|" << tipo_nodos << "|" << endl;
        const auto& lista = (l == 0) ? LS : LP; // Seleccionar la lista correspondiente
        for (auto i = 0; i < lista.size(); ++i) {
            cout << "[" << i + 1 << "]: "; // Mostrar el índice del nodo actual más 1 para ajustarlo al rango de 1 a n
            for (auto j = 0; j < lista[i].size(); ++j) {
                cout << lista[i][j].j + 1 << "|"; // Mostrar el índice del nodo adyacente o predecesor más 1
            }
            cout << endl; // Salto de línea para separar las listas de adyacencia o predecesores
        }
        cout << endl; 
    }
}


// Método para mostrar la matriz de adyacencia del grafo
void GRAFO::Mostrar_Matriz() {
    // Creamos una matriz para almacenar la matriz de adyacencia
    vector<vector<int>> matriz(n, vector<int>(n, 0));

    // Llenamos la matriz de adyacencia con los costos de las aristas desde LS
    for (unsigned i = 0; i < LS.size(); ++i) {
        for (unsigned j = 0; j < LS[i].size(); ++j) {
            matriz[i][LS[i][j].j] = LS[i][j].c; // Asignamos el costo de la arista al elemento correspondiente de la matriz
        }
    }

    // Si el grafo es no dirigido, llenamos la matriz con los costos de las aristas desde LP
    if (dirigido == 0) {
        for (unsigned i = 0; i < LP.size(); ++i) {
            for (unsigned j = 0; j < LP[i].size(); ++j) {
                matriz[i][LP[i][j].j] = LP[i][j].c; // Asignamos el costo de la arista al elemento correspondiente de la matriz
            }
        }
    }

    // Mostramos la matriz de adyacencia con los costos de las aristas
    cout << "Matriz de adyacencia:" << endl;
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            cout << matriz[i][j] << " "; // Mostramos el costo de la arista entre los nodos i y j
        }
        cout << endl;
    }
}

// Método de recorrido en profundidad recursivo con preorden y postorden
void GRAFO::dfs_num(unsigned i, vector<LA_nodo> L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) {
    visitado[i] = true; // Marcamos el nodo como visitado
    prenum[prenum_ind++] = i; // Asignamos el orden de visita preorden que corresponde al nodo i
    for (unsigned j = 0; j < L[i].size(); j++) {
        if (!visitado[L[i][j].j]) {
            dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind); // Llamada recursiva para visitar los nodos adyacentes
        }
    }
    postnum[postnum_ind++] = i; // Asignamos el orden de visita postorden que corresponde al nodo i
}

// Método para realizar el recorrido en profundidad en el grafo
void GRAFO::RecorridoProfundidad() {
    // Creación e inicialización de variables y vectores
    vector<bool> visitado(n, false); // Vector para marcar los nodos visitados
    vector<unsigned> prenum(n, 0);   // Vector para almacenar el orden de visita preorden
    vector<unsigned> postnum(n, 0);  // Vector para almacenar el orden de visita postorden
    unsigned prenum_ind = 0;         // Índice para preorden
    unsigned postnum_ind = 0;        // Índice para postorden

    // Solicitud al usuario del nodo inicial del recorrido en profundidad
    unsigned nodo_inicial;
    cout << "Ingrese el nodo inicial del recorrido en profundidad: ";
    cin >> nodo_inicial;

    // Realizar el recorrido en profundidad desde el nodo inicial
    dfs_num(nodo_inicial - 1, LS, visitado, prenum, prenum_ind, postnum, postnum_ind);

    // Mostrar en pantalla el preorden
    cout << "Preorden: ";
    for (unsigned i = 0; i < n; ++i) {
        cout << prenum[i] << " ";
    }
    cout << endl;

    // Mostrar en pantalla el postorden
    cout << "Postorden: ";
    for (unsigned i = 0; i < n; ++i) {
        cout << postnum[i] << " ";
    }
    cout << endl;
}

// Método para realizar el recorrido en amplitud en el grafo
void GRAFO::RecorridoAmplitud() {
    // Creación e inicialización de variables y vectores
    vector<bool> visitado(n, false);     // Vector para marcar los nodos visitados
    vector<unsigned> pred(n, 0);         // Vector para almacenar los predecesores
    vector<unsigned> distancias(n, maxint); // Vector para almacenar las distancias, inicializado con el valor máximo
    queue<unsigned> cola;                // Cola para el recorrido en amplitud

    // Solicitud al usuario del nodo inicial del recorrido en amplitud
    unsigned nodo_inicial;
    cout << "Ingrese el nodo inicial del recorrido en amplitud: ";
    cin >> nodo_inicial;
    nodo_inicial--; // Ajustamos el nodo al rango de 0 a n-1

    // Inicializamos el nodo inicial
    visitado[nodo_inicial] = true;
    distancias[nodo_inicial] = 0;
    cola.push(nodo_inicial);

    // Realizamos el recorrido en amplitud
    while (!cola.empty()) {
        unsigned nodo_actual = cola.front();
        cola.pop();

        // Recorremos todos los nodos adyacentes al nodo actual
        for (unsigned i = 0; i < LS[nodo_actual].size(); ++i) {
            unsigned nodo_adyacente = LS[nodo_actual][i].j;
            if (!visitado[nodo_adyacente]) {
                // Marcamos el nodo como visitado
                visitado[nodo_adyacente] = true;
                // Actualizamos el predecesor y la distancia
                pred[nodo_adyacente] = nodo_actual + 1; // Sumamos 1 para ajustar el índice al rango de 1 a n
                distancias[nodo_adyacente] = distancias[nodo_actual] + 1;
                // Agregamos el nodo adyacente a la cola
                cola.push(nodo_adyacente);
            }
        }
    }

    // Mostrar en pantalla la etiqueta distancia
    cout << "Etiqueta distancia:" << endl;
    for (unsigned i = 0; i < n; ++i) {
        cout << "Distancia al nodo " << i + 1 << ": ";
        if (distancias[i] == maxint) {
            cout << "Infinito" << endl;
        } else {
            cout << distancias[i] << endl;
        }
    }

    // Mostrar en pantalla los predecesores
    cout << "Predecesores:" << endl;
    for (unsigned i = 0; i < n; ++i) {
        cout << "Predecesor del nodo " << i + 1 << ": " << pred[i] << endl;
    }
}
