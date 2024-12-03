#include <iostream>
#include <string>
#include <memory>

class Color{
    public:
    virtual ~Color() = default;
    virtual std::string fill() const = 0; 
};

class White : public Color{
    public:
    std::string fill() const override{
        return "White";
    }
};

class Pink : public Color{
    public:
    std::string fill() const override {
        return "Pink";
    }
};

class Shape{
    protected:
    std::shared_ptr<Color> color;

    public:
    explicit Shape(std::shared_ptr<Color> color) : color(std::move(color)){}
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape{
    public:
    explicit Circle(std::shared_ptr<Color> color) : Shape(std::move(color)){}

    void draw() const override {
        std::cout << "Drawing a circle with " << color->fill() << " color \n";
    }
};

class Rectangle : public Shape{
    public:
    explicit Rectangle(std::shared_ptr<Color> color) : Shape(std::move(color)){}

    void draw() const override{
        std::cout << "Drawing a rectangle with " << color->fill() << " color \n";
    }
};

int main(){
    std::shared_ptr<Color> white = std::make_shared<White>();
    std::shared_ptr<Shape> whiteCircle = std::make_shared<Circle>(white);
    whiteCircle->draw();

    std::shared_ptr<Color> pink = std::make_shared<Pink>();
    std::shared_ptr<Shape> pinkRectangle = std::make_shared<Rectangle>(pink);
    pinkRectangle->draw();

    return 0;
}
