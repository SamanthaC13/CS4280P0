/* Name:Samantha Craig
   Class:CS4280
   Project 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"node.h"
#include"tree.h"
int main(int argc, char**argv)
{
	FILE* input;
        if(argc==1)
        {
	/*	char string;
		input=stdin;
		FILE* temp;
		temp=fopen("temp.txt","w");
		while(string!=*/
        }
        else
        {
		char*filename=argv[1];
		char* extenstion=".f2021";
		char* period=".";
		if(strstr(filename,".f2021")!=NULL)
		{
			filename=argv[1];
		}
		else if (strstr(filename,period)!=NULL)
		{
			printf("Error! You have entered an incorrect file extension for input file please use an input file with the extension .f2021.\nAborting the Program");
			exit(1);
		}
		else
		{
			filename= strcat(argv[1],".f2021");
		}
	}
	root=buildTree(filename)	
	}		
}
