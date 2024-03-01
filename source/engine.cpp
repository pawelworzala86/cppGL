#include "init.cpp"
#include "texture.cpp"
#include "shader.cpp"


GLuint VAO;
GLuint bufferID;

double vertices[] = {1.0,1.0,0.0,1.0,-1.0,0.0,-1.0,-1.0,0.0,1.0,1.0,0.0,-1.0,-1.0,0.0,-1.0,1.0,0.0};
double vertices2[] = {1.0,1.0,0.0,1.0,-1.0,0.0,-1.0,-1.0,0.0,1.0,1.0,0.0,-1.0,-1.0,0.0,-1.0,1.0,0.0};
double coords[] = {1.0,1.0,1.0,0.0,0.0,0.0,1.0,1.0,0.0,0.0,0.0,1.0};

//char* texfileName = "girl.jpg";
int gl_texID = 0;
int gl_texFontID = 0;

GLuint programID;
GLuint programFontID;


float widthsFnt[] = {7.0,49.0,0.0,49.0,49.0,49.0,49.0,    
        49.0,49.0,16.0,16.0,16.0,16.0,16.0,    
        49.0,49.0,49.0,49.0,49.0,49.0,49.0,    
        49.0,49.0,49.0,49.0,49.0,49.0,49.0,    
        49.0,49.0,49.0,49.0,16.0,21.0,26.0,    
        32.0,32.0,53.0,49.0,11.0,21.0,21.0,    
        32.0,36.0,16.0,21.0,16.0,17.0,32.0,    
        32.0,32.0,32.0,32.0,32.0,32.0,32.0,    //;1234567
        32.0,32.0,17.0,17.0,36.0,36.0,36.0,    //;89
        28.0,58.0,42.0,42.0,42.0,42.0,39.0,    //;  ABCDE
        35.0,42.0,42.0, 21.0,24.0,42.0,39.0,    //;FGH IJKL
        56.0,42.0,42.0,35.0,42.0,42.0,35.0,    //;MNOPQRS
        39.0,42.0,42.0, 55.0,42.0,42.0,39.0,    //;TUV WXYZ
        21.0,17.0,21.0,30.0,32.0,21.0,28.0,    //;      a
        32.0,28.0,32.0,32.0,21.0,32.0,32.0,    //;bcdefgh
        17.0,17.0,32.0,15.0,49.0,32.0,35.0,    //;ijklmno
        32.0,32.0,21.0,24.0,17.0,32.0,32.0,    //;pqrstuv
        46.0,32.0,32.0,28.0,30.0,12.0,30.0,    //;wxyz   
        34.0,32.0,49.0,49.0,49.0,49.0,49.0,     
        49.0,49.0,49.0,49.0,49.0,49.0,49.0,     
        49.0,49.0,49.0,49.0,49.0,49.0,49.0,     
        49.0,49.0,49.0,49.0,49.0,49.0,49.0,     
        49.0,49.0,49.0,49.0,49.0,49.0,16.0,     
        21.0,32.0,32.0,32.0,32.0,12.0,32.0,     
        21.0,48.0,17.0,32.0,36.0,0.0,48.0,     
        32.0,25.0,35.0,19.0,19.0,21.0,36.0,     
        29.0,21.0,21.0,19.0,19.0,32.0,48.0,    
        48.0,48.0,28.0,46.0,46.0,46.0,46.0,    //;   ÀÁÂÃ
        46.0,46.0,56.0,42.0,39.0,39.0,39.0,    //;ÄÅÆÇÈÉÊ
        39.0,21.0,21.0,21.0,21.0,46.0,46.0,    //;ËÌÍÎÏÐÑ
        46.0,46.0,46.0,46.0,46.0,36.0,46.0,    //;ÒÓÔÕÖ  
        46.0,46.0,46.0,46.0,46.0,35.0,32.0,     
        28.0,28.0,28.0,28.0,28.0,28.0,42.0,     
        28.0,28.0,28.0,28.0,28.0,17.0,17.0,     
        17.0,17.0,32.0,32.0,32.0,32.0,32.0,     
        32.0,32.0,35.0,32.0,32.0,32.0,32.0,     
        32.0,32.0,32.0,32.0};



class CMesh
{
    private:
        GLuint VAO;
        GLuint bufferID;
    public:
        CMesh();
        ~CMesh();
        void Init(void* vertices,void* coords);
        void CreateBuffer(int posID,int size,int length,void* array);
        void Render();
};
CMesh::CMesh(){
};
CMesh::~CMesh(){
};
void CMesh::Init(void* vertices,void* coords){
    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);

    this->CreateBuffer(0,3,18,vertices);
    this->CreateBuffer(1,2,12,coords);

    glBindVertexArray(NULL);
};
void CMesh::CreateBuffer(int posID,int size,int length,void* array){

    glGenBuffers(1,&this->bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, this->bufferID);
    glBufferData(GL_ARRAY_BUFFER, length*8, array,GL_STATIC_DRAW);

    glEnableVertexAttribArray(posID);
    glVertexAttribPointer(posID,size,GL_DOUBLE,GL_FALSE, size*8, 0);

};
void CMesh::Render(){
    glBindVertexArray(this->VAO);

        /*//glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, gl_texID);
        GLuint uniformLocation = glGetUniformLocation(programID, "diffuseTexture");
        //printf("%i",uniformLocation);
        glUniform1i(uniformLocation, 0);*/

        //glActiveTexture(gl.TEXTURE0);
        ///glBindTexture(gl.TEXTURE_2D, textureID1)
        //MacroSetUniform1i(programID, 'diffuseTexture', 0)


        //MacroSetUniformMatrix(programID, 'projection', projection)
        //MacroSetUniformMatrix(programID, 'camera', camera)
        //MacroSetUniformMatrix(programID, 'model', model)

    
        //gl.BindBuffer,gl.ELEMENT_ARRAY_BUFFER, *indID
    
        glDrawArrays(GL_TRIANGLES, 0, 6);
}






void CreateBuffer(int posID,int size,int length,void* array){

    glGenBuffers(1,&bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, length*8, array,GL_STATIC_DRAW);

    glEnableVertexAttribArray(posID);
    glVertexAttribPointer(posID,size,GL_DOUBLE,GL_FALSE, size*8, 0);

}


CMesh mesh;
CMesh meshTex;


void CreateEngine(){

    
    

    programID = CreateShader("default.vert","default.frag");
 

    mesh.Init(&vertices,&coords);


    programFontID = CreateShader("font.vert","font.frag");



    

    for(int i=0;i<sizeof(vertices2)/8;i++){
        vertices2[i] = vertices2[i] / 10.0;
    }
    /*for(int i=0;i<sizeof(vertices2)/8;i+=3){
        vertices2[i] = vertices2[i] * sizeX;
    }*/

    meshTex.Init(&vertices2,&coords);




    //glGenVertexArrays(1, &VAO);
    //glBindVertexArray(VAO);


    //CreateBuffer(0,3,18,&vertices);

    /*glGenBuffers(1,&bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, 18*8, &vertices,GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_DOUBLE,GL_FALSE, 3*8, 0);*/

    //CreateBuffer(1,2,12,&coords);

    /*glGenBuffers(1,&bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, 12*8, &coords,GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,2,GL_DOUBLE,GL_FALSE, 2*8, 0);*/








    


    gl_texID = LoadTexture("girl.jpg");

    gl_texFontID = LoadTexture("font.png");

}


char* helloWorld = "Hello World";

void RenderGL(){

    glClearColor(0.2f, 0.4f, 0.6f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(programID);

        //glBindVertexArray(VAO);

        //glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, gl_texID);
        GLuint uniformLocation = glGetUniformLocation(programID, "diffuseTexture");
        //printf("%i",uniformLocation);
        glUniform1i(uniformLocation, 0);


        mesh.Render();


glUseProgram(programFontID);

        //glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, gl_texFontID);
        uniformLocation = glGetUniformLocation(programFontID, "diffuseTexture");
        //printf("%i",uniformLocation);
        glUniform1i(uniformLocation, 0);



        
        float offsetX = 0.0;

        for(int i=0;i<strlen(helloWorld);i++){
            int letter = helloWorld[i];
            //printf("%i",letter);
        //}
        uniformLocation = glGetUniformLocation(programFontID, "fontIndex");
        //printf("%i",uniformLocation);
        glUniform1i(uniformLocation, letter);

        float sizeX = (widthsFnt[letter] / 64.0)*0.2;
        uniformLocation = glGetUniformLocation(programFontID, "offsetX");
        glUniform1f(uniformLocation, offsetX);
        offsetX += sizeX;

        meshTex.Render();

        }

        /*sizeX = (widthsFnt[65] / 64.0)*0.2;
        uniformLocation = glGetUniformLocation(programFontID, "offsetX");
        glUniform1f(uniformLocation, offsetX);
        offsetX += sizeX;

        meshTex.Render();*/


}
