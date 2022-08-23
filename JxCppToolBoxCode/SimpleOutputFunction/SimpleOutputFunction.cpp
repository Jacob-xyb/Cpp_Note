#include "SimpleOutputFunction.h"

int main()
{
    int arr[] = { 1,2,3,4,5 };

    std::cout << sizeof(arr) << std::endl;

    PrintArrry(arr, sizeof(arr)/sizeof(arr[0]), 0, -1);
}