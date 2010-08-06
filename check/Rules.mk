# public
check_CPPFLAGS		:= $(layer2p_CPPFLAGS) $(layer2v_CPPFLAGS) $(layer2x_CPPFLAGS) -Icheck/include

# private
check_CFLAGS		:= -Icheck/src/include
check_LDFLAGS		:= -lcheck -llayer2x -llayer2v -llayer2p -llayer1 -llayer0

# sources
check_SUITES		:= $(shell find check/src -name "*_suite.h")
check_SOURCES		:= $(patsubst %_suite.h,%.c,$(check_SUITES)) check/src/main.c
check_OBJECTS		:= $(addsuffix .o,$(basename $(check_SOURCES)))

# target
bin/check: $(check_OBJECTS) bin/liblayer2x.so bin/liblayer2v.so bin/liblayer2p.so bin/liblayer1.so bin/liblayer0.so
	@echo "   CCLD   " $@
	@$(LINK.c) $(check_OBJECTS) $(check_LDFLAGS) -o $@

# compile
check/%.o: check/%.c
	@echo "   CC     " $@
	@$(COMPILE.c) $(check_CPPFLAGS) $(check_CFLAGS) $< -o $@

$(check_OBJECTS): check/include/gen/suites.h
check/include/gen/suites.h: $(check_SOURCES)
	@echo "   MAKE   " $@
	@$(MKDIR_P) $(@D)
	@grep -oh '^suite_\w\+' $(check_SOURCES) | sed -e 's/^suite_/SUITE (/;s/$$/)/' > $@

SUITE = $(subst /,_,$(patsubst check/src/layer0/%.h,%,$1))

%.c: %_suite.h
	@echo "   MAKE   " $@
	@echo "#include <check.h>" > $@
	@echo "#include <suites.h>" >> $@
	@echo "#include \"$(<F)\"" >> $@
	@echo "" >> $@
	@echo "Suite *" >> $@
	@echo "suite_$(call SUITE,$<) (void)" >> $@
	@echo "{" >> $@
	@echo "  Suite *s = suite_create (\"$(call SUITE,$<)\");" >> $@
	@echo "" >> $@
	@echo "  TCase *tc_master = tcase_create (\"$(call SUITE,$<)\");" >> $@
	@echo "  tcase_add_checked_fixture (tc_master, setup, teardown);" >> $@
	@for i in `$(CPP) $< 2> /dev/null	\
			| grep '^START_TEST'	\
			| sed -e 's/START_TEST (\(\w\+\))/\1/'`; do	\
		echo "  tcase_add_test (tc_master, $$i);" >> $@;	\
	done
	@echo "  suite_add_tcase (s, tc_master);" >> $@
	@echo "" >> $@
	@echo "  return s;" >> $@
	@echo "}" >> $@

clean: check-clean
check-clean:
	$(RM) $(shell find check/src/layer* -name "*.c")

# all sources
SOURCES += $(check_SOURCES)
