#include<iostream>
using namespace std;

int main()
{
    enum Woche{
        Montag = 1,
        Dienstag,
        Mitwoche,
        Donnerstag,
        Freitag,
        Samstag,
        Sonntag
    };
    cout << "size of this enum struct is " << sizeof(Woche) << endl;
    cout <<"Value of Mitwoche is " << Mitwoche << endl;
    cout << Woche(2) << endl;
    return 0;
}