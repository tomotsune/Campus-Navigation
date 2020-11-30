//
// Created by tomot on 2020/11/29.
//
#include <stack>
#include "map.h"

map::map() {
    // init
}

void map::dijkstra() {
    // this algorithm need to init flowing three vectors
    final[0] = true,
            dist[0] = 0;
    path[0] = -1;
    for (int i = 1; i < MAX_VERTEX_NUM; ++i) {
        final[i] = false;
        dist[i] = arcs[0][i].wight;
        path[i] = (arcs[0][i].wight == INT_MAX) ? -1 : 0;
    }

    // n-1 轮处理, 找到还没确定最短路径, 且dist最短的顶点vi, 令final[i]=true.
    // 并检查所有邻接自Vi的顶点, 对于邻接自Vi的顶点Vj,
    // 若final[j]=false且dist[i]+arcs[i][j]<dist[j], 则令dist[j]=arcs[i][j];
    // path[j]=i; arcs表示两点间弧权值.

    // the core algorithm of dijkstra
    // find the closest vertices.
    for (int i = 0; i < MAX_VERTEX_NUM; ++i) {
        EdgeType min{INT_MAX};
        int index{};
        for (int j = 1; j < MAX_VERTEX_NUM; ++j) {
            if (!final[j] && dist[j] < min) {
                if (dist[j] < min) {
                    min = dist[j];
                    index = j;
                }
            }
        }
        // find all out-edges of node i.
        for (int j = 0; j < MAX_VERTEX_NUM; ++j) {
            if (dist[i] + arcs[i][j].wight < dist[j]) {
                dist[j] = arcs[i][j].wight;
                path[j] = i;
            }
        }
    }

}

//void map::floyd_warshall() {
//    for (int k = 0; k < n + 1; ++k) {
//        for (int i = 0; i < n + 1; ++i) {
//            for (int j = 0; j < n + 1; ++j) {
//                if (e[i][j] > e[i][k] + e[k][j])
//                    e[i][j] = e[i][k] + e[k][j];
//                // TODO
//                // you should get a vertex sequence of the shortest path
//                // and put it into "path".
//            }
//        }
//    }
//}

void map::show_disjkstra() {
// input the final result.
    int target{};
    cout << "please type the index of the target place you wanna be" << endl;
    cin >> target;
    cout << "最短距离为：" << dist[target] << endl;
    cout << "路径为: " << endl;
    int index{target};
    std::stack<int> s;
    s.push(target);
    while (index != -1) {
        s.push(path[index]);
        index=path[index];
    }
    while(!s.empty()){
        cout<<s.top()<<"-->";
        s.pop();
    }
}

//void map::show_floyd() {
//    int from{}, to{};
//    cout << "请输入两地点序号" << endl;
//    cout << "地点一：";
//    cin >> from;
//    cout << "地点二：";
//    cin >> to;
//    cout << "最短距离为：" << distance[from][to] << endl;
//    cout << "最短路径为：";
//    int temp = from;
//    int flag = false;
//    // WARRING:
//    // I update the dependent data structure.
//    // the flowing code is right yet?
//    while (true) {
//        cout << (vexs[temp]).placename;
//        if (flag == true) break;
//        if (path[temp][to] == to) flag++;
//        temp = path[temp][to];
//        cout << "->";
//    }
//    cout << endl;
//}


