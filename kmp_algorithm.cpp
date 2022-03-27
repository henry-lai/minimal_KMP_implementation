#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) 
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) 
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) //when we have a mismatch
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) //when we have a match
        {
            j++;
        }
        pi[i] = j;
        //cout << pi[i];
    }   
    //cout << endl;
    return pi;
}

void kmpAlg(string text, string pattern )
{
    //prepare Pi table
    vector<int> piTable = prefix_function(pattern);

    int i=0, j = 0;

    while (  i < text.length() )
    {
        if(pattern[j] == text[i]) // if theres a match, keep going 
        {
            j++;
            i++;
        }
        if ( j == pattern.length() ) 
        {
            printf("Found pattern at index %d \n", i - j);
            j = piTable[j - 1];
        }
        else if (i < text.length() && pattern[j] != text[i]) 
        {
            if (j != 0)
                j = piTable[j - 1];
            else
                i = i + 1;
        }
    }

}


int main(int argc, char *argv[])
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    kmpAlg(text, pattern);
    //prefix_function(pattern);
    return 0;
}