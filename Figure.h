#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>

class Figure {
 private:
     std::string** ppShapes;    /*  placeholder for Shapes obj */
     unsigned int shapes;
     void realloc();

 public:
     Figure() : ppShapes{nullptr}, shapes{0} {}
     ~Figure();
     void addShape(std::string* s);
     std::string getBoundingBox() const;
};

#endif
/* vim: set ts=4 sw=4 tw=79 ft=cpp et :*/
