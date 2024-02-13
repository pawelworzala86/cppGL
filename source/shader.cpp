#include <stdio.h>

#include <gl/gl.h>


GLuint CreateShader(char* vertfileName,char* fragfileName){

    //char* vertfileName = "default.vert";
    //char* fragfileName = "default.frag";

    


    

    GLint Result = GL_FALSE;
	int InfoLogLength;


    HANDLE handle = CreateFile(vertfileName, GENERIC_READ,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, 0);
    int fsize = GetFileSize(handle, 0);
    void* buffor = malloc(fsize);
    ReadFile(handle, buffor, fsize, 0, 0);

    printf(" OK %i ", fsize);
    //printf(" OK %s ", &buffor);
    
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1, &buffor, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		//std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        char* VertexShaderErrorMessage = NULL;
		glGetShaderInfoLog(vertexShader, InfoLogLength, NULL, &VertexShaderErrorMessage);
		printf("%s\n", VertexShaderErrorMessage);
	}


    handle = CreateFile(fragfileName, GENERIC_READ,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, 0);
    fsize = GetFileSize(handle, 0);
    buffor = malloc(fsize);
    ReadFile(handle, buffor, fsize, 0, 0);

    //printf(" OK %i ", fsize);
    //printf(" OK %s ", &buffor);
    
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1, &buffor, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		//std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        char* VertexShaderErrorMessage = NULL;
		glGetShaderInfoLog(fragmentShader, InfoLogLength, NULL, &VertexShaderErrorMessage);
		printf("%s\n", VertexShaderErrorMessage);
	}

    printf("before creste prog");

    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    // Check the program
	glGetProgramiv(programID, GL_LINK_STATUS, &Result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		//std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        char* ProgramErrorMessage = NULL;
		glGetProgramInfoLog(programID, InfoLogLength, NULL, &ProgramErrorMessage);
		printf("%s\n", ProgramErrorMessage);
	}


    glUseProgram(programID);
    //gl.ValidateProgram,*programID

    glDetachShader(programID, vertexShader);
	glDetachShader(programID, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return programID;

}