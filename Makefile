all: bin/reflect

LEX		= flex
YACC		= bison
MKDIR_P		= mkdir -p

LDFLAGS		= -Wl,-z,defs -Wl,-rpath,$(PWD)/bin -Lbin
CPPFLAGS	= -include stdinc.h -MD
CFLAGS		= -Wall -Wextra -ggdb3 -O3 -fPIC
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
include reflect/Rules.mk

clean:
	$(RM) -r bin
	$(RM) $(shell find . -name "*.o")

depclean: clean
	$(RM) $(shell find . -name "*.d")

codegen: ast.codegen.stamp
codegen: pt.codegen.stamp

%.codegen.stamp: generate/astgen/generate generate/data/%.ast
	$(MKDIR_P) layer1/include/$*/gen
	$(MKDIR_P) layer1/src/$*/gen
	$(MKDIR_P) layer2v/src/visitor/$*/gen
	@./$+

-include prepare
prepare: $(SOURCES)
	$(MKDIR_P) bin

generate/data/pt.ast: $(shell find layer2p/src/yy/grammar -wholename "*rules/*.y")
	echo '# vim:ft=perl' > $@
	echo >> $@
	echo '$$main::dataname = "pt";' >> $@
	echo >> $@
	echo '{' >> $@
	grep ' new ' $+	\
		| sed -e 's/^[^:]*:\s*{ new (\(\w\+\)) (\(.*\)); }/  \1 => [\2],/;s/\$$\([0-9]\+\)/"n\1"/g'	\
		| sort												\
		>> $@
	echo '}' >> $@
