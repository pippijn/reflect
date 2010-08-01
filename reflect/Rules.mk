reflect_CFLAGS	:= $(layer2p_CFLAGS) $(layer2v_CFLAGS) -Ireflect/include
reflect_SOURCES	:= $(shell find reflect/src -name "*.c")
reflect_OBJECTS	:= $(addsuffix .o,$(basename $(reflect_SOURCES)))

bin/reflect: $(reflect_OBJECTS) bin/liblayer2v.so bin/liblayer2p.so bin/liblayer1.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) $(reflect_OBJECTS) -llayer2v -llayer2p -llayer1 -llayer0 -o $@

reflect/%.o: reflect/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(reflect_CFLAGS) $< -o $@

SOURCES += $(reflect_SOURCES)
