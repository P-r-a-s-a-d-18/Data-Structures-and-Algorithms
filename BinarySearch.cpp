#include<iostream>

using namespace std;

int binarySearch(int* arr,int left, int right, int num)
{
    while(left <= right)
    {
        int mid = left + (right-left)/2;
        if(arr[mid] == num)
        {
            return mid;
        }
        else if(arr[mid] < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, num;
    cout << endl << "Enter size of array : ";
    cin >> n;
    int arr[100];
    cout << endl << "Enter elements in the ASCENDING order." << endl;
    for(int i=0; i<n; i++)
    {
        cout << "Enter element : ";
        cin >> arr[i];
    }
    cout << "Enter an element to be searched : ";
    cin >> num;

    int res = binarySearch(arr, 0, (n-1), num);
    if(res == -1)
    {
        cout << "No match found." << endl;
    }
    else
    {
        cout << "Element found at position : " << res+1 << endl;
    }

    return 0;
}