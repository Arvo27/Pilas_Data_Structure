#include <iostream>
#include <exception>
#include "Pilas.hpp"

// Incluir vectores para pruebas adicionales
#include "Vector.hpp"

using namespace std;


int main()
{
    try{
    
    Pilas<int>  p;

    p.push(5);

    cout << endl;
    p.print();

    p.push(3);

    cout << endl;
    p.print();

    p.push(-4);

    cout << endl;
    p.print();

    // Pilas<string> p2;

    // p2.push("Hello");

    // cout << endl;
    // p2.print();

    // p2.push("World");

    // cout << endl;
    // p2.print();

    // Pilas<Vector> p3;

    // p3.push(Vector(3, 1.0)); 

    // cout << endl;
    // p3.print();

    // //Crear una pila de pilas de enteros
    // Pilas<Pilas<int, 10>,25> p4;
    // Pilas<int,10> p5;
    // //Imprimir pila vacia
    // cout << "Pila vacia de enteros: " << p5 << endl;
    // p5.push(1);
    // p5.push(2);
    // p4.push(p5);

    // cout << endl;
    // cout << "Pila de pilas de enteros: " << endl;
    // cout << p4;

    
    }catch(Pilas<int, 10>::StackEmpty& e){
        cerr << e.QuePaso() << endl;
    }catch(Pilas<int, 10>::StackFull& e){
        cerr << e.QuePaso() << endl;
    }catch(...){
        cerr << "An unknown error occurred." << endl;
    }

     return 0;
}
