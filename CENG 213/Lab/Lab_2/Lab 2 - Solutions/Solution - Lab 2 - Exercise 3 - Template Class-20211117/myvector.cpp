#include "myvector.h"

/*              Default Constructor for MyVector Class
 
 In the constructor, you should initialize class members as the following:
 1) size and initial value should be set to given parameters.
 2) Your vector should be initialized with the given size with embedded initial
 values inside of it.                                                  */
template <class T>
MyVector<T>::MyVector(const T& init_val, const int vector_size)
{
    int i = 0;
    this->size     = vector_size;
    this->vector   = new T[vector_size];
    this->init_val = init_val;
    for (i = 0; i < vector_size; i++)
        this->vector[i] = init_val;
}

/*              Destructor for MyVector Class
 In the destructor you should delete all the memory you allocated for your
 vector. Don't forget to set the pointer to nullptr.                       */
template <class T>
MyVector<T>::~MyVector()
{
    this->size = 0;
    delete [] this->vector;
}

/*                 Get Size Function
 This function should return the size of the vector.                    */
template <class T>
int MyVector<T>::get_size() const
{
    return this->size;
}

/*                        Resize Function
 This function should resize your vector with the given size. Key points:
 1) If given parameter value (new size) is less than or equal to the current
 size, your function has to return 0 and shouldn't change anything.
 2) Else, you have to resize your vector with the given value, copy the
 existing elements in it and initialize the remaining indexes with the
 T init_val member of the class. If the operation is successfull, return 1.
 3) Please consider cases that can cause memory leak.
 */
template <class T>
int MyVector<T>::resize(const int new_size)
{
    if (new_size <= this->size)
        return 0;
    
    int i = 0;
    T* new_vector = new T[new_size];
    for (i = 0; i < this->size; i++)
        new_vector[i] = this->vector[i];
    for (i = size; i < new_size; i++)
        new_vector[i] = this->init_val;
    
    delete [] this->vector;
    this->size   = new_size;
    this->vector = new_vector;
    new_vector = NULL;
    return 1;
}

/*                 Set Initial Value Function
 This function sets the T init_val member of the class to given new one.
 */
template <class T>
void MyVector<T>::set_init_val(const T& new_val)
{
    this->init_val = new_val;
}

/*                   [] Operator Overloading
 This function will overload the operator []. It should return
 the ith member of the vector.                                          */
template <class T>
T& MyVector<T>::operator[] (int i) const
{
    return this->vector[i];
}

/*                         Append Function
 This function appends the given value at the end of the vector. Key points:
 1) You have to increment your vector's size.
 2) Please keep in mind that additional memory operations might be required.
 3) Be careful about pointers and memory leaks.
 Hint: You need to do something similar to what you did in double_size() function
 inExercise1
 */
template <class T>
void MyVector<T>::append(const T& val)
{
    int i = 0;
    T* temp = new T[this->size + 1];
    for (i = 0; i < this->size; i++)
        temp[i] = this->vector[i];
    temp[this->size] = val;
    this->size++;
    delete [] this->vector;
    this->vector = temp;
    temp = NULL;
}

/*              << Operator Overloading
 This function used for creating a output format for
 our MyVector implementation. This is implemented for you. DO NOT
 MODIFY any of the code in this function.                        */
template <class T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& myVector)
{
    int i, n;
    n = myVector.get_size();
    os << "[";
    for (i = 0; i < n; i++)
    {
        os << myVector[i];
        if (i != n - 1)
            os << ", ";
    }
    os << "]" << std::endl;
    return os;
}

