ROOTDIR=src/
TXTURDIR = src/textures/constant/
OBSTACLEDIR = src/textures/obstacles/
PHYSDIR = src/physics/
OBJS = $(ROOTDIR)Main.o \
			 $(ROOTDIR)WindowInit.o \
			 $(ROOTDIR)Timer.o \
			 $(ROOTDIR)GameLoop.o \
			 $(PHYSDIR)Gravity.o \
			 $(TXTURDIR)Ball.o \
			 $(TXTURDIR)Bob.o \
			 $(TXTURDIR)FPSCounter.o \
			 $(TXTURDIR)ScoreCounter.o \
			 $(TXTURDIR)Text.o \
			 $(TXTURDIR)Texture.o \
			 $(TXTURDIR)TextureContainer.o
	
CXX = g++
CXXFLAGS = -g
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OUT = yumper

all: $(OUT)
$(OUT): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^ $(LDLIBS)

clean:
	-rm -f $(OUT) $(OBJS)

$(ROOTDIR)Main.o: $(ROOTDIR)Main.cpp $(ROOTDIR)GameLoop.hpp $(ROOTDIR)Timer.hpp $(ROOTDIR)WindowInit.hpp $(TXTURDIR)Bob.hpp $(TXTURDIR)FPSCounter.hpp $(TXTURDIR)TextureContainer.hpp
$(ROOTDIR)WindowInit.o: $(ROOTDIR)WindowInit.hpp $(ROOTDIR)const.hpp
$(ROOTDIR)GameLoop.o: $(ROOTDIR)GameLoop.hpp $(TXTURDIR)TextureContainer.o $(TXTURDIR)ScoreCounter.o $(TXTURDIR)FPSCounter.o $(TXTURDIR)Bob.o
$(TXTURDIR)TextureContainer.o:$(ROOTDIR)const.hpp $(TXTURDIR)Texture.hpp $(TXTURDIR)TextureContainer.hpp
$(TXTURDIR)Ball.o:$(TXTURDIR)Ball.hpp $(ROOTDIR)const.hpp $(TXTURDIR)Texture.hpp
$(TXTURDIR)Bob.o:$(TXTURDIR)Bob.hpp $(ROOTDIR)const.hpp $(PHYSDIR)Gravity.hpp
$(TXTURDIR)Text.o:$(TXTURDIR)Text.hpp $(TXTURDIR)Texture.hpp
$(TXTURDIR)ScoreCounter.o:$(TXTURDIR)ScoreCounter.hpp $(TXTURDIR)Text.hpp $(ROOTDIR)const.hpp 
$(TXTURDIR)FPSCounter.o:$(TXTURDIR)FPSCounter.hpp $(ROOTDIR)Timer.hpp $(TXTURDIR)Text.hpp $(ROOTDIR)const.hpp 

.PHONY: all clean
