LEX		= flex
YACC		= bison

CPPFLAGS	= -Iinclude -Iparsing -include stdinc.h
CFLAGS		= -Wall -ggdb3 -O3

SOURCES =			\
	parsing/parser.y	\
	parsing/lexer.l		\
	$(shell find src -name "*.c")

OBJECTS = $(addsuffix .o,$(basename $(SOURCES)))

reflect: $(OBJECTS)
	$(LINK.c) $(OBJECTS) -o $@

clean:
	$(RM) reflect
	$(RM) $(OBJECTS)
	$(RM) parsing/parser.c
	$(RM) parsing/parser.h
	$(RM) parsing/lexer.c
	$(RM) parsing/lexer.h

%.c: %.y
	$(YACC) -d $< -o $@

%.c: %.l
	$(LEX) -o$@ $<

%.o: %.c $(shell find . -name "*.h")
	$(COMPILE.c) $< -o $@

-include prepare
prepare: parsing/parser.c
prepare: parsing/lexer.c
