
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <time.h>


#include "glad.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "util.hpp"
#include "vertices.h"
#include "player.hpp"
#include "world.hpp"



//#define FULLSCREEN
//#define LOWRES
//#define VLOWRES

#ifdef FULLSCREEN
#ifndef LOWRES
#define WIDTH 2560
#define HEIGHT 1600
#else
#ifndef VLOWRES
#define WIDTH 1680	
#define HEIGHT 1050
#else
#define WIDTH 1280	
#define HEIGHT 800
#endif
#endif
#else
#define WIDTH 2880
#define HEIGHT 1800
#endif

#define SENSITIVITY 0.1f



float width, height;
glm::vec3 cam_eye = glm::vec3(1.0f, 0.0f, 0.0f), cam_up = glm::vec3(0.0f, 1.0f, 0.0f), cam_pos;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void immediate_input(GLFWwindow* window);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

Player Mexican;
World Mexico;
Solid Faces[6];
Texture Textures[NB_TEX];


int main()
{
	srand(time(NULL));
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	width = WIDTH;
	height =  HEIGHT;
	//FULLSCREEN
	#ifdef FULLSCREEN
	GLFWwindow* window = glfwCreateWindow(width/2, height/2, "Mexico", glfwGetPrimaryMonitor(), NULL);
	//NOT FULLSCREEN
	#else
	GLFWwindow* window = glfwCreateWindow(width/2, height/2, "Mexico", NULL, NULL);
	#endif


	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED | GLFW_CURSOR_HIDDEN);

	glfwMakeContextCurrent(window);


	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	//no openGL function before this line /!\
	//callbacks linking
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	
	//opengl init stuff
	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);

	

	Shader normalShader = Shader("shaders/normal.vert", "shaders/normal.frag");
	Shader skyboxShader = Shader("shaders/skybox.vert", "shaders/skybox.frag");
	Shader crossShader = Shader("shaders/crosshair.vert", "shaders/crosshair.frag");

	Cubemap skyboxCubemap = Cubemap("textures/skybox/front.jpg", "textures/skybox/back.jpg",
									"textures/skybox/left.jpg","textures/skybox/right.jpg",
									"textures/skybox/top.jpg","textures/skybox/bot.jpg");


	Texture Textures[NB_TEX];

	Textures[TEX(STONE)] = Texture("textures/blocs/stone.jpg");
	Textures[TEX(GRASS)] = Texture("textures/blocs/grass.jpg");
	Textures[TEX(WOOD)] = Texture("textures/blocs/wood.jpg");
	Textures[TEX(LEAF)] = Texture("textures/blocs/leaf.jpg");
	Texture Cross = Texture("textures/cross.jpg");
	
	Solid Cube = Solid(skybox_vertices, sizeof(skybox_vertices), VERT);
	Solid Bloc = Solid(cube_vertices, sizeof(cube_vertices), VERT_NORM_TEX);
	Solid Quad = Solid(quad_vertices, sizeof(quad_vertices), VERT_TEX);

	Solid Faces[6];
	Faces[TOP] = Solid(top_vert, sizeof(top_vert), VERT_NORM_TEX);
	Faces[BOT] = Solid(bot_vert, sizeof(bot_vert), VERT_NORM_TEX);
	Faces[LEFT] = Solid(left_vert, sizeof(left_vert), VERT_NORM_TEX);
	Faces[RIGHT] = Solid(right_vert, sizeof(right_vert), VERT_NORM_TEX);
	Faces[FRONT] = Solid(front_vert, sizeof(front_vert), VERT_NORM_TEX);
	Faces[BACK] = Solid(back_vert, sizeof(back_vert), VERT_NORM_TEX);

	Mexico.create(time(NULL));


	Mexican.tp(glm::vec3(WORLD_SIZE*CHUNK_SIZE/2.0, 25.0f, WORLD_SIZE*CHUNK_SIZE/2.0));

	normalShader.use();
	normalShader.uniform1i("Texture", 0);


	unsigned long time = 0;
	float delta_t=1, initial;


	//mainloop!
	while(!glfwWindowShouldClose(window)) {
		time++;
		initial = clock();
		normalShader.use();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		immediate_input(window);
		Mexican.update(delta_t, Mexico);


		//cam_pos = Mexican.get_pos();
		//printf("pos: %g %g %g\n", cam_pos.x, cam_pos.y, cam_pos.z);
		//glm::vec3 c_coord = chunk_coord(cam_pos);
		//printf("C: %g %g %g\n", c_coord.x, c_coord.y, c_coord.z);
		cam_pos = Mexican.get_cam();
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.01f, 100.0f);
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view;

		skyboxShader.use();
		view = glm::lookAt(	glm::vec3(0.0f),
							cam_eye,
							cam_up);
		skyboxShader.uniformMat4f("projection", projection);
		skyboxShader.uniformMat4f("view", view);
		glDepthMask(GL_FALSE);
		skyboxCubemap.bind();
		Cube.draw();
		glDepthMask(GL_TRUE);

		normalShader.use();
		view = glm::lookAt(	cam_pos,
							cam_pos+cam_eye,
							cam_up);

		

		
		normalShader.uniformMat4f("projection", projection);
		normalShader.uniformMat4f("view", view);

		Mexico.update(Mexican.get_cam(), Mexican.get_eye());

		Mexico.draw(normalShader, Faces, Textures);

		glDisable(GL_DEPTH_TEST);
		crossShader.use();
		crossShader.uniformMat4f("model", glm::scale(glm::mat4(1.0), glm::vec3(0.05, 0.08, 1.0)));
		Cross.bind();
		Quad.draw();
		glEnable(GL_DEPTH_TEST);

		delta_t = (clock() - initial)/100000;
		
		printf("delta_t : %g\n", delta_t);


 		
		glfwSwapBuffers(window);
		glfwPollEvents(); 
	}


	glfwTerminate();
	return EXIT_SUCCESS;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	static float lastx=xpos, lasty=ypos, yaw=0, pitch=0;

	float xoffset = xpos - lastx;
	float yoffset = ypos - lasty;
	lastx = xpos;
	lasty = ypos;

	yaw += SENSITIVITY*xoffset;
	pitch -= SENSITIVITY*yoffset;
	if (pitch >= 89.9)
		pitch = 89.9;
	if (pitch <= -89.9)
		pitch = -89.9;
	if(yaw > 360)
		yaw = yaw - 360;
	if (yaw < 0)
		yaw = yaw + 360;


	glm::vec3 t_eye, front ;
	t_eye.x = cosf(glm::radians(pitch)) * cosf(glm::radians(yaw));
	t_eye.y = sinf(glm::radians(pitch));
	t_eye.z = cosf(glm::radians(pitch)) * sinf(glm::radians(yaw));

	front.x = cosf(glm::radians(yaw));
	front.y = 0.0f;
	front.z = sinf(glm::radians(yaw));

	cam_eye = glm::normalize(t_eye);
	front = glm::normalize(front);
	Mexican.set_orient(front, cam_eye);

	

}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	Collision c = Mexico.trace(Mexican.get_cam(), Mexican.get_eye());
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        if(c.happened) {
        	if(c.face == TOP) {
        		Mexico.update_block(c.bloc.get_pos()+glm::vec3(0.0, 1.0, 0.0), Mexican.get_hand());
        	}
        	if(c.face == BOT) {
        		Mexico.update_block(c.bloc.get_pos()+glm::vec3(0.0, -1.0, 0.0), Mexican.get_hand());
        	}
        	if(c.face == RIGHT) {
        		Mexico.update_block(c.bloc.get_pos()+glm::vec3(1.0, 0.0, 0.0), Mexican.get_hand());
        	}
        	if(c.face == LEFT) {
        		Mexico.update_block(c.bloc.get_pos()+glm::vec3(-1.0, 0.0, 0.0), Mexican.get_hand());
        	}
        	if(c.face == FRONT) {
        		Mexico.update_block(c.bloc.get_pos()+glm::vec3(0.0, 0.0, 1.0), Mexican.get_hand());
        	}
        	if(c.face == BACK) {
        		Mexico.update_block(c.bloc.get_pos()+glm::vec3(0.0, 0.0, -1.0), Mexican.get_hand());
        	}
        	
        }
    }
    if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS) {
        if(c.happened) {
        	Mexican.set_hand(c.bloc.get_type());
        }
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        if(c.happened) {
        	Mexico.update_block(c.bloc.get_pos(), AIR);
        }
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (key == GLFW_KEY_P && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(key == GLFW_KEY_C && action == GLFW_PRESS) {

    }
}

void immediate_input(GLFWwindow* window)
{
	if(glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {

	}

	if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
		Mexican.forward();
	}
	if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
		Mexican.backward();
	}

	if(glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS){
		
	}
	if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){
		
	}
	if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
		Mexican.jump();
	}

	if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
		Mexican.left();
	}
	if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
		Mexican.right();
	}

	if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
		
	}
	if(glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
		
	}
		
}