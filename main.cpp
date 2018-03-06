#include"Floyd.h"
#include"Dijkstra.h"
#include"campus.h"
Distance d;
Campus c[10] = { Campus(1, "东门"), Campus(2, "食堂"), Campus(3, "宿舍一"), Campus(4, "宿舍二"), Campus(5, "西门"), Campus(6, "澡堂"), Campus(7, "教学楼一"), Campus(8, "教学楼二"), Campus(9, "图书馆"), Campus(10, "操场") };
int vexnum = 10; int edge = 19;


void getcampus(){

	for (int i = 0; i < 10; i++){
		cout << "景点编号 " << c[i].number << "\t景点名称  " << c[i].namelist << endl;
	}
}

void memulist(){
	cout << "\t输入想要实现的功能" << endl;
	cout << "\t1 输出景点信息" << endl;
	cout << "\t2 输出相邻景点之间距离的信息" << endl;
	cout << "\t3 修改两个相邻景点之间的距离" << endl;
	cout << "\t4 输出给定两个景点之间的最短路径和距离" << endl;
	cout << "\t5 输出任意景点到其他各点的最短路径和距离" << endl;
	cout << "\t6 退出";
}
void twopartdistance(){

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j< 10; j++)
		{
			if (d.a[i][j] == INT_MAX)continue;
			if (i == j)continue;

			cout << c[i].namelist << "\t和\t" << c[j].namelist << "\t之间的距离为\t" << d.a[i][j] << endl;
		}


	}

}

void settwopartdiatance(){
	while (1){
		int i, j, x;
		cout << "输入要改变景点之间距离的的两个景点的编号和要更改成的距离" << endl;
		cin >> i >> j >> x;
		if (i<1 || i>10 || j<1 || j>10 || x < 0){ cout << "输入错误值请重新输入" << endl; continue; }
		if (d.a[i][j] == INT_MAX){ cout << "输入的景点不相邻，请确认后重新输入" << endl; continue; }
		if (i == j){ cout << "原地踏步，请重新输入" << endl; continue; }

		d.a[i - 1][j - 1] = x;
		d.a[j - 1][i - 1] = x;
		twopartdistance();
		cout << "\n\t修改成功\n" << endl; break;
	}
}
void twopointditance(){
	int begin;
	cout << "输入起始点景点的编号" << endl;
	cin >> begin;
	Graph_Di graph(vexnum, edge);
	graph.createGraph(d.a);
	graph.Dijkstra(begin);
	graph.print_path(begin);
}
void anywheredistance(){
	Graph_Fl graph(vexnum, edge);
	graph.createGraph(d.a);
	graph.Floyd();
	graph.print_path();
}


void main()
{


	int order = 1;	d.distance();
	while (!(order == 6)){
		memulist();
		cout << "输入命令" << endl;
		cin >> order;

		switch (order){
		case 1:getcampus(); break;
		case 2:twopartdistance(); break;
		case 3:settwopartdiatance(); break;
		case 4:twopointditance(); break;
		case 5:anywheredistance(); break;
		default:cout << "输入错误请重新输入正确的指令" << endl; break;
		}

	}
}