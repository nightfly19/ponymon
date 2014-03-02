.PHONY:
	all
	sum_originals
	gen_masks

all: bin/xor_file

bin:
	@mkdir $@

bin/xor_file: src/xor_file.c bin
	@gcc $< -o $@

sum_originals:
	@echo "Checksuming originals"
	@md5sum -c checksums

gen_masks: sum_originals
	@./bin/gen_masks

apply_masks: sum_originals
	@./bin/apply_masks
