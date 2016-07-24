//
//  main.cpp
//  Single Disk Failure Recovery
//
//  Created by 李璐雨 on 16/4/11.
//  Copyright (c) 2016年 李璐雨. All rights reserved.


#include "solution.h"
#include "search.h"
#include "variables.h"
#include "erasureCodes.h"
#include "common.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int n, m, k,w;
vector<vector<bool>> bitm;
vector<int> min_io_id;
int block_number;//the total number of blocks
int data_number;
int error_disk_id;
int first_block;
int end_block;
set<int> forbid;

int main() {

    cin>>n;

    clock_t init_time, final_time;
    init_time=clock();

    RDP(n);

    block_number=n*w;//the total number of blocks
    data_number=k*w;
    first_block=w*error_disk_id;
    end_block=first_block+w;


    vector<solution> solution_list(w);
    for(int i=0;i<w;i++)
    {
        solution_list[i].block_id=i+first_block;
        solution_list[i].set_solution();
    }

    error_disk_id=0;
    dijistra s1;
    s1.get_minimum_cost(solution_list);

    final_time=clock()-init_time;
    int picked_scheme_number=(int)min_io_id.size();
    for(int i=0;i<picked_scheme_number;i++)
    {
        int vertex_id=min_io_id[i];
        cout<<"minimum distance: "<<s1.vertex_list[vertex_id].distance<<"\n";
        int parent_idd=s1.vertex_list[vertex_id].id;
        while(parent_idd!=0)
        {
            for(int i=0;i<block_number;i++)
                cout<<s1.vertex_list[parent_idd].scheme[i];
            cout<<"\n";
            parent_idd=s1.vertex_list[parent_idd].parent_id;
        }
        cout<<"\n";
    }
    cout<<"takes "<<(double)final_time/((double)CLOCKS_PER_SEC)<<" seconds";

    return 0;
}


