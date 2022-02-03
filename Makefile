CXX = clang++
CXXFLAGS = -std=c++17

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

hello_OBJS = hello.o
hello: $(hello_OBJS)
	$(CXX) $(CXXFLAGS) $(hello_OBJS) -o main

literal_type_OBJS = literal_type.o
literal_type: $(literal_type_OBJS)
	$(CXX) $(CXXFLAGS) $(literal_type_OBJS) -o main

clean:
	rm -f *.o main