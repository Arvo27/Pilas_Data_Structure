#include "Vector.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::sqrt;


// Vector::Vector() {
//     // Constructor por default
//     setDim(2);
//     try{
//         enter = new float[dim];
//         for(int i = 0; i < dim; ++i) {
//             enter[i] = 0;
//         }
//     } catch (std::bad_alloc& e) {
//         throw "Memory allocation failed";
//     }
// }

// Vector::Vector(short dim) {
//     setDim(dim);
//     for(int i = 0; i < dim; ++i) {
//         enter[i] = 0;
//     }
// }

Vector::Vector(short dim, float valor) {
    setDim(dim);
    enter = new float[dim];
    for(int i = 0; i < dim; ++i) {
        enter[i] = valor;
    }
}

Vector::Vector(const Vector &v) {
    //querermos llamar al operador igualpara optimizar codigo
    enter = nullptr;
    *this = v; // llamada al operador de asignacion
}

Vector & Vector::operator=(const Vector &v) {
    if (this != &v) {
        delete[] enter;
        setDim(v.dim);
        try {
            enter = new float[dim];
            for(int i = 0; i < dim; ++i) {
                enter[i] = v.enter[i];
            }
        } catch (std::bad_alloc& e) {
            throw "Memory allocation failed";
        }
    }
    return *this; 
}

Vector::~Vector() {
    delete[] enter;
}

void Vector::setDim(short dim){
    if(dim <= 0 || dim > MAX_DIM) {
        throw "dimension Invalida";
    }
    this->dim = dim;
}

int Vector::getDim() const{
    return dim;
}

void Vector::printDim() const{
    cout << "(";
    for(int i = 0; i < dim; ++i) {
        cout << enter[i] << ", ";
    }
    cout << "\b\b)";
}
    /*
    Explicacion del codigo linea por linea
    1. Se crea un nuevo arreglo de floats llamado 
    newVector con el tamaño newDim.
    2. Se determina la dimensión mínima entre
    la dimensión actual (dim) y la nueva dimensión (newDim)
    y se almacena en minDim.
    3. Se copian los elementos del arreglo antiguo
    (enter) al nuevo arreglo (newVector) hasta
    minDim.
    4. Si la nueva dimensión es mayor que la
    dimensión actual, se inicializan los elementos
    adicionales en newVector a 0.
    5. Se libera la memoria del arreglo antiguo
    (enter) para evitar fugas de memoria.
    6. Se actualiza el puntero enter para que apunte
    al nuevo arreglo (newVector).
    7. Se actualiza la dimensión del vector
    llamando a setDim con newDim.
    8. Finalmente, se devuelve el objeto Vector
    actualizado.
    */

void Vector::redimensionar(short newDim){
    float* newVector = new float[newDim];
    short minDim = (dim < newDim) ? dim : newDim;

    for(short i = 0; i < minDim; ++i) {
        newVector[i] = enter[i];
    }

    for(short i = minDim; i < newDim; ++i) {
        newVector[i] = 0;
    }

    delete[] enter;
    enter = newVector;
    setDim(newDim);
}


void Vector::setEnter(int i, float valor) {
    if(i < 0 || i >= dim) {
        throw "Index out of bounds";
    }
    enter[i] = valor;
}

float Vector::getEnter(int i) const {
    if(i < 0 || i >= dim) {
        throw "Index out of bounds";
    }
    return enter[i];
}

float & Vector::operator[](int i) {
    if(i < 0 || i >= dim) {
        throw "Index out of bounds";
    }
    return enter[i];
}

float Vector::operator[](int i) const {
    return getEnter(i);
}

void Vector::capture() {
    for(int i = 0; i < dim; ++i) {
        cout << "Enter the " << i+1 << " element: ";
        cin >> enter[i];
    }
}

Vector Vector::sumVectors(const Vector &b) const{
    if(dim != b.dim) {
        throw "The Dimensions are not the same";
    }
    Vector result(dim);
    for(int i = 0; i < dim; ++i) {
        result.enter[i] = enter[i] + b.enter[i];
    }
    return result;
}

Vector Vector::operator+(const Vector &v2) const{
    return this->sumVectors(v2);
}

Vector Vector::restVectors(const Vector &b) const{
    if(dim != b.dim) {
        throw "The Dimensions are not the same";
    }
    Vector result(dim);
    for(int i = 0; i < dim; ++i) {
        result.enter[i] = enter[i] - b.enter[i];
    }
    return result;
}

Vector Vector::operator-(const Vector &b) const{
    return this->restVectors(b);
}

float Vector::scaleProduct(const Vector &b) const{
    if(dim != b.dim) {
        throw "The Dimensions are not the same";
    }
    float result = 0;
    for(int i = 0; i < dim; ++i) {
        result += enter[i] * b.enter[i];
    }
    return result;
}

float Vector::operator*(const Vector &b) const{
    return this->scaleProduct(b);
}

float Vector::obtenerMagnitud() const{
    float suma = 0;
    for(int i = 0; i < dim; ++i) {
        suma += enter[i] * enter[i];
    }
    return sqrt(suma);
}

Vector Vector::scaleProduct(float scalar) {
    Vector result(dim);
    for(int i = 0; i < dim; ++i) {
        result.enter[i] = scalar * enter[i];
    }
    return result;
}

Vector operator*(float scalar, const Vector &v) {
    Vector result(v.dim);
    for(int i = 0; i < v.dim; ++i) {
        result.enter[i] = scalar * v.enter[i];
    }
    return result;
}

Vector& Vector::operator++() {
    for(int i = 0; i < dim; ++i) {
        ++enter[i];
    }
    return *this;
}

Vector Vector::operator++(int){
    Vector v = *this;
    for(int i = 0; i < dim; ++i) {
        ++enter[i];
    }
    return v;
}

std::ostream& operator<<(std::ostream &out, const Vector &v) {
    out << "(";
    for(int i = 0; i < v.dim; ++i) {
        out << v.enter[i] << ", ";
    }
    out << "\b\b)";
    return out;
}

std::istream& operator>>(std::istream &in, Vector &v) {
    for(int i = 0; i < v.dim; ++i) {
        cout << "Enter the " << i+1 << " element: ";
        in >> v.enter[i];
    }
    return in;
}