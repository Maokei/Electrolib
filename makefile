# Sanel Merdovic, Niklas Andersson
# 2015-10-20
# Rev. 0.3

# Compiler directive
CC = gcc

# Flags & commands
FLAGS			= -Wall -Werror
COMPILE			= $(FLAGS) -c -fPIC
SHARE			= $(FLAGS) -shared -fPIC -o
LOCAL_LD		= $(FLAGS) $(LSHARED) -lm -Wl,-rpath,lib -o $(EXEC_FILE)
GLOBAL_LD		= $(FLAGS) -lresistance -lpower -lcomponent -lm -o /usr/bin/$(EXEC_FILE)

# Program file
EXEC_FILE	= electrotest
PROG_SOURCE = $(EXEC_FILE).c

# Library names
LRES 	= libresistance
LCOMP	= libcomponent
LPOW	= libpower

# Paths
SOURCE_PATH		= src
LRES_PATH 		= $(SOURCE_PATH)/$(LRES)
LPOW_PATH		= $(SOURCE_PATH)/$(LPOW)
LCOMP_PATH		= $(SOURCE_PATH)/$(LCOMP)
EXEC_PATH		= $(SOURCE_PATH)/$(EXEC_FILE)
LPATH 			= lib

# Lists
LSOURCE 	= $(LRES_PATH)/$(LRES).c $(LPOW_PATH)/$(LPOW).c $(LCOMP_PATH)/$(LCOMP).c
LOBJECTS 	= $(LRES_PATH)/$(LRES).o $(LPOW_PATH)/$(LPOW).o $(LCOMP_PATH)/$(LCOMP).o
LHEADERS	= $(LRES_PATH)/$(LRES).h $(LPOW_PATH)/$(LPOW).h $(LCOMP_PATH)/$(LCOMP).h
LSHARED		= $(LPATH)/$(LRES).so $(LPATH)/$(LPOW).so $(LPATH)/$(LCOMP).so

all: lib $(EXEC_FILE)

# Target "all" will build a complete program.
# If a library is missing, it will be built also (that's how I interpret
# the target name ("all").

$(EXEC_FILE): $(EXEC_PATH)/$(PROG_SOURCE) $(LSOURCE) $(LHEADERS) $(LOBJECTS)
	$(CC) $< $(LOCAL_LD) 

# Target "lib" will build only the local shared objects to lib/ (all three)
lib: $(LOBJECTS)
	mkdir -pv $(LPATH)
	$(CC) $(SHARE) $(LPATH)/$(LRES).so $(LRES_PATH)/$(LRES).o 
	$(CC) $(SHARE) $(LPATH)/$(LPOW).so $(LPOW_PATH)/$(LPOW).o
	$(CC) $(SHARE) $(LPATH)/$(LCOMP).so $(LCOMP_PATH)/$(LCOMP).o


# Will compile the library source code, i.e. create .o-files
$(LRES_PATH)/$(LRES).o: $(LRES_PATH)/$(LRES).c $(LRES_PATH)/$(LRES).h
	$(CC) $(COMPILE) $^
	mv $(LRES).o $(LRES_PATH)/

$(LPOW_PATH)/$(LPOW).o: $(LPOW_PATH)/$(LPOW).c $(LPOW_PATH)/$(LPOW).h
	$(CC) $(COMPILE) $^
	mv $(LPOW).o $(LPOW_PATH)/

$(LCOMP_PATH)/$(LCOMP).o: $(LCOMP_PATH)/$(LCOMP).c $(LCOMP_PATH)/$(LCOMP).h
	$(CC) $(COMPILE) $^
	mv $(LCOMP).o $(LCOMP_PATH)/

.PHONY: clean
clean:
	rm -f $(LRES_PATH)/*.o
	rm -f $(LPOW_PATH)/*.o
	rm -f $(LCOMP_PATH)/*.o
	# Removed build files

# Target "install" will build the library and then install it
.PHONY: install
install: $(EXEC_PATH)/$(PROG_SOURCE) $(LSHARED)
	cp $(LSHARED) -t /usr/lib
	ldconfig
	$(CC) $< $(GLOBAL_LD)
	# Finished task install.


.PHONY: uninstall
uninstall:
	sudo rm /usr/lib/$(LIBRESISTANCE).so
	# Finished task uninstall.
