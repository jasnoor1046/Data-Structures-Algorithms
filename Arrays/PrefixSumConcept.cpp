/*Concept: Prefix Sum

Approach: A prefix sum is a technique where each element of a new array represents
the cumulative sum of the original array’s elements up to that index. We need prefix
sum to quickly calculate the sum of any subarray in constant time after linear preprocessing.

Time complexity: O(n)

Space complexity: O(n) (for storing the prefix sum array).
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixSum(vector<int> &a)
{
    int n = a.size();
    vector<int> pref(n);

    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }
    return pref;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> pref = prefixSum(a);

    cout << "Prefix Sum Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << pref[i] << " ";
    }
    cout << endl;

    return 0;
}