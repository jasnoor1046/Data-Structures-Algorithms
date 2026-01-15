/*
Approach of Binary Search

- Precondition: The array must be sorted (ascending or descending).
- Initialize: Two pointers → left = 0, right = n-1.
- Loop until left ≤ right:
- Find middle index:
mid=left+(right-left)/2- (safe formula to avoid overflow).
- Compare arr[mid] with the target:
- If arr[mid] == target → return mid (found).
- If arr[mid] < target → search in the right half (left = mid + 1).
- If arr[mid] > target → search in the left half (right = mid - 1).
- If not found: Return -1.
Time Complexity-
- Best Case: O(1) → target found at the middle on the first check.
- Worst Case: O(\log n) → array keeps halving until search space is empty.
- Average Case: O(\log n).

- Space Complexity: O(1) for iterative version, O(\log n) for recursive version (due to call stack).
*/
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // avoid overflow

        if (arr[mid] == target)
        {
            return mid; // found
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // search right half
        }
        else
        {
            right = mid - 1; // search left half
        }
    }
    return -1; // not found
}

int main()
{
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target element: ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
