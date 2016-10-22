/*! \file mls_container.h
 * 	\brief Container static API for mls_storage
 *
 * 	\mls_purpose To hold the data, and server CRUD operations on data item
 *
 * The container is an instance, that is backed by particualr file or a number
 * of files. Data can be memory mapped or retreived on demand.
 * Each container holds the list of free items(S_range) to fast store data at
 * first available location.
 */
#ifndef MLS_S_CONTAINER_H
#define MLS_S_CONTAINER_H

/*! \brief Range of free items
 *
 * 	\mls_purpose To quick item insertion
 *
 * linked list, first item is the available free cell.
 * Added on remove, and freed when item is added.
 */
struct S_range {
	struct S_range *next;
	uint32_t start;
	uint32_t end;
};

/*! \brief Container representation
 *
 * 	\mls_purpose This struct is context for container CRUD operations
 *
 * Holds all data, that is needed by container procedures to be performed.
 */ 
struct S_container {
	uint64_t size;
	uint64_t item_size;
	uint64_t items;
	void *item;
	struct S_range *free;
};

/*! \mls_purpose To init container within storage
 *
 * 	\param container Pointer to container structure to write data to
 * 	\param path Path to storage folder
 * 	\param name Unique container name within storage.
 *
 * 	\return 0 on success and err_num in case of error.
 */
extern int init_container(struct S_container *container, char *path, char *name);

#endif
