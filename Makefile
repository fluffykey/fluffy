#http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/
#Modified to fit purpose of our program
#must use: export CPLUS_INCLUDE_PATH=/usr/include/python2.7 
CC := g++ 
# CC := clang --analyze
SRCDIR := src
TESTDIR := test
BUILDDIR := build
TARGET := bin/test
PYDIR := pywrap
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -fPIC -std=c++11 #-coverage -fprofile-arcs -ftest-coverage
LIB := -lssl -lcrypto -lpython2.7 -lboost_python -lpthread -ldl -lutil #-lgcov
INC := -I include -I /usr/include/python2.7/

$(TARGET): $(OBJECTS)
	@echo "\nCreating Shared Library..."
	$(CC) -shared $(BUILDDIR)/*.o -o $(BUILDDIR)/gsk.so $(LIB)

	@echo "\nMaking a copy of the shared library file in fluffy/pywrap"
	@echo "cp $(BUILDDIR)/*.so pywrap/"; cp $(BUILDDIR)/*.so pywrap/

	@echo " \nLinking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) 
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(PYDIR)/*.so $(TARGET)" ; $(RM) -r $(BUILDDIR) $(PYDIR)/*.so $(TARGET)

# Tests
key_test:
	@echo " Building Key Test...";
	$(CC) $(CFLAGS) test/key_test.cpp build/keys.o $(INC) $(LIB) -o bin/key_test

tests: $(OBJECTS)
	@echo " \nLinking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

# Spikes
#ticket:
#$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
.PHONY: tests
