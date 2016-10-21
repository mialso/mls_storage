#ifndef MLS_STORAGE_H
#define MLS_STORAGE_H

#include <stdint.h>

/* internal ??? */
struct S_item_id {
	uint32_t offset;
	uint16_t type_id;
	uint16_t container_id;
};

struct S_item {
	uint64_t size;
	void *data;
};

#include <mls_container.h>

struct MLS_storage {
	struct S_container *containers;
};

extern int init_storage();
extern const char *get_error();

extern int get_item(struct MLS_storage *, const uint64_t, struct S_item *);
extern int post_item(struct MLS_storage *,uint64_t *, const struct S_item);
extern int put_item(struct MLS_storage *, uint64_t *, const struct S_item);
extern int remove_item(struct MLS_storage *, const uint64_t, struct S_item *);


#endif
