/*! \file mls_storage.h
 * 	\brief Main header, representing the API
 */
#ifndef MLS_STORAGE_H
#define MLS_STORAGE_H

#include <stdint.h>

/*! \brief The unique item_id fields representation
 *
 * 	\todo this struct is to be moved to static scope
 *
 * Item id is the unique 64 bit unsigned integer value. S_item_id struct shows
 * how the data is layed out within it and the purpose of each field.
 */
struct S_item_id {
	uint32_t offset;
	uint16_t type_id;
	uint16_t container_id;
};

/*! \brief The data, storage holds
 *
 * This struct is used by to exchange data with store.
 * In case the data should be retrieved, the struct is filled,
 * In case the data should be stored, this struct is copied from
 */
struct S_item {
	uint64_t size;
	void *data;
};

#include <mls_container.h>

/*! \brief Storage representation
 *
 * This is a context, in which all methods(operations) are performed.
 */
struct MLS_storage {
	char *path;
	size_t path_len;
	struct S_container *containers;
};

/*! \mls_purpose To init storage at some place within file system
 *
 * 	\param path The path, storage will reside at.
 * 	\return
 * 		 0 in success case and the err_number on error.
 * 		 The error string could be retrieved with get_error() call
 */
extern int init_storage(char *path);

/*! \mls_purpose To get string, describing the error occured
 *
 * \param err_num The error number, returned by API call.
 * \return
 * 		 pointer to string wich holds human readable description of error
 */
extern const char *get_error(int err_num);

/*! \mls_purpose 	To get item data from storage
 * 	\param item_id 	The unique id of item to get
 * 	\param item 	The struct, where data would be copied
 * 	\return			0 and data update on success
 * 					err_num in error case
 */
extern int get_item(const uint64_t item_id, struct S_item *item);
/*! \mls_purpose 	To add new item data to storage
 * 	\param item_id 	The pointer, where newly created item id would be written
 * 	\param item 	The struct, from which data would be copied into storage
 * 	\return			0 and data update on success
 * 					err_num in error case
 */
extern int post_item(uint64_t *item_id, const struct S_item item);
/*! \mls_purpose 	To update item data within storage
 * 	\param item_id 	The pointer, from which item id would be retrieved
 * 					and, on container change, where new item id would be written
 * 	\param item 	The struct, from which data would be copied into storage
 * 	\return			0 and data update on success
 * 					err_num in error case
 */
extern int put_item(uint64_t *item_id, const struct S_item item);
/*! \mls_purpose 	To delete item data within storage
 * 	\param item_id 	The unique id of item to delete
 * 	\param item 	The struct, where removed data would be copied
 * 	\return			0 and data update on success
 * 					err_num in error case
 */
extern int remove_item(const uint64_t item_id, struct S_item * item);


#endif
