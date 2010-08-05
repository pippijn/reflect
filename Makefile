all: bin/reflect bin/check

LINK.c		= $(LINK.cpp)

LEX		= flex
YACC		= bison
MKDIR_P		= mkdir -p

ifdef WANT_GLIB
LDFLAGS		+= $(shell pkg-config --libs glib-2.0)
CPPFLAGS	+= -DWANT_GLIB
CFLAGS		+= $(shell pkg-config --cflags glib-2.0)
CXXFLAGS	+= $(shell pkg-config --cflags glib-2.0)
endif

LDFLAGS		+= -Wl,-z,defs -Wl,-rpath,$(PWD)/bin -Lbin
CPPFLAGS	+= -include stdinc.h -MD
CFLAGS		+= -Wall -Wextra -O0 -ggdb3 -fPIC
CXXFLAGS	+= -Wall -Wextra -O0 -ggdb3 -fPIC -std=c++0x
CFLAGS		+= -Wredundant-decls			\
		   -Wmissing-prototypes			\
		   -Wnested-externs			\
		   -Wbad-function-cast			\
		   -Wdeclaration-after-statement	\
		   -Wstrict-prototypes			\
		   #-Werror				\
		   -Wconversion				\
		   -Wno-error=conversion		\

%.c: %.y
	@echo " YACC " $@
	@$(YACC) -d $< -o $@

%.c: %.l
	@echo "  LEX " $@
	@$(LEX) -o$@ $<

include layer0/Rules.mk
include layer1/Rules.mk
include layer2p/Rules.mk
include layer2v/Rules.mk
include layer2x/Rules.mk
include check/Rules.mk
include reflect/Rules.mk

clean:
	$(RM) -r bin
	$(RM) $(shell find . -name "*.o")

depclean: clean
	$(RM) $(shell find . -name "*.d")

codegen: ast.codegen.stamp
codegen: pt.codegen.stamp
	$(MKDIR_P) bin
	$(MAKE) prepare

%.codegen.stamp: generate/astgen/generate generate/data/%.ast
	$(MKDIR_P) layer1/include/$*/gen
	$(MKDIR_P) layer1/src/$*/gen
	$(MKDIR_P) layer2v/src/visitor/$*/gen
	@./$+

-include prepare
prepare: $(SOURCES)

-include $(shell find . -name "*.d")
