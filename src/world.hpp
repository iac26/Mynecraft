#ifndef WORLD_HPP
#define WORLD_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "util.hpp"

#define CHUNK_SIZE 16
#define CHUNK_HEIGHT 30

#define WORLD_SIZE 10

#define FREQ 50.0
#define NB_TREE 80
#define W_GROUND 20

#define NB_TEX 4
#define TEX(i) (i-1)
enum{X, Y, Z};
enum{AIR, STONE, GRASS, WOOD, LEAF};
enum{TOP, BOT, LEFT, RIGHT, FRONT, BACK};


class World;

class Block {
public:
	Block();
	Block(glm::vec3 _pos, int _type);
	void create(glm::vec3 _pos, int _type);
	void destroy();
	void retex(int _type);
	void draw(Shader shader, Solid faces[6], Texture tex[NB_TEX]);
	bool is_transparent();
	bool is_air();
	void set_transparent(bool val);
	void set_visible(int face, bool value);
	bool is_visible(int face);
	void hide();
	void unhide();
	glm::vec3 get_pos();


private:
	bool visible[6];
	bool transparent;
	int type;
	glm::vec3 pos;
};

struct Collision {
	int face;
	double dist;
	Block bloc;
	bool happened;
};


class Chunk {
public:
	Chunk();
	Chunk(glm::vec3 _pos);
	void create(glm::vec3 _pos);
	void generate(unsigned int seed);
	void load();
	void unload();
	void update(glm::vec3 p_pos, glm::vec3 p_eye, World * w);
	Block get_block(glm::vec3 b_pos);
	void update_block(glm::vec3 b_pos, int type);
	void draw(Shader shader, Solid faces[6], Texture tex[NB_TEX]);
	Collision trace(glm::vec3 pos, glm::vec3 eye);



private:
	glm::vec3 pos;
	Block blocks[CHUNK_SIZE][CHUNK_HEIGHT][CHUNK_SIZE];
	bool isloaded;
};

class World {
public:
	World();
	void create(unsigned int seed);
	void update(glm::vec3 p_pos, glm::vec3 p_eye);
	bool vertical_colision(glm::vec3 pos);
	bool horizontal_colision(glm::vec3 pos);
	glm::vec3 collision(glm::vec3 pos, glm::vec3 d_pos);
	void draw(Shader shader, Solid faces[6], Texture tex[NB_TEX]);
	Block get_block(glm::vec3 b_pos);
	bool is_block(glm::vec3 b_pos);
	Collision trace(glm::vec3 pos, glm::vec3 eye);
	void update_block(glm::vec3 pos, int type);


private:
	//this is temporary
	Chunk ** chunks;
	glm::vec3 player_cpos;
 
};

glm::vec3 chunk_coord(glm::vec3 coord);










#endif