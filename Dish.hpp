#ifndef DISH_H
#define DISH_H
#include <string>

class Dish {
private:
    std::string description;

public:
    Dish() {
        this->description = "";
    }

    Dish(std::string description) {
        this->description = description;
    }

    std::string get_description(){
        return this->description;
    }

    bool operator==(const Dish& other) const {
        return this->description == other.description;
    }
};

#endif // DISH_H