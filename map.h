//
// Created by tomot on 2020/11/29.
//

#ifndef CAMPUS_NAVIGATION_MAP_H
#define CAMPUS_NAVIGATION_MAP_H

#include <iostream>

using namespace std;
struct vexNode {
    string placename;
    string introduction;
};

class map {

private:
    vexNode vexs[50];
    int n{}, m{};   // num of vertexes and edges.
    int e[10][10]{};
    int dis[10]{}; // for dijkstra
    int distance[10][10]{}; // for floyd
    int book[10]{};
    int path[10][10]{};
    static const int inf = 99999999; // infinity.
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
