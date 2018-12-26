PROJNAME = macc

SUFFIX   = .c
COMPILER = gcc
CFLAGS   = -Wall -std=c11 -g

SRCDIR   = ./src
INCDIR   = ./include
BINDIR   = ./bin

SOURCES  = $(wildcard $(SRCDIR)/*$(SUFFIX))
OBJECTS  = $(notdir $(SOURCES:$(SUFFIX)=.o))
HEADERS  = $(wildcard $(INCDIR)/*.h)


$(BINDIR)/$(PROJNAME): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(COMPILER) $(CFLAGS) -o $@ main.c $(SOURCES) $(LDFLAGS)

$(OBJECTS): $(HEADERS)

test: $(BINDIR)/$(PROJNAME)
	./test/test.sh

clean:
	rm -rf $(BINDIR) $(OBJECTS) tmp*
