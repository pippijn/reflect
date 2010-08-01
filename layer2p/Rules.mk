layer2p_CFLAGS	:= $(layer1_CFLAGS) -Ilayer2p/include -Ilayer2p/src/yy
layer2p_SOURCES	:=		\
	layer2p/src/yy/lexer.c	\
	layer2p/src/yy/parser.c	\
	$(wildcard layer2p/src/*.c)
layer2p_OBJECTS	:= $(addsuffix .o,$(basename $(layer2p_SOURCES)))

bin/liblayer2p.so: $(layer2p_OBJECTS) bin/liblayer1.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) -shared $(layer2p_OBJECTS) -llayer1 -llayer0 -o $@

layer2p/%.o: layer2p/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer2p_CFLAGS) $< -o $@

clean: layer2p-clean
layer2p-clean:
	$(RM)    layer2p/src/yy/lexer.[ch]
	$(RM)    layer2p/src/yy/parser.[chy]
	$(RM) -r layer2p/src/yy/gen


layer2p/src/yy/gen/%.y: layer2p/src/yy/grammar/%.h $(shell find layer2p/src/yy/grammar -name "*.y")
	$(MKDIR_P) $(@D)
	$(CPP) $(YCPPFLAGS) -C -P -xc++ $< -o $@
	sed -i -e 's/^%[%{}]//' $@

layer2p/src/yy/parser.y:			\
		layer2p/src/yy/parser.y.in	\
		layer2p/src/yy/gen/rules.y	\
		layer2p/src/yy/gen/tokens.y
	$(CPP) $(YCPPFLAGS) -C -P -xc++ $< -o $@
	sed -i -e 's/^##include/#include/' $@
	sed -i -e 's/^##define/#define/' $@

SOURCES += $(layer2p_SOURCES)
