layer1_CFLAGS	:= $(layer0_CFLAGS) -Ilayer1/include
layer1_SOURCES	:= $(shell find layer1/src -name "*.c")
layer1_OBJECTS	:= $(addsuffix .o,$(basename $(layer1_SOURCES)))

bin/liblayer1.so: $(layer1_OBJECTS) bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) -shared $(layer1_OBJECTS) -llayer0 -o $@

layer1/%.o: layer1/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer1_CFLAGS) $< -o $@

clean: layer1-clean
layer1-clean:
	$(RM) -r layer1/include/ast/gen
	$(RM) -r layer1/src/ast/gen
	$(RM) -r layer1/include/pt/gen
	$(RM) -r layer1/src/pt/gen

SOURCES += $(layer1_SOURCES)
