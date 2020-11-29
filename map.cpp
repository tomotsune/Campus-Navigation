//
// Created by tomot on 2020/11/29.
//
#include "map.h"

map::map() {
    //init
    createGraph();
    // init dis vector, it describe a original distance between the first and other vertices.
    book[1] = 1;
}

void map::dijkstra() {
    // init dis
    for (int i = 1; i < n + 1; ++i) {
        dis[i] = e[1][i];
    }
    // the core algorithm of dijkstra
    for (int i = 1; i < n - 1; ++i) {
        // find the closest vertices.
        int min = inf;
        int u;
        for (int j = 1; j < n + 1; ++j) {
            if (book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for (int v = 0; v < n + 1; ++v) {
            if (e[u][v] < inf) {
                if (dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
    }
    // TODO
    // you should get a vertex sequence of the shortest path
    // and put it into "path".
}

void map::floyd_warshall() {
    for (int k = 0; k < n + 1; ++k) {
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                if (e[i][j] > e[i][k] + e[k][j])
                    e[i][j] = e[i][k] + e[k][j];
                // TODO
                // you should get a vertex sequence of the shortest path
                // and put it into "path".
            }
        }
    }
}

void map::show_disjkstra() {
// input the final result.
    int target{};
    cout << "please type the index of the target place you wanna be" << endl;
    cin >> target;
    cout << "最短距离为：" << dis[target] << endl;
    // todo
    // should output vertex sequence of the shortest path
}

void map::show_floyd() {
    int from{}, to{};
    cout << "请输入两地点序号" << endl;
    cout << "地点一：";
    cin >> from;
    cout << "地点二：";
    cin >> to;
    cout << "最短距离为：" << distance[from][to] << endl;
    cout << "最短路径为：";
    int temp = from;
    int flag = false;
    // WARRING:
    // I update the dependent data structure.
    // the flowing code is right yet?
    while (true) {
        cout << (vexs[temp]).placename;
        if (flag == true) break;
        if (path[temp][to] == to) flag++;
        temp = path[temp][to];
        cout << "->";
    }
    cout << endl;
}

void map::createGraph() {
    n = 7;
    m = 10;
    vexNode vex1, vex2, vex3, vex4, vex5, vex6, vex7;
    vex1.placename = "主楼";
    vex1.introduction = "黑龙江大学主楼建筑风格为折衷式，融合了俄罗斯社会主义民族风格的基本框架和中国建筑的装饰，是哈尔滨近现代建筑中的代表。黑龙江大学主楼，与哈尔滨工业大学主楼、黑龙江中医院大学主楼 被国家文化部誉为全国高校“俄罗斯社会主义民族风格”教学主楼三大经典作品，是国家级一类保护建筑（全国重点文物保护工程）。黑龙江大学主楼现为黑龙江大学-外国语学部（俄语学部、西方语言研究院、东方语言研究院）以及学校校长办公室、党委等行政机关等教学单位用楼。";
    vex2.placename = "图书馆";
    vex2.introduction = "黑龙江大学图书馆是历史悠久、馆藏丰富的高校图书馆，学校图书馆各类藏书1058万册。黑龙江大学图书馆，与吉林大学图书馆，已被确定为联合国教科文组织、联合国工业工业发展组织和世界银行的图书馆，也是黑龙江省高校图工委及哈尔滨高校图书馆学会秘书处所在馆。";
    vex3.placename = "体育场";
    vex3.introduction = "体育场为学生体育课主要场地，同时有很多大型活动也在该地举行，每一年的大学生体测也在体育场上进行。同时体育场还有地下部分，地下有乒乓球教室，击剑教室等，在雨天或雪天，也可以在地下操场进行跑步等体育运动。";
    vex4.placename = "汇文楼";
    vex4.introduction = "汇文楼是同学们上课的主要场所之一，建筑风格与主楼类似，是俄罗斯社会主义风格与中国建筑的混合，内有电梯并且有大量的教室，能够基本满足同学们的上课和自习需求。";
    vex5.placename = "三号楼";
    vex5.introduction = "三号楼是同学们上课的主要场所之一，以专业课居多，一共有六层，以双号教室和单号教室分为了左右两个楼，两个楼之间只有二楼通道互通";
    vex6.placename = "四号楼";
    vex6.introduction = "四号楼是计软学院和创业学院的教学楼，里面有老师办公室，同时计软学院的同学上机课，实验课都在做该楼进行，同时计软学院科协主要活动地点也在四号楼";
    vex7.placename = "艺术楼";
    vex7.introduction = "艺术楼位于黑龙江大学C区，为艺术学院的主要教学地点，内设有考研教室。";
    vexs[1] = vex1;
    vexs[2] = vex2;
    vexs[3] = vex3;
    vexs[4] = vex4;
    vexs[5] = vex5;
    vexs[6] = vex6;
    vexs[7] = vex7;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            G->edges[i][j] = 20000;
//            if (i == j) G->edges[i][j] = 0;
//        }
//    }
    e[1][2] = 50;
    e[2][1] = 50;
    e[1][3] = 70;
    e[3][1] = 70;
    e[2][3] = 30;
    e[3][2] = 30;
    e[3][4] = 20;
    e[4][3] = 20;
    e[2][4] = 40;
    e[4][2] = 40;
    e[4][6] = 35;
    e[6][4] = 35;
    e[6][5] = 10;
    e[5][6] = 10;
    e[6][7] = 45;
    e[7][6] = 45;
    e[5][7] = 45;
    e[7][5] = 45;
    e[3][7] = 100;
    e[7][3] = 100;
    // WARRING:
    // I don't cleared the mind of flowing code.
    // Please verify.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            distance[i][j] = e[i][j];
            path[i][j] = j;
        }
    }
}
void map:: show()
{
    cout<<"************欢迎来到黑大************"<<endl;
    cout<<"*                                  *"<<endl;
    cout<<"*  +----艺术楼（7）----+           *"<<endl;
    cout<<"*  |        |          |           *"<<endl;
    cout<<"*  |    四号楼（6）—三号楼（5）   *"<<endl;
    cout<<"*  |        |                      *"<<endl;
    cout<<"*  |    汇文楼（4）----+           *"<<endl;
    cout<<"*  |        |          |           *"<<endl;
    cout<<"*  +----体育场（3）—图书馆（2）   *"<<endl;
    cout<<"*           |          |           *"<<endl;
    cout<<"*         主楼（1）----+           *"<<endl;
    cout<<"*                                  *"<<endl;
    cout<<"************************************"<<endl;
}