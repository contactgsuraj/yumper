ROOTDIR=src/
CONSTTXTUREDIR = src/textures/constant/
TXTUREDIR = src/textures/
OBSTACLEDIR = src/textures/obstacles/
SPIKEDIR = src/textures/obstacles/spikeTrap/
PHYSDIR = src/physics/
OBJS = $(ROOTDIR)Main.o \
			 $(ROOTDIR)WindowInit.o \
			 $(ROOTDIR)Timer.o \
			 $(ROOTDIR)GameLoop.o \
			 $(ROOTDIR)ObstacleGenerator.o \
			 $(PHYSDIR)Gravity.o \
			 $(PHYSDIR)Collision.o \
			 $(CONSTTXTUREDIR)Ball.o \
			 $(CONSTTXTUREDIR)Bob.o \
			 $(CONSTTXTUREDIR)FPSCounter.o \
			 $(CONSTTXTUREDIR)ScoreCounter.o \
			 $(CONSTTXTUREDIR)TextureContainer.o \
			 $(CONSTTXTUREDIR)Floor.o \
			 $(CONSTTXTUREDIR)BG.o \
			 $(TXTUREDIR)Text.o \
			 $(TXTUREDIR)ScrollableTexture.o \
			 $(TXTUREDIR)Texture.o \
			 $(OBSTACLEDIR)Obstacle.o \
			 $(SPIKEDIR)SpikeTrap.o
	
CXX = g++
CXXFLAGS = -g -Wall -Werror
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OUT = yumper

all: $(OUT)
$(OUT): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^ $(LDLIBS)

clean:
	-rm -f $(OUT) $(OBJS)

$(ROOTDIR)Main.o: $(ROOTDIR)Main.cpp $(ROOTDIR)GameLoop.hpp $(ROOTDIR)Timer.hpp $(ROOTDIR)WindowInit.hpp $(CONSTTXTUREDIR)Bob.hpp $(CONSTTXTUREDIR)FPSCounter.hpp $(CONSTTXTUREDIR)TextureContainer.hpp
$(ROOTDIR)WindowInit.o: $(ROOTDIR)WindowInit.hpp $(ROOTDIR)const.hpp
$(ROOTDIR)GameLoop.o: $(ROOTDIR)GameLoop.hpp $(CONSTTXTUREDIR)TextureContainer.hpp $(CONSTTXTUREDIR)ScoreCounter.hpp $(CONSTTXTUREDIR)FPSCounter.hpp $(CONSTTXTUREDIR)Bob.hpp
$(ROOTDIR)ObstacleGenerator.o: $(ROOTDIR)ObstacleGenerator.hpp $(SPIKEDIR)SpikeTrap.hpp 
$(CONSTTXTUREDIR)TextureContainer.o:$(ROOTDIR)const.hpp $(TXTUREDIR)Texture.hpp $(CONSTTXTUREDIR)TextureContainer.hpp
$(CONSTTXTUREDIR)Ball.o:$(CONSTTXTUREDIR)Ball.hpp $(ROOTDIR)const.hpp $(TXTUREDIR)Texture.hpp
$(CONSTTXTUREDIR)Bob.o:$(CONSTTXTUREDIR)Bob.hpp $(ROOTDIR)const.hpp $(PHYSDIR)Gravity.hpp
$(TXTUREDIR)Text.o:$(TXTUREDIR)Text.hpp $(TXTUREDIR)Texture.hpp
$(TXTUREDIR)ScrollableTexture.o:$(TXTUREDIR)ScrollableTexture.hpp $(TXTUREDIR)Texture.hpp
$(CONSTTXTUREDIR)ScoreCounter.o:$(CONSTTXTUREDIR)ScoreCounter.hpp $(TXTUREDIR)Text.hpp $(ROOTDIR)const.hpp 
$(CONSTTXTUREDIR)FPSCounter.o:$(CONSTTXTUREDIR)FPSCounter.hpp $(ROOTDIR)Timer.hpp $(TXTUREDIR)Text.hpp $(ROOTDIR)const.hpp 
$(CONSTTXTUREDIR)Floor.o:$(CONSTTXTUREDIR)Floor.hpp $(TXTUREDIR)ScrollableTexture.cpp $(ROOTDIR)const.hpp
$(CONSTTXTUREDIR)BG.o:$(CONSTTXTUREDIR)BG.hpp $(TXTUREDIR)ScrollableTexture.cpp $(ROOTDIR)const.hpp
$(OBSTACLEDIR)Obstacle.o:$(OBSTACLEDIR)Obstacle.hpp $(TXTUREDIR)ScrollableTexture.cpp
$(SPIKEDIR)SpikeTrap.o:$(SPIKEDIR)SpikeTrap.hpp $(OBSTACLEDIR)Obstacle.hpp $(ROOTDIR)const.hpp
$(PHYSDIR)Collision.o:$(CONSTTXTUREDIR)Bob.hpp 


.PHONY: all clean
