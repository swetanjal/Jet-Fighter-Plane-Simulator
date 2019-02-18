#define GLM_ENABLE_EXPERIMENTAL
#include "ring.h"
#include "main.h"

Ring::Ring(float x, float y, float z, color_t color, double SPEED) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = SPEED;
    gravity = 0.0;
    this->radius = 2;
    this->length = 0.4;
    const int N = 360;
	float deg = 360 * 1.0f / N;
	float theta = 0.0f;
	float pi = 3.141;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[3 * 2 * N * 3];
    for(int i = 0; i < N; ++i){
		vertex_buffer_data[18 * i] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 1] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 2] = this->length / 2;

		theta += deg;
		vertex_buffer_data[18 * i + 3] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 5] = this->length / 2;
        
        vertex_buffer_data[18 * i + 6] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 8] = -this->length / 2;

        vertex_buffer_data[18 * i + 9] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 10] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 11] = -this->length / 2;

        vertex_buffer_data[18 * i + 12] = this->radius * 1.0f * cos((theta-deg) * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 13] = this->radius * 1.0f * sin((theta-deg) * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 14] = -this->length / 2;

        vertex_buffer_data[18 * i + 15] = this->radius * 1.0f * cos((theta-deg) * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 16] = this->radius * 1.0f * sin((theta-deg) * pi * 1.0f / 180);
		vertex_buffer_data[18 * i + 17] = this->length / 2;
    }

    this->object = create3DObject(GL_TRIANGLES, 3 * 2 * N, vertex_buffer_data, COLOR_YELLOW, GL_FILL);
}

void Ring::draw(glm::mat4 VP) {
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

void Ring::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ring::tick() {
    //this->rotation += speed;
    this->position.x += speed;
    this->position.y += gravity;
}

