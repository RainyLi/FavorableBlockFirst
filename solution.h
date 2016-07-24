//
//  solution.h
//  Single Disk Failure Recovery
//
//  Created by 李璐雨 on 16/4/16.
//  Copyright (c) 2016年 李璐雨. All rights reserved.
//

#ifndef __Single_Disk_Failure_Recovery__solution__
#define __Single_Disk_Failure_Recovery__solution__

#include <stdio.h>
#include "variables.h"
#include <vector>
#include <stdlib.h>

using namespace std;

class solution
{
    // the decoding equation for a specific missing block
public:
    int block_id;
    vector<vector<bool>> equation_list;
    void set_solution();
    int equation_count;
};

#endif /* defined(__Single_Disk_Failure_Recovery__solution__) */
