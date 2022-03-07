#include<iostream>

using namespace std;

void bubbleSort(int *arr1, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr1[j] > arr1[j+1])
            {
                int temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int arr1[100];
    for(int i = 0; i<n; i++)
    {
        cout << "Enter element : ";
        cin >> arr1[i];
    }
    bubbleSort(arr1, n);
    cout << endl << "SORTED ARRAY : " << endl;
    for(int i = 0; i<n; i++)
    {
        cout << arr1[i]<<" ";
    }
}