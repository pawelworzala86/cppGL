gcc.exe -Wall -g  -c C:\cppGL\main.cpp  -o obj\Debug\main.o
gcc.exe  -o bin\Debug\cppGL.exe obj\Debug\main.o -LC:\cppGL\  -lopengl32 -lglu32 -lgdi32 -lfreeimage

cd dist
.\..\bin\Debug\cppGL.exe
cd ..