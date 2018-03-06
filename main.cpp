#include"Floyd.h"
#include"Dijkstra.h"
#include"campus.h"
Distance d;
Campus c[10] = { Campus(1, "����"), Campus(2, "ʳ��"), Campus(3, "����һ"), Campus(4, "�����"), Campus(5, "����"), Campus(6, "����"), Campus(7, "��ѧ¥һ"), Campus(8, "��ѧ¥��"), Campus(9, "ͼ���"), Campus(10, "�ٳ�") };
int vexnum = 10; int edge = 19;


void getcampus(){

	for (int i = 0; i < 10; i++){
		cout << "������ " << c[i].number << "\t��������  " << c[i].namelist << endl;
	}
}

void memulist(){
	cout << "\t������Ҫʵ�ֵĹ���" << endl;
	cout << "\t1 ���������Ϣ" << endl;
	cout << "\t2 ������ھ���֮��������Ϣ" << endl;
	cout << "\t3 �޸��������ھ���֮��ľ���" << endl;
	cout << "\t4 ���������������֮������·���;���" << endl;
	cout << "\t5 ������⾰�㵽������������·���;���" << endl;
	cout << "\t6 �˳�";
}
void twopartdistance(){

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j< 10; j++)
		{
			if (d.a[i][j] == INT_MAX)continue;
			if (i == j)continue;

			cout << c[i].namelist << "\t��\t" << c[j].namelist << "\t֮��ľ���Ϊ\t" << d.a[i][j] << endl;
		}


	}

}

void settwopartdiatance(){
	while (1){
		int i, j, x;
		cout << "����Ҫ�ı侰��֮�����ĵ���������ı�ź�Ҫ���ĳɵľ���" << endl;
		cin >> i >> j >> x;
		if (i<1 || i>10 || j<1 || j>10 || x < 0){ cout << "�������ֵ����������" << endl; continue; }
		if (d.a[i][j] == INT_MAX){ cout << "����ľ��㲻���ڣ���ȷ�Ϻ���������" << endl; continue; }
		if (i == j){ cout << "ԭ��̤��������������" << endl; continue; }

		d.a[i - 1][j - 1] = x;
		d.a[j - 1][i - 1] = x;
		twopartdistance();
		cout << "\n\t�޸ĳɹ�\n" << endl; break;
	}
}
void twopointditance(){
	int begin;
	cout << "������ʼ�㾰��ı��" << endl;
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
		cout << "��������" << endl;
		cin >> order;

		switch (order){
		case 1:getcampus(); break;
		case 2:twopartdistance(); break;
		case 3:settwopartdiatance(); break;
		case 4:twopointditance(); break;
		case 5:anywheredistance(); break;
		default:cout << "�������������������ȷ��ָ��" << endl; break;
		}

	}
}