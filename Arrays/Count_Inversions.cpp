/*
Problem:
Count the number of inversions in an array.

Definition:
An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].

Pattern:
Divide and Conquer (Merge Sort based)

Approach:
Use a modified merge sort to count inversions while merging.
This reduces the time complexity from O(n²) to O(n log n).

Time Complexity:
O(n log n).
- Best Case: O(n log n)
Even if the array is already sorted, merge sort still divides and merges recursively.
- Average Case: O(n log n)
Each level of recursion requires merging, and there are \log n levels.
- Worst Case: O(n log n)
Unlike quicksort, merge sort does not degrade to quadratic time.
Breakdown:
- Splitting the array: \log n levels of recursion.


Space Complexity:
O(n).Temporary arrays are needed to store left and right halves during merging.

Edge Cases:
- Already sorted array
- Reverse sorted array
- Duplicate elements
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;
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
            invCount += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
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
    return invCount;
}
bool isSortedAscending(const vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

bool isSortedDescending(const vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > arr[i - 1])
            return false;
    return true;
}

bool hasDuplicates(const vector<int> &arr)
{
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    for (int i = 1; i < temp.size(); i++)
        if (temp[i] == temp[i - 1])
            return true;
    return false;
}

int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        int leftInvCount = mergeSort(arr, st, mid);       // recursive call for the left half
        int rightInvCount = mergeSort(arr, mid + 1, end); // recursive call for the right half

        int invCount = merge(arr, st, mid, end);

        return leftInvCount + rightInvCount + invCount;
    }
    return 0;
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements\n: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = mergeSort(arr, 0, n - 1);
    cout << "Inversion Count is: " << ans << endl;
    return 0;
}
