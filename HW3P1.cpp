#include <iostream>
#include <string>
using namespace std;
using std::cout;
using std::cin;

class Animal{ //parent class
    private:
        int weight;
        int age;

    public:
        Animal(){  //default constructor
            weight = 0;
            age = 0;
        };
        Animal(int a, int b){ //parameterized constructor
            weight = a;
            age = b;
        };
        void animaleat();
        void animalsleep();
        void showdata();
        ~Animal(){};
};

void Animal::animaleat(){
    cout << "I Can Eat" << endl;
}

void Animal::animalsleep(){
    cout << "I Can Sleep" << endl;
}

void Animal::showdata(){ // this will output the weight and age
    cout << "The animals weight is: " << weight << endl;
    cout << "The animals age is: " << age << endl;
}

class Dog: private Animal{  //derived class

    string dogtype;

    public:
        Dog():dogtype(NULL){}; //default constructor
        Dog(string typer){ //parameterized constructor
            dogtype = typer;
        };
        void saydog();
        void saydogtype();
        ~Dog(){};
};

void Dog::saydog(){
    cout << "I am a dog" << endl;

} 

void Dog::saydogtype(){ //this will output the dog breed
    cout << "The dog type is: " << dogtype <<endl;

}

int main(){
    cout << "Sajed Atwa" << " FILE: " << __FILE__ << " DATE: " << __DATE__ << " CSC 21200 LM24126" << endl;
    int Weight;
    int Age;
    string doggo;
    cout << "Enter a dog breed: "<<endl;
    getline(cin, doggo);
    cout << "enter a weight value: "<<endl;
    cin >> Weight;
    cout << "enter a age value: "<<endl; 
    cin >> Age;
    Animal foo(Weight,Age); //class calls
    foo.animaleat();
    foo.animalsleep();
    foo.showdata();
    Dog moo(doggo);
    moo.saydog();
    moo.saydogtype();
    return 0;
}