/* Name:Samantha Craig
   Class:CS4280
   Project 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "tree.h"
//void free_tree(struct node_t*);
int main(int argc, char**argv)
{
        if(argc==1)
        {
	/*	char string;
		input=stdin;
		FILE* temp;
		temp=fopen("temp.txt","w");
		while(string!=*/
        }
	char* filename=argv[1];
	struct node_t* root;
	root=buildTree(filename);
	if(root==NULL)
	{
		exit(1);
	}
//	free_tree(root);
	//printPreorder(root,0,filename);			
}
/*void free_tree(struct node_t* nodeP)
{
	if(nodeP!=NULL)
	{
		free_tree(nodeP->left);
		free_tree(nodeP->right);
		free(nodeP);
	}
}*/
