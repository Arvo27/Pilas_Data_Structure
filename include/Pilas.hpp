#ifndef PILAS_HPP
#define PILAS_HPP

#include <exception>

template <typename T = int, int tam = 2>
class Pilas {

    template <typename U, int ttam>
    friend std::ostream & operator<<(std::ostream &os, const Pilas<U, ttam> &p);
    public:
        Pilas();
        void push(T value);
        void pop();
        T top() const;
        bool empty() const;
        bool full() const;
        int size() const;
        void print() const;
        void clear();

        class StackEmpty{
            public:
                StackEmpty() throw();
                virtual const char *QuePaso() const throw();
        };

        // Al igual que pila vacia ahora crear pila llena
        class StackFull{
            public:
                StackFull() throw();
                virtual const char *QuePaso() const throw();
        };


    private:
        T *element;
        int tope;
};

#include "Pilas.tpp"

#endif