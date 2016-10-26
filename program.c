#include<stdio.h>
#include<stdlib.h>
#include "mstring.h"
char *readline(char inputarr1[]){
	char *str;
	int i = 0;
	char mych;
	while((mych = getchar()) != '\n') {
		inputarr1[i] = mych;
		i++;
	}
	inputarr1[i] = '\0';
	str = &(inputarr1[0]);
	return str;
}
int main(){
	int ch, string_to_use, n, len_return_strtok, loop_strtok;
	char *input3,*input1, *input2, *return_result, *tokens;
	char inputarr1[20], inputarr2[20], dummy_search_ch;
	char *str;
	int len, i, return_val, ch1, len_dummy, search_ch, input1_counter, mych;
	printf("Enter two strings : \n");
	input3 = readline(inputarr1);
	input2 = readline(inputarr2);
	label :
		while(1){
		printf("\t|1. Single string Manipulation\n\t|2. Two string Manipulation\n\t|0. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("String to use 1st or 2nd ?");
				scanf("%d", &string_to_use);
				if(string_to_use == 1)
					input1 = input3;
				else
					input1 = input2;
				while(1){
					printf("\n----------------------------------------------------------\n");
					printf("\t1. Length\n\t2. Max Length\n\t3. Search char\n\t4. Search char(reverse)\n\t0. Main Menu");
					printf("\n----------------------------------------------------------\n");
					scanf("%d", &ch1);
					
					switch(ch1){
						case 1:
							printf("Length : %d\n", mstrlen(input1));
							break;
						case 2:
							scanf("%d", &len_dummy);
							printf("Max length : %d\tActual length : %d\n", len_dummy, mstrnlen(input1,len_dummy));
							break;
						case 3:
							//scanf("%c", &dummy_search_ch);
							dummy_search_ch = getchar();
							search_ch = dummy_search_ch;
							printf("Search string : %s\n", mstrchr(input1, search_ch));
							break;
						case 4:
							scanf("%c", &(dummy_search_ch));
							search_ch = dummy_search_ch;
							printf("Reverse Search string : %s\n", mstrrchr(input1, search_ch));
							break;
						case 0:
							goto label;
						default:
							printf("Invalid Choice");
					}
				}
				break;
			case 2:
				while(1){
					printf("\n----------------------------------------------------------\n");
					printf("\t1. Comparison\n\t2. Concat\n\t3. Copy\n\t4. Copy n characters\n\t5. Strtok\n\t6. Strdup\n\t7.mstrlwr \n\t8.strupr\n\t0. Main Menu");
					printf("\n---------------------------------------------------------\n");					
					scanf("%d", &ch1);
					switch(ch1){
						case 1:
							return_val = mstrcmp(input3, input2);
							if(return_val == 0)
								printf("Strings are equal");
							else if(return_val > 0)
								printf("Greater String %s",input3);
							else
								printf("Greater String %s",input2);
							break;
						case 2:
							input3 = mstrcat(input3, input2);
							printf("Concated String : %s\n", input3);
							break;
						case 3:
							input3 = mstrcpy(input3, input2);
							printf("String 1: %s\nString 2: %s\n",input3, input2);
							break;
						case 4:
							printf("How many characters to copy : ");
							scanf("%d", &n);
							input3 = mstrncpy(input3, input2, n);
							printf("String 1: %s\nString 2: %s\n",input3, input2);					
							break;
						case 5:
							tokens = mstrtok(input3);
							str = input3;

							printf("Token : %s\n", tokens);
							len_return_strtok = mstrlen(tokens);
							tokens = NULL;
							while(str != NULL){
								if(tokens == NULL)
								len_return_strtok = mstrlen(str);
								loop_strtok = 0;
								while(loop_strtok <= len_return_strtok){
									str++;
									//printf("\n\n\t&&& str value : %c", *str);
									loop_strtok++;
								}
								//printf("\n\n\t\tAdditional : %s", str);
								str = mstrtok(str);
								printf("Token : %s\n", str);					
							}
							break;
						case 6:
							return_result = mstrdup(input3);
							printf("str dup : %s", return_result);
							break;
						case 7:
							return_result = mstrlwr(input3);
							printf("strlwr : %s", return_result);
							break;
						case 8:
							return_result = mstrupr(input3);
							printf("strupr : %s", return_result);
							break;
						case 0:
							goto label;

					}
				}
				break;
			case 0:
				return 0;
			default:
				printf("Wrong choice !");
		}
	}
	return 0;
}
