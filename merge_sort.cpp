//Time Complexity 
//Best case:o(nlogn)
//Avg. case:o(nlogn)
//Worst case:o(nlogn)

#include<iostream>
using namespace std;
//here we are going to create a function that mergs two array 
void merge(int arr[], int left, int mid, int right)
{
    int temp[100];

    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(int x = left; x <= right; x++)
        arr[x] = temp[x];
}
// main merge sort algorithm
void merge_sort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {2,8,5,3,9,4,1,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    merge_sort(arr, 0, n - 1);

    cout << "\nSorted Array: ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
