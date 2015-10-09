# Sanel Merdovic
# 2015-10-09

CC = gcc

# Flags
FLAGS		= -Wall -Werror
COMPILE_FLAGS	= $(FLAGS) -c -fPIC
SHARED_FLAGS	= $(FLAGS) -shared -fPIC -o $(LIBRESISTANCE).so 
COMPLETE_FLAGS  = $(FLAGS) -lm -o $(EXEC_FILE)

# Base filenames
MAIN		= electrotest
#LIBRESISTANCE	= resistance
LIBRESISTANCE	= libresistance

# Finished program name
EXEC_FILE 	 = electrotest



all: $(EXEC_FILE)

# To create program1 we need the compiled files to complete the program.
$(EXEC_FILE): $(MAIN).c $(LIBRESISTANCE).so
	$(CC) $^ $(COMPLETE_FLAGS)

$(LIBRESISTANCE).so: $(LIBRESISTANCE).o 
	$(CC) $(SHARED_FLAGS) $^

$(LIBRESISTANCE).o: $(LIBRESISTANCE).c $(LIBRESISTANCE).h
	$(CC) $(COMPILE_FLAGS) $^


.PHONY: clean
clean:
	rm -f *.o *.gch
	# Removed build files


.PHONY: install
install: $(LIBRESISTANCE).so
	sudo cp $^ /usr/lib/$^
	# Finished task install.


.PHONY: uninstall
uninstall:
	sudo rm /usr/lib/$(LIBRESISTANCE).so
	# Finished task uninstall.
