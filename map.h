//
// Created by tomot on 2020/11/29.
//

#ifndef CAMPUS_NAVIGATION_MAP_H
#define CAMPUS_NAVIGATION_MAP_H

#include <iostream>

using namespace std;
#define INT__MAX	   65000										//最大值65535，表示两顶点没有联系
#define MAX_VERTEX_NUM 10											//最多顶点数

typedef char VertexType;
typedef int  EdgeType;


//顶点信息
typedef struct ArcCell {
    EdgeType wight;

}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
class map {
private:
    VertexType vexs[MAX_VERTEX_NUM]{};								//顶点向量
    AdjMatrix  arcs;												//邻接矩阵
    int vexnum{}, arcnum{};
    bool final[MAX_VERTEX_NUM]{}; // 标记各顶点是否找到最短路径
    EdgeType dist[MAX_VERTEX_NUM]{}; // 最短路径长度
    VertexType path[MAX_VERTEX_NUM]{}; // 路径上的前驱
    void createGraph(); // for init
public:

    map();

    void dijkstra();

    void floyd_warshall();

    void show_disjkstra();

    void show_floyd();

    void show();
};


#endif //CAMPUS_NAVIGATION_MAP_H
