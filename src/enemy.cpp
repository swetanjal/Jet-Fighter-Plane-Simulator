#define GLM_ENABLE_EXPERIMENTAL
#include "enemy.h"
#include "main.h"

Enemy::Enemy(float x, float y, float z, color_t color, double SPEED) {
    float length = 1.0f;
    float breadth = 1.0f;
    float depth = 6.0f;
    this->position = glm::vec3(x, y + breadth / 2, z);
    this->rotation = 0;
    speed = SPEED;
    gravity = 0.0;
    
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -length *1.0f / 2, breadth *1.0f/ 2, depth / 2, //1
        -length *1.0f/ 2, -breadth *1.0f/ 2, depth / 2,//2
        length *1.0f/ 2, -breadth *1.0f/ 2, depth / 2, //3
        
        length *1.0f/ 2, -breadth *1.0f/ 2, depth / 2,
        length *1.0f/ 2, breadth *1.0f/ 2, depth / 2, //4
        -length *1.0f/ 2, breadth *1.0f/ 2, depth / 2,

        -length *1.0f/ 2, breadth *1.0f/ 2, -depth / 2,//5
        -length *1.0f/ 2, -breadth *1.0f/ 2, -depth / 2,//6
        length *1.0f/ 2, -breadth *1.0f/ 2, -depth / 2,//7
        
        length *1.0f/ 2, -breadth *1.0f/ 2, -depth / 2,
        length *1.0f/ 2, breadth *1.0f/ 2, -depth / 2,//8
        -length *1.0f/ 2, breadth *1.0f/ 2, -depth / 2,

        -length *1.0f/ 2, breadth *1.0f/ 2, depth / 2,
        -length *1.0f/ 2, breadth *1.0f/ 2, -depth / 2,//5
        length / 2, breadth / 2, -depth / 2,//8

        length / 2, breadth / 2, -depth / 2,//8
        length / 2, breadth / 2, depth / 2, //4
        -length / 2, breadth / 2, depth / 2, //1

        -length / 2, breadth / 2, depth / 2, //1
        -length *1.0f/ 2, breadth *1.0f/ 2, -depth / 2,//5
        -length / 2, -breadth / 2, -depth / 2,//6

        -length / 2, -breadth / 2, -depth / 2,//6
        -length / 2, breadth / 2, depth / 2, //1
        -length / 2, -breadth / 2, depth / 2,//2

        length / 2, breadth / 2, depth / 2, //4
        length / 2, -breadth / 2, -depth / 2,//7
        length / 2, breadth / 2, -depth / 2,//8

        length / 2, -breadth / 2, depth / 2, //3
        length / 2, -breadth / 2, -depth / 2,//7
        length / 2, breadth / 2, depth / 2, //4
    };

    this->object = create3DObject(GL_TRIANGLES, 10*3, vertex_buffer_data, color, GL_FILL);
}

void Enemy::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Enemy::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Enemy::tick() {
    
}

