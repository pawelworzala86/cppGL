#include "init.cpp"
#include "texture.cpp"
#include "shader.cpp"


void* VAO = NULL;
int* bufferID = NULL;

double vertices[] = {1.0,1.0,0.0,1.0,-1.0,0.0,-1.0,-1.0,0.0,1.0,1.0,0.0,-1.0,-1.0,0.0,-1.0,1.0,0.0};
double coords[] = {1.0,1.0,1.0,0.0,0.0,0.0,1.0,1.0,0.0,0.0,0.0,1.0};

//char* texfileName = "girl.jpg";
int gl_texID = 0;

GLuint programID;














void CreateBuffer(int posID,int size,int length,void* array){

    glGenBuffers(1,&bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, length*8, array,GL_STATIC_DRAW);

    glEnableVertexAttribArray(posID);
    glVertexAttribPointer(posID,size,GL_DOUBLE,GL_FALSE, size*8, 0);

}



void CreateEngine(){

    
    

    programID = CreateShader("default.vert","default.frag");
 







    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    CreateBuffer(0,3,18,&vertices);

    /*glGenBuffers(1,&bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, 18*8, &vertices,GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_DOUBLE,GL_FALSE, 3*8, 0);*/

    CreateBuffer(1,2,12,&coords);

    /*glGenBuffers(1,&bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, 12*8, &coords,GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,2,GL_DOUBLE,GL_FALSE, 2*8, 0);*/








    


    gl_texID = LoadTexture("girl.jpg");

}

void RenderGL(){

    glClearColor(0.2f, 0.4f, 0.6f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //gl.UseProgram(programID)

        glBindVertexArray(VAO);

        //glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, gl_texID);
        int uniformLocation = glGetUniformLocation(programID, "diffuseTexture");
        //printf("%i",uniformLocation);
        glUniform1i(uniformLocation, 0);

        //glActiveTexture(gl.TEXTURE0);
        ///glBindTexture(gl.TEXTURE_2D, textureID1)
        //MacroSetUniform1i(programID, 'diffuseTexture', 0)


        //MacroSetUniformMatrix(programID, 'projection', projection)
        //MacroSetUniformMatrix(programID, 'camera', camera)
        //MacroSetUniformMatrix(programID, 'model', model)

    
        //gl.BindBuffer,gl.ELEMENT_ARRAY_BUFFER, *indID
    
        glDrawArrays(GL_TRIANGLES, 0, 6);
    
        //glDrawElements(gl.TRIANGLES, 3*2, gl.UNSIGNED_SHORT,0)


}


