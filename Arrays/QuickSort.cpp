/*
Problem:
Sort an array using Quick Sort.

Pattern:
Divide and Conquer

Approach:
Select a pivot element, partition the array around the pivot,
and recursively apply the same process to subarrays.
Efficient in practice but worst-case occurs with bad pivot selection.

Time Complexity:
Average: O(n log n)
Worst: O(n²)

Space Complexity:
O(log n) (recursive stack)

Edge Cases:
- Already sorted array
- Array with duplicate elements
*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1;
    int pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}
void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivIdx = partition(arr, st, end);
        quickSort(arr, st, pivIdx - 1);
        quickSort(arr, pivIdx + 1, end);
    }
}
int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    if (n == 0)
    {
        cout << "Edge Case: Empty array. Nothing to sort." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << "Edge Case: Single element array. Already sorted." << endl;
        cout << "Sorted array: " << arr[0] << endl;
        return 0;
    }

    bool sorted = true;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            sorted = false;
            break;
        }
    }
    if (sorted)
        cout << "Edge Case: Already sorted array." << endl;

    // Edge case: duplicates
    bool duplicates = false;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            duplicates = true;
            break;
        }
    }
    if (duplicates)
        cout << "Edge Case: Array contains duplicate elements." << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
