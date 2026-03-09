#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right, vector<int> &temp)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    k = 0;
    while (left <= right)
    {
        arr[left++] = temp[k++];
    }
}

void mergeSort(vector<int> &arr, int left, int right, vector<int> &temp)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, temp);
    mergeSort(arr, mid + 1, right, temp);

    merge(arr, left, mid, right, temp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), temp(n);
    for (int i = 0; i < n; i++)
    {
        int tempnum;
        cin >> tempnum;
        arr[i] = tempnum;
    }

    mergeSort(arr, 0, arr.size() - 1, temp);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << " ";
    }
    cout << endl;
}