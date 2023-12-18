#include <iostream>
using namespace std;

class Test
{
public:
    Test(int a, char b):i(a), c(b){}
    void getInt(){
        cout << i;
    }
private:
    int i;
    char c;
    double d;
};

int main()
{
    Test t0(1,'c');
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(t0) << endl;

    return 0;
}
