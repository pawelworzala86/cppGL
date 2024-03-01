g++.exe -Wall -O2  -c C:\cppGL\main.cpp -o obj\Release\main.o
g++.exe  -o bin\Release\cppGL.exe obj\Release\main.o  -s -LC:\cppGL\ -lopengl32 -lglu32 -lgdi32 -mwindows -lfreeimage

cd dist
.\..\bin\Release\cppGL.exe
cd ..