#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pcsource{
	double x;
	double y;
	double z;
	double probability;
}pcsource;

typedef struct _angTreeNode{
	int Sample;
	double Cnt;
	int Start;
	int End;
	double x,y,z;
	double clowbound,c2lowbound,slowbound;
	struct _angTreeNode *lptr;
	struct _angTreeNode *rptr;
}angTreeNode;