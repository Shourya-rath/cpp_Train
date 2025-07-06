#include <iostream>
#include <vector>
using namespace std;
// User function template for C++
void print_array(vector <int> &arr) ;
class Solution
{
public:
    void pushZerosToEnd(vector<int> &arr)
    {
        int k = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            // k will hold the first 0's index
            // and will not get updated if it already has 0

            if (arr[i] == 0 && arr[k] != 0)
            {
                k = i;
            }
            cout << "k = " << k << " arr[k] : "<< arr[k] << endl;

            // swap whenever there is non zero
            if ((arr[i] != 0) && (arr[k] == 0))
            {

                cout << "swapping :" << arr[i] << " with " << arr[k] << endl;
                cout << "BEFORE swapping k = " << k << " arr[k] : "<< arr[k] << endl;
                arr[k] = arr[i] + arr[k];
                arr[i] = arr[k] - arr[i];
                arr[k] = arr[k] - arr[i];
                k++ ;
                cout << "AFTER swapping k = " << k << " arr[k] : "<< arr[k] << endl;

                // increment k if the previous two elements were 0

            }
            print_array(arr) ;
        }
    }
};
int main()
{
    freopen("output.txt", "w", stdout);
    vector<int> arr = { 10,0 , 20, 30 ,0 , 5 , 0};
    Solution solution;
    solution.pushZerosToEnd(arr);
    print_array(arr) ;
}
void print_array(vector <int> &arr)
{
    cout << endl ;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl ;
    cout << endl ;
}