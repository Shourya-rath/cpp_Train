#include <iostream>
#include <vector>
using namespace std;
void printvec(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// void rotateArr(vector<int> &arr, int d)
// {

//     int n = ((int)arr.size());
//     cout << "n :" << n << endl;

//     int k = d % n;
//     cout << "k :" << k << endl;

//     int last_i = n - 1;
//     int temp = arr[0];
//     // int t_index;
//     bool gone_over_first_pos = false;
//     int current_pos = 0;
//     int first_pos = (n - k + current_pos) % n;

//     if (n % 2 != 0)
//     {
//         cout << "odd execution" << endl;
//         while ((current_pos != first_pos) || gone_over_first_pos == false)
//         {
//             if (current_pos == first_pos)
//             {
//                 gone_over_first_pos = true;
//             }
//             printvec(arr);

//             // calculate the position where current element is to be placed
//             int pos = (n - k + current_pos) % n;
//             cout << "current position where we are :- " << current_pos << endl;
//             cout << "current element to be handled (using the current position):- " << temp << endl;

//             int arr_at_pos = arr[pos];
//             // put the current element(temp) in the right pos
//             arr[pos] = temp;

//             // store element at pos in temp to prevent loss
//             temp = arr_at_pos;

//             // update the current position to the position were we have updated the value
//             current_pos = pos;

//             printvec(arr);
//         }
//     }
//     else if ((n % 2 == 0) && ((n - k) != (int)n / 2))
//     {
//         cout << "EVEN execution" << endl;
//         cout << "(n % 2 == 0) && ((n - k) != (int)n / 2) " << endl;

//         while ((current_pos != first_pos) || gone_over_first_pos == false)
//         {
//             if (current_pos == first_pos)
//             {
//                 gone_over_first_pos = true;
//             }
//             printvec(arr);

//             // calculate the position where current element is to be placed
//             int pos = (n - k + current_pos) % n;
//             cout << "current position where we are :- " << current_pos << endl;
//             cout << "current element to be handled (using the current position):- " << temp << endl;

//             int arr_at_pos = arr[pos];
//             // put the current element(temp) in the right pos
//             arr[pos] = temp;

//             // store element at pos in temp to prevent loss
//             temp = arr_at_pos;

//             // update the current position to the position were we have updated the value
//             current_pos = pos;

//             printvec(arr);
//         }
//     }
//     else
//     {
//         cout << "EVEN execution" << endl;
//         cout << "(n % 2 == 0) && ((n - k) == n/2)" << endl;
//         for (int j = 0; j < (int)n / 2; j++)
//         {
//             swap(arr[j], arr[(n - k + j) % n]);
//         }
//     }
// }

void rotateArr(vector<int> &arr, int d)
{

    int n = ((int)arr.size());
    int k = d % n;
    int last_i = n - 1;
    int temp = arr[0];
    bool GONE_OVER_FIRST_POS = false;
    int current_pos = 0;
    int first_pos = (n - k + current_pos) % n;

    if (n % 2 != 0)
    {
cout << "odd execution" << endl;
        while ((current_pos != first_pos) || GONE_OVER_FIRST_POS == false)
        {
            cout << " runing while loop " << endl;
            if (current_pos == first_pos)
            {
                GONE_OVER_FIRST_POS = true;
            }
            // calculate the position where current element is to be placed
            int pos = (n - k + current_pos) % n;
            cout << "current position where we are :- " << current_pos << endl;
            
            // make temp the current element we are dealing with
            int current_element = temp;
            cout << "current element to be handled (using the current position):- " << temp << endl;

            // store the element at the calculated position to prevent loss
            temp = arr[pos];

            // place current element at the position calculated
            arr[pos] = current_element;

            // update current position to new postion
            current_pos = pos;
            printvec(arr);
        }
    }
    else if ((n % 2 == 0) && ((n - k) != (int)n / 2))
    {

        while ((current_pos != first_pos) || GONE_OVER_FIRST_POS == false)
        {
            cout << " runing while loop " << endl;
            if (current_pos == first_pos)
            {
                GONE_OVER_FIRST_POS = true;
            }
            // calculate the position where current element is to be placed
            int pos = (n - k + current_pos) % n;
            cout << "current position where we are :- " << current_pos << endl;
            
            // make temp the current element we are dealing with
            int current_element = temp;
            cout << "current element to be handled (using the current position):- " << temp << endl;

            // store the element at the calculated position to prevent loss
            temp = arr[pos];

            // place current element at the position calculated
            arr[pos] = current_element;

            // update current position to new postion
            current_pos = pos;
            printvec(arr);
        }
    }
    else
    {
        for (int j = 0; j < (int)n / 2; j++)
        {
            swap(arr[j], arr[(n - k + j) % n]);
        }
    }
}

int main()
{
    freopen("output.txt", "w", stdout);
    // vector<int> arr[ = {1, 2, 3, 4, 5};
    // vector<int> arrGFG = {1, 2, 3, 4, 5};
    vector<int> arr2 = {5 , 1, 2, 3, 4};

    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    // vector<int> arr2 = {12, 14, 16, 18, 20, 2, 4, 6, 8, 10};
    
    vector<int> arrGFG = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    // vector<int> arr2 = {8, 10, 12, 14, 16, 18, 20, 2, 4, 6};

    
    int d = 4;
    // rotateArr(arr, d);
    rotateArr(arrGFG, d);
    cout << "arr :- ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "arr GFG :- ";
    for (int i = 0; i < arrGFG.size(); i++)
    {
        cout << arrGFG[i] << " ";
    }
    cout << endl;
}