# Ponymon

This is an independant effort to continue the work of http://ponymondawndusk.wikia.com/wiki/Ponymon_Dawn/Dusk_Wiki

## Getting Started

This project assumes an environment with a few basic command line utilities such as GNU Make, gcc, base64

To git started first cd into the the ponymon project directory and run 

```Shell
make init
```
This will generate some assumed directories (*original*, *working*, and *patch_mask*) and compile bin/xor_file

Checksums contains an md5sum manifest of expected original ROM files that are used by this project.
Currently this is just the Ponymon Dawn ROM that is available from the main ponymondawn project. 
It would be nice to in the future source the original altered ROMs and base our diffs off of those.

Ensure that the original ROM files matching these checksums and names exist in the *orignal* directory.
next run
```Shell
make apply_masks
```
to generate updated ROMs into your *working* direcotory with the same name as your original ROM.

## Workflow

Changes should be made to the copy of your ROM in your *working* directory.
After each logical change made to a ROM you should run
```Shell
make gen_masks
```
to update the xor mask for each rom in the *patch_mask* directory and then commit the changes to the xor masks to git
