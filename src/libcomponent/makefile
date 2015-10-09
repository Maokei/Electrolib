# Welcome to the make file, let's make things.
# Let's make some helper variables
CC = gcc

# Flags
ALL_ERRORS      = -Wall -Werror
PREFS_FLAGS 	= -Wunused-variable
COMPILE_FLAGS	= -c -fPIC $(ALL_ERRORS) $(PREFS_FLAGS)
SHARED_FLAGS	= -shared -fPIC -o $(LIBCOMPONENT).so
COMPLETE_FLAGS  = -o $(EXEC_FILE) $(ALL_ERRORS) $(PREFS_FLAGS) \
-L. -lm

# Base filenames
MAIN			= main
LIBCOMPONENT	= libcomponent

# Finished program name
EXEC_FILE 	 = program_libcomp



all: $(EXEC_FILE)

# To create program1 we need the compiled files to complete the program.
$(EXEC_FILE): $(MAIN).c $(LIBCOMPONENT).so
	$(CC) $(COMPLETE_FLAGS) $^

$(LIBCOMPONENT).so: $(LIBCOMPONENT).o 
	$(CC) $(SHARED_FLAGS) $^

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
install: $(LIBCOMPONENT).so
	sudo cp $^ /usr/lib/$^
	# Finished task install.


.PHONY: uninstall
uninstall:
	sudo rm /usr/local/bin/$(EXEC_FILE)
	# Finished task uninstall.
