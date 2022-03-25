#include <iostream>

using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal - constructor\n";
	}
	// virtual is a important part in inheritance
	virtual void sound() { 
		cout << "some sound" << endl;
	}	
};

class Dog : public Animal {
public:
	Dog() {
		cout << "Dog - constructor\n";
	}
	void sound() {
		cout << "bow wow" << endl;
	}
};

class Cat : public Animal {
public:
	Cat() {
		cout << "Cat - constructor\n";
	}
	void sound() {
		cout << "meow meow" << endl;
	}
};

class Duck : public Animal {
public:
	Duck() {
		cout << "Duck - constructor\n";
	}
	void sound() {
		cout << "quack quack" << endl;
	}
};

int main() {
	Animal* animals[4];
	cout << endl;
	animals[0] = new Animal();
	cout << endl;
	animals[1] = new Dog();
	cout << endl;
	animals[2] = new Cat();
	cout << endl;
	animals[3] = new Duck();
	cout << endl;
	for (int i = 0; i < 4; i++) {
		animals[i]->sound();
		cout << "---------- \n";
	}
	return 0;
}