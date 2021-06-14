#include <iostream>
using namespace std;

class ClosedShape {
    public:
        void draw() const {
            cout << "Closed" << '\n';
        }
};

class Triangle : public ClosedShape {
    public:
        void draw() const {
            cout << "Triangle" << '\n';
        }
};


class Circle : public ClosedShape {
    public:
        void draw() const {
            cout << "Circle" << '\n';
        }
};



int main() {
    ClosedShape* pClosedShape;
    pClosedShape->draw();

    Triangle p;
    p.draw();

    pClosedShape = new Circle();
    pClosedShape->draw();

    
}