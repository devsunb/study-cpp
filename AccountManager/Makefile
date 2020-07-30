CC = g++
OBJS = AccountManagerFunc.o AccountManagerMain.o
TARGET = AccountManager

.SUFFIXES : .cpp .o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean :
	rm -f $(OBJS) $(TARGET)

AccountManagerFunc.o : AccountManagerFunc.cpp AccountManager.h
AccountManagerMain.o : AccountManagerMain.cpp AccountManager.h
