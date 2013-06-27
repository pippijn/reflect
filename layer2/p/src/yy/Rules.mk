clean: layer2p-clean
layer2p-clean:
	$(RM)    layer2/p/src/yy/lexer.[ch]
	$(RM)    layer2/p/src/yy/parser.[chy]
	$(RM) -r layer2/p/src/yy/gen


layer2/p/src/yy/gen/%.y: layer2/p/src/yy/grammar/%.h $(shell find layer2/p/src/yy/grammar -name "*.y")
	$(MKDIR_P) $(@D)
	$(CPP) $(YCPPFLAGS) -P -xc $< -o $@
	sed -i -e 's/^%[%{}]//' $@

%-pp.y: %.y generate/grammar/gpp $(shell find generate/grammar -type f)
	generate/grammar/gpp -y $< $@

generate/data/pt.ast: layer2/p/src/yy/gen/rules.y generate/grammar/gpp $(shell find generate/grammar -type f)
	generate/grammar/gpp -a $< $@

layer2/p/src/yy/parser.y:			\
		layer2/p/src/yy/parser.y.in	\
		layer2/p/src/yy/gen/rules-pp.y	\
		layer2/p/src/yy/gen/tokens.y
	$(CPP) $(YCPPFLAGS) -P -xc $< -o $@
	sed -i -e 's/^##include/#include/' $@
	sed -i -e 's/^##define/#define/' $@
