#include <iostream>
#include <string>
#include <string_view>

class Fruit {
private:
    std::string m_name {};
    std::string m_color {};
public:
    Fruit(std::string_view name = "", std::string_view color = "")
        : m_name {name}
        , m_color {color}
    {}

    const std::string& name() const {return m_name;}
    const std::string& color() const {return m_color;}
};

class Apple : public Fruit {
private:
    double m_fiber {};
public:
    Apple(std::string_view name, std::string_view color, double fiber)
        : Fruit(name, color)
        , m_fiber {fiber}
    {}

    double fiber() const {return m_fiber;}
};

std::ostream& operator<< (std::ostream& out, const Apple& apple) {
    out << "Apple(" << apple.name() << ", " << apple.color() << ", " << apple.fiber() << ")";
    return out;
}

class Banana : public Fruit {
public:
    Banana(std::string_view name, std::string_view color)
        : Fruit(name, color)
    {}
};


std::ostream& operator<< (std::ostream& out, const Fruit& banana) {
    out << "Banana(" << banana.name() << ", " << banana.color() << ")";
    return out;
}

int main()
{
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}