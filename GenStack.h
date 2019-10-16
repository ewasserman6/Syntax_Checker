/*Eric Wasserman
2300841
ewasserman@chapman.edu
CPSC 350 Section 3
Template Stack class - Implementation */

#include <iostream>

using namespace std;
template <class T>

class GenStack{
public:
    GenStack(); // constructor
    GenStack(int maxSize); // overloaded constructor
    ~GenStack(); // destructor

    void push(T);
    T pop();
    T peek(); // AKA top()
    T copy();

    bool isFull();
    bool isEmpty();
    T readFile(string fileName);
    T checkParenth(string delimString);

    int size = 10;
    int top;
    int maxSize;


    T *myArray; // pointer - pointing to the furst address of that array
};

//constructor
template <class T>
GenStack<T>::GenStack(){
    myArray = new T[size];
    maxSize = size;
    top = -1;
}

// overload constructor
template <class T>
GenStack<T>::GenStack(int maxSize){
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
}

//deconstructor
template <class T>
GenStack<T>::~GenStack(){
    delete[] myArray;
}

// this pushes an element into the stack
template <class T>
void GenStack<T>::push(T d){ // make sure theres room for it
    if(isFull()){
        copy(); // if the array is full copy and double it
    }
    myArray[++top] = d; // iterating to 0 - first element of the array. pre increment becuase it increments to 0 before evaluating -1.
}

// returns and removes an element from the top of the stack
template <class T>
T GenStack<T>::pop(){
    if(isEmpty()) // error checking - can't remove ana element from an empty stack
    {
        cout << "Stack is empty" << endl;
    }
    return myArray[top--];
}

// returns the top of the stack but does not remove it
template <class T>
T GenStack<T>::peek(){
    if(!isEmpty()){
        return myArray[top];
    }
    else
        exit(EXIT_FAILURE); // if stack is empty exit

}

// if the stack is full double the size
template <class T>
T GenStack<T>::copy(){
    if(isFull()){
        size = size * 2;
    }
}

// if stack is full - true / if stack isn't false
template <class T>
bool GenStack<T>::isFull(){
    return (top == size - 1); // returns true or false - Full - true
}

// true - empty, false - full
template <class T>
bool GenStack<T>::isEmpty(){
    return (top == - 1);
}
