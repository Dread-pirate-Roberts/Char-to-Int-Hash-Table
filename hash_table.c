#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>

void allocate(struct char_int_dict * dict, size_t size){
	dict->size = size;
	dict->source = (struct hash_entry **) malloc( sizeof(struct hash_entry *) * size);
	
	for(size_t i = 0; i < size; i++){
		(dict->source)[i] = NULL;
	}
}

struct hash_entry * at(struct char_int_dict * dict, char c){
	int hash_key = ((int) c) % dict->size;
	
	for(struct hash_entry * ptr = dict->source[hash_key]; ptr != NULL; ptr = ptr->next){
		if(ptr->key == c){
			return ptr;
		}
	}
	
	return NULL;
}

void set(struct char_int_dict * dict, char c, int i){
	int hash_key = ((int) c) % dict->size;
	
	struct hash_entry * ptr = dict->source[hash_key];
	
	while(ptr != NULL){
		if(ptr->key == c){
			ptr->count = i;
			return;
		}
		ptr = ptr->next;
	}
	
	struct hash_entry * newPtr = (struct hash_entry *) malloc( sizeof(struct hash_entry));
	
	newPtr->key = c;
	newPtr->count = i;
	newPtr->next = dict->source[hash_key];
	
	dict->source[hash_key] = newPtr;
}

void clear(struct char_int_dict * dict, char c){
	struct hash_entry * ptr = dict->source[((int) c) % dict->size];
	
	if(ptr == NULL){
		return;
	}
	
	//first node
	if(ptr->key == c){
		dict->source[((int) c) % dict->size] = ptr->next;
		free(ptr);
		return;
	}
	
	//second and on
	while(ptr->next != NULL){
		if(ptr->next->key == c){
			struct hash_entry * del_node = ptr->next;
			ptr->next = del_node->next;
			free(del_node);
			return;
		}
		ptr = ptr->next;
	}
}

void print(struct char_int_dict * dict){
	printf("-----\n");
	for(size_t i = 0; i < dict->size; i++){
		if(dict->source[i]){
			struct hash_entry * ptr = dict->source[i];
			
			while(ptr != NULL){
				printf(" -> [%c : %d]", ptr->key, ptr->count);
				ptr = ptr->next;
			}
			printf("\n");
		} else {
			printf("[.]\n");
		}
	}
	printf("-----\n");
}

