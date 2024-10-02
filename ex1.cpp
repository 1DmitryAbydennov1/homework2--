#include <cmath>
#include <iostream>
class Point
{
public:
    float x;
    float y;
    Point(float ax = 0, float ay = 0) {
        x = ax;
        y = ay;
    }
};

class Circle
{
private:
    Point center;
    float radius;

public:
    // Конструктор с параметрами
    Circle(const Point& acenter, float aradius)
    {
        center = acenter;
        radius = (aradius < 0) ? 0 : aradius;
    }


    // Конструктор по умолчанию
    Circle()
    {
        center = Point(0, 0);
        radius = 1;
    }


    // Конструктор копирования
    Circle(const Circle& circle) {
        center = circle.center;
        radius = circle.radius;
    }


    // Геттеры и сеттеры
    Point getCenter() const { return center; }
    float getRadius() const { return radius; }

    void setCenter(const Point& acenter) { center = acenter; }
    void setRadius(float aradius) { radius = aradius < 0 ? 0 : aradius; }

    // Метод для получения площади круга
    float getArea() const { return 3.1415926 * radius * radius; }

    // Метод для получения расстояния от точки до окружности
    float getDistance(const Point& p) const {
        float dist = std::sqrt(std::pow(center.x - p.x, 2) + std::pow(center.y - p.y, 2));
        if (dist <= radius)
        {
            return radius - dist;
        }
        else
            return dist - radius;
    }

    // Метод для проверки пересечения с другой окружностью
    bool isColliding(const Circle& c) const {
        float dist = std::sqrt(std::pow(center.x - c.center.x, 2) + std::pow(center.y - c.center.y, 2));
        return dist <= (radius + c.radius);
    }

    // Метод для перемещения окружности
    void move(const Point& p) {
        center.x += p.x;
        center.y += p.y;
    }
};
