SOURCES =		\
	src/main.c	\
	src/parser.y	\
	src/lexer.l

OBJECTS = $(addsuffix .o,$(basename $(SOURCES)))

reflect: $(OBJECTS)
	$(LINK.c) $(OBJECTS) -o $@

clean:
	$(RM) $(OBJECTS) reflect
	$(RM) src/parser.c src/parser.h
	$(RM) src/lexer.c

%.c: %.y
	$(YACC) -d $< -o $@
