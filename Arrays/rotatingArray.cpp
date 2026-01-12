#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int l, int r)
{
    while (l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}
// Function to take array by k positions
void rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
        return;
    k = k % n; // normalize k into a valid rotation distance that actually changes array

    // reversing an entire array
    reverseArray(arr, 0, n - 1);

    // reversing first k elements
    reverseArray(arr, 0, k - 1);

    reverseArray(arr, k, n - 1); // reversing remaining n-k elememts
}
int main()
{
    int n, k;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter k: ";
    cin >> k;

    rotateArray(arr, k);
    cout << "Rotated array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    return 0;
}