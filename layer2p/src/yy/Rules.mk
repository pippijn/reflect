clean: layer2p-clean
layer2p-clean:
	$(RM)    layer2p/src/yy/lexer.[ch]
	$(RM)    layer2p/src/yy/parser.[chy]
	$(RM) -r layer2p/src/yy/gen


layer2p/src/yy/gen/%.y: layer2p/src/yy/grammar/%.h $(shell find layer2p/src/yy/grammar -name "*.y")
	$(MKDIR_P) $(@D)
	$(CPP) $(YCPPFLAGS) -P -xc $< -o $@
	sed -i -e 's/^%[%{}]//' $@

%-pp.y: %.y
	generate/grammar/gpp $< > $@

layer2p/src/yy/parser.y:			\
		layer2p/src/yy/parser.y.in	\
		layer2p/src/yy/gen/rules-pp.y	\
		layer2p/src/yy/gen/tokens.y
	$(CPP) $(YCPPFLAGS) -P -xc $< -o $@
	sed -i -e 's/^##include/#include/' $@
	sed -i -e 's/^##define/#define/' $@
