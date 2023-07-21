//
//  anagram.cpp
//  Homework12
//
//  Created by Sean Belingheri on 11/17/22.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isAnagram(string str0, string str1);


int main()
{
    string term1, term2;
    cout<<"First string: ";
    getline(cin, term1);
    cout<<"Second string: ";
    getline(cin, term2);
    
    
    if(isAnagram(term1, term2) == true)
        cout<<"These two strings are anagrams."<<endl;
    else
        cout<<"These two strings are NOT anagrams."<<endl;
    return 0;
}

bool isAnagram(string str0, string str1)
{
    string temp1 = str0, temp2 = str1;
    char store;
    int indicator = 0, spacecounter1 = 0, spacecounter2 = 0;
    
    do{
        for(int k = 0; k < temp1.length() - 1; k++)
        {
            store = temp1[k];
            if(temp1[k]>temp1[k+1])
            {
                temp1[k] = temp1[k+1];
                temp1[k+1] = store;
            }
        }
        indicator++;
    }while(indicator < temp1.length());
    
    indicator = 0;
    
    do{
        for(int k = 0; k < temp2.length() - 1; k++)
        {
            store = temp2[k];
            if(temp2[k]>temp2[k+1])
            {
                temp2[k] = temp2[k+1];
                temp2[k+1] = store;
            }
        }
        indicator++;
    }while(indicator < temp2.length());
    
    for(int r = 0; r<temp1.length(); r++)
        if(temp1[r] == ' ')
            spacecounter1++;
    
    for(int r = 0; r<temp2.length(); r++)
        if(temp2[r] == ' ')
            spacecounter2++;
    
    temp1 = temp1.substr(spacecounter1, temp1.length()-spacecounter1);
    temp2 = temp2.substr(spacecounter2, temp2.length()-spacecounter2);
    
    return temp1 == temp2;
}
