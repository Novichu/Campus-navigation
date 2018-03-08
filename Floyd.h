#include<iostream>
#include<string>
using namespace std;

class Graph_Fl {
private:
	int vexnum;   //图的顶点个数
	int edge;     //图的边数
	int **arc;   //邻接矩阵
	int ** dis;   //记录各个顶点最短路径的信息
	int ** path;  //记录各个最短路径的信息
public:
	//构造函数
	Graph_Fl(int vexnum, int edge);
	//析构函数
	~Graph_Fl();
	//创建图
	void createGraph(int a[10][10]);
	//求最短路径
	void Floyd();
	//打印最短路径
	void print_path(Campus c[10]);
};
//构造函数
Graph_Fl::Graph_Fl(int vexnum, int edge) {
	//初始化顶点数和边数
	this->vexnum = vexnum;
	this->edge = edge;
	//为邻接矩阵开辟空间和赋初值
	arc = new int*[this->vexnum];
	dis = new int*[this->vexnum];
	path = new int*[this->vexnum];
	for (int i = 0; i < this->vexnum; i++) {
		arc[i] = new int[this->vexnum];
		dis[i] = new int[this->vexnum];
		path[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; k++) {
			//邻接矩阵初始化为无穷大
			arc[i][k] = INT_MAX;
		}
	}
}
//析构函数
Graph_Fl::~Graph_Fl() {

	for (int i = 0; i < this->vexnum; i++) {
		delete this->arc[i];
		delete this->dis[i];
		delete this->path[i];

	}
	delete dis;
	delete arc;
	delete path;
}

// 判断我们每次输入的的边的信息是否合法
//顶点从1开始编号
void Graph_Fl::createGraph(int a[10][10]) {
	for (int i = 0; i < this->vexnum; i++) {
		arc[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; k++) {

			arc[i][k] = a[i][k];
		}
	}
}



void Graph_Fl::Floyd() {
	int row = 0;
	int col = 0;
	for (row = 0; row < this->vexnum; row++) {
		for (col = 0; col < this->vexnum; col++) {
			//把矩阵D初始化为邻接矩阵的值
			this->dis[row][col] = this->arc[row][col];
			//矩阵P的初值则为各个边的终点顶点的下标
			this->path[row][col] = col;
		}
	}

	//三重循环，用于计算每个点对的最短路径
	int temp = 0;
	int select = 0;
	for (temp = 0; temp < this->vexnum; temp++) {
		for (row = 0; row < this->vexnum; row++) {
			for (col = 0; col < this->vexnum; col++) {
				//为了防止溢出，所以需要引入一个select值
				select = (dis[row][temp] == INT_MAX || dis[temp][col] == INT_MAX) ? INT_MAX : (dis[row][temp] + dis[temp][col]);
				if (this->dis[row][col] > select) {
					//更新我们的D矩阵
					this->dis[row][col] = select;
					//更新我们的P矩阵
					this->path[row][col] = this->path[row][temp];
				}
			}
		}
	}
}

void Graph_Fl::print_path(Campus c[10]) {
	cout << "各个顶点对的最短路径：" << endl;
	int row = 0;
	int col = 0;
	int temp = 0;
	for (row = 0; row < this->vexnum; row++) {
		for (col = row + 1; col < this->vexnum; col++) {
			
			cout << c[row ].namelist << "---" << c[col ].namelist<< " 距离 "
				<< this->dis[row][col] << " 路径是 " << c[row].namelist;
			temp = path[row][col];
			//循环输出途径的每条路径。
			while (temp != col) {
				cout << "-->" << c[temp ].namelist;
				temp = path[temp][col];
			}
			cout << "-->" << c[col ].namelist << endl;
		}

		cout << endl;
	}
}