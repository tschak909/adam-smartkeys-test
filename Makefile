CC=zcc +coleco -pragma-redirect:CRT_FONT=_font_8x8_msx_system -subtype=adam
AS=z88dk-z80asm

all: adam-smartkeys-test

clean:
	$(RM) -f adam-smartkeys-test *.o *.ddp *.bin

adam-smartkeys-test.o: adam-smartkeys-test.c
	$(CC) -o adam-smartkeys-test.o -c adam-smartkeys-test.c 

adam-smartkeys-test: adam-smartkeys-test.o
	$(CC) -oadam-smartkeys-test -create-app adam-smartkeys-test.o
