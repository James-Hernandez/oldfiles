uniform float scale;

void main(){
    vec4 a = gl_Vertex;         // a will get the vertices values from the CPU
    a.x = a.x * scale;
    a.y = a.y * scale;

    gl_Position = gl_ModelViewProjectionMatrix * a;

}
