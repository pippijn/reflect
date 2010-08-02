layer2x_INCLUDE	:= $(layer1_CFLAGS) -Ilayer2x/include

layer2x_CFLAGS	:= $(layer2x_INCLUDE) $(shell pkg-config --cflags libxml-2.0)
layer2x_LDFLAGS	:= -llayer1 -llayer0 $(shell pkg-config --libs libxml-2.0)

layer2x_SOURCES	:= $(shell find layer2x/src -name "*.c")
layer2x_OBJECTS	:= $(addsuffix .o,$(basename $(layer2x_SOURCES)))

bin/liblayer2x.so: $(layer2x_OBJECTS) bin/liblayer1.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) -shared $(layer2x_OBJECTS) $(layer2x_LDFLAGS) -o $@

layer2x/%.o: layer2x/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer2x_CFLAGS) $< -o $@

SOURCES += $(layer2x_SOURCES)
