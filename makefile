# Sanel Merdovic
# 2015-10-17
# Rev. 0.1

# Compiler directive
CC = gcc

# Flags
FLAGS		= -Wall -Werror
COMPILE_FLAGS	= $(FLAGS) -c -fPIC
SHARED_FLAGS	= $(FLAGS) -shared -fPIC -o 
COMPLETE_FLAGS  = $(FLAGS) -lm -o $(EXEC_FILE)

# Base filenames
#
MAIN			= src/electrotest/electrotest
LIBRESISTANCE		= libresistance
LIBRESISTANCE_PATH	= src/libresistance/
LIBPOWER		= libpower
LIBPOWER_PATH		= src/libpower/
LIBCOMPONENT		= libcomponent
LIBCOMPONENT_PATH	= src/libcomponent/


# Finished program name
EXEC_FILE 	 = electrotest


all: $(EXEC_FILE)

# Target "all" will build a complete program.
# If a library is missing, it will be built also (that's how I interpret
# the target name ("all").

$(EXEC_FILE): $(MAIN).c $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).h $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).so \
              $(LIBPOWER_PATH)$(LIBPOWER).h $(LIBPOWER_PATH)$(LIBPOWER).so \
              $(LIBCOMPONENT_PATH)$(LIBCOMPONENT).h $(LIBCOMPONENT_PATH)$(LIBCOMPONENT).so
	$(CC) $^ $(COMPLETE_FLAGS)

$(LIBRESISTANCE_PATH)$(LIBRESISTANCE).so: $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).o 
	$(CC) $(SHARED_FLAGS)$(LIBRESISTANCE_PATH)$(LIBRESISTANCE).so $^

$(LIBPOWER_PATH)$(LIBPOWER).so: $(LIBPOWER_PATH)$(LIBPOWER).o 
	$(CC) $(SHARED_FLAGS)$(LIBPOWER_PATH)$(LIBPOWER).so $^

$(LIBCOMPONENT_PATH)$(LIBCOMPONENT).so: $(LIBCOMPONENT_PATH)$(LIBCOMPONENT).o 
	$(CC) $(SHARED_FLAGS)$(LIBCOMPONENT_PATH)$(LIBCOMPONENT).so $^


# Target "lib" will build only the libraries (all three)
lib: $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).o \
     $(LIBPOWER_PATH)$(LIBPOWER).o \
     $(LIBCOMPONENT_PATH)$(LIBCOMPONENT).o
	$(CC) $(SHARED_FLAGS) $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).so $^
	$(CC) $(SHARED_FLAGS) $(LIBPOWER_PATH)$(LIBPOWER).so $^
	$(CC) $(SHARED_FLAGS) $(LIBCOMPONENT_PATH)$(LIBCOMPONENT).so $^


# Will compile the library source code
$(LIBRESISTANCE_PATH)$(LIBRESISTANCE).c:
	$(CC) $(COMPILE_FLAGS) $^
$(LIBPOWER_PATH)$(LIBPOWER).c:
	$(CC) $(COMPILE_FLAGS) $^
$(LIBCOMPONENT_PATH)$(LIBCOMPONENT).c:
	$(CC) $(COMPILE_FLAGS) $^


.PHONY: clean
clean:
	sudo rm -f $(LIBRESISTANCE_PATH)*.o
	sudo rm -f $(LIBPOWER_PATH)*.o
	sudo rm -f $(LIBCOMPONENT_PATH)*.o
	# Removed build files

# Target "install" will build the library and then install it
.PHONY: install
install: $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).so
	sudo cp $^ /usr/lib/
	# Finished task install.


.PHONY: uninstall
uninstall:
	sudo rm /usr/lib/$(LIBRESISTANCE).so
	# Finished task uninstall.
