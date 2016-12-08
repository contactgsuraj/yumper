ROOTDIR=src/
TXTURDIR = src/screen_objs/
PHYSDIR = src/physics/
#OBJS specifies which files to compile as part of the project
OBJS = $(ROOTDIR)Main.cpp \
			 $(ROOTDIR)WindowInit.cpp \
			 $(ROOTDIR)Timer.cpp \
			 $(ROOTDIR)IO.cpp \
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
COMPILER_FLAGS = -g
#
#  #LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = yumpa

#This is the target that compiles our executable
all: exe
exe: $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean :
	rm $(OBJ_NAME)
