#include <iostream>
#include <vector>

using namespace std;

void getValues(float* arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        arr[i] = i * 0.2;
    }
    
}

void init_pointerFirst_pointerLast()
{
    float* arr = new float[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }
    vector<float> arrf = vector<float>(arr, arr + 10);
    vector<double> arrd(arr, arr + 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arrf[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        cout << arrd[i] << " ";
    }
}

void init_pointerFirst_pointerLast_copy()
{
    float* arr = new float[10];
    for (int i = 0; i < 10; i++)`
    {
        arr[i] = i + 1;
    }
    vector<float> arrf = vector<float>(arr, arr + 10);
    vector<double> arrd(arr, arr + 10);  // deep copy

    for (int i = 0; i < 10; i++)
    {
        arrd[i] = i - 10;
        cout << arrf[i] << " ";
    }
    cout << "\n";
}

void vector_to_pointer()
{
    vector<float> arrx;
    for (int i = 0; i < 10; i++)
    {
        arrx.push_back(i * 0.1);
    }

    getValues(arrx.data(), 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arrx[i] << " ";
    }
    
}



int main(int argc, char const *argv[])
{
    // init_pointerFirst_pointerLast();
    init_pointerFirst_pointerLast_copy();
    // vector_to_pointer();

    return 0;
}
