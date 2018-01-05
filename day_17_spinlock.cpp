//
//  main.cpp
//  spinlock
//
//  Created by Sriram Sonti on 26/12/17.
//  Copyright © 2017 Sriram Sonti. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int getRotVal(int pos, vector<int> vec, int steps)
{
    for (; steps >= 0; steps--)
    {
        pos++;
        
        if(pos > vec.size()-1)
        {
            pos -= vec.size();
        }
    }
    
    return pos;
}

int addVal(int oldpos, int num, vector<int>& vec)
{
    int newpos = getRotVal(oldpos, vec, 371);
    
    vec.insert(vec.begin()+newpos+1, num);
    
    return newpos;
}

void print(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
}

int main(int argc, const char * argv[])
{
    vector<int> vec;
    vec.push_back(0);
    
    int i = 1;
    int pos = 0;
    
    while(i<=2017)
    {
        pos = addVal(pos, i, vec);
        
        ++i;
    }
    
    print(vec);
    
    return 0;
}












