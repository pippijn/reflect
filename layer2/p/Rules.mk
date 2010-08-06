# public
layer2p_CPPFLAGS	:= $(layer1a_CPPFLAGS) -Ilayer2/p/include -Ilayer2/p/src/yy

# private
layer2p_CFLAGS		:= -Ilayer2/p/src/include
layer2p_LDFLAGS		:= -shared -llayer1a -llayer0

# sources
layer2p_SOURCES		:=	\
	layer2/p/src/yy/lexer.c	\
	layer2/p/src/yy/parser.c	\
	$(wildcard layer2/p/src/*.c)
layer2p_OBJECTS	:= $(addsuffix .o,$(basename $(layer2p_SOURCES)))

# target
bin/liblayer2p.so: $(layer2p_OBJECTS) bin/liblayer1a.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) $(layer2p_OBJECTS) $(layer2p_LDFLAGS) -o $@

# compile
layer2/p/%.o: layer2/p/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer2p_CPPFLAGS) $(layer2p_CFLAGS) $< -o $@

# extra yacc rules
include layer2/p/src/yy/Rules.mk

# all sources
SOURCES += $(layer2p_SOURCES)
