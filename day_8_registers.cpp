//
//  main.cpp
//  registers
//
//  Created by Sriram Sonti on 15/12/17.
//  Copyright © 2017 Sriram Sonti. All rights reserved.
//

#include <iostream>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

bool isConditionMet(int operand, string operation, int compare_value)
{
    if(operation == "<")
    {
        if(operand < compare_value)
            return true;
    }
    
    else if(operation == ">")
    {
        if(operand > compare_value)
            return true;
    }
    
    else if(operation == "==")
    {
        if(operand == compare_value)
            return true;
    }
    
    else if(operation == "<=")
    {
        if(operand <= compare_value)
            return true;
    }
    
    else if(operation == ">=")
    {
        if(operand >= compare_value)
            return true;
    }
    
    else if(operation == "!=")
    {
        if(operand != compare_value)
            return true;
    }
    
    return false;
}

int getMax(map<string, int> m)
{
    map<string, int>::iterator b = m.begin();
    
    map<string, int>::iterator e = m.end();
    
    int max = 0;
    
    while(b!=e)
    {
        if(max < b->second)
        {
            max = b->second;
        }
        
        b++;
    }
    
    return max;
}

int main(int argc, const char * argv[])
{
    map<string, int> registers;
    
    istringstream input;
    
    string reg_name;
    string command;
    int reg_value;
    string ifstatement;
    string oper1;
    string condition;
    int compare_value;
    
    while(reg_name!="n")
    {
        cin >> reg_name >> command >> reg_value >> ifstatement >> oper1 >> condition >> compare_value;
        
        if(isConditionMet(registers[oper1], condition, compare_value))
        {
            if(command=="dec")
            {
                reg_value*=-1;
            }
            
            if(registers.count(reg_name)>0)
            {
                registers[reg_name] += reg_value;
            }
            
            else
            {
                registers.insert(pair<string,int>(reg_name, reg_value));
            }
        }
                
        string more;
        cout << "More? ";
        cin >> more;
        cout << endl;
        if(more == "n")
            break;
    }
    
    cout << endl << "MAX " << getMax(registers) << endl;
    
    return 0;
}


/*
TEST:
 
b inc 5 if a > 1
a inc 1 if b < 5
c dec -10 if a >= 1
c inc -20 if c == 10
 
 */

























