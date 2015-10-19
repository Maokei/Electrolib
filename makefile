# Sanel Merdovic
# 2015-10-18
# Rev. 0.2

# Compiler directive
CC = gcc

# Flags
FLAGS		= -Wall -Werror
COMPILE_FLAGS	= $(FLAGS) -c -fPIC
#SHARED_FLAGS	= $(FLAGS) -shared -fPIC -o 
SHARED_FLAGS	= -shared -fPIC -o 
#COMPLETE_FLAGS  = $(FLAGS) -Llib -lcomponent -lresistance -lpower -o $(EXEC_FILE), -Wl,-rpath,lib
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
LIBPATH			= lib/

# Finished program name
EXEC_FILE 	 = electrotest


all: $(EXEC_FILE)

# Target "all" will build a complete program.
# If a library is missing, it will be built also (that's how I interpret
# the target name ("all").

$(EXEC_FILE): $(MAIN).c $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).h $(LIBPATH)$(LIBRESISTANCE).so \
              $(LIBCOMPONENT_PATH)$(LIBCOMPONENT).h $(LIBPATH)$(LIBCOMPONENT).so \
              $(LIBPOWER_PATH)$(LIBPOWER).h $(LIBPATH)$(LIBPOWER).so
	$(CC) $^ $(COMPLETE_FLAGS)

$(LIBPATH)$(LIBRESISTANCE).so: $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).o 
	sudo mkdir -pv $(LIBPATH)
	$(CC) $(SHARED_FLAGS) $(LIBPATH)$(LIBRESISTANCE).so $^

$(LIBPATH)$(LIBPOWER).so: $(LIBPOWER_PATH)$(LIBPOWER).o 
	sudo mkdir -pv $(LIBPATH)
	$(CC) $(SHARED_FLAGS) $(LIBPATH)$(LIBPOWER).so $^

$(LIBPATH)$(LIBCOMPONENT).so: $(LIBCOMPONENT_PATH)$(LIBCOMPONENT).o 
	sudo mkdir -pv $(LIBPATH)
	$(CC) $(SHARED_FLAGS) $(LIBPATH)$(LIBCOMPONENT).so $^


# Target "lib" will build only the libraries (all three)
lib: $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).o \
     $(LIBPOWER_PATH)$(LIBPOWER).o \
     $(LIBCOMPONENT_PATH)$(LIBCOMPONENT).o
	sudo mkdir -pv $(LIBPATH)
	$(CC) $(SHARED_FLAGS) $(LIBPATH)$(LIBRESISTANCE).so $^
	$(CC) $(SHARED_FLAGS) $(LIBPATH)$(LIBPOWER).so $^
	$(CC) $(SHARED_FLAGS) $(LIBPATH)$(LIBCOMPONENT).so $^


# Will compile the library source code, i.e. create .o-files
$(LIBPATH)$(LIBRESISTANCE).o: $(LIBRESISTANCE_PATH)$(LIBRESISTANCE).c
	$(CC) $(COMPILE_FLAGS) $^
$(LIBPATH)$(LIBPOWER).o: $(LIBPOWER_PATH)$(LIBPOWER).c
	$(CC) $(COMPILE_FLAGS) $^
$(LIBPATH)$(LIBCOMPONENT).o: $(LIBCOMPONENT_PATH)$(LIBCOMPONENT).C
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
