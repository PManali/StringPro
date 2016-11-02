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
#ifndef _STRING_H_
#define _STRING_H_
int mstrlen(char *);
char *mstrdup(char *);
char *mstrtok(char *, char *);
char *mstrlwr(char *);
char *mstrupr(char *);
char *mstrrev(char *);
char *mstrcat(char *, char *);
char *mstrstr(char *, char *);
char *mstrrstr(char *, char *); 
int mstrcmp(char *, char *); 
int mstrcmpi(char *, char *);
char *mstrcpy(char *, char *);
int mstrnlen(char *, int);
char *mstrchr(char *, int);
char *mstrrchr(char *, int);
char *mstrncat(char *, char *, int);
char *mstrncpy(char *,char *, int);
char *mstrset(char *, int);
void *mmemset(void *, int, int);
void *mmemcpy(void *, void *, int);
#endif
