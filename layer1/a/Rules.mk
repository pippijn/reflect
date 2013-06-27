# public
layer1a_CPPFLAGS	:= $(layer0_CPPFLAGS) -Ilayer1/a/include

# private
layer1a_CFLAGS		:= -Ilayer1/a/src/include
layer1a_LDFLAGS		:= -shared -llayer0

# all sources
layer1a_SOURCES		:= $(shell find layer1/a/src -name "*.c")
layer1a_OBJECTS		:= $(addsuffix .o,$(basename $(layer1a_SOURCES)))

# target
bin/liblayer1a.so: $(layer1a_OBJECTS) bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) $(layer1a_OBJECTS) $(layer1a_LDFLAGS) -o $@

# compile
layer1/a/%.o: layer1/a/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer1a_CPPFLAGS) $(layer1a_CFLAGS) $< -o $@

# clean
clean: layer1a-clean
layer1a-clean:
	$(RM) -r layer1/a/include/ast/gen
	$(RM) -r layer1/a/src/ast/gen
	$(RM) -r layer1/a/include/pt/gen
	$(RM) -r layer1/a/src/pt/gen

# all sources
SOURCES += $(layer1a_SOURCES)
