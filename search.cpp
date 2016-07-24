//
//  search.cpp
//  Single Disk Failure Recovery
//
//  Created by 李璐雨 on 16/4/16.
//  Copyright (c) 2016年 李璐雨. All rights reserved.
//

#include "search.h"

void dijistra::get_minimum_cost(vector<solution> solution_list)
{
    vertex start;//the start vertex has no block_number in reality  and is assumed requiredNumber-1
    start.initialize(error_disk_id*w-1);
    start.parent_id=-1;
    for(int i=0;i<block_number;i++)
        start.scheme[i]=false;
    for(int i=0;i<w;i++)
        start.block_correct_mark[i]=false;
    start.distance=0;
    start.id=(int)vertex_list.size();
    vertex_list.push_back(start);
    while(true)
    {
        vertex* next_vertex=get_next_nearest_vertex();
        if(next_vertex==NULL)
            break;
        next_vertex->marked=true;
        next_vertex->insert_next_vertex(vertex_list, solution_list);
    }

    return;
}

vertex* dijistra::get_next_nearest_vertex()
{
    vertex *nearest_vertex=NULL;
    vertex *temp;
    int size=(int)vertex_list.size();
    int min_dis=-1;
    for(int i=0;i<size;i++)
    {
        temp=&vertex_list[i];
        if(min_io_id.size()!=0&&temp->distance>vertex_list[min_io_id[0]].distance)
        //means the end of the tree has been reached and this vertex is futher than the end
        //this vertex should be pruned
        {
            temp->pruned=true;
        }
        else if(temp->pruned==false&&temp->marked==false&&((min_dis==-1)||(temp->distance<min_dis)))
        {
           nearest_vertex=temp;
           min_dis=temp->distance;
        }
    }
    return nearest_vertex;//NULL means all the vertex is marked or been pruned
}
