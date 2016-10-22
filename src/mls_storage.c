#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <mls_storage.h>
#include <mls_storage_error.h>
#include <mls_container.h>
#include <mls_storage_log.h>


static struct MLS_storage storage;
static const char *CONF_FILE = "storage.conf";

static int init_config(char *path);

int init_storage(char *path)
{
	int res = 0;
	if ((res = init_config(path))) {
		return ERR_INIT;
	}

	return ERR_NOT_IMPLEMENTED;
}
int init_config(char *path)
{
	struct dirent *dir_entry = NULL;
	DIR *storage_dir = NULL;
	uint64_t error_counter = 0;
	uint64_t success_counter = 0;
	struct S_container container = {0};
	size_t path_len = strlen(path);
	if (1 > path_len) {
		log_debug_e(AT, "path_len", path_len, ERR_INIT_NO_PATH);
		return ERR_INIT_NO_PATH;
	}
	if (NULL == (storage_dir = opendir(path))) {
		log_debug_e(AT, path, NULL, ERR_INIT_NO_DIR);
		return ERR_INIT_NO_DIR;
	}
	storage.path = calloc(path_len+1, sizeof(char));
	if (NULL == storage.path) {
		log_err(AT, ERR_MEMORY);
		return ERR_MEMORY;
	}
	if (NULL == (memcpy((void *)storage.path, (const void *)path, path_len))) {
		log_err(AT, ERR_MEMCPY);
		return ERR_MEM_COPY;
	}
	storage.path_len = path_len;
	do {
		errno = 0;
		dir_entry = readdir(storage_dir);
		if (NULL == dir_entry) {
			if (errno) {
				log_debug_e(AT, strerror(errno), errno, ERR_INIT_READ_DIR);
			}
			break;
		}
		if ((init_storage(path, dir_entry->d_name))) {
			++error_counter;
		} else {
			++success_counter;
		}
	} while (1);
	if (error_counter) {
		log_degug_e(AT, "some containers error initalization detected =", error_counter, NULL);
	}
	if (!success_counter) {
		log_error(AT, ERR_INIT_NO_CONTAINER);
		return ERR_INIT_NO_CONTAINER;
	}
	return OK;
}

const char *get_error(int num)
{
	return errors[num];
}
