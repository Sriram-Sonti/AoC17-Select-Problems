//
//  main.cpp
//  series_of_tubes
//
//  Created by Sriram Sonti on 29/12/17.
//  Copyright © 2017 Sriram Sonti. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef enum direction {nomove,u,d,l,r} direction;

int no_of_steps = 0;

direction move(vector<string>& lines, int row, int col, direction dir);

string tracker(vector<string>& lines)
{
    string letters;
    
    int row=0, col=0;
    
    while (lines[row][col]!='|')
        col++;         // find starting position
    
    direction dir = d;
    
    while (dir != nomove)
    {
        no_of_steps++;
        
        dir = move(lines,row,col,dir);
        
        switch(dir)
        {
            case d:
                row++;
                break;
                
            case u:
                row--;
                break;
                
            case r:
                col++;
                break;
                
            case l:
                col--;
                break;
                
            case nomove:
                break;
        }
        
        if (lines[row][col]>='A' && lines[row][col]<='Z')
            letters+=lines[row][col];
    }
    return letters;
}

direction move(vector<string>& lines, int row, int col, direction dir)
{
    if(lines[row][col]=='+')
    {
        if(dir!=d && row>0 && lines[row-1][col]!=' ')
        {
            return u;
        }
        
        
        else if(dir!=u && row<lines.size()-1 && lines[row+1][col]!=' ')
        {
            return d;
        }
        
        
        else if(dir!=l && col<lines[row].length()-1 && lines[row][col+1]!=' ')
        {
            return r;
        }
        
        
        else if(dir!=r && col>0 && lines[row][col-1]!=' ')
        {
            return l;
        }
    }
    
    else
    {
        return dir;
    }
    
    return nomove;
}

int main()
{
    fstream f("map.txt");
    string line;
    
    vector<string> lines;
    
    while (getline(f,line))
    {
        lines.push_back(line);
    }
    
    string letters = tracker(lines);
    
    cout << "ORDER:: " << letters << endl;
    cout << "STEPS:: " << no_of_steps << endl;
    
    return 0;
}









