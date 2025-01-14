CXX = g++
CXXFLAGS = -Wall -g
STATIC_LIB = libsocketutil.a

ifeq ($(OS),Windows_NT)
	CLEAN_CMD = del /f
else
	CLEAN_CMD = rm -f
endif

$(STATIC_LIB): socketUtil.o
	ar rcs $(STATIC_LIB) socketUtil.o

socketUtil.o: socketUtil.c socketUtil.h
	$(CXX) $(CXXFLAGS) -c socketUtil.c

clean:
	$(CLEAN_CMD) *.o $(STATIC_LIB)
