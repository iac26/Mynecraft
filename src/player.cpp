#include <stdlib.h>
#include <stdio.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define MOVE_SENSITIVITY 0.7f
#define JMP_SENSITIVITY 1.0f
#define FALL_SPEED 0.2f

#include "player.hpp"


Player::Player(glm::vec3 _pos) {
	pos = _pos;
	fall = false;
	mov = glm::vec3(0.0f);
	front = glm::vec3(1.0f, 0.0f, 0.0f);
	eye = glm::vec3(1.0f, 0.0f, 0.0f);
}

Player::Player() {
	fall = false;
	front = glm::vec3(1.0f, 0.0f, 0.0f);
	eye = glm::vec3(1.0f, 0.0f, 0.0f);
}

void Player::tp(glm::vec3 _pos) {
	pos = _pos;
	mov = glm::vec3(0.0f);
}

void Player::forward() {
	mov += glm::normalize(front);
}

void Player::backward() {
	mov -= glm::normalize(front);
}

void Player::left() {
	mov -= glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
}

void Player::right() {
	mov += glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
}

void Player::jump() {
	jmp = true;
}

void Player::set_orient(glm::vec3 _front, glm::vec3 _eye) {
	front = _front;
	eye = _eye;
}

void Player::update(float dt, World w) {
	spd = glm::vec3(0.0);
	if(glm::length(mov) != 0.0f) {
		spd = MOVE_SENSITIVITY*glm::normalize(mov);
	}
	mov = glm::vec3(0.0);
	v_spd += -0.2*dt;
	if(jmp && w.vertical_colision(pos)) {
		v_spd = 0.6;
		printf("jump\n");
	}
	if(w.head_colision(pos)) {
		v_spd = -0.1;
		printf("ouch\n");
	}
	jmp = false;
	if(v_spd < -0.9)
		v_spd = -0.9;
	glm::vec3 d_pos = spd*dt + glm::vec3(0.0, v_spd, 0.0)*dt;
	pos = w.collision(pos, d_pos);

	
}

void Player::set_hand(int type) {
	hand = type;
}

int Player::get_hand() {
	return hand;
}

glm::vec3 Player::get_cam() {
	return pos+glm::vec3(0.0f, PLAYER_HEIGHT, 0.0f);
}

glm::vec3 Player::get_pos() {
	return pos;
}
glm::vec3 Player::get_eye() {
	return eye;
}









