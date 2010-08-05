# public
layer0_CPPFLAGS		:= -Ilayer0/include

# private
layer0_CFLAGS		:=
layer0_LDFLAGS		:= -shared

# sources
layer0_SOURCES	:= $(shell find layer0/src -name "*.c" -or -name "*.cpp")
layer0_OBJECTS	:= $(addsuffix .o,$(basename $(layer0_SOURCES)))

# target
bin/liblayer0.so: $(layer0_OBJECTS)
	@echo "   CCLD   " $@
	@$(LINK.c) $(layer0_OBJECTS) $(layer0_LDFLAGS) -o $@

# compile
layer0/%.o: layer0/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(layer0_CPPFLAGS) $(layer0_CFLAGS) $< -o $@

layer0/%.o: layer0/%.cpp
	@echo "   CXX    " $@
	@$(COMPILE.cpp) $(layer0_CPPFLAGS) $(layer0_CXXFLAGS) $< -o $@

# all sources
SOURCES += $(layer0_SOURCES)

prepare: layer0/include/stdinc.h.gch
%.h.gch: %.h
	$(RM) $@
	$(COMPILE.c) $(layer0_CPPFLAGS) $<
