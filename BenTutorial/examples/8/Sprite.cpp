#include "Sprite.h"


Sprite::Sprite()
{
    //Always initialize your buffer IDs to 0
    _vboID = 0;
}


Sprite::~Sprite()
{
    //Always remember to delete your buffers when
    //you are done!
    if (_vboID != 0) {
        glDeleteBuffers(1, &_vboID);
    }
}

//Initializes the sprite VBO. x, y, width, and height are
//in the normalized device coordinate space. so, [-1, 1]
void Sprite::init(float x, float y, float width, float height) {
    //Set up our private vars
    _x = x;
    _y = y;
    _width = width;
    _height = height;

    //Generate the buffer if it hasn't already been generated
    if (_vboID == 0) {
        glGenBuffers(1, &_vboID);
    }

    //This array will hold our vertex data.
    //We need 6 vertices, and each vertex has 2
    //floats for X and Y
    float vertexData[12];

    //First Triangle
    vertexData[0] = x + width;
    vertexData[1] = y + height;

    vertexData[2] = x;
    vertexData[3] = y + height;

    vertexData[4] = x;
    vertexData[5] = y;

    //Second Triangle
    vertexData[6] = x;
    vertexData[7] = y;

    vertexData[8] = x + width;
    vertexData[9] = y;

    vertexData[10] = x + width;
    vertexData[11] = y + height;

    //Tell opengl to bind our vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    //Upload the data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    //Unbind the buffer (optional)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//Draws the sprite to the screen
void Sprite::draw() {

    //bind the buffer object
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);

    //Tell opengl that we want to use the first
    //attribute array. We only need one array right
    //now since we are only using position.
    glEnableVertexAttribArray(0);

    //Point opengl to the data in our VBO. We will learn
    //more on this later
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

    //Draw the 6 vertices to the screen
    glDrawArrays(GL_TRIANGLES, 0, 6);

    //Disable the vertex attrib array. This is not optional.
    glDisableVertexAttribArray(0);

    //Unbind the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}