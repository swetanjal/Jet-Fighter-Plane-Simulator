#include "main.h"
#include "timer.h"
#include "sea.h"
#include "plane.h"
#include "enemy.h"
#include "models.h"
#include "missile1.h"
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int camera = 2;
int pressed;
int camera_x, camera_y, camera_z;
Timer t60(1.0 / 60);

/* Render the scene with openGL */
Sea sea;
Models cube;
Plane plane;
vector <Enemy> enemies;
vector <Missile1> missile1;
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    //glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    glm::vec3 eye, target, up;
    if(camera == 0){
        if(pressed == 1){
            camera_x = plane.position.x + (-1 * (rand() % 2)) * rand() % 4;
            camera_y = plane.position.y + 10 + (-1 * (rand() % 2)) * rand() % 4;
            camera_z = plane.position.z + 15 + (-1 * (rand() % 2)) * rand() % 4;
            pressed = 0;
        }
        glm::vec3 eye (camera_x, camera_y, camera_z);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (plane.position.x, plane.position.y, plane.position.z);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);
    }
    if(camera == 1){
        glm::vec3 z = glm::vec3(-plane.zcoord[0], -plane.zcoord[1], -plane.zcoord[2]);
        glm::vec3 x = glm::vec3(plane.xcoord[0], plane.xcoord[1], plane.xcoord[2]);
        glm::vec3 y = glm::vec3(plane.ycoord[0], plane.ycoord[1], plane.ycoord[2]);
        glm::vec3 eye  = glm::vec3(plane.position.x + (3 * z[0]), plane.position.y + 3 * z[1], plane.position.z + 3 * z[2]);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target  = glm::vec3(eye[0] + 2 * z[0], eye[1] + 2*z[1], eye[2]+2*z[2]); //(plane.position.x + 10 * plane.coords[2][0], plane.position.y + 10 * plane.coords[2][1], plane.position.z -10 * plane.coords[2][2]);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (y[0], y[1], y[2]);
    }
    if(camera == 2){
        glm::vec3 eye (plane.position.x, plane.position.y + 20, plane.position.z + 5);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (plane.position.x, plane.position.y, plane.position.z);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::mat4 rotate = glm::rotate((float) (plane.rot[1] * M_PI / 180.0f), glm::vec3(0, 1, 0));
        glm::vec3 up (0, 0, -1);
    }
    if(camera == 3){
        glm::mat4 rotate = glm::rotate((float) (plane.rot[1] * M_PI / 180.0f), glm::vec3(0, 1, 0));
        glm::vec3 eye (plane.position.x + 10 * rotate[2][0], plane.position.y + 15, plane.position.z + 15 * rotate[2][2]);
        //glm::vec3 eye (plane.position.x - 10 * plane.coords[2][0], plane.position.y + 15, plane.position.z + 15 );//* plane.coords[2][2]);
        // Target - Where is the camera looking at.  Don't change unless you are sure!!
        glm::vec3 target (plane.position.x, plane.position.y, plane.position.z);
        // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
        glm::vec3 up (0, 1, 0);
    }
    if(camera == 4){

    }
    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model
    // Scene render
    //cube.draw(VP);
    sea.draw(VP);
    plane.draw(VP);
    for(int i = 0; i < enemies.size(); ++i)
        enemies[i].draw(VP);
    for(int i = 0; i < missile1.size(); ++i)
        missile1[i].draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    //int s = glfwGetKey(window, GLFW_KEY_S);
    int w = glfwGetKey(window, GLFW_KEY_W);
    int q = glfwGetKey(window, GLFW_KEY_Q);
    int e = glfwGetKey(window, GLFW_KEY_E);
    int k = glfwGetKey(window, GLFW_KEY_K);
    int m = glfwGetKey(window, GLFW_KEY_M);
    int spc = glfwGetKey(window, GLFW_KEY_SPACE);
    if(k){
        plane.axis = 0;
        plane.rot[plane.axis] += 1;
    }
    if(m){
        plane.axis = 0;
        plane.rot[plane.axis] -= 1;
    }
    if (left) {
        // Do something
    }
    if(up){
        plane.position.y += 0.1;
        //plane.rot[0] += 1;
    }
    if(down){
        plane.position.y -= 0.1;
        //plane.rot[0] -= 1;
    }
    if(w){
        plane.position.x += (-0.1 * plane.zcoord[0]);
        plane.position.z += (-0.1 * plane.zcoord[2]);
    }
    if(q){
        plane.axis = 1;
        plane.rot[plane.axis] += 1;
    }
    if(e){
        plane.axis = 1;
        plane.rot[plane.axis] += (-1);
    }
    if(left){
        plane.axis = 2;
        plane.rot[plane.axis] += 1;
    }
    if(right){
        plane.axis = 2;
        plane.rot[plane.axis] += (-1);
    }
    if(spc){
        glm::vec3 z = glm::vec3(-plane.zcoord[0], -plane.zcoord[1], -plane.zcoord[2]);
        missile1.push_back(Missile1(plane.position.x, plane.position.y, plane.position.z, COLOR_BLACK, 1, z[0], z[1], z[2]));
    }
}

void tick_elements() {
    for(int i = 0; i < missile1.size(); ++i)
    {
        
        missile1[i].set_position(missile1[i].position.x + missile1[i].v.x, missile1[i].position.y + missile1[i].v.y, missile1[i].position.z + missile1[i].v.z);
    }
    plane.tick();
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    //cube = Models(0, 0, COLOR_BLACK, 1);
    sea = Sea(0, 0, COLOR_SEA_BLUE, 1);
    plane = Plane(1, 5, COLOR_RED, 1);
    enemies.push_back(Enemy(6, 0, -10, COLOR_BLACK, 0));
    enemies.push_back(Enemy(12, 0, 0, COLOR_BLACK, 0));
    enemies.push_back(Enemy(6, 0, 10, COLOR_BLACK, 0));
    enemies.push_back(Enemy(-12, 0, 0, COLOR_BLACK, 0));
    
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}
int window_width;
int window_height;
int main(int argc, char **argv) {
    srand(time(0));
    window_width  = 800;
    window_height = 800;

    window = initGLFW(window_width, window_height);

    initGL (window, window_width, window_height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    GLfloat fov = M_PI / 2;
    Matrices.projection = glm::perspective(fov, (GLfloat) window_width / (GLfloat) window_height, 0.1f, 500.0f);
    //Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
