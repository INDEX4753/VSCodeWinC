#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int> &A, vector<int> &temp, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    long long cross_inversions = 0;

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            cross_inversions += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = A[i++];
    }

    while (j <= high)
    {
        temp[k++] = A[j++];
    }

    for (int m = low; m <= high; m++)
    {
        A[m] = temp[m];
    }

    return cross_inversions;
}

long long mergeSortAndCount(vector<int> &A, vector<int> &temp, int low, int high)
{
    long long inversions = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        inversions += mergeSortAndCount(A, temp, low, mid);

        inversions += mergeSortAndCount(A, temp, mid + 1, high);

        inversions += mergeAndCount(A, temp, low, mid, high);
    }
    return inversions;
}

long long countInversions(vector<int> &A)
{
    int n = A.size() - 1;
    vector<int> temp(A.size());
    return mergeSortAndCount(A, temp, 1, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    long long res = countInversions(A);
    cout << res << endl;

    return 0;
}