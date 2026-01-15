/*Approach for bubble sort:
- Repeatedly compare adjacent elements.
- Swap them if they are in the wrong order.
- After each pass, the largest element “bubbles up” to the end.
- Keep doing passes until the array is sorted.

Complexities:

- Best Case (already sorted): O(n)
- Worst Case: O(n^2).
- Average Case: O(n^2).
-Space Complexity: O(1) (in-place sorting).

Selection Sort
Approach:
- For each position i, find the minimum element in the unsorted part.
- Swap it with the element at position i.
- After the i^{th} pass, the first i elements are sorted.

Complexities:
- Best Case: O(n^2) (still scans the array to find min).
- Worst Case: O(n^2).
- Average Case: O(n^2).
- Space Complexity: O(1) (in-place sorting).

Insertion Sort
Approach:
- Start from the second element (i = 1).
- Compare it with elements before it and shift larger elements to the right.
- Insert the current element (key) into its correct position.
- Repeat until the array is sorted.

Complexities:
- Best Case (already sorted): O(n).
- Worst Case (reverse sorted): O(n^2).
- Average Case: O(n^2).
- Space Complexity: O(1) (in-place sorting).

*/
#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};

    // bubbleSort(arr);
    // selectionSort(arr);
    insertionSort(arr);

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
