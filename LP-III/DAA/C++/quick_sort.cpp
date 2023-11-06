#include <iostream>
using namespace std;
class Quick_Sort
{
public:
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i = low, j = high;
        while (i < j)
        {
            while (i <= j && arr[i] <= pivot)
                i++;
            while (j >= i && arr[j] > pivot)
                j--;
            if (i < j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        swap(arr[j], arr[low]);
        return j;
    }
};
int main()
{
    int n;
    cout << "How many elements in array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array Before sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    Quick_Sort q;
    q.quickSort(arr, 0, n - 1);
    cout << "\nArray After sort\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
