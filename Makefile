CXX = clang++
CXXFLAGS = -std=c++17

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

hello: hello.o
	$(CXX) $(CXXFLAGS) hello.o -o main

literal_type: literal_type.o
	$(CXX) $(CXXFLAGS) literal_type.o -o main

function_overload: function_overload.o
	$(CXX) $(CXXFLAGS) function_overload.o -o main

auto_type: auto_type.o
	$(CXX) $(CXXFLAGS) auto_type.o -o main

inheritance: inheritance.o
	$(CXX) $(CXXFLAGS) inheritance.o -o main

pimpl: pimpl/widget.o pimpl/main.o
	$(CXX) $(CXXFLAGS) pimpl/widget.o pimpl/main.o -o main

clean:
	rm -f *.o main