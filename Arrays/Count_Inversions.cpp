#include <iostream>
#include <vector>
using namespace std;

/* Count inversions in array measures how far it is being sorted, specifically by counting pairs
of elements in an array specifically where arr[i]>arr[j]. */

int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0; // initializing the variable for count inversion.

    while (i <= mid && j <= end)
    { /*Here we check compare the elements of left side to right side
if element in the left is smaller then the right it is pushed in the temp vector otherwise
the element on the right is pushed to the temp vector*/
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
    { /*This part will merge the two sorted parts
    i.e., left and the right half in a single array.*/
        arr[idx + st] = temp[idx];
    }
    return invCount;
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
