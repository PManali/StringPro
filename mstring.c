#include "mstring.h"
#include<stdio.h>
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
	return dest;
}
/*char *mstrcat(char *dest, char *source){
	int counter = 0, dest_len = 0;
	//dest = (char *)realloc(dest, mstrlen(source));
	dest_len = mstrlen(dest);
	//*(dest+dest_len) = source;
	while((*source + counter) != '\0'){
		printf("**%c", (*(dest+dest_len)));
		*(dest+dest_len) = *(source + counter);
		counter++;
		dest_len++;
	}
	*(dest + dest_len) = '\0';
	return dest;
}
/*	mstrchr() finds the first occurence in the string
*/
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
	//tmp = *(str[len_str-1]);
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
		//helper++;
	}
	dest = helper;
	return dest;
}
