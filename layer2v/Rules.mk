layer2v_INCLUDE	:= $(layer1_CFLAGS) -Ilayer2v/include

layer2v_CFLAGS	:= $(layer2v_INCLUDE) $(shell pkg-config --cflags libxml-2.0)
layer2v_LDFLAGS	:= -llayer1 -llayer0 $(shell pkg-config --libs libxml-2.0)

layer2v_SOURCES	:= $(shell find layer2v/src -name "*.c")
layer2v_OBJECTS	:= $(addsuffix .o,$(basename $(layer2v_SOURCES)))

bin/liblayer2v.so: $(layer2v_OBJECTS) bin/liblayer1.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) -shared $(layer2v_OBJECTS) $(layer2v_LDFLAGS) -o $@

layer2v/%.o: layer2v/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer2v_CFLAGS) $< -o $@

clean: layer2v-clean
layer2v-clean:
	$(RM) -r layer2v/src/visitor/ast/gen
	$(RM) -r layer2v/src/visitor/pt/gen

SOURCES += $(layer2v_SOURCES)
