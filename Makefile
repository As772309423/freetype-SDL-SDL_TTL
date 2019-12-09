ROOT_PATH = ~/Desktop
SDL_PATH = $(ROOT_PATH)/font/test/SDL/include
SDL_TTL_PATH = $(ROOT_PATH)/font/test/SDL_TTL/include/SDL
FT_PATH = $(ROOT_PATH)/font/test/freetype/include

SDL_LIB_PATH = $(ROOT_PATH)/font/test/SDL/lib
SDL_TLL_LIB_PATH = $(ROOT_PATH)/font/test/SDL_TTL/lib
FT_LIB_PATH = $(ROOT_PATH)/font/test/freetype/lib

CCO = arm-hisiv500-linux-gcc

CC = $(CCO)
INCLUDE = -I$(FT_PATH) -I$(SDL_TTL_PATH) -I$(SDL_PATH)
LIB = -L$(FT_LIB_PATH) -L$(SDL_LIB_PATH) -L$(SDL_TLL_LIB_PATH)
SERVER_OBJS = soapC.o stdsoap2.o duration.o wsaapi.o soapClient.o onvif_cilent.o


all: arm 
arm:
	$(CCO) *.c $(INCLUDE) $(LIB) -lfreetype -lSDL -lSDL_ttf -o test


clean: 
	rm -f *.o test
