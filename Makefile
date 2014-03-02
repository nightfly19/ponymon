.PHONY:
	sum_originals
	gen_masks
	init

init: bin working original patch_mask bin/xor_file

bin:
	@mkdir $@
working:
	@mkdir $@
original:
	@mkdir $@
patch_mask:
	@mkdir $@

bin/xor_file: src/xor_file.c bin
	@gcc $< -o $@

sum_originals:
	@echo "Checksuming originals"
	@md5sum -c checksums

gen_masks: sum_originals bin/xor_file init
	@./bin/gen_masks

apply_masks: sum_originals bin/xor_file init
	@./bin/apply_masks
