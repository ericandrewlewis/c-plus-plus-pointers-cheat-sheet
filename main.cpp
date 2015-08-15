//
//  main.cpp
//  PointerCheatSheet
//
//  Created by Eric Lewis on 8/15/15.
//  Copyright (c) 2015 Eric Lewis. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    /*
     * When declaring a variable by identifier (or name),
     * the variable is synonymous with its value.
     */
    int number = 3;
    std::cout << "The number is initialized at " << number << "\n";

    // We can modify the value of the variable.
    number++;
    number = number * 2;
    std::cout << "After modifying the number, its value is now " << number << "\n";

    /* 
     * Internally, the value of the variable lives at a specific memory address.
     * We can access the memory address of the variable through the "&" operator.
     */
    std::cout << "The number variable's memory address is " << &number << "\n";

    /*
     * This is synonymous with a pointer. A pointer is a memory address.
     * Let's create a pointer.
     */
    int *numberPointer;
    // We've created a pointer that points nowhere.
    std::cout << "The numberPointer points to the memory address " << numberPointer << "\n";

    // We can set the memory address the pointer should point to.
    numberPointer = &number;

    std::cout << "The numberPointer points to the memory address `" << numberPointer << "`, which is the memory address of `number`\n";

    /*
     * With this pointer, the value of the referenced variable can be accessed with
     * the deference operator.
     */
    std::cout << "The variable's value pointed to by numberPointer is " << *numberPointer << "\n";
    
    // The value of the variable pointed to can be modified.
    *numberPointer = 4;
    
    std::cout << "The variable's value has been modified indirectly by the pointer. The variable's value is now " << number << "\n";
    

    /*
     * A pointer represents a memory address where a variable exists.
     * This piece of code says "create a pointer, and expect what will live
     * at this memory address to be an integer.
     */
    int* aPointer;
    std::cout << aPointer << "\n";
    // At this point, we cannot declare the value of the variable, because the
    // variable does not exist. We would need to do something like this.
    // The new operator returns a pointer.
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
