//
//  vertex.h
//  Single Disk Failure Recovery
//
//  Created by 李璐雨 on 16/4/16.
//  Copyright (c) 2016年 李璐雨. All rights reserved.
//

#ifndef __Single_Disk_Failure_Recovery__vertex__
#define __Single_Disk_Failure_Recovery__vertex__

#include <stdio.h>
#include <string>
#include "variables.h"
#include <stdlib.h>
#include <vector>
#include "solution.h"
#include <array>

using namespace std;

class vertex{
public:
    vector<bool> scheme;//the whole scheme
    int block_id;//the block it is going to correct in this step
    int id;//the unique id in vertex list
    bool pruned;
    bool marked;
    int distance;
    vector<bool> block_solution;//equation for the specific block
    int parent_id;
    void initialize(int blockid);
    bool insert_next_vertex(vector<vertex> &vertex_list, vector<solution> solution_list);
    vector<bool> block_correct_mark;
};

#endif /* defined(__Single_Disk_Failure_Recovery__vertex__) */
