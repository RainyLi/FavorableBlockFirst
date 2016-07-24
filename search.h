//
//  search.h
//  Single Disk Failure Recovery
//
//  Created by 李璐雨 on 16/4/16.
//  Copyright (c) 2016年 李璐雨. All rights reserved.
//

#ifndef __Single_Disk_Failure_Recovery__search__
#define __Single_Disk_Failure_Recovery__search__

#include <stdio.h>
#include <vector>
#include "variables.h"
#include "vertex.h"
#include "solution.h"
using namespace std;
class dijistra{
public:
    vector<vertex> vertex_list;
    void get_minimum_cost(vector<solution> solution_list);
    vertex* get_next_nearest_vertex();//mark whether a block is error or not, it might be (error/correct/error but corrected)
};
#endif /* defined(__Single_Disk_Failure_Recovery__search__) */
