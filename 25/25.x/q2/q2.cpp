#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x {};
    int y {};
};

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "Point(" << point.x << ", " << point.y << ")";
    return out;
}

class Shape {
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    virtual ~Shape() = default;

    friend std::ostream& operator<<(std::ostream& out, const Shape& shape) {
        return shape.print(out);
    }
};

class Triangle : public Shape {
private:
    Point m_p1 {};
    Point m_p2 {};
    Point m_p3 {};
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : m_p1 {p1}
        , m_p2 {p2}
        , m_p3 {p3}
    {}

    std::ostream& print(std::ostream& out) const override {
        out << "Triangle (" << m_p1 << ", " << m_p2 << ", " << m_p3 << ')';
        return out;
    }
};

class Circle : public Shape {
private:
    Point m_center {};
    int m_radius {};
public:
    Circle(const Point& center, int radius)
        : m_center {center}
        , m_radius {radius}
    {}

    std::ostream& print(std::ostream& out) const override {
        out << "Circle(" << m_center << ", radius " << m_radius << ')';
        return out;
    }

    int getRadius() const {return m_radius;}

};

int getLargestRadius(const std::vector<Shape*>& v) {
    int largest {0};
    for(const auto* shape : v) {
        auto* circle {dynamic_cast<const Circle*>(shape)};
        if(circle) {
            largest = std::max(largest, circle->getRadius());
        }
    }
    return largest;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here

    for(const auto* shape : v) {
        std::cout << *shape << '\n';
    }

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
    for(const auto* shape : v) {
        delete shape;
    }

	return 0;
}