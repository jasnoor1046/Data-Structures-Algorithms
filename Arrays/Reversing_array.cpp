#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr)
{
    int l = 0; // Initializing two pointers one one iterate from starting and another will from the last
    int r = arr.size() - 1;

    while (l < r)
    {
        swap(arr[l], arr[r]); // first element is swapped with the last one; then left pointer
        // is incremented and the right pointer is decremented, this process continues
        // until the left position is less then the right one.
        l++;
        r--;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    reverseArray(arr);

    cout << "Reversed Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}