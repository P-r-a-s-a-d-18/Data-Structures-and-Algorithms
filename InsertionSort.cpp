#include<iostream>

using namespace std;

void insertionSort(int* arr1, int n)
{
    int key = 0;
    int j = 0;
    for(int i=0; i<n; i++)
    {
        key = arr1[i];
        j = i - 1;

        while(j >= 0 && arr1[j] > key)
        {
            arr1[j+1] = arr1[j];
            j = j - 1;
        }
        arr1[j+1] = key;
    }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int arr1[n];
    for(int i = 0; i<n; i++)
    {
        cout << "Enter element : ";
        cin >> arr1[i];
    }
    insertionSort(arr1, n);
    cout << "SORTED ARRAY : " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr1[i] << " ";
    }

    return 0;
}