#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};     // sample array
    int n = sizeof(arr) / sizeof(arr[0]); // length of array
    /* sizeof gives the total memory size (in bytes) occupied by the array.
    Example: if arr has 5 integers and each int takes 4 bytes → sizeof(arr) = 20.
    */

    cout << "Array elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // accessing each element
    }

    cout << endl;
    return 0;
}