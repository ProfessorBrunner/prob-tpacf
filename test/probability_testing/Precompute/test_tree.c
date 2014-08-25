/* tests the binary tree file to make sure its output is fine after the modifications. */

#include "test.h"

int NodePos;

static angTreeNode *angTreeFill(angTreeNode *root){

/* Fill in pointers in newly read tree */

	angTreeNode *node;
	node = root+NodePos;

	if((int)node->lptr == 1){
		NodePos++;
		node->lptr = angTreeFill(root);
		NodePos++;
		node->rptr = angTreeFill(root);
	}else{
		node->lptr = NULL;
		node->rptr = NULL;
	}

	return node;
}

int main(){
	int max, size;
	FILE *f;
	void *block1;
	angTreeNode *a;

	f = fopen("atest_1.dat0.tree", "r");
	fread(&size, sizeof(int), 1, f);

	printf("%d\n", size);

	max = size;
	block1 = malloc(max*sizeof(angTreeNode));
	if(block1 == NULL)
		printf("%s\n", "poop. stuff went wrong.");
	fread(block1, sizeof(angTreeNode), size, f);
	NodePos = 0;
	if(block1 == NULL)
		fprintf(stderr, "shit. something went wrong again. ");
	block1 = (void *)angTreeFill((angTreeNode *)block1);
	a = (angTreeNode *)block1;
	//printf("%f\n", a->lptr->lptr->lptr->lptr->lptr->lptr->lptr->Cnt);
}