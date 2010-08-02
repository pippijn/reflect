# public
layer0_CPPFLAGS		:= -Ilayer0/include

# private
layer0_CFLAGS		:=
layer0_LDFLAGS		:= -shared

# sources
layer0_SOURCES	:= $(shell find layer0/src -name "*.c")
layer0_OBJECTS	:= $(addsuffix .o,$(basename $(layer0_SOURCES)))

# target
bin/liblayer0.so: $(layer0_OBJECTS)
	@echo "   CCLD   " $@
	@$(LINK.c) $(layer0_OBJECTS) $(layer0_LDFLAGS) -o $@

# compile
layer0/%.o: layer0/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer0_CPPFLAGS) $(layer0_CFLAGS) $< -o $@

# all sources
SOURCES += $(layer0_SOURCES)
