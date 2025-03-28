
#include <iostream>

using namespace std;

/*
Binary Operator Overloading using FRIEND FUNCTION.
ARGUMENT PASSED TO THE FRIEND FUNCTION : 2
*/

class Box{
    int length, width, height;

    public:

        // default constructor (explicitly defined), since it is called by the operator func.
        Box(){};

        // parameterized constructor
        Box(int a, int b, int c){
            length = a;
            width = b;
            height = c;
        }

        // friend addition operator function
        friend Box operator+(Box &obj1, Box &obj2);

        // void function (returns nothing)
        void show(){
            cout << "length : " << length << endl;
            cout << "width : " <<  width << endl;
            cout << "height : " << height << endl;
        }
};


// creating the operator function
Box operator+(Box &obj1, Box &obj2){
    Box obj3;
    obj3.length = obj1.length + obj2.length;
    obj3.width = obj1.width + obj2.width;
    obj3.height = obj1.height + obj2.height;
    return obj3;
}

int main(){
    Box first(1,2,3), second(3,4,5);  // using parameterized constructor
    Box third = first + second;
    cout << "dimension of first box: " << endl;
    first.show();
    cout << "dimension of second box: " << endl;
    second.show();
    cout << "dimension of third box: " << endl;
    third.show();
    return 0;
}
