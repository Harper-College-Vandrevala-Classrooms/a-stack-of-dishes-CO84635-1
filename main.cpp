#include <iostream>
#include <cassert>
#include "Dish.hpp"
#include "Stack.hpp"

int main() {
    
    // Stack of Zero Dishes:
    {
        Stack stack_zero_dishes = Stack(5);
        assert(stack_zero_dishes.is_empty());
        assert(!stack_zero_dishes.is_full());
        std::cout << "Should print out \"Stack is empty! Not _______!\" twice:" << std::endl;
        assert(stack_zero_dishes.pop().get_description() == "");
        assert(stack_zero_dishes.peek().get_description() == "");
    }

    // Stack of One Dish:
    {
        Stack stack_one_dish = Stack(5);
        Dish oneDish = Dish("A dish with a big smiley face on it");
        stack_one_dish.push(oneDish);

        assert(!stack_one_dish.is_empty());
        assert(!stack_one_dish.is_full());
        assert(stack_one_dish.size() == 1);
        assert(stack_one_dish.pop() == oneDish);
        assert(stack_one_dish.is_empty());
    }

    //Stack of Many Dishes:;
    {
        Stack stack_many_dishes = Stack(5);
        Dish oneDish = Dish("A dish with a big smiley face on it");
        Dish twoDish = Dish("A dish with a big frowny face on it");
        Dish threeDish = Dish("A dish with a no face on it");

        stack_many_dishes.push(oneDish);
        stack_many_dishes.push(twoDish);
        stack_many_dishes.push(threeDish);

        assert(!stack_many_dishes.is_empty());
        assert(!stack_many_dishes.is_full());
        assert(stack_many_dishes.pop() == threeDish);
        assert(stack_many_dishes.size() == 2);
        assert(stack_many_dishes.pop() == twoDish);
        assert(stack_many_dishes.size() == 1);
        assert(stack_many_dishes.pop() == oneDish);
        assert(stack_many_dishes.is_empty());
    }
    
    //Stack of Too Many Dishes:
    {
        Stack stack_too_many_dishes = Stack(5);
        Dish oneDish = Dish("A dish with a big smiley face on it");
        Dish twoDish = Dish("A dish with a big frowny face on it");
        Dish threeDish = Dish("A dish with a no face on it");
        Dish fourDish = Dish("A dish with a small angry on it");
        Dish fiveDish = Dish("A dish with a medium smerk on it");
        Dish sixDish = Dish("A dish too big to fit");

        stack_too_many_dishes.push(oneDish);
        stack_too_many_dishes.push(twoDish);
        stack_too_many_dishes.push(threeDish);
        stack_too_many_dishes.push(fourDish);
        stack_too_many_dishes.push(fiveDish);

        assert(stack_too_many_dishes.is_full());
        std::cout << "Should print \"Overflow! Stack is full! Not Pushing!\" once:" << std::endl;
        stack_too_many_dishes.push(sixDish);

        assert(stack_too_many_dishes.size() == 5);
        assert(stack_too_many_dishes.pop() == fiveDish);
    }

    std::cout << "All of the tests have passed!" << std::endl;
    return 0;
}