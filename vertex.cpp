//
//  vertex.cpp
//  Single Disk Failure Recovery
//
//  Created by 李璐雨 on 16/4/16.
//  Copyright (c) 2016年 李璐雨. All rights reserved.
//

#include "vertex.h"

void vertex::initialize(int blockid)
{
    //use blockid and solutionid can locate specific vertex in graph
    block_id=blockid;
    id=0;
    marked=false;
    pruned=false;
    scheme.resize(block_number);
    block_solution.resize(block_number);
    block_correct_mark.resize(w);
    return;
}

//insert all the leaves grows from this vertex
bool vertex::insert_next_vertex(vector<vertex> &vertex_list, vector<solution> solution_list)
{
    vertex temp;
    temp.scheme=scheme;
    temp.block_correct_mark=block_correct_mark;
    temp.block_id=block_id;
    temp.distance=distance;
    temp.id=id;
    //if reaching the end of the tree
    if(block_id==(end_block-1))
    {
        int s=min_io_id.size();
        if(s==0||vertex_list[min_io_id[0]].distance==distance)
        {
            min_io_id.push_back(temp.id);
        }
        else if(vertex_list[min_io_id[0]].distance>distance)
        {
            min_io_id.clear();
            min_io_id.push_back(temp.id);
        }
        return true;
    }

    //otherwise
    int next_block_id=block_id+1;

    //that's weird, all the vairables of "this" become random after visited, so i have to save it in advance
    for(int i=0;i<solution_list[next_block_id-first_block].equation_count;i++){
        //i is the equation id for a specific solution
        vertex new_vertex;
        bool flag=true;
        new_vertex.initialize(block_id+1);
        for(int t=0;t<w;t++)
            new_vertex.block_correct_mark[t]=temp.block_correct_mark[t];
        if(temp.block_id!=-1)
            new_vertex.block_correct_mark[temp.block_id]=true;
        int dis=0;
        bool a;
        bool b;
        for(int t=0;t<block_number;t++)
        {
            a=temp.scheme[t];
            b=(solution_list[next_block_id-first_block].equation_list)[i][t];
            new_vertex.scheme[t]=a||b;
            new_vertex.block_solution[t]=b;
            if(new_vertex.scheme[t]!=temp.scheme[t])
            {
                if(t>=first_block&&t<end_block&&t!=new_vertex.block_id&&new_vertex.block_correct_mark[t-first_block]==false)
                    flag=false;
                dis++;
            }
        }
        new_vertex.distance=temp.distance+dis;
        new_vertex.id=vertex_list.size();
        new_vertex.parent_id=temp.id;
        if(flag)
            vertex_list.push_back(new_vertex);
    }

    return false;
}
