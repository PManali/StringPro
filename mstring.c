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
#include "mstring.h"
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
/*mstrlen : Gives the length of str1*/
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
/*mstrcat : Concatenates str2 at the end of str1*/
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
/*mstrncat : Appends a portion of string to another*/
char *mstrncat(char *str1, char *str2, int t){
	int dest_len = mstrlen(str1);
	if(mstrlen(str2) < t)
		return str1;
	int temp = t-1;
	while(str2[temp] != '\0'){
		str1[dest_len] = str2[temp];
		dest_len++;
		temp++;	
	}
	str1[dest_len] = '\0';	
	return str1;
}
/*mstrnlen : Returns max length if it is greater than actual length of str, otherwise returns actual len*/
int mstrnlen(char *str, int max_len){
	int actual_len;
	actual_len = mstrlen(str);
	if(actual_len < max_len)
		return actual_len;
	else
		return max_len;
}
/*mstrchr : Returns char pointer to first occurence of char chr*/
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
/*mstrrchr : same like mstrchr, but gives last occurence of char chr*/
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
/*mstrcmp :
*	Returns 0 if str1 is same as str2. 
*	Returns <0 if strl < str2. 
*	Returns >0 if str1 > str2
*/
int mstrcmp(char *str1, char *str2){
	int flag = 0;
	while((*str1) != '\0' || (*str2) != '\0'){
		if((*str1) > (*str2))
			flag = 1;
		else if((*str1) == (*str2)){
			if(flag != -1 && flag != 1)
				flag = 0;
		}
		else
			flag = -1;
		str1++;
		str2++;
	}
	return flag;
}
/*mstrcmpi : same as mstrcmp(), but is not case sensitive*/
int mstrcmpi(char *str1, char *str2){
	char *fstr1, *fstr2;
	fstr1 = str1;
	fstr2 = str2;
	int i;
	mstrcpy(fstr1, mstrlwr(fstr1));
	mstrcpy(fstr2, mstrlwr(fstr2));
	i = mstrcmp(fstr1, fstr2);	
	return i;
}
/*mstrcpy : Copies str2 into str1*/
char *mstrcpy(char *str1, char *str2){
	str1 = str2;
	return str1;
}
/*mstrncpy : Copies given number of characters of one string to another*/
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
/*mstrtok : tokenising string str1 with given delimiter*/
char *mstrtok(char *str1, char *delimiter){
	int i = 0, j = 0;
	char *ptr;
	static char *str;
	static int pos;
	if(str1 != NULL){
		str = str1;
		pos = 0;	
	}
	else{
		i = pos;		
		ptr = &(str[pos]);
	}
	while(str[i] != '\0'){
		while(delimiter[j] != '\0'){
			if(str[i] == delimiter[j]){
				str[i] = '\0';
				pos = i+1;
				break;
			}		
			j++;
		}
		if(str[i] == '\0')
			break;
		i++;
		j = 0;
	}
	if(str1 == NULL){
		return ptr;
	}
	return str;
}
/*mstrdup : duplicates the string*/
char *mstrdup(char *dup){
	char *str;
	str = (char *)malloc(sizeof(char));
	str = dup;
	return str;
}
/*mstrlwr : convertes the string to lower case*/
char *mstrlwr(char *str){
	int ch, i = 0;
	while(str[i] != '\0'){
		ch = str[i];
		if(ch >= 65 && ch <= 90){
			str[i] = str[i] + 32;
		}
		else if(ch >= 97 && ch <= 122)
			str[i] = str[i];
		else if(ch == ' ')
			str[i] = ' ';
		else if((ch >= 33 && ch<= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126)){
			str[i] = str[i];
		}
		else{
			return "NULL";
		}
		i++;
	}
	return str;
}
/*mstrupr : convertes the string to upper case*/
char *mstrupr(char *str){
	int ch, i = 0;
	while(str[i] != '\0'){
		ch = str[i];
		if(ch >= 97 && ch <= 122){
			str[i] = str[i] - 32;
		}
		else if(ch >= 65 && ch <= 90)
			str[i] = str[i];
		else if(ch == ' ')
			str[i] = ' ';
		else if((ch >= 33 && ch<= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126)){
			str[i] = str[i];
		}
		else{
			return "NULL";
		}
		i++;
	}
	return str;
}
/*mstrstr : returns the pointer to the first occurence of string str2 in str1*/
char *mstrstr(char *str1, char *str2){
	int i = 0, j = 0, k;
	int len2 = mstrlen(str2);
	char *ptr = NULL;
	while(str1[i] != '\0'){
		k = i;
		while(str2[j] != '\0'){
			if(str1[k] == str2[j]){
				k++;
				j++;
				if(j == len2){
					ptr = &(str1[i]);
					return ptr;
				}
			}
			else{
				i++;
				j = 0;
				break;
			}
		}	
	}
	return ptr;
}
/*mstrrstr : same like mstrstr, but returns last occurence*/
char *mstrrstr(char *str1, char *str2){
	int len1, x, len2, a, i, j;
	char *dummy;
	dummy = (char *)malloc(sizeof(char));
	len1 = mstrlen(str1);
	len2 = mstrlen(str2);
	if(len2 > len1)
		return NULL;
	for(a = len1-1, i = len1-1; i > 0; i--, a--){
		if(str1[i] == str2[len2 - 1]){
			x = a;
			for(j = len2 - 2; j >= 0 ; j--){
				if(str2[j] != str1[--x])
					break;
			}
			dummy = &(str1[x]);
			
			if(j <= len2)
				return dummy;
			else
				return NULL;
		}
	}
	return NULL;
}
/*mstrrev : reverses the string str*/
char *mstrrev(char *str){
	int len, i, j;
	char *dummy = (char *)malloc(sizeof(char));
	len = mstrlen(str);
	for(i = (len-1), j = 0; i >= 0; i--, j++){
		dummy[j] = str[i];
	}
	dummy[j] = '\0';
	return dummy;
}
/*mstrset : sets all the characters in the string to given character*/
char *mstrset(char *str, int ch){
	int i = 0;
	while(str[i]!='\0'){
		str[i] = ch;
		i++;
	}
	return str;
}
/*mmemset : initialize specified numbers of bytes to ch*/
void *mmemset(void *dest, int ch, int count){
	unsigned char *dummy = dest;
	while(count > 0){
		*dummy = ch;
		dummy++;
		count--;
	}
	return dest;
}
/*mmemcpy : copy a specified number of bytes from one memory to another*/
void *mmemcpy(void *dest, void *source, int i){
	unsigned char *ptr1, *ptr2;
	ptr1 = dest;
	ptr2 = source;
	if(i == 0)
		return dest;
	while(i > 0){
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
		i--;
	}
	return dest;
}
