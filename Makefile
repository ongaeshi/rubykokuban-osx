MRUBY    = ../rubykokuban-mruby
HEADER   = $(MRUBY)/include
LIBMRUBY = $(MRUBY)/build/osx/lib/libmruby.a
SRC      = ./apps/RubyKokubanWorkspace/RubyKokuban/src/mruby

update-mruby:
	mkdir -p $(SRC) $(SRC)/mruby
	cp $(LIBMRUBY) $(SRC)
	cp $(HEADER)/*.h $(SRC)
	cp $(HEADER)/mruby/*.h $(SRC)/mruby

.PHONY: update-mruby

