CC ?= gcc

bin_dir := bin/

test_dir := test/
test_objs := $(test_dir)storage.o

src_dir := src/
head_dir := include/
lib_name := libmlsstorage.a
lib_objs := mls_storage.o mls_container.o mls_storage_log.o
lib_headers := $(shell find ./include -name *.h)

CFLAGS := -g -std=c99 -Wall -Wextra -Wpedantic -I$(head_dir)

lib: $(lib_objs) 
	ar rcs $(bin_dir)$(lib_name) $(lib_objs)

mls_storage.o: $(src_dir)mls_storage.c $(lib_headers)
	$(CC) $(CFLAGS) -c $<

mls_container.o: $(src_dir)mls_container.c $(head_dir)mls_container.h
	$(CC) $(CFLAGS) -c $<

mls_storage_log.o: $(src_dir)mls_storage_log.c $(head_dir)mls_storage_log.h
	$(CC) $(CFLAGS) -c $<

test: storage_test.o lib
	$(CC) -static $< -L$(bin_dir) -lmlsstorage -o test_it

storage_test.o: $(test_dir)storage_test.c
	$(CC) $(CFLAGS) -c $^
