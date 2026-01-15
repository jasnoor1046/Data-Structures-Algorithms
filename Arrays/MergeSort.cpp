
/*
Problem:
Sort an array using Merge Sort.

Pattern:
Divide and Conquer

Approach:
Recursively divide the array into two halves, sort each half,
and then merge the sorted halves.
This guarantees O(n log n) time complexity.

Time Complexity:
O(n log n)

Space Complexity:
O(n)

Edge Cases:
- Empty array
- Single element array
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    { // this part will put the remaining elements in the temp vector
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, st, mid, end);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n == 0)
    {
        cout << "Edge Case: Empty array. Nothing to sort." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << "Edge Case: Single element array. Already sorted." << endl;
        cout << "Sorted Array: " << arr[0] << endl;
        return 0;
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
