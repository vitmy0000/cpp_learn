CXX = clang++
CXXFLAGS = -std=c++17
EXE = main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

hello_OBJS = hello.o
hello: $(hello_OBJS)
	$(CXX) $(CXXFLAGS) $(hello_OBJS) -o main

literal_type_OBJS = type.o
type: $(literal_type_OBJS)
	$(CXX) $(CXXFLAGS) $(literal_type_OBJS) -o main

clean:
	rm -f *.o main