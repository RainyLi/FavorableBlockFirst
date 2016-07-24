//
//  solution.cpp
//  Single Disk Failure Recovery
//
//  Created by 李璐雨 on 16/4/16.
//  Copyright (c) 2016年 李璐雨. All rights reserved.
//

#include "solution.h"

void solution::set_solution(){
/*
read from bitm and get the equation
*/
    equation_count=0;
    vector<bool> equation(block_number);
    int size=(int)bitm.size();
    for(int i=0;i<size;i++)
    {
        if(bitm[i][block_id]==1)
        for(int j=0;j<block_id;j++)
            equation[j]=bitm[i][j];
        equation_list.push_back(equation);
        equation_count++;
    }
}
