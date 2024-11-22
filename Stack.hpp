#ifndef STACK_H
#define STACK_H
#include "Dish.hpp"
#include <iostream>
#include <array>

class Stack {
private:
    int top, capacity;
    Dish *arr_dish;

public:
    Stack(int size) {
        this->arr_dish = new Dish[size];
        this->capacity = size;
        this->top = -1;
    }

    void push(Dish dish) {
        if (!is_full()) {
            arr_dish[++top] = dish;
        } else {
            std::cout << "Overflow! Stack is full! Not Pushing!" << std::endl;
        }
    }

    Dish pop() {
        if (!is_empty()) {
            return arr_dish[top--];
        } else {
            std::cout << "Stack is empty! Not popping!" << std::endl;
            return Dish();
        }
    }

    Dish peek() {
        if (!is_empty()){
            return arr_dish[top];
        } else {
            std::cout << "Stack is empty! Not peeking!" << std::endl;
            return Dish();
        }
    }

    int size() {
        return top + 1;
    }

    bool is_full() {
        return top == capacity -1;
    }

    bool is_empty() {
        return top == -1;
    }
};

#endif // STACK_H