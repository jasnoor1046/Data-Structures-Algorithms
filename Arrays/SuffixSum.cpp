
/* Approach to Build Suffix Sum:

- Start from the last element.
- Initialize suff[n-1] = a[n-1].
- Move backward:
suff[i]=suff[i+1]+a[i]

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> suffixSum(vector<int> &a)
{
    int n = a.size();
    vector<int> suff(n);

    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + a[i];
    }
    return suff;
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

    vector<int> suff = suffixSum(a);

    cout << "Suffix Sum Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << suff[i] << " ";
    }
    cout << endl;

    return 0;
}