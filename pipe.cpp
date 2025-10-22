#include "pipe.h"
#include "shablones.h"
#include <iostream>
using namespace std; 

void Pipe::input() {
    cin.ignore(10000, '\n');
    cout << "Укажите название трубы: ";
    getline(cin, name);
    
    length = getValidInput<float>("Укажите длину (км): ", [](float x) { return x > 0; });
    diameter = getValidInput<int>("Укажите диаметр (мм): ", [](int x) { return x > 0; });
    
    repair = false;
}

void Pipe::display() const {
    cout << "ID: " << id << "\nНазвание: " << name << "\nДлина: " << length 
         << " км\nДиаметр: " << diameter << " мм\nВ ремонте: " << (repair ? "Да" : "Нет") << endl;
}

std::ostream& operator<<(std::ostream& os, const Pipe& pipe) {
    os << pipe.id << endl << pipe.name << endl << pipe.length << endl 
       << pipe.diameter << endl << pipe.repair;
    return os;
}

std::istream& operator>>(std::istream& is, Pipe& pipe) {
    is >> pipe.id;
    is.ignore();
    getline(is, pipe.name);
    is >> pipe.length >> pipe.diameter >> pipe.repair;
    return is;
}