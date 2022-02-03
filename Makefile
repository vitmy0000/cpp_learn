CXX = clang++
CXXFLAGS = -std=c++17

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

hello: hello.o
	$(CXX) $(CXXFLAGS) hello.o -o main

literal_type: literal_type.o
	$(CXX) $(CXXFLAGS) literal_type.o -o main

clean:
	rm -f *.o main