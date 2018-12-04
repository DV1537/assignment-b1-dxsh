#ifndef FIGURE_H
#define FIGURE_H
#include <string>

class Figure {
 private:
     std::string** ppShapes;    /*  placeholder for Shapes obj */
     unsigned int shapes;

 public:
     Figure() : ppShapes(nullptr), shapes(0) {}
     ~Figure() {};
};

#endif
/* vim: set ts=4 sw=4 tw=79 ft=cpp et :*/
