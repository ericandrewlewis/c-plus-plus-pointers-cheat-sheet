//
//  main.cpp
//  PointerCheatSheet
//
//  Created by Eric Lewis on 8/15/15.
//  Copyright (c) 2015 Eric Lewis. All rights reserved.
//

#include <iostream>

/*
 * Set a variable to five.
 *
 * This function shows how pass by value works.
 * The variable the function was invoked with is unmodified.
 *
 * @param int x An integer.
 */
void setValueToFive(int x)
{
    x = 5;
}

/*
 * Set the memory address' value for a given pointer to 5.
 *
 * @param int* x An integer that will be set to five.
 */
void setPointerValueToFive(int* x)
{
    *x = 5;
}

/*
 * Set the value for a given variable to 5.
 *
 * @param int& x An integer that will be set to five.
 */
void setValueToFiveWithReference(int& x)
{
    x = 5;
}

int main(int argc, const char * argv[]) {
    /*
     * When declaring a variable by identifier (or name),
     * the variable is synonymous with its value.
     * 
     * If you program JavaScript or another modern language, this is our basic understanding of variables.
     */
    int number = 3;
    std::cout << "number is initialized at " << number << "\n";

    // The value of the variable can be modified directly.
    number++;
    number = number * 2;
    std::cout << "After modifying number, its value is now " << number << "\n";

    /* 
     * Internally, this variables "lives" somewhere in memory, at a specific memory address.
     *
     * We can access the memory address through the "&" operator.
     */
    std::cout << "number's memory address is " << &number << "\n";

    /*
     * A construct that holds a memory address is a pointer.
     *
     * A pointer is created using the "*" operator before an identifier. 
     *
     * As C++ is a statically typed language, a type needs to be declared when creating a pointer.
     * This is the type of data that will live at the memory address it points to.
     */
    int *numberPointer;

    // This pointer has been initialized, but it points nowhere.
    std::cout << "The numberPointer points to the memory address " << numberPointer << ", \n";
    
    // We can set the memory address the pointer should point to.
    numberPointer = &number;

    std::cout << "The numberPointer points to the memory address `" << numberPointer << "`, which is the memory address of number\n";
    
    /*
     * With a pointer, the value at the memory address pointed to can be accessed with
     * the deference operator, "*".
     */
    std::cout << "The variable's value pointed to by numberPointer is " << *numberPointer << "\n";

    // The value of the variable pointed to can be modified using this operator as well.
    *numberPointer = 4;
    
    std::cout << "The variable's value has been modified using the pointer. The variable's value is now " << number << "\n";

    // Why would you use pointers?

    /*
     * In C++, variables are passed to a function by value.
     * A new variable is instantiated inside the function with the value passed to it.
     *
     * Any modifications to the value inside the function are not performed against the
     * variable where the function is invoked.
     */
    int x = 3;
    setValueToFive(x);
    std::cout << "The value of x is " << x << ", setValueToFive() did not modify x.\n";

    /*
     * A function can be written to perform the same task but instead accept a pointer as the argument.
     *
     * This lowers the memory footprint of the program. Unnecessary duplicate variables aren't created.
     *
     * The function can modify the variable's value directly. Any modifications to the variable in the function
     * affect the variable here in this scope too.
     */
    setPointerValueToFive( &x );
    std::cout << "The value of x is " << x << ", setPointerValueToFive() modified x.\n";
    
    /*
     * In C++ (not in C), you can pass a variable by reference by passing in a variable,
     * and defining the function's parameter like `int &x`.
     *
     * Any modifications to the variable inside the function will also affect the variable here in this scope too.
     */
    setValueToFiveWithReference( x );
    
    /*
     * Which to use is a matter of style, and whether you want to perform pointer arithmetic in the function.
     * Google has specific guidelines for which to use http://google-styleguide.googlecode.com/svn/trunk/cppguide.html#Reference_Arguments
     */

    /*
     * A pointer represents a memory address where a variable exists.
     * This piece of code says "create a pointer, and expect what will live
     * at this memory address to be an integer.
     */
    int* aPointer;
    std::cout << aPointer << "\n";
    // At this point, we cannot declare the value of the variable, because the
    // variable does not exist. We would need to do something like this.
    // The new operator always returns a pointer.
    aPointer = new int;
    *aPointer = 3;

    int b = 3;
    std::cout << b << "\n";
    std::cout << &b << "\n";
    int* c = &b;
    std::cout << c << "\n";
    int* a = new int;
    *a = 3;
    std::cout << a;
    return 0;
}
