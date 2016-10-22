#ifndef MLS_STORAGE_ERROR_H
#define MLS_STORAGE_ERROR_H

const char* errors[] = {
	"no error",
	"memory error",
	"memory copy error",
	"initialization error",
	"init: provided path length is less then 1",
	"init: proveded directory path is not valid",
	"init: directory read error",
	"init: no container was initialized",
	"not implemented"
};
enum ERROR {
	OK,
	ERR_MEMORY,
	ERR_MEM_COPY,
	ERR_INIT,
	ERR_INIT_NO_PATH,
	ERR_INIT_NO_DIR,
	ERR_INIT_READ_DIR,
	ERR_INIT_NO_CONTAINER,
	ERR_NOT_IMPLEMENTED
};
#endif
