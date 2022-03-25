#include <iostream>
using namespace std;
class Animal {
public:
    Animal() {
        cout << "animal - constructor\n";
    }
    void sound() {
        cout << "animal - void" << endl;
    }
};
class Cat : public Animal {
public:
    Cat() {
        cout << "cat - constructor\n";
    }
    void sound() {
        cout << "meow meow" << endl;
    }
};
class Dog : public Animal {
public:
    Dog() {
        cout << "dog - constructor\n";
    }
    void sound() {
        cout << "woof woof" << endl;
    }
};
int main() {
    Cat cat;
    cout << endl;
    Animal* animal1 = &cat;
    cout << endl;
    animal1->sound ();
    cout << endl;
    Dog dog;
    cout << endl;
    Animal* animal2 = &dog;
    cout << endl;
    animal2->sound ();
    return 0;
}