//
//  main.cpp
//  checksum
//
//  Created by Sriram Sonti on 12/12/17.
//  Copyright © 2017 Sriram Sonti. All rights reserved.
//

#include <iostream>

using namespace std;

int arrsum(int arr[], int sz)
{
    int sum = 0;
    
    for(int i = 0; i < sz; i++)
    {
        sum+=arr[i];
        cout << i+1 << " " << sum << endl;
    }
    
    return sum;
}

int main(int argc, const char * argv[])
{
    cout << "Enter number of rows: ";
    int rows;
    cin >> rows;
    
    cout << "Enter number of columns: ";
    int cols;
    cin >> cols;
    
    int arr[rows][cols];
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }
    
    int maxes[rows];
    int mins[rows];
    int diffs[rows];
    
    for(int k = 0; k < rows; k++)
    {
        int max = 0;
        
        for(int l = 0; l < cols; l++)
        {
            if(arr[k][l]>max)
            {
                max = arr[k][l];
            }
        }
        
        cout << "ROW MAX " << max << endl;
        maxes[k] = max;
    }
    
    cout << endl;
    
    for(int k = 0; k < rows; k++)
    {
        int min = arr[k][0];
        
        for(int l = 0; l < cols; l++)
        {
            if(arr[k][l]<min)
            {
                min = arr[k][l];
            }
        }
        
        mins[k] = min;
        cout << "ROW MIN " << min << endl;
    }
    
    cout << endl << endl << endl;
    
    for(int m = 0; m < rows; m++)
    {
        diffs[m] = maxes[m]-mins[m];
        cout << "DIFFS " << diffs[m] << endl;
    }
    
    cout << arrsum(diffs, rows) << endl;
    
    return 0;
}
















