#include <stdio.h>
#include <stdlib.h>
#include <mls_storage.h>

int main(void)
{
	int res = 0;
	if ((res = init_storage)) {
		printf("[ERROR]: init_storage error [%d] {%s}\n", res, get_error(res));
		exit(EXIT_FAILURE);
	}
	printf("storage init [OK]\n");
	exit(EXIT_SUCCESS);
}
