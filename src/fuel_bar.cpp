#define GLM_ENABLE_EXPERIMENTAL
#include "fuel_bar.h"
#include "main.h"
#include "global.h"
using namespace std;
Fuel_Bar::Fuel_Bar(float x, float y, float z, color_t color, double SPEED) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = SPEED;
    gravity = 0.0;
    float length = 0.4;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -length *1.0f,-length *1.0f,0.0f, // triangle 1 : begin
        -length *1.0f, length *1.0f, 0.0f,
        length *1.0f, length *1.0f, 0.0f, // triangle 1 : end
        length *1.0f, length *1.0f, 0.0f, // triangle 2 : begin
        length *1.0f,-length *1.0f,0.0f,
        -length *1.0f, -length *1.0f, 0.0f, // triangle 2 : end
    };

    this->object = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, COLOR_WHITE, GL_FILL);
}

void Fuel_Bar::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    float length = 0.4;
    float br = F * 1.0f * length/ 200;
    cout << br << endl;
    GLfloat vertex_buffer_data[] = {
        -length * 1.0f, -length * 1.0f + (float)(br * 2.0f), 0.0f, // triangle 1 : begin
        length * 1.0f, -length * 1.0f + (float)(br * 2.0f), 0.0f,
        length * 1.0f, -length * 1.0f, 0.0f, // triangle 1 : end
        length * 1.0f, -length * 1.0f, 0.0f, // triangle 2 : begin
        -length * 1.0f, -length * 1.0f,0.0f,
        -length * 1.0f, -length * 1.0f + (float)(br * 2.0f), 0.0f, // triangle 2 : end
    };
    this->object1 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data, COLOR_VIOLET, GL_FILL);
    draw3DObject(this->object1);
}

void Fuel_Bar::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Fuel_Bar::tick() {
    //this->rotation += speed;
    this->position.x += speed;
    this->position.y += gravity;
}

