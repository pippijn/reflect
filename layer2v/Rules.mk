# public
layer2v_CPPFLAGS	:= $(layer1_CPPFLAGS) -Ilayer2v/include

# private
layer2v_CFLAGS		:= -Ilayer2v/src/include $(shell pkg-config --cflags libxml-2.0)
layer2v_LDFLAGS		:= -shared -llayer1 -llayer0 $(shell pkg-config --libs libxml-2.0)

# sources
layer2v_SOURCES		:= $(shell find layer2v/src -name "*.c")
layer2v_OBJECTS		:= $(addsuffix .o,$(basename $(layer2v_SOURCES)))

# target
bin/liblayer2v.so: $(layer2v_OBJECTS) bin/liblayer1.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) $(layer2v_OBJECTS) $(layer2v_LDFLAGS) -o $@

# compile
layer2v/%.o: layer2v/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer2v_CPPFLAGS) $(layer2v_CFLAGS) $< -o $@

# clean
clean: layer2v-clean
layer2v-clean:
	$(RM) -r layer2v/src/visitor/ast/gen
	$(RM) -r layer2v/src/visitor/pt/gen

# all sources
SOURCES += $(layer2v_SOURCES)
