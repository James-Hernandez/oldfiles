uniform float Scale;
varying vec2 vTexCoord;


void main(void)
{
vec4 a = gl_Vertex;

vTexCoord = vec2(gl_MultiTexCoord0);

a.x = a.x * Scale; // Scale x
a.y = a.y * Scale; // Scale y


gl_Position = gl_ModelViewProjectionMatrix * a; // same as 
}


