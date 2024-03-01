#version 440 core




uniform sampler2D diffuseTexture;


in vec2 vCoord;

uniform int fontIndex;

out vec4 color;

void main()
{
	//vec2 coord = vCoord/16.0;

	float distance = 1.0/16.0;
    float X = 0.0;
    float Y = 0.0;

    int index = 0;
    for(int y=1;y<=16;y++){
        for(int x=1;x<=16;x++){
            index+=1;
            if(index==fontIndex){
                X = float(x)*distance;
                Y = float(y)*distance;
            }
        }
    }


    vec2 coord = vCoord/16.0;

    //coord.x *= float(44.0)/64.0;

    coord += vec2(X,1.0026-Y);

	vec3 diffuse = vec3(texture(diffuseTexture, coord).rgb);
	
	color = vec4(diffuse,1.0);

}