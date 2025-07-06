#include <iostream>
#include <vector>
using namespace std;

int getSecondLargest(vector<int> &arr)
{
    // code here
    int largest = -1;
    int sec_large = -1;
    int temp = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            // 1
            // cout << temp ;
            largest = arr[i];
            cout << "largest : " << largest << endl;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if ((temp < arr[i]) && (arr[i] != largest))
        {
            temp = arr[i];
            cout << "temp: " << temp << endl;
        }
        else
        {

            cout << "temp: " << temp << endl;
        }
        if (temp < largest)
        {
            sec_large = temp;
            cout << "sec_large : " << sec_large << endl;
        }
    }
    return sec_large;
}

int main()
{
    vector<int> arr = {10, 5, 10};
    int n = getSecondLargest(arr);
    cout << n;
}