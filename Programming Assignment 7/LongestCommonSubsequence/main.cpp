//
//  main.cpp
//  LongestCommonSubsequence
//
//  Created by Madhumita Ghosal on 11/20/18.
//  Copyright © 2018 Madhumita Ghosal. All rights reserved.
//

#include <iostream>

using namespace std;

// create LCS table
void create_lcs_table(string first_subsequence, string second_subsequence, int first_subsequence_size, int second_subsequence_size)
{
    int lcs_table[first_subsequence_size+1][second_subsequence_size+1];
    int i, j = 0;
    int val = 0;
    
    for(int i = 0 ; i <= first_subsequence_size; i++)
    {
        lcs_table[i][0] = 0;
    }
        
    for(int j = 0; j <= second_subsequence_size; j++)
    {
        lcs_table[0][j] = 0;
    }
        
    for(i = 1; i <= first_subsequence_size ; i++)
    {
        for(j = 1; j <= second_subsequence_size; j++)
        {
            if(first_subsequence[i-1] == second_subsequence[j-1])
            {
                lcs_table[i][j] = lcs_table[i-1][j-1]+1;
            }
            else
            {
                lcs_table[i][j] = max(lcs_table[i-1][j], lcs_table[i][j-1]);
            }
        }
    }
    
    // print lcs_table
    for(int i=0; i <= first_subsequence_size; i++)
    {
        for(int j=0; j <= second_subsequence_size; j++)
        {
            cout << lcs_table[i][j] << " ";
        }
        cout << "\n";
    }
    
    val = lcs_table[first_subsequence_size][second_subsequence_size];
    
    // print LCS subsequence
    int max_val = lcs_table[first_subsequence_size][second_subsequence_size];
    char longest_subsequence[max_val+1];
    longest_subsequence[max_val] = '\0';
    
    while(first_subsequence_size>0 && second_subsequence_size>0)
    {
        if(lcs_table[first_subsequence_size-1][second_subsequence_size] > lcs_table[first_subsequence_size][second_subsequence_size-1])
        {
            first_subsequence_size--;
        }
        else if(first_subsequence[first_subsequence_size-1] == second_subsequence[second_subsequence_size-1])
        {
            longest_subsequence[max_val-1] = first_subsequence[first_subsequence_size-1];
            max_val--;
            first_subsequence_size--;
            second_subsequence_size--;
            
        }
        else
        {
            second_subsequence_size--;
        }
    }
    
    cout << "\nLCS is " << longest_subsequence;
    
    cout << "\nThe LCS value is " << val;
    
}

int main(int argc, const char * argv[]) {
    
    string first_subsequence = "";
    string second_subsequence = "";
    int first_subsequence_size;
    int second_subsequence_size;
    cout << "Enter first subsequence: \n";
    getline(cin, first_subsequence);
    // cout << first_subsequence << "\n";
    cout << "Enter second subsequence: \n";
    getline(cin, second_subsequence);
    // cout << second_subsequence << "\n";
    
    first_subsequence_size = (int)first_subsequence.length();
    second_subsequence_size = (int)second_subsequence.length();
    
    create_lcs_table(first_subsequence, second_subsequence, first_subsequence_size, second_subsequence_size);
    
}


