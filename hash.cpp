#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_ROW 16

typedef struct _Row{ 
	int index;
	int numara;
	struct _Row *pNext;
}Row;

typedef struct _Table{
	Row rows[MAX_ROW];
}Table;


Table table;

void add_collision(Row *row, Row *startRow);
void initialize_Table();
int RSHash(int no);
void add_Row(int no);
void collision(Row *row, Row *startRow);
int find_row(int no);
void display_Table();


int RSHash(int no){
	return no % MAX_ROW;
}

void initialize_Table(){
	int i;
	for (i = 0; i < MAX_ROW; ++i){
		table.rows[i].index = -1;
		table.rows[i].numara=-1;
		table.rows[i].pNext = NULL;
	}
}

void add_Row(int no){ 
	int hash_index;
	Row *row;
	hash_index = RSHash(no);
	printf("%d ",hash_index);
	if (table.rows[hash_index].index==-1|| (table.rows[hash_index].numara== no)) { 
		table.rows[hash_index].index = hash_index;
		table.rows[hash_index].numara=no;
		return;
	}
	row = (Row *)malloc(sizeof(Row));
	if (!row) {
		puts("yeterli bellek yok!");
		exit(0);
	}
	row->index = hash_index;
	row->numara=no;
	row->pNext=NULL;
	collision(row, &table.rows[hash_index]);
}


void collision(Row *row, Row *startRow){ 
	while(startRow->pNext!=NULL){ 
		startRow = startRow->pNext;
	}
	startRow->pNext = row;
}
	
	
int find_row(int no){ 
	int hash_index,tut,adim=0;
	Row *row;
	hash_index = RSHash(no);
	if (table.rows[hash_index].numara==no)
		return table.rows[hash_index].index;
	else {
		row = table.rows[hash_index].pNext;
		while(row){
		if (row->numara==no)
			return row->index;//table.rows[hash_index].index;
		row = row->pNext;
		}
	}	
	return -1;
}


void Display_Table()
{ 
	int i;
	Row *row;
	puts("\n***Tablo***");
	for (i =0; i < MAX_ROW; ++i){
		if (table.rows[i].index!=-1){
			printf("%2d: %d ", table.rows[i].index, table.rows[i].numara);
			row = table.rows[i].pNext;
			while(row){ 		
				printf("%2d: %d ", row->index, row->numara);
				row = row->pNext;
			}	
		puts("\n");
		}
	}
}


int main(){ 
	int i,index;
	int numaralar[MAX_ROW] = {15, 26, 6, 58, 35, 95, 86, 21, 14, 18, 27,33, 10, 7, 16, 38};
	initialize_Table();
	for (i = 0; i < MAX_ROW; ++i) add_Row(numaralar[i]);
	int aranan=numaralar[5];
	index=find_row(aranan);
	printf("\n %d numarali kayit %d. indextedir ",aranan,index);
	Display_Table();
	getch();
	return 0;
}

