#version 130
//The fragment shader operates on each pixel in a given polygon

in vec2 fragmentPosition;
in vec4 fragmentColor;

//This is the 3 component float vector that gets outputted to the screen
//for each pixel.
out vec4 color;

uniform float time;

void main() {

    //cos(x) returns a number between -1 and 1. To convert it into the range 0 to 1
    //you simply do (cos(x) + 1.0) * 0.5

    //Make crazy colors using time and position!
    color = vec4(fragmentColor.r * (tan(fragmentPosition.x * 0.250 + fragmentPosition.y * 0.250 + ( (cos(time*10)+1) * 0.5 ) + 3.0) * 0.25),
                 fragmentColor.g * (tan(fragmentPosition.x * 0.250 + fragmentPosition.y * 0.250 + ( (cos(time*2)+1) * 0.5 ) + 3.0) * 0.25),
                 fragmentColor.b * (tan(fragmentPosition.x * 0.250 + fragmentPosition.y * 0.250 + ( (cos(time*5)+1) * 0.5 ) + 3.0) * 0.25), 
                 fragmentColor.a );
}
