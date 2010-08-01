LEX		= flex
YACC		= bison
MKDIR_P		= mkdir -p

CPPFLAGS	= -Iinclude -Iparsing -include stdinc.h -MD
CFLAGS		= -Wall -Wextra -ggdb3 -O3
CFLAGS		+= -Wredundant-decls			\
		   -Wmissing-prototypes			\
		   -Wnested-externs			\
		   -Wmissing-parameter-type		\
		   -Wbad-function-cast			\
		   -Wdeclaration-after-statement	\
		   -Wstrict-prototypes			\
		   -Wconversion				\

SOURCES :=			\
	parsing/parser.y	\
	parsing/lexer.l		\
	$(shell find src -name "*.c")

OBJECTS = $(addsuffix .o,$(basename $(SOURCES)))

reflect: $(OBJECTS)
	@echo "  CCLD" $@
	@$(LINK.c) $(OBJECTS) -o $@

codegen: ast.codegen.stamp pt.codegen.stamp

%.codegen.stamp: astgen data/%.ast
	$(MKDIR_P) include/$*/gen
	$(MKDIR_P) src/$*/gen
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
	$(RM) include/pt/gen/*
	$(RM) src/pt/gen/*

depclean: clean
	$(RM) $(OBJECTS:.o=.d)

%.c: %.y
	@echo " YACC " $@
	@$(YACC) -d $< -o $@

%.c: %.l
	@echo "  LEX " $@
	@$(LEX) -o$@ $<

%.o: %.c
	@echo "  CC  " $@
	@$(COMPILE.c) $< -o $@

-include prepare
prepare: parsing/parser.c
prepare: parsing/lexer.c

include parsing/parser.mk
-include $(shell find parsing src -name "*.d")
