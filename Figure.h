#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include "shape.h"

class Figure {
 private:
     Shape** ppShapes;
     unsigned int nShapes;
     void realloc();

 public:
     Figure() : ppShapes{nullptr}, nShapes{0} {}
     ~Figure();
     void addShape(Shape& const s);
     std::string getBoundingBox() const;
};

#endif
/* vim: set ts=4 sw=4 tw=79 ft=cpp et :*/
