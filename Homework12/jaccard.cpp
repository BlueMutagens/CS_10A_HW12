//
//  main.cpp
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

int uniqueTags(string arr1[], string arr2[], int arraysize1, int arraysize2);

int main()
{
    string*item1=NULL;
    string*item2=NULL;
    int i=0, size1, size2, common = 0;
    char ch;
    string temp;
    
    cout<<"Number of tags in Item 1: ";
    cin>>size1;
    
    cout<<"Enter tags: ";
    item1=new string[size1];
    do
    {
        cin>>item1[i];
        i++;
        ch = cin.get();
    } while(ch != '\n' && i < size1);
    
    if(i == size1 && ch != '\n')
        getline(cin, temp);
    else if(i < size1 && ch == '\n')
    {
        for(i; i<size1; i++)
            item1[i]=" ";
    }
    
    i = 0;
   
    cout<<"Number of tags in Item 2: ";
    cin>>size2;
    
    cout<<"Enter tags: ";
    item2=new string[size2];
    do
    {
        cin>>item2[i];
        i++;
        ch = cin.get();
    } while(ch != '\n' && i < size2);
    
    if(i == size2 && ch != '\n')
        getline(cin, temp);
    else if(i < size2 && ch == '\n')
    {
        for(i; i<size2; i++)
            item2[i]=" ";
    }
    
    for(int f = 0; f < size1; f++)
    {
        for(int g = 0; g < size2; g++)
        {
            if(item1[f] == item2[g])
                common++;
        }
    }
  
    cout<<"Jaccard Index is "<<setprecision(2)<<fixed<<(common * 1.0)/uniqueTags(item1, item2, size1, size2)<<endl;
    return 0;
}

int uniqueTags(string arr1[], string arr2[], int arraysize1, int arraysize2)
{
    string*combined_list=NULL;
    int size3, indicator = 0, unique = 1;
    string store1;
    size3 = arraysize1 + arraysize2;
    
    combined_list=new string[size3];
    for(int g = 0; g<arraysize1; g++)
        combined_list[g]=arr1[g];
    
    for(int k = 0; k<arraysize2; k++)
        combined_list[k+arraysize1]=arr2[k];
    
    
    do{
        for(int k = 0; k < size3 - 1; k++) //goes through each index in array and compares it with value to the left. If the first value is greater than the second value, this swaps them. This needs to run multiple times for the entire sequence, as this loop naturally pushes the biggest numbers to the back first.
            {
                store1 = combined_list[k];
                if(combined_list[k]>combined_list[k+1])
                {
                    combined_list[k] = combined_list[k+1];
                    combined_list[k+1] = store1;
                }
            }
        indicator++; //the indicator makes it so the loop runs as many times as there are values in the array.
    }while(indicator < size3);
    
    for(int w = 0; w<size3-1; w++)
        if(combined_list[w] != combined_list[w+1])
            unique ++;
    
    
    return unique;
}
