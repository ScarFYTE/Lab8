#include<iostream>

class Shape {

    public:
        virtual void area() = 0; // pure virtual function
};

class Circle : public Shape {

    private:
        float radius;

    public:
        Circle(float r) {
            radius = r;
        }

        void area() {
            std::cout << "Area of Circle: " << 3.14 * radius * radius << std::endl;
        }
};

class Rectangle : public Shape {

    private:
        float length;
        float width;

    public:
        Rectangle(float l, float w) {
            length = l;
            width = w;
        }

        void area() {
            std::cout << "Area of Rectangle: " << length * width << std::endl;
        }
};

class Triangle : public Shape {

    private:
        float base;
        float height;

    public:
        Triangle(float b, float h) {
            base = b;
            height = h;
        }

        void area() {
            std::cout << "Area of Triangle: " << 0.5 * base * height << std::endl;
        }
};

int main(){
    Shape* shape1 = new Circle(5.5);
    Shape* shape2 = new Rectangle(8, 4.2);
    Shape* shape3 = new Triangle(6, 3.5);
    shape1->area();
    shape2->area();
    shape3->area();
    delete shape1;
    delete shape2;
    delete shape3;
    return 0;
}