libMyBigChars.a: myReadKey.c
	@$(DIRGUARD)
	@cp -R ./*.h ../include/
	@gcc -I../include/ -c myReadKey.c
	@ar ruv ../lib/libMyReadKey.a myReadKey.o
	@ranlib ../lib/libMyReadKey.a
	@rm -fR myReadKey.o
