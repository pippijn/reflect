# public
layer2x_CPPFLAGS	:= $(layer1a_CPPFLAGS) -Ilayer2/x/include

# private
layer2x_CFLAGS		:= -Ilayer2/x/src/include $(shell pkg-config --cflags libxml-2.0)
layer2x_LDFLAGS		:= -shared -llayer1a -llayer0 $(shell pkg-config --libs libxml-2.0)

# sources
layer2x_SOURCES		:= $(shell find layer2/x/src -name "*.c")
layer2x_OBJECTS		:= $(addsuffix .o,$(basename $(layer2x_SOURCES)))

# target
bin/liblayer2x.so: $(layer2x_OBJECTS) bin/liblayer1a.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) $(layer2x_OBJECTS) $(layer2x_LDFLAGS) -o $@

# compile
layer2/x/%.o: layer2/x/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer2x_CPPFLAGS) $(layer2x_CFLAGS) $< -o $@

# all sources
SOURCES += $(layer2x_SOURCES)
