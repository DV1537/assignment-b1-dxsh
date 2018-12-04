#include "Figure.h"

void Figure::realloc() {
    auto tmp = new Shape*[this->nShapes](); // zero init

    for (size_t i = 0; i < (this->nShapes - 1); i++) {
        tmp[i] = this->ppShapes[i];
    }
    
    delete[] this->ppShapes;
    this->ppShapes = tmp;
}

void Figure::addShape(Shape* const s) {
    this->nShapes++;
    realloc();
    ppShapes[this->nShapes - 1] = s;
}

std::string Figure::getBoundingBox() const {
    double minX{this->ppShapes[0]->getXCoords()},
          minY{this->ppShapes[0]->getYCoords()},
          maxX{minX},
          maxY{minY};

    for (size_t i = 1; i < this->nShapes; i++) {
        auto x = this->ppShapes[i]->getXCoords();
        auto y = this->ppShapes[i]->getYCoords();

        if (x > maxX)
            maxX = x;
        if (x < minX)
            minX = x;
        if (y > maxY)
            maxY = y;
        if (y < minY)
            minY = y;
    }


    // TODO: calculate bbox

}

Figure::~Figure() {
    delete[] this->ppShapes;
}
/* vim: set ts=4 sw=4 tw=79 ft=cpp et :*/
