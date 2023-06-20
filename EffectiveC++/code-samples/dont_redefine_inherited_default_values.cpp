#include <iostream>

// class Shape {
// public:
//     enum ShapeColor { Red, Green, Blue };
//     virtual void draw(ShapeColor color = Red) const = 0;
// };

// class Rectangle : public Shape {
// public:
//     virtual void draw(ShapeColor color = Green) const {
//         std::cout << "color = " << color << std::endl; // this will use color=Red
//     }
// };


// NVI idiom
class Shape {
    public:
        enum ShapeColor {Red, Green, Blue};
        void draw(ShapeColor color = Red) {
            doDraw(color);
        }
    private:
        virtual void doDraw(ShapeColor color) = 0;
};

class Rectangle : public Shape {
public:
    virtual void doDraw(ShapeColor color) {
        std::cout << "Derived's doDraw, color = " << color << "\n";
    } 
};

int main() {
    Shape* pr = new Rectangle();
    pr->draw(); // what color will be used? Red or Green?
    pr->draw(Shape::Blue); 
}