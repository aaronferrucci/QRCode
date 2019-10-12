
SRC := ../../src
INC := ../../src
OBJS := shellqr.o qrcode.o

shellqr: $(OBJS) 
	gcc -o shellqr $(OBJS)

qrcode.o: $(SRC)/qrcode.c $(INC)/qrcode.h
	gcc -c $(SRC)/qrcode.c -I $(INC) 

shellqr.o: shellqr.c $(INC)/qrcode.h
	gcc -c shellqr.c -I $(INC) 
