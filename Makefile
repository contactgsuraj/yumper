ROOTDIR=src/
TXTURDIR = src/screen_objs/
PHYSDIR = src/physics/
#OBJS specifies which files to compile as part of the project
OBJS = $(ROOTDIR)Main.cpp \
			 $(ROOTDIR)WindowInit.cpp \
			 $(ROOTDIR)Timer.cpp \
			 $(ROOTDIR)GameLoop.cpp \
			 $(PHYSDIR)Gravity.cpp \
			 $(TXTURDIR)Texture.cpp \
			 $(TXTURDIR)TextureContainer.cpp \
			 $(TXTURDIR)Ball.cpp \
			 $(TXTURDIR)Bob.cpp \
			 $(TXTURDIR)Text.cpp \
			 $(TXTURDIR)FPSCounter.cpp 
	
#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -g -o
#
#  #LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
#OBJ_NAME specifies the name of our exectuable
OUT = yumper

all: $(OUT)
$(OUT): $(OBJS)
	$(CC) $(COMPILER_FLAGS) $@ $^ ${LINKER_FLAGS}

clean:
	rm yumper
