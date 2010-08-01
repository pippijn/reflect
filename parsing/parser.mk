parsing/gen/%.y: parsing/grammar/%.h $(shell find parsing/grammar -name "*.y")
	$(MKDIR_P) $(@D)
	$(CPP) $(YCPPFLAGS) -C -P -xc++ $< -o $@
	sed -i -e 's/^%[%{}]//' $@

parsing/parser.y:			\
		parsing/parser.y.in	\
		parsing/gen/rules.y	\
		parsing/gen/tokens.y
	$(CPP) $(YCPPFLAGS) -C -P -xc++ $< -o $@
	sed -i -e 's/^##include/#include/' $@
	sed -i -e 's/^##define/#define/' $@
