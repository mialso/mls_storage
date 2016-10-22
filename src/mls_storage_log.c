#include <stdio.h>
#include <mls_storage_error.h>

void log_debug(const char *location, const char *message, int64_t data)
{
	fprintf(stdout, "[DEBUG]: %s(): %s = %ld\n",
					location,
					message,
					data
	);
}
void log_debug_e(const char *location, const char *message, int64_t data, uint64_t err_num)
{
	fprintf(stderr, "[ERROR_DEBUG]: %s(): %s = %ld\n",
					location,
					message,
					data
	);
	if (err_num) {
		fprintf(stderr, "[ERROR]: [%lu] = %s\n", err_num, errors[err_num]);
	}
}
void log_error(const char *location, uint64_t err_num)
{
	fprintf(stderr, "[ERROR]: %s(): [%lu] = %s\n",
					location,
					err_num,
					errors[err_num]
	};
}

