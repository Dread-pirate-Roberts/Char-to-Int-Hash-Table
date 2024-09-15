#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>

struct hash_entry {
	char key;
	int count;
	struct hash_entry * next;
};

struct char_int_dict{
	size_t size;
	struct hash_entry ** source;
};

void allocate(struct char_int_dict * dict, size_t size);

struct hash_entry * at(struct char_int_dict * dict, char c);

void set(struct char_int_dict * dict, char c, int i);

void clear(struct char_int_dict * dict, char c);

void print(struct char_int_dict * dict);

#endif