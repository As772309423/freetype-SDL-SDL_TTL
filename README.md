# freetype-SDL-SDL_TTL
the sourse code of freetype、SDL、SDL_TTL 


# Makefile

1） create a font directory, copy the freetype, SDL, SDL_TTL source package to the font directory, decompress and compile the static library (or dynamic library);

2) create a test directory under the font directory;

3) create the lib directory and copy related static libraries (or dynamic libraries) to lib;

4) copy the include directory related to each source package to the test directory;

5) modify ROOT_PATH in Makefile.

6) make
