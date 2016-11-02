/*************************************************************************
*    Copyright (C) 2016  Manali Pawar pawarmr16.it@coep.ac.in
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.0
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>
*************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include "mstring.h"
#include "mstringfunc.h"
int findfunction(char *str){
	int i;	
	for(i = 0; i < 20; i++){
		if(strcmp(str, functions[i]) == 0)
			return i;
	}
	return -1;
}
int main(){
	char line [120];
    	FILE *fp;
	char *testid, *test_function, *input1, *input2, *input3, *output, *exoutput; 
	char *token, *result;
	int i = 0, int_result, j, k, flag = 0; 
	token = (char *)malloc(sizeof(char));
	result = (char *)malloc(sizeof(char));
	int funcall;
	fp=fopen("testcase.txt", "r");
	if (fp == NULL) 
		perror ("error opening file");
    	else{
		while(fgets(line, 100, fp) != NULL){
			token = strtok(line, " ");
			if(token != NULL){
				testid = token;
				printf("\n\t|%s", testid);
				token = strtok(NULL, " ");
				test_function = token;
				printf("\t|%s", test_function);
			}
			else{
				printf("NO TOKEN");
			}	
			funcall = findfunction(test_function);
			switch(funcall){
				case 0:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL, " ");
					exoutput = token;
					i = atoi(exoutput);
					int len = mstrlen(input1);
					if(len == i)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 1:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrdup(input1);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 2:
					token = strtok(NULL,"\"");
					input1 = token;	
					token = strtok(NULL, "\"");
					input2 = token;
					result = mstrtok(input1, input2);
					token = strtok(NULL, "\"");
					exoutput = token;
					if(strcmp(exoutput, result) != 0){
						printf("\t[FAIL]");
						break;
					}
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrtok(NULL, input2);
					if(strcmp(exoutput, result) != 0){
						printf("\t[FAIL]");
						break;
					}
					printf("\t[PASS]");
					break;
				case 3:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrlwr(input1);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 4:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrupr(input1);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 5:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrrev(input1);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 6:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL,"\"");
					input2 = token;
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrcat(input1, input2);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 7:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL,"\"");
					input2 = token;
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrstr(input1, input2);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 8:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL,"\"");
					input2 = token;
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrrstr(input1, input2);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 9:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL,"\"");
					input2 = token;
					token = strtok(NULL, " ");
					exoutput = token;
					i = atoi(exoutput);
					int_result = mstrcmp(input1, input2);
					if(int_result == i)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 10:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL,"\"");
					input2 = token;
					token = strtok(NULL, " ");
					exoutput = token;
					i = atoi(exoutput);
					int_result = mstrcmpi(input1, input2);
					if(int_result == i)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 11:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL,"\"");
					input2 = token;
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrcpy(input1, input2);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 12:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL," ");
					input2 = token;
					j = atoi(input2);
					token = strtok(NULL, " ");
					exoutput = token;
					i = atoi(exoutput);
					int_result = mstrnlen(input1, j);
					if(int_result == i)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 13:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL," ");
					input2 = token;
					j = input2[0];
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrchr(input1, j);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");					
					break;
				case 14:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL," ");
					input2 = token;
					j = input2[0];
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrrchr(input1, j);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");					
										
					break;
				case 15:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL,"\"");
					input2 = token;
					token = strtok(NULL, " ");
					input3 = token;
					j = atoi(input3);
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrncat(input1, input2, j);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 16:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL,"\"");
					input2 = token;
					token = strtok(NULL, " ");
					input3 = token;
					j = atoi(input3);
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrncpy(input1, input2, j);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 17:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL," ");
					input2 = token;
					j = input2[0];
					token = strtok(NULL, "\"");
					exoutput = token;
					result = mstrset(input1, j);
					if(mstrcmp(exoutput, result) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 18:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL," ");
					input2 = token;
					j = input2[0];
					token = strtok(NULL," ");
					input3 = token;
					k = atoi(input3);
					token = strtok(NULL, "\"");
					exoutput = token;
					mmemset(input1+2, j, k);
					if(mstrcmp(exoutput, input1) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
				case 19:
					token = strtok(NULL,"\"");
					input1 = token;
					token = strtok(NULL," ");
					input3 = token;
					k = atoi(input3);
					token = strtok(NULL, "\"");
					exoutput = token;
					mmemcpy(input1+2, input1+6, k);
					if(mstrcmp(exoutput, input1) == 0)
						printf("\t[PASS]");
					else
						printf("\t[FAIL]");
					break;
			}
			
		}
	}
	printf("\n");
	fclose(fp);
    	return(0);
}
