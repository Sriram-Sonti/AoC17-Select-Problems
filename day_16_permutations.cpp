//
//  main.cpp
//  permutations
//
//  Created by Sriram Sonti on 25/12/17.
//  Copyright © 2017 Sriram Sonti. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void spin(string& str, int i)
{
    while(i!=0)
    {
        char ch = str[str.length()-1];
        str.erase(str.length()-1);
        str = ch+str;
        i--;
    }
}

void exchange(string& str, int pos1, int pos2)
{
    swap(str[pos1], str[pos2]);
}

int getPos(string s, char ch)
{
    int pos = 0;
    
    while(s[pos]!=ch)
        pos++;
    
    return pos;
}

void partner(string& str, char e1, char e2)
{
    swap(str[getPos(str, e1)], str[getPos(str, e2)]);
}

int main(int argc, const char * argv[])
{
    string str = "abcdefghijklmnop";
    fstream f;
    f.open("Untitled.txt");
    cout << str << endl << endl;
    string line;
    while(getline(f, line, ','))
    {
        istringstream inp(line);
        
        if(line[0]=='s')
        {
            char x;
            int shift;
            
            inp >> x >> shift;
            
            spin(str, shift);
        }
        
        else if(line[0]=='x')
        {
            char x;
            int pos1, pos2;
            char div;
            
            inp >> x >> pos1 >> div >> pos2;
            
            exchange(str, pos1, pos2);
        }
        
        else if(line[0]=='p')
        {
            char x;
            char e1, e2;
            char div;
            
            inp >> x >> e1 >> div >> e2;
            
            partner(str, e1, e2);
        }
        
        cout << '\t' << line << endl;
    }
    
    cout << endl << str << endl << endl;
    
    return 0;
}












