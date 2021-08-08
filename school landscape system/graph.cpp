#include "graph.h"

//default constructing function
Graph::Graph()
{
	int i, j;
	n = 50;
	e = 50;
	vex_now = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			edge[i][j] = initEdge;
	for (i = 0; i < n; i++)
		vexlist[i] = initVertex;
	for (i = 0; i < n; i++)
		vexLocation[i] = { -1,-1 };
}

//put a vertexdata into the bottom of vexlist
void Graph::insertVertex(VertexData V) {
	int i = 0;
	for (i; i <= vex_now; i++) {
		if (vexlist[i].code == V.code)
			break;
	}
	if (i > vex_now) {
		vexlist[vex_now] = V;
        vex_now++;
		n = vex_now + 1;
		cout << "��ӳɹ�\n";
	}
	else
		cout << "location already exist\n";
}

void Graph::setN(int n)
{
	Graph::n = n;
}

//insert edge into array edge[][]
void Graph::insertEdge(EdgeData E,int left,int right)
{
	if (edge[left][right].isEdge == false)
	{
		edge[left][right] = E;
		e++;
	}
	else
		cout << "route already exist\n";
}

void Graph::setE(int e)
{
	Graph::e = e;
}

int Graph::getN() {
	return n;
}
int Graph::getE() {
	return e;
}

int Graph::getEdgeDistance(int i, int j) {
	return edge[i][j].distance;
}

VertexData Graph::getVexlist(int i) {
	return vexlist[i];
}

string Graph::getVertexName(int k) {
	return vexlist[k].location_name;
}

void Graph::renewVertex(string code, VertexData s) {
	int i;
	i = atoi(code.c_str());
	vexlist[i] = s;
	cout << "�޸ĳɹ�\n";
}

void Graph::deleteVertex(string s) {
	int j,i;
	string name;
	for (j = 0; j <= vex_now; j++) {
		if (vexlist[j].code == s) {
			break;
		}
		if (vexlist[j].location_name == s) {
			s = vexlist[j].code;
			break;
		}
	}
	i = atoi(s.c_str());
	name = vexlist[i].location_name;
	vexlist[i] = initVertex;
	for (j = 0; j < n; j++) {
		edge[i][j] = initEdge;
	}
	for (j = 0; j < n; j++) {
		edge[j][i] = initEdge;
	}
	cout << "����" << name << "��ɾ����һ���Ƴ����·��\n";
}

VertexData Graph::serchVexByCode(string i)
{
	int j;
	for (j=0; j <= vex_now; j++) {
		if (vexlist[j].code ==i) {
			return vexlist[j];
		}
	}
	//cout << "no result by code:" << i << endl;
	return initVertex;
}

VertexData Graph::serchVexByName(string s)
{
	int j;
	for (j = 0; j <= vex_now; j++) {
		if (vexlist[j].location_name == s) {
			return vexlist[j];
		}
	}
	//cout << "no result by name:" << s << endl;
	return initVertex;
}

//draw out the landscape graph
void Graph::print()
{
	int i = 0;
	int j = 1;//j>i
	int k;//����ѭ����
	int tempx=25, tempy=25;
	int tempi, tempj;//��ȡǰ���i�ͺ���j��ֵ����Ϊ��ͼ��
	int tempDirection, tempDistance;//��ȡdir��dis����ͼ
	for (i; i < n; i++) {
		for (j; j < n; j++) {
			if (edge[i][j].isEdge == true) {
				tempDirection = edge[i][j].direction;
				tempDistance = edge[i][j].distance;
				tempi = i, tempj = j;//��ֵ
				if (vexLocation[i].x == -1&&vexLocation[j].x==-1)
				{
					vexLocation[i].x = tempx;
					vexLocation[i].y = tempy;
					output[vexLocation[i].x][vexLocation[i].y] = vexlist[i].location_name;
				}
				else if (vexLocation[i].x == -1 && vexLocation[j].x != -1) {
					tempi = i, tempj = j;
					swap(tempi, tempj);//����tempi��tempj
					tempDirection = (tempDirection + 4) % 8;
				}
				switch (tempDirection)
				{
	/*      N 0
*      NW 7    NE 1
*    W 6           E 2
*      SW 5     SE 3
		   S 4
*/

				case 0://�ڶ����λ�ڵ�һ�ڵ㱱
					tempy = vexLocation[tempi].x;
					tempx = vexLocation[tempi].y;
					output[tempx][tempy] = vexlist[tempi].location_name;
					k = tempDistance / 50;
					for (k; k > 0; k--) {
						output[--tempx][tempy] = "*";
					}
					output[--tempx][tempy] = vexlist[tempj].location_name;
					vexLocation[tempj].x = tempy;
					vexLocation[tempj].y = tempx;
					break;
				case 1://����
					tempy = vexLocation[tempi].x;
					tempx = vexLocation[tempi].y;
					output[tempx][tempy] = vexlist[tempi].location_name;
					k = tempDistance / 50;
					for (k; k > 0; k--) {
						output[--tempx][++tempy] = "*";
					}
					output[--tempx][++tempy] = vexlist[tempj].location_name;
					vexLocation[tempj].x = tempy;
					vexLocation[tempj].y = tempx;
					break;
				case 2://��
					tempy = vexLocation[tempi].x;
					tempx = vexLocation[tempi].y;
					output[tempx][tempy] = vexlist[tempi].location_name;
					k = tempDistance / 50;
					for (k; k > 0; k--) {
						output[tempx][++tempy] = "*";
					}
					output[tempx][++tempy] = vexlist[tempj].location_name;
					vexLocation[tempj].x = tempy;
					vexLocation[tempj].y = tempx;
					break;
				case 3://����
					tempy = vexLocation[tempi].x;
					tempx = vexLocation[tempi].y;
					output[tempx][tempy] = vexlist[tempi].location_name;
					k = tempDistance / 50;
					for (k; k > 0; k--) {
						output[++tempx][++tempy] = "*";
					}
					output[++tempx][++tempy] = vexlist[tempj].location_name;
					vexLocation[tempj].x = tempy;
					vexLocation[tempj].y = tempx;
					break;
				case 4://��
					tempy = vexLocation[tempi].x;
					tempx = vexLocation[tempi].y;
					output[tempx][tempy] = vexlist[tempi].location_name;
					k = tempDistance / 50;
					for (k; k > 0; k--) {
						output[++tempx][tempy] = "*";
					}
					output[++tempx][tempy] = vexlist[tempj].location_name;
					vexLocation[tempj].x = tempy;
					vexLocation[tempj].y = tempx;
					break;
				case 5://����
					tempy = vexLocation[tempi].x;
					tempx = vexLocation[tempi].y;
					output[tempx][tempy] = vexlist[tempi].location_name;
					k = tempDistance / 50;
					for (k; k > 0; k--) {
						output[++tempx][--tempy] = "*";
					}
					output[++tempx][--tempy] = vexlist[tempj].location_name;
					vexLocation[tempj].x = tempy;
					vexLocation[tempj].y = tempx;
					break;
				case 6://��
					tempy = vexLocation[tempi].x;
					tempx = vexLocation[tempi].y;
					output[tempx][tempy] = vexlist[tempi].location_name;
					k = tempDistance / 50;
					for (k; k > 0; k--) {
						output[tempx][--tempy] = "*";
					}
					output[tempx][--tempy] = vexlist[tempj].location_name;
					vexLocation[tempj].x = tempy;
					vexLocation[tempj].y = tempx;
					break;
				case 7://����
					tempy = vexLocation[tempi].x;
					tempx = vexLocation[tempi].y;
					output[tempx][tempy] = vexlist[tempi].location_name;
					k = tempDistance / 50;
					for (k; k > 0; k--) {
						output[--tempx][--tempy] = "*";
					}
					output[--tempx][--tempy] = vexlist[tempj].location_name;
					vexLocation[tempj].x = tempy;
					vexLocation[tempj].y = tempx;
					break;
				default:
					break;
				}
			}
		}
		j = i + 2;
	}
	k = 0;
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			if (output[i][j] != "") {
				cout << output[i][j];
				k = 1;
			}
			else
				cout << " " ;
			}
		//if (k==1) {
			cout << endl;
		//	k = 0;
		//}
	}
}


Graph::~Graph()
{
}