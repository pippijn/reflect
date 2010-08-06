# public
layer1_CPPFLAGS		:= $(layer0_CPPFLAGS) -Ilayer1/include

# private
layer1_CFLAGS		:= -Ilayer1/src/include
layer1_LDFLAGS		:= -shared -llayer0

# all sources
layer1_SOURCES		:= $(shell find layer1/src -name "*.c")
layer1_OBJECTS		:= $(addsuffix .o,$(basename $(layer1_SOURCES)))

# target
bin/liblayer1.so: $(layer1_OBJECTS) bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) $(layer1_OBJECTS) $(layer1_LDFLAGS) -o $@

# compile
layer1/%.o: layer1/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer1_CPPFLAGS) $(layer1_CFLAGS) $< -o $@

# clean
clean: layer1-clean
layer1-clean:
	$(RM) -r layer1/include/ast/gen
	$(RM) -r layer1/src/ast/gen
	$(RM) -r layer1/include/pt/gen
	$(RM) -r layer1/src/pt/gen

# all sources
SOURCES += $(layer1_SOURCES)
