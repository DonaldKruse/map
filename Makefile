CC         = gcc
CFLAGS     = -fPIC -Wall -Wextra -g
#CFLAGS     = -Wall -Wextra
LDFLAGS    = -shared
RM         = rm
NAME_LIB   = map
TARGET_LIB = lib$(NAME_LIB).so

SRCS = src/map.c
TEST_SRCS = src/test.c
TEST_OUTPUT = test
OBJS = $(SRCS:.c=.o)

.PHONY: all
all: $(TARGET_LIB) $(TEST_OUTPUT)

$(TARGET_LIB): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	-$(RM) $(TARGET_LIB) $(OBJS) $(TEST_OUTPUT)

test:
	-$(CC) $(CFLAGS) $(TEST_SRCS) -l$(NAME_LIB) -Wl,-rpath,. -o $(TEST_OUTPUT) -L.
