#pragma once
#include <iostream>

template<class T>
class TStack{
    int capacity;
    T* stack;
    int lastIndex;
public:
    TStack(int _capacity = 10){
        if (_capacity <= 0){
            throw "wrong size";
        }
        capacity = _capacity;
        stack = new T[capacity];
        lastIndex = -1;
    }

    ~TStack(){
        delete[] stack;
    }

    TStack(const TStack<T>* bf){
        capacity = bf->capacity;
        stack = new T[capacity];
        for(int i = 0; i < capacity; i++){
            stack[i] = bf.stack[i];
        }
    }

    bool empty() const{
        return lastIndex == -1;
    }

    bool full() const{
        return lastIndex - 1 == 10;
    }

    void cleaning(){
        lastIndex = -1;
    }

    void push(const T& elem){
        if(lastIndex + 1 >= capacity){
            throw "stack full";
        }
        stack[++lastIndex] = elem;
    }

    T pop(){
        if(lastIndex == -1){
            throw "stack empty";
        }

        return stack[lastIndex--];
    }

    T& top(){
        if(lastIndex == -1){
            throw "stack empty";
        }
        return stack[lastIndex];
    }

};