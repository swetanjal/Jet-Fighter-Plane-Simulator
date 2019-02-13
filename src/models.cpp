#define GLM_ENABLE_EXPERIMENTAL
#include "models.h"
#include "main.h"
#include "string.h"
using namespace std;
Models::Models(float x, float y, color_t color, double SPEED) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = SPEED;
    gravity = 0.0;

    FILE * file = fopen("/home/tapas/Desktop/sphere.obj", "r");
    if( file == NULL ){
        printf("Impossible to open the file !\n");
    }
    while( 1 ){
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // else : parse lineHeader

        if ( strcmp( lineHeader, "v" ) == 0 ){
            glm::vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            this->temp_vertices.push_back(vertex);
        }
        else if ( strcmp( lineHeader, "vt" ) == 0 ){
            glm::vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y );
            this->temp_uvs.push_back(uv);
        }
        else if ( strcmp( lineHeader, "vn" ) == 0 ){
            glm::vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
            this->temp_normals.push_back(normal);
        }
        else if ( strcmp( lineHeader, "f" ) == 0 ){
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            if (matches != 9){
                printf("File can't be read by our simple parser : ( Try exporting with other options\n");
                printf("%d\n", matches);
            }
            this->vertexIndices.push_back(vertexIndex[0]);
            this->vertexIndices.push_back(vertexIndex[1]);
            this->vertexIndices.push_back(vertexIndex[2]);
            this->uvIndices    .push_back(uvIndex[0]);
            this->uvIndices    .push_back(uvIndex[1]);
            this->uvIndices    .push_back(uvIndex[2]);
            this->normalIndices.push_back(normalIndex[0]);
            this->normalIndices.push_back(normalIndex[1]);
            this->normalIndices.push_back(normalIndex[2]);
        }
    }
    for( unsigned int i=0; i<this->vertexIndices.size(); i++ ){
        unsigned int vertexIndex = this->vertexIndices[i];
        glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
        this->out_vertices.push_back(vertex);
    }
    for( unsigned int i=0; i<this->uvIndices.size(); i++ ){
        unsigned int uvIndex = this->uvIndices[i];
        glm::vec2 uv = this->temp_uvs[ uvIndex-1 ];
        this->out_uvs.push_back(uv);
    }
    for( unsigned int i=0; i<this->normalIndices.size(); i++ ){
        unsigned int normalIndex = this->normalIndices[i];
        glm::vec3 normal = temp_vertices[ normalIndex-1 ];
        this->out_normals.push_back(normal);
    }
    GLfloat vertex_buffer_data[3 * this->out_vertices.size()];
    int c = 0;
    for(int i = 0; i < this->out_vertices.size(); ++i){
        for(int j = 0; j < 3; ++j)
            vertex_buffer_data[c++] = this->out_vertices[i][j];
    }
    this->object = create3DObject(GL_TRIANGLES, this->out_vertices.size(), vertex_buffer_data, color, GL_FILL);
}

void Models::draw(glm::mat4 VP) {
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

void Models::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Models::tick() {
    //this->rotation += speed;
    this->position.x += speed;
    this->position.y += gravity;
}

