CC = g++
TARGET = tetris

SOURCES = main.cpp\
 					Tetris.cpp \
					Pane.cpp \
					BoardPane.cpp \
					InfoPane.cpp \
					HelpPane.cpp \
					StatPane.cpp \
					NextPane.cpp \
					Block.cpp \
					I_Block.cpp \
					S_Block.cpp \
					Z_Block.cpp \
					L_Block.cpp \
					J_Block.cpp \
					T_Block.cpp \

LDFLAGS = -lncurses
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)
