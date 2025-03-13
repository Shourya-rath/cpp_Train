#include <iostream>
#include <vector>
#include <string>
using namespace std;
void printVec(vector<int> &v) ;
int main()
{
    vector<pair<int, string>> vp;
    // vp.push_back({1,"string"} );
    /* vp = {
        {1,"one"} ,
        {2, "two"} ,
        } ; */

    // cout << vp[0].first << vp[0].second ;
    int N;
    cin >> N;  
    vector<int> vec[N]; // this will keep the rows fixed
    vector<  vector< int >  > vec[N];
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            vec[i].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
    {
        printVec(vec[i]);
    }
}
void printVec(vector<int> &v)
{
    cout << "size :" << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}