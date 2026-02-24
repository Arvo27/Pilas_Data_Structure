#ifndef STACKS_HPP
#define STACKS_HPP

#include <exception>

/**
 * @file Stacks.hpp
 * @brief Generic Stack implementation using dynamic arrays.
 */

/**
 * @class Stacks
 * @brief A template-based Stack data structure.
 * @tparam T Type of elements stored in the stack (default is int).
 */
template <typename T = int>
class Stacks {

    /**
     * @brief Overloads the insertion operator to print the stack content.
     */
    template <typename U>
    friend std::ostream & operator<<(std::ostream &os, const Stacks<U> &p);

    public:
        /**
         * @brief Default constructor. Initializes an empty stack.
         */
        Stacks();

        /**
         * @brief Destructor. Frees allocated memory.
         */
        ~Stacks();

        /**
         * @brief Copy constructor for deep copying.
         * @param other The stack to be copied.
         */
        Stacks(const Stacks<T> &other);

        /**
         * @brief Assignment operator for deep copying.
         * @param other The stack to be assigned.
         * @return Reference to the current stack.
         */
        Stacks<T>& operator=(const Stacks<T> &other);

        /**
         * @brief Adds an element to the top of the stack.
         * @param value The element to add.
         */
        void push(T value);

        /**
         * @brief Removes the top element from the stack.
         */
        void pop();

        /**
         * @brief Returns the top element without removing it.
         * @return The element at the top.
         */
        T top() const;

        /**
         * @brief Checks if the stack has no elements.
         * @return true if empty, false otherwise.
         */
        bool empty() const;

        /**
         * @brief Gets the current total capacity of the internal array.
         * @return Integer representing capacity.
         */
        int getCapacity() const;

        /**
         * @brief Gets the number of elements currently in the stack.
         * @return Integer representing the size.
         */
        int size() const;

        /**
         * @brief Displays the stack elements to the standard output.
         */
        void print() const;

        /**
         * @brief Removes all elements and resets the stack.
         */
        void clear();

        /**
         * @class StackEmpty
         * @brief Exception thrown when performing operations on an empty stack.
         */
        class StackEmpty{
            public:
                StackEmpty() throw();
                /**
                 * @brief Provides the error message.
                 * @return Pointer to a character string describing the error.
                 */
                virtual const char *whats() const throw();
        };

    private:
        int capacity, tope;
        T *element;

        /**
         * @brief Checks if the internal array is at full capacity.
         */
        bool full() const;

        /**
         * @brief Adjusts the internal array size when the stack is full.
         * @param new_capacity The new size for the array.
         */
        void resize(int new_capacity);
};

#include "Stacks.tpp"

#endif