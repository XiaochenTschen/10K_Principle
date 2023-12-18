#include <iostream>
using namespace std;

/*int type as default*/
enum Type {General, Light, Medium, Heavy};
/*char type when defined*/
enum class Type1:char {General, Light, Medium, Heavy};

/*when use enum class, all variables are constrained in class scope*/
/*same name but in different scope is possiable*/
enum class Side {Right, Lift};
enum class Thing {Wrong, Right}; /*no error*/

int main()
{
    Type type = General;
    cout << "size of Type element is " << sizeof(type) << endl;
    cout << "size of Type enum structure is " << sizeof(Type) << endl;

    Type1 type1 = Type1::General;
    cout << "size of Type1 element is " << sizeof(type1) << endl;
    cout << "size of Type1 enum class is " << sizeof(Type1) << endl;

    Side s = Side::Right;
    Thing t = Thing::Right;
    /*cout << (s == t) << endl;*/ /*error, different enum variablees can not be conparied*/
    cout << static_cast<std::underlying_type<Side>::type>(s) << endl; // must explicit cast
    //cout << type << endl; // no error

    return 0;
}