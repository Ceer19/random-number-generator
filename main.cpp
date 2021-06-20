#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int size, limits;

    srand(time(nullptr));
    b:cout << "Enter array size: ";
    cin >> size;
    cout << "Enter the biggest value for the number in the array: ";
    cin >> limits;

    if (size < 1)
    {
        cout << "Error. Array size can't be less than one.";
        cin.get();
        goto b;
    }

    if (limits < size)
    {
        cout << "Error. The biggest number can't be less than the array size." << endl;
        goto b;
    }

    int *arr = new int [size];

    for (int i = 0; i < size; i++)
    {
        a:arr[i] = rand() % limits;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j]) goto a;
        }
    }

    cout << "Non-repeating pseudo-random numbers: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    int max = arr[0];
    int min = arr[0];
    for (int r = 0; r < size; r++)
    {
        if (max < arr[r])max = arr[r];
        if (min > arr[r])min = arr[r];
    }
    cout << "\nMaximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;

    s:cout << "Do you want to perform manipulations with the array?\nAddition (1)\n"
              "Subtraction (2)\nMultiplication (3)\nDivision (4)" << endl;
    cout << "Enter the command number: ";

    int CommandNumber;
    cin >> CommandNumber;

    switch (CommandNumber)
    {
        case 1:
            cout << "Sum addition: " << (max + min) << endl;
            break;
        case 2:
            cout << "Sum subtraction: " << (max - min) << endl;
            break;
        case 3:
            cout << "Sum multiplication: " << (max * min) << endl;
            break;
        case 4:
            cout << "Sum division: " << (max / min) << endl;
            break;
        default:
            cout << "Error. You entered the wrong command number. Enter the command number again: " << endl;
            goto s;
    }

    delete [] arr;
}
