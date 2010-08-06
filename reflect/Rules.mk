# public
reflect_CPPFLAGS	:= $(layer2p_CPPFLAGS) $(layer2v_CPPFLAGS) $(layer2x_CPPFLAGS) -Ireflect/include

# private
reflect_CFLAGS		:= -Ireflect/src/include
reflect_LDFLAGS		:= -llayer2x -llayer2v -llayer2p -llayer1a -llayer0

# sources
reflect_SOURCES		:= $(shell find reflect/src -name "*.c")
reflect_OBJECTS		:= $(addsuffix .o,$(basename $(reflect_SOURCES)))

# target
bin/reflect: $(reflect_OBJECTS) bin/liblayer2x.so bin/liblayer2v.so bin/liblayer2p.so bin/liblayer1a.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) $(reflect_OBJECTS) $(reflect_LDFLAGS) -o $@;

# compile
reflect/%.o: reflect/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(reflect_CPPFLAGS) $(reflect_CFLAGS) $< -o $@

# all sources
SOURCES += $(reflect_SOURCES)
