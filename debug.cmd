g++.exe -Wall -g  -c C:\cppGL\main.cpp  -o obj\Debug\main.o
g++.exe  -o bin\Debug\cppGL.exe obj\Debug\main.o -LC:\cppGL\  -lopengl32 -lglu32 -lgdi32 -lfreeimage

IF ERRORLEVEL 1 GOTO koniec

cd dist
.\..\bin\Debug\cppGL.exe
cd ..

:koniec