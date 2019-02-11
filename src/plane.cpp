#define GLM_ENABLE_EXPERIMENTAL
#include "plane.h"
#include "main.h"
using namespace std;

Plane::Plane(float r, float l, color_t color, double SPEED) {
    this->position = glm::vec3(0, 5, 0);
	this->coords[0] = glm::vec3(1, 0, 0);
	this->coords[1] = glm::vec3(0, 1, 0);
	this->coords[2] = glm::vec3(0, 0, 1);
	for(int i = 0; i < 4; ++i)
	{	
		for(int j = 0; j < 4; ++j)
		{
			if(i == j)
				this->ROT[i][j] = 1;
			else
				this->ROT[i][j] = 0;
		}
	}
	for(int i = 0; i < 3; ++i)
		this->rot[i] = 0;
	this->axis = 0;
    this->rotation = 0;
    this->radius = r;
    this->length = l;
    speed = SPEED;
    gravity = 0.0;
    const int N = 360;
	float deg = 360 * 1.0f / N;
	float theta = 0.0f;
	float pi = 3.141;
	static GLfloat vertex_buffer_data[3 * 3 * N];
    static GLfloat vertex_buffer_data2[3 * 3 * N];
    static GLfloat vertex_buffer_data3[N * 3 * 3 * 2];
	static GLfloat vertex_buffer_data4[] = {
		-0.05f, this->radius, this->length / 2,
		-0.05f, 4 * this->radius, this->length / 2,
		-0.05f, this->radius, this->length / 2 - 1,

		0.05f, this->radius, this->length / 2,
		0.05f, 4 * this->radius, this->length / 2,
		0.05f, this->radius, this->length / 2 - 1,

		-0.05f, this->radius, this->length / 2,
		0.05f, this->radius, this->length / 2,
		0.05f, 4 * this->radius, this->length / 2,

		0.05f, 4 * this->radius, this->length / 2,
		-0.05f, 4 * this->radius, this->length / 2,
		-0.05f, this->radius, this->length / 2,

		-0.05f, 4 * this->radius, this->length / 2,
		0.05f, 4 * this->radius, this->length / 2,
		0.05f, this->radius, this->length / 2 - 1,

		0.05f, this->radius, this->length / 2 - 1,
		-0.05f, this->radius, this->length / 2 - 1,
		-0.05f, 4 * this->radius, this->length / 2
	};
	static GLfloat vertex_buffer_data5[] = {
		this->radius, 0, this->length/2 - 2,
		this->radius, 0, this->length/2 - 4,
		5 * this->radius, 0, this->length/2 - 2,

		-this->radius, 0, this->length/2 - 2,
		-this->radius, 0, this->length/2 - 4,
		-5 * this->radius, 0, this->length/2 - 2,
	};
	for(int i = 0; i < N; ++i){
		vertex_buffer_data[9 * i] = 0.0f;
		vertex_buffer_data[9 * i + 1] = 0.0f;
		vertex_buffer_data[9 * i + 2] = -this->length / 2;

		vertex_buffer_data[9 * i + 3] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 5] = -this->length / 2;

		theta += deg;
		vertex_buffer_data[9 * i + 6] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data[9 * i + 8] = -this->length / 2;
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
		vertex_buffer_data3[18 * i] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 1] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 2] = this->length / 2;

		theta += deg;
		vertex_buffer_data3[18 * i + 3] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 4] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 5] = this->length / 2;
        
        vertex_buffer_data3[18 * i + 6] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 7] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 8] = -this->length / 2;

        vertex_buffer_data3[18 * i + 9] = this->radius * 1.0f * cos(theta * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 10] = this->radius * 1.0f * sin(theta * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 11] = -this->length / 2;

        vertex_buffer_data3[18 * i + 12] = this->radius * 1.0f * cos((theta-deg) * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 13] = this->radius * 1.0f * sin((theta-deg) * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 14] = -this->length / 2;

        vertex_buffer_data3[18 * i + 15] = this->radius * 1.0f * cos((theta-deg) * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 16] = this->radius * 1.0f * sin((theta-deg) * pi * 1.0f / 180);
		vertex_buffer_data3[18 * i + 17] = this->length / 2;
    }
    this->object = create3DObject(GL_TRIANGLES, 3 * N, vertex_buffer_data, COLOR_GREEN, GL_FILL);
    this->object2 =  create3DObject(GL_TRIANGLES, 3 * N, vertex_buffer_data2, COLOR_GREEN, GL_FILL);
    this->object3 =  create3DObject(GL_TRIANGLES, 3 * 2 * N, vertex_buffer_data3, COLOR_RED, GL_FILL);
	this->object4 = create3DObject(GL_TRIANGLES, 3 * 6, vertex_buffer_data4, COLOR_STEEL_GRAY, GL_FILL);
	this->object5 = create3DObject(GL_TRIANGLES, 3 * 2, vertex_buffer_data5, COLOR_STEEL_GRAY, GL_FILL);
}

void Plane::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate;
	//if(this->rot[this->axis] != 0)
	rotate  = glm::rotate((float) (this->rot[1] * M_PI / 180.0f), glm::vec3(0, 1, 0)) * glm::rotate((float) (this->rot[0] * M_PI / 180.0f), glm::vec3(1, 0, 0)) * glm::rotate((float) (this->rot[2] * M_PI / 180.0f), this->coords[2] = glm::vec3(0, 0, 1));
	// No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
	Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
	draw3DObject(this->object4);
	draw3DObject(this->object5);
	//cout << rotate[0][2] << " " << rotate[1][2] << " " << rotate[2][2]<<endl;
	for(int i = 0; i < 3; ++i)
		this->coords[i] = glm::vec3(rotate[0][i], rotate[1][i], rotate[2][i]);
}

void Plane::set_position(float x, float y) {
    //this->position = glm::vec3(x, y, 0);
}

void Plane::tick() {
	for(int i = 0; i < 3; ++i){
		if(this->rot[i] > 360)
			this->rot[i] -= 360;
	}
}

