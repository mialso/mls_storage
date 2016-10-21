#include <mls_storage.h>
#include <mls_storage_error.h>

static struct MLS_storage storage;

int init_storage(void)
{
	return ERR_NOT_IMPLEMENTED;
}

const char *get_error(int num)
{
	return errors[num];
}
