#include "mstring.h"
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int mstrlen(char *str){
	char *dummy;
	int len=0;
	dummy = str;
	while(*dummy != '\0'){
		len++;
		++dummy;
	}
	return len;
}
char *mstrcat(char *dest, char *source){
	int dest_len = mstrlen(dest);
	int temp = 0;
	while(source[temp] != '\0'){
		dest[dest_len] = source[temp];
		dest_len++;
		temp++;	
	}
	dest[dest_len] = '\0';	
	return dest;
}
int mstrnlen(char *str, int max_len){
	int actual_len;
	actual_len = mstrlen(str);
	if(actual_len < max_len)
		return actual_len;
	else
		return max_len;
}
char *mstrchr(char *str, int chr){
	int value;
	while((*str) != '\0'){
		value = *str;
		if(value == chr)
			return str;
		str++;
	}
	return NULL;
}
char *mstrrchr(char *str, int chr){
	char *tmp;
	int i, value;
	tmp = (char *)malloc(sizeof(char));
	int len_str = mstrlen(str);
	tmp = str;
	i=1;
	while(i <= len_str-1){
		tmp++;
		i++;
	}
	do{
		value = *tmp;
		if(value == chr)
			return tmp;
		tmp--;
	
	}while(tmp != str);
	return NULL;
}
int mstrcmp(char *str1, char *str2){
	int flag = 0;
	while((*str1) != '\0' || (*str2) != '\0'){
		if((*str1) > (*str2))
			flag = 1;
		else if((*str1) == (*str2))
			flag = 0;
		else
			flag = -1;
		str1++;
		str2++;
	}
	return flag;
}
char *mstrcpy(char *str1, char *str2){
	str1 = str2;
	return str1;
}
char *mstrncpy (char *dest,char *source, int num){
	int i = 0;
	char *helper;
	helper = (char *)malloc(sizeof(source));
	while(i < num){
		*(helper + i) = *(source + i);
		i++;
	}
	dest = helper;
	return dest;
}
/*char *mstrtok(char *str){
	/*char *dummy[5];
	int i = 0, temp = 0;	
	for(i = 0; i < 5; i++){
		dummy[i] = (char *)malloc(sizeof(char));
	}
	i = 0;
	while(*str != '\0'){
		if(isalnum(*str)){
			dummy[i][temp] = *str; 
			temp++;
			str++;
			continue;
		}			
		if(*str == ' '){
			i++;
			temp = 0;		
		}
		if(*str == '\0'){
			break;
		}
	}*/
	char *dummy, ch;
	/*int i = 0, j = 0;
	while(*str != ' '){
		ch = str[i];
		printf("\n\n\t##%c", ch);
		if(isalnum(ch)){
			dummy[i] = str[i];
			i++;	
		}
		str[i] = '\0';
		/*else if(str[i] == ' '){
			str[i] = '\0';
			return dummy;
		}
	//}
	while(*str != ' '){
		i++;
	}
	return dummy;
}*/
char *mstrtok(char *str){
	char arr[20], *dummy = NULL;
	int i = 0;
	while(*str != '\0'){
		if(*str != ' '){
			arr[i] = *str;
			i++;
			str++;
		}
		else{
			arr[i] = '\0';
			dummy = arr;
			break;
		}
	}
	return dummy;
}
char *mstrdup(char *dup){
	char *str;
	str = (char *)malloc(sizeof(char));
	str = dup;
	return str;
}
char *mstrlwr(char *str){
	int ch, i = 0;
	while(str[i] != '\0'){
		ch = str[i];
		if(ch >= 65 && ch <= 90){
			str[i] = str[i] + 32;
		}
		i++;
	}
	return str;
}
char *mstrupr(char *str){
	int ch, i = 0;
	while(str[i] != '\0'){
		ch = str[i];
		if(ch >= 97 && ch <= 122){
			str[i] = str[i] - 32;
		}
		i++;
	}
	return str;
}
