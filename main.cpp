#include <iostream>
#include "array/array.h"
#include "pointers/rampointer.h"
using namespace std;

int main()
{
        array<int> arr(10);
        arr[0] = 435;
        arr[1] = 45;
        arr[2] = 15;
        arr[3] = 435;
        arr[4] = 478;
        arr[5] = 245;
        arr[6] = 745;
        arr[7] = 405;
        arr[8] = 45;
        arr[9] = 478;

        array<int> arr2(10);
        arr2[0] = 435;
        arr2[1] = 45;
        arr2[2] = 15;
        arr2[3] = 435;
        arr2[4] = 478;
        arr2[5] = 245;
        arr2[6] = 745;
        arr2[7] = 405;
        arr2[8] = 45;
        arr2[9] = 478;

        RAMPointer test;
        test.setPointer(&arr);
        bool compare = (*(array<int>*)test.getPointer() == arr2);
        cout << compare<<"\n";
    return 0;
}

