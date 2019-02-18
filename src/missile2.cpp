#define GLM_ENABLE_EXPERIMENTAL
#include "missile2.h"
#include "main.h"

Missile2::Missile2(float x, float y, float z, color_t color, double SPEED, float vx, float vy, float vz, double ya, double p) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->yaw = ya;
    this->pitch = p;
    this->v = glm::vec3(vx,vy,vz);
    speed = SPEED;
    gravity = 0.0;
    this->radius = 0.5;
    this->length = 1;
    speed = SPEED;
    gravity = 0.0;
    const int N = 360;
	float deg = 360 * 1.0f / N;
	float theta = 0.0f;
	float pi = 3.141;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[3 * 3 * 2 * N];
    GLfloat vertex_buffer_data2[3 * 3 * N];
    GLfloat vertex_buffer_data3[3 * 3 * N];

    for(int i = 0; i < N; ++i){
		vertex_buffer_data3[9 * i] = 0.0f;
		vertex_buffer_data3[9 * i + 1] = 0.0f;
		vertex_buffer_data3[9 * i + 2] = -this->length / 2;

		vertex_buffer_data3[9 * i + 3] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data3[9 * i + 4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data3[9 * i + 5] = -this->length / 2;

		theta += deg;
		vertex_buffer_data3[9 * i + 6] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data3[9 * i + 7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data3[9 * i + 8] = -this->length / 2;
    }
    for(int i = 0; i < N; ++i){
		vertex_buffer_data2[9 * i] = 0.0f;
		vertex_buffer_data2[9 * i + 1] = 0.0f;
		vertex_buffer_data2[9 * i + 2] = this->length / 2;

		vertex_buffer_data2[9 * i + 3] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data2[9 * i + 4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data2[9 * i + 5] = this->length / 2;

		theta += deg;
		vertex_buffer_data2[9 * i + 6] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data2[9 * i + 7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data2[9 * i + 8] = this->length / 2;
    }

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
    this->object3 = create3DObject(GL_TRIANGLES, 3 * N, vertex_buffer_data3, COLOR_YELLOW, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3 * N, vertex_buffer_data2, COLOR_YELLOW, GL_FILL); 
    this->object = create3DObject(GL_TRIANGLES, 2 * 3 * N, vertex_buffer_data, COLOR_RED, GL_FILL);
}

void Missile2::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->yaw * M_PI / 180.0f), glm::vec3(0, 1, 0)) * glm::rotate((float) (this->pitch * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Missile2::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Missile2::tick() {
    //this->rotation += speed;
    this->position.x += speed;
    this->position.y += gravity;
}

