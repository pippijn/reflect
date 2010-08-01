layer0_CFLAGS	:= -Ilayer0/include
layer0_SOURCES	:= $(shell find layer0/src -name "*.c")
layer0_OBJECTS	:= $(addsuffix .o,$(basename $(layer0_SOURCES)))

bin/liblayer0.so: $(layer0_OBJECTS)
	@echo "   CCLD   " $@
	@$(LINK.c) -shared $(layer0_OBJECTS) -o $@

layer0/%.o: layer0/%.c
	$(COMPILE.c) $(layer0_CFLAGS) $< -o $@

SOURCES += $(layer0_SOURCES)
