#include <iostream>
#include <fstream>
#include <clocale>
#include "Lista.h"
using namespace std;

/**
 * Abre el archivo según el origen, procesa las líneas del mismo y
 * almacena la información resultante en el contenedor pasado por referencia.
 **/
void procesar_archivo_entrada(string origen);//, Contenedor & contenedor);

int main()
{
    Lista<int> l;
    l.agregar(2);
    l.agregar(3);
    l.agregar(7);
    l.agregar(6);
    setlocale(LC_ALL, ""); //asegurarse que el archivo de texto fue guardado como Ansi y no como Unicode
    procesar_archivo_entrada("libros.csv");
    bool j = l.vacia();
    cout << j <<endl;
    l.P();
    return 0;
}

//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_libros = atoi(linea.c_str());
        cout << "Se cargarán " << cantidad_libros << " libros." << endl;

        //Leemos de una linea completa por vez (getline).
        int nroLibro = 1;
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            string isbn = linea.substr(pos_inicial, pos_final);

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string fechaPublicacion = linea.substr(pos_inicial, pos_final - pos_inicial);

             //Quinta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string paisOrigen = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            cout << "LIBRO Nro "<< nroLibro<< "--------------------------------------" << endl;
            cout << "   ISBN: " << isbn << endl;
            cout << "   TITULO: " << titulo<< endl;
            cout << "   AUTOR: " << autor<< endl;
            cout << "   FECHA PUBLIC: " << fechaPublicacion<<endl;
            cout << "   PAIS: " << paisOrigen<< endl;
            cout << "   PRECIO: " << precio<<endl;

            //TO DO: Completar la lectura de los Idiomas del libro

            //Desde esta posición hasta el final se encuentra un número variable de idiomas de cada libro.
            //no tomo en cuenta los corchetes
            pos_inicial = pos_final + 2;
            pos_final = linea.size()-1;
            string idiomas = linea.substr(pos_inicial, pos_final - pos_inicial);
            cout << "   IDIOMAS: " << idiomas<<endl;

            /*
            // el siguiente código de prueba separa los diferentes idiomas en un arreglo de 10 posiciones
            string listaIdiomas[10];
            int pos_inicial_idiomas = 0, pos_final_idiomas = 0;
            int nroIdioma = 0;
            while (pos_final_idiomas != -1) {
                pos_final_idiomas = idiomas.find(',', pos_inicial_idiomas);
                listaIdiomas[nroIdioma] = idiomas.substr(pos_inicial_idiomas, pos_final_idiomas - pos_inicial_idiomas);
                pos_inicial_idiomas = pos_final_idiomas + 1;
                nroIdioma++;
            }

            */

            nroLibro++;
        }
    }
}

