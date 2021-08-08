#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;
#define INF 0x3f3f3f3f

#define NumVertices 50//顶点数
struct EdgeData
{
	bool isEdge;//两点间存在边则为true,default false
	int distance;//距离defaultINF
	int direction;//方向default-1,从左向右的方向        
	/*         N 0
	*      NW 7    NE 1
	*    W 6           E 2
	*      SW 5     SE 3
	           S 4
	*/
};
struct VertexData
{
	string code;//编号,唯一标识码 default -1
	string location_name;//景点名称default "NULL"
	string discribe;//描述
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
	VertexData vexlist[NumVertices];//顶点表
	EdgeData edge[NumVertices][NumVertices];//邻接矩阵--边表，顶点之间的关系,只取用上三角（left<right）

	int n, e;//图的顶点数与边数
	int vex_now;//当前vexlist最后一个的下标
	EdgeData initEdge = {false,INF,-1};
	VertexData initVertex = {"-1","NULL", "it's a default discribe" };
	string output[50][50];//*表示路径每个*表示50米
	location vexLocation[NumVertices];//顶点在输出图中的位置
};


