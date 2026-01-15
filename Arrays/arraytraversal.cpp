/*
Problem:
Traverse an array and access each element.

Data Structure:
Array

Approach:
Iterate through the array using a single loop and process each element.
This is the most basic operation on arrays and forms the foundation
for many other algorithms.

Time Complexity:
O(n)

Space Complexity:
O(1)

Edge Cases:
- Empty array
- Single element array
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n == 0)
    {
        cout << "Array is empty." << endl;
    }
    else
    {
        int arr[n];
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Array elements are: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}