#define GLM_ENABLE_EXPERIMENTAL
#include "airspeed.h"
#include "global.h"
#include "main.h"

Airspeed::Airspeed(float x, float y, float z, color_t color, double SPEED) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = SPEED;
    gravity = 0.0;
    this->radius = 0.4;
    const int N = 360;
	float deg = 360 * 1.0f / N;
	float theta = 0.0f;
	float pi = 3.141;
	static GLfloat vertex_buffer_data[3 * 3 * N];
	for(int i = 0; i < N; ++i){
		vertex_buffer_data[9 * i] = 0.0f;
		vertex_buffer_data[9 * i + 1] = 0.0f;
		vertex_buffer_data[9 * i + 2] = 0.0f;

		vertex_buffer_data[9 * i + 3] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 5] = 0.0f;

		theta += deg;
		vertex_buffer_data[9 * i + 6] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 8] = 0.0f;
    }
    GLfloat vertex_buffer_data2[] = {
        0.0f, 0.0f, 0.0f,
        -0.3f, 0.0f, 0.0f,
        -0.3f, 0.1f, 0.0f,
        -0.3f, 0.1f, 0.0f,
        0.0f, 0.1f, 0.0f,
        0.0f, 0.0f, 0.0f
    };
    this->object = create3DObject(GL_TRIANGLES, N*3, vertex_buffer_data, COLOR_WHITE, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 3*2, vertex_buffer_data2, COLOR_VIOLET, GL_FILL);
}

void Airspeed::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);

    float rot = knots * 360;
    Matrices.model = glm::mat4(1.0f);
    translate = glm::translate (this->position);    // glTranslatef
    rotate = glm::rotate((float) (-rot * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}

void Airspeed::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Airspeed::tick() {
    //this->rotation += speed;
    this->position.x += speed;
    this->position.y += gravity;
}

