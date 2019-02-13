#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL
#ifndef MODELS_H
#define MODELS_H


class Models {
public:
    Models() {}
    Models(float x, float y, color_t color, double SPEED);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< glm::vec3 > temp_vertices;
    std::vector< glm::vec2 > temp_uvs;
    std::vector< glm::vec3 > temp_normals;
    std::vector< glm::vec3 > out_vertices;
    std::vector< glm::vec2 > out_uvs;
    std::vector< glm::vec3 > out_normals;
    double speed;
    double gravity;
private:
    VAO *object;
};

#endif // BALL_H
