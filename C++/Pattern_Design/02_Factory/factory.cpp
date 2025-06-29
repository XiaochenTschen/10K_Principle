#include <cmath>

struct PointFactory;

struct Point
{
protected:
    float x, y;
    Point(const float x, const float y)
        : x{x}, y{y} {}

public:
    friend class PointFactory;
    // 其它成员略
};

struct PointFactory {
    static Point NewCartesian(float x, float y)
    {
        return Point{ x, y };  // 调用的是构造函数 Point(float, float)
    }

    static Point NewPolar(float r, float theta)
    {
        return Point{ r * cos(theta), r * sin(theta) };
    }
};

int main() {
    Point p1 = PointFactory::NewCartesian(3, 4);
    Point p2 = PointFactory::NewPolar(5, M_PI / 4);

    return 0;
}