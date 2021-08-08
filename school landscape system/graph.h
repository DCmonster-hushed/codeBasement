#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;
#define INF 0x3f3f3f3f

#define NumVertices 50//������
struct EdgeData
{
	bool isEdge;//�������ڱ���Ϊtrue,default false
	int distance;//����defaultINF
	int direction;//����default-1,�������ҵķ���        
	/*         N 0
	*      NW 7    NE 1
	*    W 6           E 2
	*      SW 5     SE 3
	           S 4
	*/
};
struct VertexData
{
	string code;//���,Ψһ��ʶ�� default -1
	string location_name;//��������default "NULL"
	string discribe;//����
};
struct location
{
	int x;
	int y;
};
class Graph
{
public:
	Graph();
	~Graph();
	void setN(int n);
	void setE(int e);
	int getN();
	int getE();
	int getEdgeDistance(int i, int j);
	string getVertexName(int k);
	VertexData getVexlist(int i);
	void insertVertex(VertexData);
	void insertEdge(EdgeData,int,int);
	void renewVertex(string code, VertexData s);
	void deleteVertex(string);
	VertexData serchVexByCode(string);
	VertexData serchVexByName(string);
	void print();

private:
	VertexData vexlist[NumVertices];//�����
	EdgeData edge[NumVertices][NumVertices];//�ڽӾ���--�߱�����֮��Ĺ�ϵ,ֻȡ�������ǣ�left<right��

	int n, e;//ͼ�Ķ����������
	int vex_now;//��ǰvexlist���һ�����±�
	EdgeData initEdge = {false,INF,-1};
	VertexData initVertex = {"-1","NULL", "it's a default discribe" };
	string output[50][50];//*��ʾ·��ÿ��*��ʾ50��
	location vexLocation[NumVertices];//���������ͼ�е�λ��
};


