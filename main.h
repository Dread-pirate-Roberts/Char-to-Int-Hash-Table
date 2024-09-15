#ifndef MAIN_C
#define MAIN_C

#include "hash_table.h"

int main(){
	
	struct char_int_dict dict;
	allocate(&dict, 10);
	
	set(&dict, 'r', 5);
	set(&dict, 'p', 3);
	set(&dict, 'c', 2);
	set(&dict, 'a', 1);
	set(&dict, 'b', 3);
	set(&dict, 'd', 8);
	
	
	print(&dict);
	
	at(&dict, 'r')->count = 1;
	set(&dict, 'z', 0);
	set(&dict, 'y', 3);
	set(&dict, 'x', 2);
	
	print(&dict);
	
	return 0;
}

#endif