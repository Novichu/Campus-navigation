#include<iostream>
#include<string>
using namespace std;

class Graph_Fl {
private:
	int vexnum;   //ͼ�Ķ������
	int edge;     //ͼ�ı���
	int **arc;   //�ڽӾ���
	int ** dis;   //��¼�����������·������Ϣ
	int ** path;  //��¼�������·������Ϣ
public:
	//���캯��
	Graph_Fl(int vexnum, int edge);
	//��������
	~Graph_Fl();
	//����ͼ
	void createGraph(int a[10][10]);
	//�����·��
	void Floyd();
	//��ӡ���·��
	void print_path(Campus c[10]);
};
//���캯��
Graph_Fl::Graph_Fl(int vexnum, int edge) {
	//��ʼ���������ͱ���
	this->vexnum = vexnum;
	this->edge = edge;
	//Ϊ�ڽӾ��󿪱ٿռ�͸���ֵ
	arc = new int*[this->vexnum];
	dis = new int*[this->vexnum];
	path = new int*[this->vexnum];
	for (int i = 0; i < this->vexnum; i++) {
		arc[i] = new int[this->vexnum];
		dis[i] = new int[this->vexnum];
		path[i] = new int[this->vexnum];
		for (int k = 0; k < this->vexnum; k++) {
			//�ڽӾ����ʼ��Ϊ�����
			arc[i][k] = INT_MAX;
		}
	}
}
//��������
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

// �ж�����ÿ������ĵıߵ���Ϣ�Ƿ�Ϸ�
//�����1��ʼ���
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
			//�Ѿ���D��ʼ��Ϊ�ڽӾ����ֵ
			this->dis[row][col] = this->arc[row][col];
			//����P�ĳ�ֵ��Ϊ�����ߵ��յ㶥����±�
			this->path[row][col] = col;
		}
	}

	//����ѭ�������ڼ���ÿ����Ե����·��
	int temp = 0;
	int select = 0;
	for (temp = 0; temp < this->vexnum; temp++) {
		for (row = 0; row < this->vexnum; row++) {
			for (col = 0; col < this->vexnum; col++) {
				//Ϊ�˷�ֹ�����������Ҫ����һ��selectֵ
				select = (dis[row][temp] == INT_MAX || dis[temp][col] == INT_MAX) ? INT_MAX : (dis[row][temp] + dis[temp][col]);
				if (this->dis[row][col] > select) {
					//�������ǵ�D����
					this->dis[row][col] = select;
					//�������ǵ�P����
					this->path[row][col] = this->path[row][temp];
				}
			}
		}
	}
}

void Graph_Fl::print_path(Campus c[10]) {
	cout << "��������Ե����·����" << endl;
	int row = 0;
	int col = 0;
	int temp = 0;
	for (row = 0; row < this->vexnum; row++) {
		for (col = row + 1; col < this->vexnum; col++) {
			
			cout << c[row ].namelist << "---" << c[col ].namelist<< " ���� "
				<< this->dis[row][col] << " ·���� " << c[row].namelist;
			temp = path[row][col];
			//ѭ�����;����ÿ��·����
			while (temp != col) {
				cout << "-->" << c[temp ].namelist;
				temp = path[temp][col];
			}
			cout << "-->" << c[col ].namelist << endl;
		}

		cout << endl;
	}
}