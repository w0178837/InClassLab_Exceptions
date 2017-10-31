//In class lab:
//Does the order of the catch statements matter?
    // No, only one will be caught, so only one will be output, regardless of order
//Try mixing up the order of the catch statements.
//what happens? why?
    // The (...) catch must be at the end of the catch block
    // If the two specific catch statements are removed, the default (...) one is run
//Try and 'rethrow' the exception (in catch of E1)
//Does 'throw E1' or 'throw e1' or just 'throw' work?
//If not, why?
    // throw E1 and throw do not work. As they are not defined.
    // throw e1 will throw the struct to the calling try/catch in main which will catch it as a generic exepction
//How may you still catch the error?
    // By surrounding the code in a try catch
//If a language has a finally catch (... in c++), 
//why does this get called regardless?
    // to catch any errors that haven't been specifically thought of and determined.

//Example using structures

//note: use F5 to launch this or it may show the correct output 
//indicating that the error was caught and yet also indicate an error 
//on a code page that you did not write



#include <iostream>
#include <exception>
using namespace std;

struct E1
{
    const char* message;
    E1() : message("Struct E1"){}
};

struct E2
{
    const char* message;
    E2() : message("Struct E2"){}
};

void f()
{
    try
    {
        cout << "In try block of f()" << endl;
        cout <<"Throwing exception of type E1" << endl;
        E1 e1;
        E2 e2;
        throw e1;// programmer thrown
        throw e2;

    }//end try

    catch(E1 e1)
    {
        throw e1;
        cout << e1.message << endl;
    }

    catch(E2 e2)
    {
        cout << e2.message << endl;
    }

    catch(...)// or use exception e
    {
        cout << "An unknown error happened" << endl;
    }




}//end function f

int main(){

    try{
        f();
    }
    catch(...)
    {
        cout << "Cought you anyway" << endl;
    }

    cin.get();
    return 0;
}//end main