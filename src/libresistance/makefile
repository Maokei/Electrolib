# Sanel Merdovic
# 2015-10-09

# Compiler directive
CC = gcc

# Flags
FLAGS		= -Wall -Werror
COMPILE_FLAGS	= $(FLAGS) -c -fPIC
SHARED_FLAGS	= $(FLAGS) -shared -fPIC -o $(LIB).so 
COMPLETE_FLAGS  = $(FLAGS) -lm -o $(EXEC_FILE)

# Base filenames
MAIN		= electrotest
LIB		= libresistance

# Finished program name
EXEC_FILE 	 = electrotest



all: $(EXEC_FILE)

# Target "all" will build a complete program.
# If library is missing, it will be built also (that's how I interpret
# the target name ("all").
$(EXEC_FILE): $(MAIN).c $(LIB).h $(LIB).so
	$(CC) $^ $(COMPLETE_FLAGS)

$(LIB).so: $(LIB).o 
	$(CC) $(SHARED_FLAGS) $^

# Target "lib" will build the library only
lib: $(LIB).o
	$(CC) $(SHARED_FLAGS) $^

# Will compile the library source code
$(LIB).c:
	$(CC) $(COMPILE_FLAGS) $^

.PHONY: clean
clean:
	rm -f *.o
	# Removed build files

# Target "install" will build the library and then install it
.PHONY: install
install: $(LIB).so
	sudo cp $^ /usr/lib/$^
	sudo cp $(EXEC_FILE) /usr/bin/$(EXEC_FILE)
	# Finished task install.


.PHONY: uninstall
uninstall:
	sudo rm -f /usr/lib/$(LIB).so
	sudo rm -f /usr/bin/$(EXEC_FILE)
	# Finished task uninstall.
