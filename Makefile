CXX = g++
CXXFLAGS = -Wall -g
STATIC_LIB = libsocketutil.a

$(STATIC_LIB): socketUtil.o
	ar rcs $(STATIC_LIB) socketUtil.o

socketUtil.o: socketUtil.c socketUtil.h
	$(CXX) $(CXXFLAGS) -c socketUtil.c

clean:
	rm -f *.o $(STATIC_LIB)
