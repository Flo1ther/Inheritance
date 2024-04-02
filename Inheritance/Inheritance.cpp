#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(const std::string& _name) : name(_name) {}

    virtual void speak() const = 0; // Віртуальна функція для "говоріння" тварини
};

class Dog : public Animal {
private:
    std::string breed;

public:
    Dog(const std::string& _name, const std::string& _breed) : Animal(_name), breed(_breed) {}

    void speak() const override {
        std::cout << "Woof! I'm a " << breed << " dog named " << name << std::endl;
    }
};

class Cat : public Animal {
private:
    std::string color;

public:
    Cat(const std::string& _name, const std::string& _color) : Animal(_name), color(_color) {}

    void speak() const override {
        std::cout << "Meow! I'm a " << color << " cat named " << name << std::endl;
    }
};

class Parrot : public Animal {
private:
    std::string species;

public:
    Parrot(const std::string& _name, const std::string& _species) : Animal(_name), species(_species) {}

    void speak() const override {
        std::cout << "Squawk! I'm a " << species << " parrot named " << name << std::endl;
    }
};

int main() {
    Dog dog("Buddy", "Labrador");
    Cat cat("Whiskers", "Tabby");
    Parrot parrot("Polly", "African Grey");

    dog.speak();
    cat.speak();
    parrot.speak();

    return 0;
}
