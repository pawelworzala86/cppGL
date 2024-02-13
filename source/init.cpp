#include <windows.h>
#include <gl/gl.h>

#include <stdio.h>
#include <stdlib.h>


#include <string.h>







//typedef void (*GENBUFFERS) (int, GLuint*);

PROC glGenBuffers = NULL;
PROC glCreateShader = NULL;
PROC glCreateProgram = NULL;
PROC glShaderSource = NULL;
PROC glCompileShader = NULL;
PROC glAttachShader = NULL;
PROC glLinkProgram = NULL;
PROC glUseProgram = NULL;
PROC glGetUniformLocation = NULL;
PROC glUniform4f = NULL;
PROC glUniform4d = NULL;
PROC glUniform1d = NULL;
PROC glUniform1i = NULL;
PROC glUniform3dv = NULL;
PROC glUniformMatrix4dv = NULL;
PROC glBindBuffer = NULL;
PROC glBufferData = NULL;
PROC glVertexAttribPointer = NULL;
PROC glEnableVertexAttribArray = NULL;
PROC glGenVertexArrays = NULL;
PROC glBindVertexArray = NULL;
PROC glDeleteShader = NULL;
PROC glCreateFramebuffers = NULL;
PROC glBindFramebuffer = NULL;
PROC glFramebufferTexture2D = NULL;
PROC glValidateProgram = NULL;
PROC glActiveTexture = NULL;
PROC glGenerateMipmap = NULL;
PROC glUniform4fv = NULL;
PROC glUniform1iv = NULL;
PROC glUniform4dv = NULL;
PROC glGetShaderiv = NULL;
PROC glGetShaderInfoLog = NULL;
PROC glGetProgramiv = NULL;
PROC glGetProgramInfoLog = NULL;
PROC glDetachShader = NULL;








GLuint GL_VERTEX_SHADER		  = 35633;
GLuint GL_FRAGMENT_SHADER		  = 35632;
GLuint GL_COMPILE_STATUS		  = 35713;
GLuint GL_LINK_STATUS			  = 35650;
GLuint GL_INFO_LOG_LENGTH = 35716;


    GLuint GL_ARRAY_BUFFER 		  = 34962;
    GLuint GL_STATIC_DRAW			  = 35044;











int InitGL(){

    /*GENBUFFERS glGenBuffers = (GENBUFFERS)wglGetProcAddress("glGenBuffers");
    GLuint buffer;
    glGenBuffers(1, &buffer);*/

    glGenBuffers = wglGetProcAddress("glGenBuffers");
    glCreateShader = wglGetProcAddress("glCreateShader");
    glCreateProgram = wglGetProcAddress("glCreateProgram");
    glShaderSource = wglGetProcAddress("glShaderSource");
    glCompileShader = wglGetProcAddress("glCompileShader");
    glAttachShader = wglGetProcAddress("glAttachShader");
    glLinkProgram = wglGetProcAddress("glLinkProgram");
    glUseProgram = wglGetProcAddress("glUseProgram");
    glGetUniformLocation = wglGetProcAddress("glGetUniformLocation");
    glUniform4f = wglGetProcAddress("glUniform4f");
    glUniform4d = wglGetProcAddress("glUniform4d");
    glUniform1d = wglGetProcAddress("glUniform1d");
    glUniform1i = wglGetProcAddress("glUniform1i");
    glUniform3dv = wglGetProcAddress("glUniform3dv");
    glUniformMatrix4dv = wglGetProcAddress("glUniformMatrix4dv");
    glBindBuffer = wglGetProcAddress("glBindBuffer");
    glBufferData = wglGetProcAddress("glBufferData");
    glVertexAttribPointer = wglGetProcAddress("glVertexAttribPointer");
    glEnableVertexAttribArray = wglGetProcAddress("glEnableVertexAttribArray");
    glGenVertexArrays = wglGetProcAddress("glGenVertexArrays");
    glBindVertexArray = wglGetProcAddress("glBindVertexArray");
    glDeleteShader = wglGetProcAddress("glDeleteShader");
    glCreateFramebuffers = wglGetProcAddress("glCreateFramebuffers");
    glBindFramebuffer = wglGetProcAddress("glBindFramebuffer");
    glFramebufferTexture2D = wglGetProcAddress("glFramebufferTexture2D");
    glValidateProgram = wglGetProcAddress("glValidateProgram");
    glActiveTexture = wglGetProcAddress("glActiveTexture");
    glGenerateMipmap = wglGetProcAddress("glGenerateMipmap");
    glUniform4fv = wglGetProcAddress("glUniform4fv");
    glUniform1iv = wglGetProcAddress("glUniform1iv");
    glUniform4dv = wglGetProcAddress("glUniform4dv");
    glGetShaderiv = wglGetProcAddress("glGetShaderiv");
    glGetShaderInfoLog = wglGetProcAddress("glGetShaderInfoLog");
    glGetProgramiv = wglGetProcAddress("glGetProgramiv");
    glGetProgramInfoLog = wglGetProcAddress("glGetProgramInfoLog");
    glDetachShader = wglGetProcAddress("glDetachShader");



    FreeImage_Initialise(FALSE);





    return 13;
}

