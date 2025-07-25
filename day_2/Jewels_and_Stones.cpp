// Jewels and Stones

// Soma is a fashionable girl. She absolutely loves shiny stones that she can put on as jewellery accessories. She has been collecting stones since her childhood - now she has become really good with identifying which ones are fake and which ones are not. Her King requested for her help in mining precious stones, so she has told him which all stones are jewels and which are not. Given her description, your task is to count the number of jewel stones.

// More formally, you're given a string J composed of latin characters where each character is a jewel. You're also given a string S composed of latin characters where each character is a mined stone. You have to find out how many characters of S are in J as well.

// Input

// First line contains an integer T denoting the number of test cases. Then follow T test cases. Each test case consists of two lines, each of which contains a string composed of English lower case and upper characters. First of these is the jewel string J and the second one is stone string S. You can assume that 1 <= T <= 100, 1 <= |J|, |S| <= 100
// Output

// Output for each test case, a single integer, the number of jewels mined. 

// input
// 4
// abc
// abcdef
// aA
// abAZ
// aaa
// a
// what
// none

// Output
// 3
// 2
// 1
// 0

#include <iostream>
#include <vector>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int n ;
    cin >> n ;
    string gem ;
    string input ;
    
    
    for (int k = 0 ; k < n ; k++)
    {
        
        int count = 0 ;
        cin >> gem ;
        cin >> input ;
        /*
        
        use input as the outer loop , for any input[i] matching gem[j]
        we can then skipp checking other gem indexes and just move to index[i+1]

        */
        for(int i = 0 ; i < input.length() ; i++)
        {
            for(int j = 0 ; j < gem.length() ; j++)
            {           
                if( input[i] == gem[j] )
                {
                    count = count + 1 ;
                    break;
                }

            }
        }
        cout << count << '\n';

    }

}

