# public
layer2p_CPPFLAGS	:= $(layer1_CPPFLAGS) -Ilayer2p/include -Ilayer2p/src/yy

# private
layer2p_CFLAGS		:= -Ilayer2p/src/include
layer2p_LDFLAGS		:= -shared -llayer1 -llayer0

# sources
layer2p_SOURCES		:=	\
	layer2p/src/yy/lexer.c	\
	layer2p/src/yy/parser.c	\
	$(wildcard layer2p/src/*.c)
layer2p_OBJECTS	:= $(addsuffix .o,$(basename $(layer2p_SOURCES)))

# target
bin/liblayer2p.so: $(layer2p_OBJECTS) bin/liblayer1.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) $(layer2p_OBJECTS) $(layer2p_LDFLAGS) -o $@

# compile
layer2p/%.o: layer2p/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer2p_CPPFLAGS) $(layer2p_CFLAGS) $< -o $@

# extra yacc rules
include layer2p/src/yy/Rules.mk

# all sources
SOURCES += $(layer2p_SOURCES)
