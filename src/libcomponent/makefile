# Welcome to the make file, let's make things.
# Let's make some helper variables
CC = gcc

# Flags
ALL_ERRORS      = -Wall
COMPILE_FLAGS	= -c $(ALL_ERRORS) -Wunused-variable
COMPLETE_FLAGS  = -o $(EXEC_FILE) $(ALL_ERRORS) -Wunused-variable

# Base filenames
MAIN			= main
LIBCOMPONENT	= libcomponent

# File lists
OBJECTS = $(MAIN).o $(LIBCOMPONENT).o

# Finished program name
EXEC_FILE = program_libcomp



all: $(EXEC_FILE)

# To create program1 we need the compiled files to complete the program.
$(EXEC_FILE): $(OBJECTS)
	$(CC) $(COMPLETE_FLAGS) $^

$(MAIN).o: $(MAIN).c $(LIBCOMPONENT).h
	$(CC) $(COMPILE_FLAGS) $<

$(LIBCOMPONENT).o: $(LIBCOMPONENT).c $(LIBCOMPONENT).h
	$(CC) $(COMPILE_FLAGS) $<

# Fallback for .o targets
%.o: %.c
	$(CC) $(COMPILE_FLAGS) $<


.PHONY: clean
clean:
	rm -f ./*.o
	rm -f $(EXEC_FILE)
	# Removed build files


.PHONY: install
install: $(EXEC_FILE)
	sudo cp program1 /usr/local/bin
	# Finished task install.


.PHONY: uninstall
uninstall:
	sudo rm /usr/local/bin/$(EXEC_FILE)
	# Finished task uninstall.
