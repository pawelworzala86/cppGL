#include <windows.h>
#include <gl/gl.h>

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "freeimage.h"



GLuint GL_VERTEX_SHADER		  = 35633;
GLuint GL_FRAGMENT_SHADER		  = 35632;

GLuint GL_COMPILE_STATUS		  = 35713;
GLuint GL_LINK_STATUS			  = 35650;
GLuint GL_INFO_LOG_LENGTH = 35716;


GLuint GL_ARRAY_BUFFER 		  = 34962;
GLuint GL_STATIC_DRAW			  = 35044;



typedef void (*GLUNIFORM1I) (int, GLuint);
typedef void (*GLBINDVERTEXARRAY) (GLuint);
typedef void (*GLGENBUFFERS) (int, GLuint*);
typedef GLuint (*GLCREATESHADER) (GLuint);
typedef GLuint (*GLCREATEPROGRAM) ();
typedef void (*GLSHADERSOURCE) (GLuint,int,void*,void*);
typedef void (*GLCOMPILESHADER) (GLuint);
typedef void (*GLATTACHSHADER) (GLuint,GLuint);
typedef void (*GLLINKPROGRAM) (GLuint);
typedef void (*GLUSEPROGRAM) (GLuint);
typedef GLuint (*GLGETUNIFORMLOCATION) (GLuint,char*);
typedef void (*GLUNIFORM4I) (GLuint,GLuint);
typedef void (*GLUNIFORM4F) (GLuint,GLfloat);
typedef void (*GLUNIFORM4D) (GLuint,GLdouble);
typedef void (*GLUNIFORM3DV) (GLuint,GLdouble*);
typedef void (*GLUNIFORM4FV) (GLuint,GLfloat*);
typedef void (*GLUNIFORM4DV) (GLuint,GLdouble*);
typedef void (*GLUNIFORMMATRIX4DV) (GLuint,GLuint,GLdouble*);
typedef void (*GLBINDBUFFER) (GLuint,GLuint);
typedef void (*GLBUFFERDATA) (GLuint,GLuint,void*,GLuint);
typedef void (*GLVERTEXATTRIBPOINTER) (GLuint,GLuint,GLuint,GLuint,GLuint,GLuint);
typedef void (*GLENABLEVERTEXATTRIBARRAY) (GLuint);
typedef void (*GLGETVERTEXARRAYS) (GLuint,GLuint*);
typedef void (*GLDELETESHADER) (GLuint);
typedef void (*GLDETACHSHADER) (GLuint,GLuint);

GLUNIFORM1I glUniform1i = NULL;
GLBINDVERTEXARRAY glBindVertexArray = NULL;
GLGENBUFFERS glGenBuffers = NULL;
GLCREATESHADER glCreateShader = NULL;
GLCREATEPROGRAM glCreateProgram = NULL;
GLSHADERSOURCE glShaderSource = NULL;
GLCOMPILESHADER glCompileShader = NULL;
GLATTACHSHADER glAttachShader = NULL;
GLLINKPROGRAM glLinkProgram = NULL;
GLUSEPROGRAM glUseProgram = NULL;
GLGETUNIFORMLOCATION glGetUniformLocation = NULL;
GLUNIFORM4F glUniform4f = NULL;
GLUNIFORM4D glUniform4d = NULL;
GLUNIFORM4D glUniform1d = NULL;
GLUNIFORM3DV glUniform3dv = NULL;
GLUNIFORM4FV glUniform4fv = NULL;
GLUNIFORM4DV glUniform4dv = NULL;
GLUNIFORMMATRIX4DV glUniformMatrix4dv = NULL;
GLBINDBUFFER glBindBuffer = NULL;
GLBUFFERDATA glBufferData = NULL;
GLVERTEXATTRIBPOINTER glVertexAttribPointer = NULL;
GLENABLEVERTEXATTRIBARRAY glEnableVertexAttribArray = NULL;
GLGETVERTEXARRAYS glGenVertexArrays = NULL;
GLDELETESHADER glDeleteShader = NULL;
GLDETACHSHADER glDetachShader = NULL;
//PROC glCreateFramebuffers = NULL;
//PROC glBindFramebuffer = NULL;
//PROC glFramebufferTexture2D = NULL;
//PROC glValidateProgram = NULL;
//PROC glActiveTexture = NULL;
//PROC glGenerateMipmap = NULL;
/*PROC glGetShaderiv = NULL;
PROC glGetShaderInfoLog = NULL;
PROC glGetProgramiv = NULL;
PROC glGetProgramInfoLog = NULL;
*/




















int InitGL(){

    /*GENBUFFERS glGenBuffers = (GENBUFFERS)wglGetProcAddress("glGenBuffers");
    GLuint buffer;
    glGenBuffers(1, &buffer);*/

    glUniform1i = (GLUNIFORM1I)wglGetProcAddress("glUniform1iv");
    glBindVertexArray = (GLBINDVERTEXARRAY)wglGetProcAddress("glBindVertexArray");
    glGenBuffers = (GLGENBUFFERS)wglGetProcAddress("glGenBuffers");
    glCreateShader = (GLCREATESHADER)wglGetProcAddress("glCreateShader");
    glCreateProgram = (GLCREATEPROGRAM)wglGetProcAddress("glCreateProgram");
    glShaderSource = (GLSHADERSOURCE)wglGetProcAddress("glShaderSource");
    glCompileShader = (GLCOMPILESHADER)wglGetProcAddress("glCompileShader");
    glAttachShader = (GLATTACHSHADER)wglGetProcAddress("glAttachShader");
    glLinkProgram = (GLLINKPROGRAM)wglGetProcAddress("glLinkProgram");
    glUseProgram = (GLUSEPROGRAM)wglGetProcAddress("glUseProgram");
    glGetUniformLocation = (GLGETUNIFORMLOCATION)wglGetProcAddress("glGetUniformLocation");
    glUniform4f = (GLUNIFORM4F)wglGetProcAddress("glUniform4f");
    glUniform4d = (GLUNIFORM4D)wglGetProcAddress("glUniform4d");
    glUniform1d = (GLUNIFORM4D)wglGetProcAddress("glUniform1d");
    glUniform3dv = (GLUNIFORM3DV)wglGetProcAddress("glUniform3dv");
    glUniformMatrix4dv = (GLUNIFORMMATRIX4DV)wglGetProcAddress("glUniformMatrix4dv");
    glBindBuffer = (GLBINDBUFFER)wglGetProcAddress("glBindBuffer");
    glBufferData = (GLBUFFERDATA)wglGetProcAddress("glBufferData");
    glVertexAttribPointer = (GLVERTEXATTRIBPOINTER)wglGetProcAddress("glVertexAttribPointer");
    glEnableVertexAttribArray = (GLENABLEVERTEXATTRIBARRAY)wglGetProcAddress("glEnableVertexAttribArray");
    glGenVertexArrays = (GLGETVERTEXARRAYS)wglGetProcAddress("glGenVertexArrays");
    glDeleteShader = (GLDELETESHADER)wglGetProcAddress("glDeleteShader");
    glDetachShader = (GLDETACHSHADER)wglGetProcAddress("glDetachShader");
    //glCreateFramebuffers = wglGetProcAddress("glCreateFramebuffers");
    //glBindFramebuffer = wglGetProcAddress("glBindFramebuffer");
    //glFramebufferTexture2D = wglGetProcAddress("glFramebufferTexture2D");

    //glValidateProgram = wglGetProcAddress("glValidateProgram");
    //glActiveTexture = wglGetProcAddress("glActiveTexture");
    //glGenerateMipmap = wglGetProcAddress("glGenerateMipmap");
    /*glGetShaderiv = wglGetProcAddress("glGetShaderiv");
    glGetShaderInfoLog = wglGetProcAddress("glGetShaderInfoLog");
    glGetProgramiv = wglGetProcAddress("glGetProgramiv");
    glGetProgramInfoLog = wglGetProcAddress("glGetProgramInfoLog");*/



    FreeImage_Initialise(FALSE);





    return 13;
}


