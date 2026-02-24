#include "Stacks.hpp"
#include <iostream>

/**
 * @brief Default constructor.
 * Initializes capacity to 15 and tope to -1.
 */
template <typename T>
Stacks<T>::Stacks(): capacity(15), tope(-1) {
    try {
        element = new T[capacity];
    } catch (const std::bad_alloc& e) {
        element = nullptr;
        throw "Memory allocation failed: " + std::string(e.what());
    }
}

/**
 * @brief Destructor.
 * Releases the dynamically allocated array.
 */
template <typename T>
Stacks<T>::~Stacks() {
    delete[] element;
}

/**
 * @brief Copy constructor.
 * Uses the assignment operator to perform a deep copy.
 */
template <typename T>
Stacks<T>::Stacks(const Stacks<T> &other): element(nullptr) {
    *this = other;
}

/**
 * @brief Assignment operator.
 * Performs a deep copy of the stack elements.
 */
template <typename T>
Stacks<T>& Stacks<T>::operator=(const Stacks<T> &other) {
    if (this != &other) {
        T *new_element = nullptr;
        try {
            new_element = new T[other.capacity];
            for (int i = 0; i <= other.tope; ++i) {
                new_element[i] = other.element[i];
            }
            delete[] element; 
            element = new_element;
            capacity = other.capacity;
            tope = other.tope;
        } catch (const std::bad_alloc& e) {
            throw; 
        }
    }
    return *this;
}

/**
 * @brief Inserts a new element.
 * Resizes the stack if it's full.
 */
template <typename T>
void Stacks<T>::push(T value) {
    if (!full()) {
        ++tope;
        element[tope] = value;
    } else {
        resize(capacity * 2);
        push(value);
    }
}

/**
 * @brief Removes the top element.
 * @throws StackEmpty If the stack is empty.
 */
template <typename T>
void Stacks<T>::pop() {
    if (!empty()) {
        --tope;
    } else {
        throw StackEmpty();
    }
}

/**
 * @brief Retrieves the top element.
 * @throws StackEmpty If the stack is empty.
 */
template <typename T>
T Stacks<T>::top() const {
    if (!empty()) {
        return element[tope];
    } else {
        throw StackEmpty();
    }
}

/**
 * @brief Checks if the stack is empty.
 */
template <typename T>
bool Stacks<T>::empty() const {
    return tope == -1;
}

/**
 * @brief Returns current number of elements.
 */
template <typename T>
int Stacks<T>::size() const {
    return tope + 1;
}

/**
 * @brief Resets the stack pointer to empty state.
 */
template <typename T>
void Stacks<T>::clear() {
    tope = -1;
}

/**
 * @brief Prints stack content to standard output.
 */
template <typename T>
void Stacks<T>::print() const {
    if (!empty()) {
        std::cout << "Stack elements: ";
        for (int i = tope; i >= 0; --i) {
            std::cout << element[i] << ", ";
        }
        std::cout << "\b\b " << std::endl;
    } else {
        std::cout << "The stack is empty." << std::endl;
    }
}

/**
 * @brief StackEmpty constructor.
 */
template <typename T>
Stacks<T>::StackEmpty::StackEmpty() throw(){}

/**
 * @brief Returns the exception error message.
 */
template <typename T>
const char *Stacks<T>::StackEmpty::whats() const throw() {
    return "Error: The stack is empty.";
}

/**
 * @brief Gets current capacity of the stack.
 */
template <typename T>
int Stacks<T>::getCapacity() const {
    return this->capacity;
}

/**
 * @brief Stream insertion operator overload.
 */
template <typename U>
std::ostream & operator<<(std::ostream &os, const Stacks<U> &p) {
        os << "Tope -> ";
        for (int i = p.tope; i >= 0; --i) {
            os << p.element[i] << ", ";
        }
        if (!p.empty()) {
            os << "\b\b " << std::endl;
    }
    return os;
}

//*******************************************
// Utilery Methods
//*******************************************

/**
 * @brief Checks if stack is at its maximum current capacity.
 */
template <typename T>
bool Stacks<T>::full() const {
    return tope == capacity - 1;
}

/**
 * @brief Resizes the internal array to a new capacity.
 */
template <typename T>
void Stacks<T>::resize(int new_capacity) {
    try {
        T *new_element = new T[new_capacity];
        for (int i = 0; i <= tope; ++i) {
            new_element[i] = element[i];
        }
        delete[] element;
        element = new_element;
        capacity = new_capacity;
    } catch (const std::bad_alloc& e) {
        throw "Memory allocation failed: " + std::string(e.what());
    }
}