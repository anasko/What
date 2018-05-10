libMyBigChars.a: myBigChars.c
	@$(DIRGUARD)
	@cp -R ./*.h ../include/
	@gcc -I../include/ -c myBigChars.c
	@ar ruv ../lib/libMyBigChars.a myBigChars.o
	@ranlib ../lib/libMyBigChars.a
	@rm -fR myBigChars.o
