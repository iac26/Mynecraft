#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "world.hpp"

#define PLAYER_HEIGHT 1.8f

class Player {
public:
	Player(glm::vec3 _pos);
	Player();
	void tp(glm::vec3 _pos);
	void forward();
	void backward();
	void left();
	void right();
	void jump();
	void set_orient(glm::vec3 _front, glm::vec3 _eye);
	void update(float dt, World w);
	void set_hand(int type);
	int get_hand();
	glm::vec3 get_pos();
	glm::vec3 get_cam();
	glm::vec3 get_eye();



private:
	glm::vec3 pos, eye, front, mov;
	glm::vec3 spd;
	bool fall;
	float v_spd;
	bool jmp;
	int hand;




};




#endif