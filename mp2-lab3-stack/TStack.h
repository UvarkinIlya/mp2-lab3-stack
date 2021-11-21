#pragma once

#include <iostream>

template<class T>
class TStack{
    int capacity;
    T* stack;
    int lastIndex;
public:
    Stack(int _capacity = 10){
        //Написать исключение при отрицат
        capacity = _capacity;
        stack = new T[capacity];
        lastIndex = -1;
    }

    ~Stack(){
        delete[] stack;
    }

    Stack(const TStack<T>* bf){
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
        if(lastIndex < capacity - 1){
            throw lastIndex;
        }
        stack[++lastIndex] = elem;
    }

    T pop(){
        if(lastIndex == -1){
            throw lastIndex;
        }

        return Stack[lastIndex--];
    }

    T& top(){
        return *Stack[lastIndex];
    }

};