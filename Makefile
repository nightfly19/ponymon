.PHONY:
	all
	sum_originals

all: bin/xor_files

bin:
	@mkdir $@

bin/xor_files: src/xor_files.c bin
	@gcc $< -o $@

sum_originals:
	@md5sum -c checksums
