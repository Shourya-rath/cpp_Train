#include <iostream>
#include <vector>
#include <string>
using namespace std;
/* 
Cant have more than 
10^5 elements locally
10^7 elements globally
*/

int main(){

    pair_func() ;
    vector_func() ;

    
}


void pair_func(){

    pair<int, string > p ;
    p = make_pair(1 , "hello") ;
    // p.first = 1 ;
    // p.second = "hello" ;
    p = {2,"hi"} ;
    pair<int, string > &p2 = p ;
    p2.first = 3 ;
    p2.second = "bye" ;
    // cout << p.first << " " << p.second << endl ;
    pair<int, string > p_array[3] = {
        {1,"hello"},
        {2,"hi"},
        {3,"bye"},
    } ;
}

void vector_func() {

    vector<int> v ;
    // v.push_back(1);
    // v.pop_back(1);
    vector<int> v2 = v ;
    // v2 is a copy of v not an alias 
    // TIME COMPLEXITY O(n)
//also if we pass it directly to a function it will be copied : O(n) for eg : PrintVector(vector<int> v) -> O(n) 
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int a ;
        cin >> a ;
        v.push_back(a);
    }
}