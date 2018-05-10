libMyTerm.a: myTerm.c
	@$(DIRGUARD)
	@cp -R ./*.h ../include/
	@gcc -I../include/ -c myTerm.c
	@ar ruv ../lib/libMyTerm.a myTerm.o
	@ranlib ../lib/libMyTerm.a
	@rm -fR myTerm.o
