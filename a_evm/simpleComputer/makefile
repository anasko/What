libMySimpComp.a: mySimpleComputer.c
	@$(DIRGUARD)
	@cp -R ./*.h ../include/
	@gcc -I../include/ -c mySimpleComputer.c
	@ar ruv ../lib/libMySimpComp.a mySimpleComputer.o
	@ranlib ../lib/libMySimpComp.a
	@rm -fR mySimpleComputer.o
