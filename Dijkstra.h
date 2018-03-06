#include<string>
#include <iostream>
#include<cstdlib>

using namespace std;


struct Dis {
	string path;
	int value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph_Di {
private:
	int vexnum;   //图的顶点个数
	int edge;     //图的边数
	int **arc;   //邻接矩阵
	Dis * dis;   //记录各个顶点最短路径的信息
public:
	//构造函数
	Graph_Di(int vexnum, int edge);
	//析构函数
	~Graph_Di(){};

	void createGraph(int a[10][10]);
	//打印邻接矩阵
	void Dijkstra(int begin);
	//打印最短路径
	void print_path(int);

};
//构造函数
Graph_Di::Graph_Di(int vexnum, int edge) {
	//初始化顶点数和边数
	this->vexnum = vexnum;
	this->edge = edge;
	//为邻接矩阵开辟空间和赋初值
	arc = new int*[this->vexnum];
	dis = new Dis[this->vexnum];
	for (int i = 0; i < this->vexnum; i++) {
		arc[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; k++) {
			//邻接矩阵初始化为无穷大
			arc[i][k] = INT_MAX;
		}
	}
}
void Graph_Di::createGraph(int a[10][10]) {

	for (int i = 0; i < this->vexnum; i++) {
		arc[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; k++) {

			arc[i][k] = a[i][k];
		}
	}
}



void Graph_Di::Dijkstra(int begin){
	//首先初始化我们的dis数组
	int i;
	for (i = 0; i < this->vexnum; i++) {
		//设置当前的路径
		dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	//设置起点的到起点的路径为0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;

	int count = 1;
	//计算剩余的顶点的最短路径（剩余this->vexnum-1个顶点）
	while (count != this->vexnum) {
		//temp用于保存当前dis数组中最小的那个下标
		//min记录的当前的最小值
		int temp = 0;
		int min = INT_MAX;
		for (i = 0; i < this->vexnum; i++) {
			if (!dis[i].visit && dis[i].value<min) {
				min = dis[i].value;
				temp = i;
			}
		}
		//cout << temp + 1 << "  "<<min << endl;
		//把temp对应的顶点加入到已经找到的最短路径的集合中
		dis[temp].visit = true;
		++count;
		for (i = 0; i < this->vexnum; i++) {
			//注意这里的条件arc[temp][i]!=INT_MAX必须加，不然会出现溢出，从而造成程序异常
			if (!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value) {
				//如果新得到的边可以影响其他为访问的顶点，那就就更新它的最短路径和长度
				dis[i].value = dis[temp].value + arc[temp][i];
				dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);
			}
		}
	}

}
void Graph_Di::print_path(int begin) {
	string str;
	str = "v" + to_string(begin);
	cout << "以" << str << "为起点的图的最短路径为：" << endl;
	for (int i = 0; i != this->vexnum; i++) {
		if (dis[i].value != INT_MAX)
			cout << dis[i].path << "=" << dis[i].value << endl;
		else {
			cout << dis[i].path << "是无最短路径的" << endl;
		}
	}
}