# Welcome to the make file, let's make things.
# Let's make some helper variables
CC = gcc

# Flags
FLAGS			= -Wall -Werror
COMPILE_FLAGS	= $(FLAGS) -c -fPIC
SHARED_FLAGS	= $(FLAGS) -shared -fPIC -o $(LIBCOMPONENT).so 
COMPLETE_FLAGS  = $(FLAGS) -L. -lm -lcomponent -Wl,-rpath,. -o $(EXEC_FILE)

# Base filenames
MAIN			= main
LIBCOMPONENT	= libcomponent

# Finished program name
EXEC_FILE 	 = program_libcomp



all: $(EXEC_FILE)

# To create program1 we need the compiled files to complete the program.
$(EXEC_FILE): $(MAIN).c $(LIBCOMPONENT).so
	$(CC) $^ $(COMPLETE_FLAGS)

$(LIBCOMPONENT).so: $(LIBCOMPONENT).o 
	$(CC) $(SHARED_FLAGS) $^

$(LIBCOMPONENT).o: $(LIBCOMPONENT).c $(LIBCOMPONENT).h
	$(CC) $(COMPILE_FLAGS) $^


.PHONY: clean
clean:
	rm -f ./*.o ./*.gch
	# Removed build files


.PHONY: install
install: $(LIBCOMPONENT).so
	sudo cp $^ /usr/lib/$^
	# Finished task install.


.PHONY: uninstall
uninstall:
	sudo rm /usr/lib/$(LIBCOMPONENT).so
	# Finished task uninstall.
