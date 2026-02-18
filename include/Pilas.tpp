#include "Pilas.hpp"
#include <iostream>

template <typename T>
Pilas<T>::Pilas() {
    tope = -1;
}

template <typename T>
void Pilas<T>::push(T value) {
    if (!full()) {
        ++tope;
        element[tope] = value;
    } else {
         throw StackFull();
    }
}

template <typename T>
void Pilas<T>::pop() {
    if (!empty()) {
        --tope;
    } else {
        throw StackEmpty();
    }
}

template <typename T>
T Pilas<T>::top() const {
    if (!empty()) {
        return element[tope];
    } else {
        throw StackEmpty();
    }
}

template <typename T>
bool Pilas<T>::empty() const {
    return tope == -1;
}

template <typename T>
int Pilas<T>::size() const {
    return tope + 1;
}

template <typename T>
void Pilas<T>::clear() {
    tope = -1;
}

template <typename T>
void Pilas<T>::print() const {
    if (!empty()) {
        std::cout << "Stack elements: ";
        for (int i = tope; i >= 0; --i) {
            std::cout << element[i] << ", ";
        }
        std::cout << "\b\b " << std::endl;
    } else {
        throw StackEmpty();
    }
}


template <typename T>
Pilas<T>::StackEmpty::StackEmpty() throw(){}

template <typename T>
Pilas<T>::StackFull::StackFull() throw() {}

template <typename T>
const char *Pilas<T>::StackEmpty::QuePaso() const throw() {
    return "Error: The stack is empty.";
}

template <typename T>
const char *Pilas<T>::StackFull::QuePaso() const throw() {
    return "Error: The stack is full.";
}

// incluir <<
template <typename U>

std::ostream & operator<<(std::ostream &os, const Pilas<U> &p) {
        os << "Tope -> ";
        for (int i = p.tope; i >= 0; --i) {
            os << p.element[i] << ", ";
        }
        if (!p.empty()) {
            os << "\b\b " << std::endl;
    }
    return os;
}
