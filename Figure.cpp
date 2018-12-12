#include "Figure.h"

void Figure::realloc() {                                                          
    auto tmp = new Shape*[this->capacity](); // zero init                         
                                                                                  
    for (size_t i = 0; i < this->nShapes; i++) {                                  
        tmp[i] = this->ppShapes[i];                                               
    }                                                                             
                                                                                  
    delete[] this->ppShapes;                                                      
    this->ppShapes = tmp;                                                         
}                                                                                 
                                                                                  
void Figure::addShape(Shape* const s) {                                           
    if (this->nShapes >= this->capacity) {                                        
        this->capacity *= 2;                                                      
        realloc();                                                                
    }                                                                             
                                                                                  
    this->nShapes++;                                                                                                                                                                                                                          
    this->ppShapes[this->nShapes - 1] = s;                                        
}            

std::string Figure::getBoundingBox() const {
    double minX = this->ppShapes[0]->getXcoords();
    double minY =  this->ppShapes[0]->getYcoords();
    double maxX = minX;
    double maxY = minY;

    for (size_t i = 1; i < this->nShapes; i++) {
        auto x = this->ppShapes[i]->getXcoords();
        auto y = this->ppShapes[i]->getYcoords();

        if (x > maxX)
            maxX = x;
        if (x < minX)
            minX = x;
        if (y > maxY)
            maxY = y;
        if (y < minY)
            minY = y;
    }

    auto topLeft = minX + minY;
    auto bttmRight = maxX + maxY;

    std::string str = "Top left corner: " + std::to_string(topLeft)
        + "\nBottom right corner:  " + std::to_string(bttmRight);

    return str;

}

Figure::~Figure() {
    delete[] this->ppShapes;
}
/* vim: set ts=4 sw=4 tw=79 ft=cpp et :*/
