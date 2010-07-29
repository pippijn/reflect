LEX		= flex
YACC		= bison

CPPFLAGS	= -Iinclude -Isrc/parsing

SOURCES =			\
	src/parsing/parser.y	\
	src/parsing/lexer.l	\
	$(wildcard src/*.c)

OBJECTS = $(addsuffix .o,$(basename $(SOURCES)))

reflect: $(OBJECTS)
	$(LINK.c) $(OBJECTS) -o $@

clean:
	$(RM) reflect
	$(RM) $(OBJECTS)
	$(RM) src/parsing/parser.c
	$(RM) src/parsing/parser.h
	$(RM) src/parsing/lexer.c
	$(RM) src/parsing/lexer.h

%.c: %.y
	$(YACC) -d $< -o $@

%.c: %.l
	$(LEX) -o$@ $<

%.o: %.c $(shell find . -name "*.h")
	$(COMPILE.c) $< -o $@

-include prepare
prepare: src/parsing/parser.c
prepare: src/parsing/lexer.c
