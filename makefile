CXX = g++-8
CXX_FLAGS = -std=c++17
CXX_FLAGS += -Wuninitialized -Wall -Wextra -Werror -pedantic -Wfatal-errors # source code quality.
CXX_FLAGS += -O0 -g # for testing and debugging.
CXX_FLAGS += -I./ # include paths.

SRCS = test.cpp

%.o: %.cpp; $(CXX) $(CXX_FLAGS) -o $@ -c $<

OBJS = $(SRCS:.cpp=.o)

all: $(OBJS); $(CXX) $^ -o test.out

clean: ; rm -rf test.out $(OBJS) *.dSYM
