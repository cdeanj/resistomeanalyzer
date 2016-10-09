CC=g++
TARGET := resistome
CXX_SRCS := $(wildcard *.cpp)
CXX_OBJS := ${CXX_SRCS:.cpp=.o}
CFLAGS := -c -std=c++11

all: $(TARGET)

$(TARGET): $(CXX_OBJS)
	$(CC) $(CXX_OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	$(RM) $(TARGET)
	$(RM) $(CXX_OBJS)
