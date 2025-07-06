#include <iostream>
#include <string>
using namespace std;
void fn_processString(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        cout << i << " : " << str[i] << endl;
    }
}
int main()
{
    freopen("string_parse.txt", "r", stdin);
    freopen("str_parse_output.txt", "w", stdout);
    string str;
    

    int i = 0 ;
   while (getline(cin, str))
    {   
        cout<< "Iteration: " << i <<endl ;
    
        cout << "length " << str.length() << endl;
        
        fn_processString(str);
        i++;
    }
}