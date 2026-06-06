CC      = gcc
CFLAGS  = -Wall -Wextra -O2
TARGET  = mfet
SRC     = mfet.c
PREFIX  = /usr/local

CYAN    = \033[36m
GREEN   = \033[32m
YELLOW  = \033[33m
RED     = \033[31m
RESET   = \033[0m

all: $(TARGET)

$(TARGET): $(SRC)
	@printf "$(CYAN)  CC$(RESET)      $(SRC) → $(TARGET)\n"
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	@printf "$(GREEN)  BUILD$(RESET)   $(TARGET) ready\n"

run: $(TARGET)
	@printf "$(YELLOW)  RUN$(RESET)     ./$(TARGET)\n\n"
	@./$(TARGET)

install: $(TARGET)
	@printf "$(CYAN)  INSTALL$(RESET) $(PREFIX)/bin/$(TARGET)\n"
	@install -Dm755 $(TARGET) $(PREFIX)/bin/$(TARGET)
	@printf "$(GREEN)  DONE$(RESET)    installed to $(PREFIX)/bin\n"

uninstall:
	@printf "$(RED)  REMOVE$(RESET)  $(PREFIX)/bin/$(TARGET)\n"
	@rm -f $(PREFIX)/bin/$(TARGET)
	@printf "$(GREEN)  DONE$(RESET)    uninstalled\n"

clean:
	@printf "$(RED)  CLEAN$(RESET)   removing $(TARGET)\n"
	@rm -f $(TARGET)
	@printf "$(GREEN)  DONE$(RESET)\n"

help:
	@printf "\n$(CYAN)mfet — Makefile targets$(RESET)\n\n"
	@printf "  $(GREEN)make$(RESET)           build the binary\n"
	@printf "  $(GREEN)make run$(RESET)       build and run\n"
	@printf "  $(GREEN)make install$(RESET)   install to $(PREFIX)/bin\n"
	@printf "  $(GREEN)make uninstall$(RESET) remove from $(PREFIX)/bin\n"
	@printf "  $(GREEN)make clean$(RESET)     remove the binary\n"
	@printf "  $(GREEN)make help$(RESET)      show this message\n\n"

.PHONY: all run install uninstall clean help
