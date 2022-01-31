CXX = clang++
CXXFLAGS = -std=c++17
EXE = main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

hello_OBJS = hello.o
hello: $(hello_OBJS)
	$(CXX) $(CXXFLAGS) $(hello_OBJS) -o main

clean:
	rm -f *.o main