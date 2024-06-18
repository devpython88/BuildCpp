# BuildCpp
Simple OpenSource library linker for c++, designed for people who think cmake is hard, Although this option is not as versatile

## Tutorial
Let me show you how you can link libraries using `BuildCpp`.
Step 1: Make sure to add BuildCpp to path by running the add_to_path.sh file in the tar.gz

--------------------------

Step 2: Make a 'makefile.txt' in your project directory
Before step 3, remeber that you dont strictly need to add the lib dir and include dir, you can either not add any or just add one, or add both

--------------------------

Step 3: Add include dir (if it exists):
	To add include directory, simple add this line into the makefile `include_dir INCLUDE` replace INCLUDE with the path or name of the dir

--------------------------

Step 4: Add lib dir (if it exists):
	To add lib directory, simple add this line into the makefile `lib_dir LIB` replace LIB with the path or name of the dir

--------------------------

Step 5 (Optional): 
	If you need to use some features that arent availaible in the default c++ version (c++11) you can simply specify the version like this:
	`cpp_version 20` replace 20 with the version you want to use

--------------------------

Step 6 (Required):
	To set the main file for the project, Do it like this:
	`main_file main.cpp` replace main.cpp with the file or the path to the file

--------------------------

Additional stuff for more automation:
1. To automatically run the project after builded, Simply add `run` to the end of the makefile
2. If you want to add a .c file or .h to your project, You can use the
	`add_file` command, like this:
	`add_file /path/to/file.h` or `/path/to/file.c`

--------------------------

Thank you for downloading BuildCpp
