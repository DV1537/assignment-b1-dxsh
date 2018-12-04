#include "Figure.h"

void Figure::realloc() {
    this->shapes++;
    auto tmp = new std::string*[this->shapes]();

    for (int i = 0; i < this->shapes - 1; i++) {
        tmp[i] = this->ppShapes[i];
    }
    
    delete[] this->ppShapes;
    this->ppShapes = tmp;
}

void Figure::addShape(std::string* s) {
    realloc();

    ppShapes[this->shapes - 1] = s;
    for (int i = 0; i < this->shapes; i++) {
        std::cout << "len: " << this->ppShapes[i]->size() << '\n';
    }
}


int main() {
    Figure figure;
    std::string foo = ("foo");

    figure.addShape(&foo);

}


Figure::~Figure() {
    delete[] this->ppShapes;
}
/* vim: set ts=4 sw=4 tw=79 ft=cpp et :*/
