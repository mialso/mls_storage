#ifndef MLS_S_CONTAINER_H
#define MLS_S_CONTAINER_H

struct S_range {
	struct S_range *next;
	uint32_t start;
	uint32_t end;
};

struct S_container {
	uint64_t size;
	uint64_t item_size;
	uint64_t items;
	void *item;
	struct S_range *free;
};

extern int init_container();
#endif
