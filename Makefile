LEX		= flex
YACC		= bison
MKDIR_P		= mkdir -p

CPPFLAGS	= -Iinclude -Iparsing -include stdinc.h
CFLAGS		= -Wall -ggdb3 -O3
CFLAGS		+= -Wredundant-decls			\
		   -Wmissing-prototypes			\
		   -Wnested-externs			\
		   -Wmissing-parameter-type		\
		   -Wbad-function-cast			\
		   -Wdeclaration-after-statement	\
		   -Wstrict-prototypes			\

SOURCES =			\
	parsing/parser.y	\
	parsing/lexer.l		\
	$(shell find src -name "*.c")

OBJECTS = $(addsuffix .o,$(basename $(SOURCES)))

reflect: $(OBJECTS)
	@echo "  CCLD" $@
	@$(LINK.c) $(OBJECTS) -o $@

codegen: astgen data/pt.ast
	$(MKDIR_P) include/ast/gen
	$(MKDIR_P) src/ast/gen
	@./$+

clean:
	$(RM) reflect
	$(RM) $(OBJECTS)
	$(RM) parsing/parser.c
	$(RM) parsing/parser.h
	$(RM) parsing/lexer.c
	$(RM) parsing/lexer.h
	$(RM) include/ast/gen/*
	$(RM) src/ast/gen/*

%.c: %.y
	@echo " YACC " $@
	@$(YACC) -d $< -o $@

%.c: %.l
	@echo "  LEX " $@
	@$(LEX) -o$@ $<

%.o: %.c $(shell find . -name "*.h")
	@echo "  CC  " $@
	@$(COMPILE.c) $< -o $@

-include prepare
prepare: parsing/parser.c
prepare: parsing/lexer.c
