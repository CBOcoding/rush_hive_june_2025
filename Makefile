CC = cc
CFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = assistant

HDR = user_interface.h
SRCS = $(wildcard *.c)

all: $(TARGET) $(HDR)
	@./$(TARGET)

$(TARGET): $(SRCS) $(HDR)
	@$(CC) $(SRCS) -o $(TARGET) $(CFLAGS)

clean:
	@rm -f $(TARGET)

re: clean all

.PHONY: all clean re run
