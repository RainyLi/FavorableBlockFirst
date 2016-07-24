//
//  variables.h
//  Single Disk Failure Recovery
//
//  Created by 李璐雨 on 16/4/16.
//  Copyright (c) 2016年 李璐雨. All rights reserved.
//

#ifndef Single_Disk_Failure_Recovery_variables_h
#define Single_Disk_Failure_Recovery_variables_h
#include <vector>
#include <set>
using namespace std;
extern int n, m, k,w;
extern std::vector<vector<bool>> bitm;
extern std::vector<int> min_io_id;
extern int block_number;//the total number of blocks
extern int data_number;
extern int error_disk_id;
extern int first_block;
extern int end_block;
extern set<int> forbid;
#endif
