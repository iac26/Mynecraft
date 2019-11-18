#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "world.hpp"
#include "PerlinNoise.hpp"



Block::Block() {

}

Block::Block(glm::vec3 _pos, int _type) {
	pos = _pos;
	type = _type;
	if(type == AIR) {
		transparent = true;
	} else {
		transparent = false;
	}

}

void Block::create(glm::vec3 _pos, int _type) {
	pos = _pos;
	type = _type;
	if(type == AIR) {
		transparent = true;
	} else {
		transparent = false;
	}
}

void Block::destroy() {
	type = AIR;
	transparent = true;
}

void Block::retex(int _type) {
	type = _type;
	if(type == AIR) {
		transparent = true;
	} else {
		transparent = false;
	}
}

void Block::hide() {
	transparent = true;
}

void Block::unhide() {
	if(type != AIR)
		transparent = false;
}

glm::vec3 Block::get_pos() {
	return pos;
}



void Block::draw(Shader shader, Solid faces[6], Texture tex[NB_TEX]) {
	shader.use();
	glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
	shader.uniformMat4f("model", model);
	tex[TEX(type)].bind();
	if(!transparent) {
		for(int i = 0; i < 6; i++) {
			if(visible[i]) {
				faces[i].draw();
			}
		}
	}
}

bool Block::is_transparent() {
	return transparent;
}

bool Block::is_air() {
	if(type == AIR) {
		return true;
	} else {
		return false;
	}
}

void Block::set_transparent(bool val) {
	transparent = val;
}


void Block::set_visible(int face, bool value) {
	visible[face] = value;
}

bool Block::is_visible(int face) {
	return visible[face];
}

int Block::get_type() {
	return type;
}


Chunk::Chunk() {


}

Chunk::Chunk(glm::vec3 _pos) {
	pos = _pos;
	isloaded = false;

}

void Chunk::create(glm::vec3 _pos) {
	pos = _pos;
	isloaded = false;

}




void Chunk::generate(unsigned int seed) {
	for(int x = 0; x < CHUNK_SIZE; x++) {
		for (int z = 0; z < CHUNK_SIZE; z++) {
			for (int y = 0; y < CHUNK_HEIGHT; y++) {
				glm::vec3 p_pos = pos+glm::vec3(x, y, z);
				siv::PerlinNoise Noise = siv::PerlinNoise(seed);
				int h = (int) (Noise.noise0_1((double)p_pos.x/FREQ, (double)p_pos.z/FREQ)*W_GROUND);
				//printf("%d\n", h);
				if(y < h) {
					blocks[x][y][z].create(p_pos, STONE);
				} else if(y == h) {
					blocks[x][y][z].create(p_pos, GRASS);
				} else {
					blocks[x][y][z].create(p_pos, AIR);
				}
			}
		}
	}
}

Block Chunk::get_block(glm::vec3 b_pos) {
	b_pos = b_pos - pos;
	return blocks[(int)b_pos.x][(int)b_pos.y][(int)b_pos.z];
}

void Chunk::load() {
	isloaded = true;
}

void Chunk::unload() {
	isloaded = false;
}

#define TOL 0.5
void Chunk::update(glm::vec3 p_pos, glm::vec3 p_eye, World * w) {
	if(isloaded) {
		for(int x = 0; x < CHUNK_SIZE; x++) {
			for (int z = 0; z < CHUNK_SIZE; z++) {
				for (int y = 0; y < CHUNK_HEIGHT; y++) {
					glm::vec3 ray = blocks[x][y][z].get_pos() - p_pos;
					float dist = glm::length(ray);
					ray = ray/dist;
					if(dist > 2.5f && glm::dot(ray, p_eye) < 0.5) {
						blocks[x][y][z].hide();
					} else {
						blocks[x][y][z].unhide();
					}
					if (!blocks[x][y][z].is_transparent()) {
						if (x < CHUNK_SIZE-1) {
							if (blocks[x+1][y][z].is_transparent() && p_eye.x < TOL) {
								blocks[x][y][z].set_visible(RIGHT, true);
							} else {
								blocks[x][y][z].set_visible(RIGHT, false);
							}
						} else if (w->is_block(pos+glm::vec3(x+1, y, z)) && !w->get_block(pos+glm::vec3(x+1, y, z)).is_transparent()) {
							blocks[x][y][z].set_visible(RIGHT, false);
						} else {
							if(p_eye.x < TOL) {
								blocks[x][y][z].set_visible(RIGHT, true);
							} else {
								blocks[x][y][z].set_visible(RIGHT, false);
							}
						}
						if (x > 0) {
							if (blocks[x-1][y][z].is_transparent() && p_eye.x > -TOL) {
								blocks[x][y][z].set_visible(LEFT, true);
							} else {
								blocks[x][y][z].set_visible(LEFT, false);
							}
						} else if (w->is_block(pos+glm::vec3(x-1, y, z)) && !w->get_block(pos+glm::vec3(x-1, y, z)).is_transparent()) {
							blocks[x][y][z].set_visible(LEFT, false);
						} else {
							if(p_eye.x > -TOL) {
								blocks[x][y][z].set_visible(LEFT, true);
							} else {
								blocks[x][y][z].set_visible(LEFT, false);
							}
						}
						if (y < CHUNK_HEIGHT-1) {
							if (blocks[x][y+1][z].is_transparent() && p_eye.y < TOL) {
								blocks[x][y][z].set_visible(TOP, true);
							} else {
								blocks[x][y][z].set_visible(TOP, false);
							}
						} else {
							if(p_eye.y < TOL) {
								blocks[x][y][z].set_visible(TOP, true);
							} else {
								blocks[x][y][z].set_visible(TOP, false);
							}
						}
						if (y > 0) {
							if( blocks[x][y-1][z].is_transparent() && p_eye.y > -TOL) {
								blocks[x][y][z].set_visible(BOT, true);
							} else {
								blocks[x][y][z].set_visible(BOT, false);
							}
						} else {
							blocks[x][y][z].set_visible(BOT, false);
						}
						if (z < CHUNK_SIZE-1) {
							if (blocks[x][y][z+1].is_transparent() && p_eye.z < TOL) {
								blocks[x][y][z].set_visible(FRONT, true);
							} else {
								blocks[x][y][z].set_visible(FRONT, false);
							}
						} else if (w->is_block(pos+glm::vec3(x, y, z+1)) && !w->get_block(pos+glm::vec3(x, y, z+1)).is_transparent()) {
							blocks[x][y][z].set_visible(FRONT, false);
						} else {
							if(p_eye.z < TOL) {
								blocks[x][y][z].set_visible(FRONT, true);
							} else {
								blocks[x][y][z].set_visible(FRONT, false);
							}
						}
						if (z > 0) {
							if (blocks[x][y][z-1].is_transparent() && p_eye.z > -TOL) {
								blocks[x][y][z].set_visible(BACK, true);
							} else {
								blocks[x][y][z].set_visible(BACK, false);
							}
						} else if (w->is_block(pos+glm::vec3(x, y, z-1)) && !w->get_block(pos+glm::vec3(x, y, z-1)).is_transparent()) {
							blocks[x][y][z].set_visible(BACK, false);
						} else {
							if(p_eye.z > -TOL) {
								blocks[x][y][z].set_visible(BACK, true);
							} else {
								blocks[x][y][z].set_visible(BACK, false);
							}
						}
					}
				}
			}
		}
	}
}

Collision Chunk::trace(glm::vec3 pos, glm::vec3 eye) {
	double min = 100.;
	Collision c;
	for(int x = 0; x < CHUNK_SIZE; x++) {
		for (int z = 0; z < CHUNK_SIZE; z++) {
			for (int y = 0; y < CHUNK_HEIGHT; y++) {
				if(!blocks[x][y][z].is_air()) {
					glm::vec3 ctr = (blocks[x][y][z].get_pos()+glm::vec3(0.5, 0.5, 0.5)) - pos;
					glm::vec3 tmp = glm::cross(ctr, eye);
					double d = glm::length(tmp);
					double dist = glm::length(ctr);
					if(d < 0.5) {
						if(dist < min){
							min = dist;
							c.bloc = blocks[x][y][z];
						}
					}
				}


			}
		}
	}
	
	if(min < 15) {
		printf("collision: %g\n", min);
		c.dist = min;
	}
	
	return c;
}

void Chunk::update_block(glm::vec3 b_pos, int type) {
	glm::vec3 i_pos = b_pos - pos;
	blocks[(int)i_pos.x][(int)i_pos.y][(int)i_pos.z].retex(type);
}




void Chunk::draw(Shader shader, Solid faces[6], Texture tex[NB_TEX]) {
	if(isloaded) {
		for(int x = 0; x < CHUNK_SIZE; x++) {
			for (int z = 0; z < CHUNK_SIZE; z++) {
				for (int y = 0; y < CHUNK_HEIGHT; y++) {
					if (!blocks[x][y][z].is_transparent()) {
						blocks[x][y][z].draw(shader, faces, tex);
					}
				}
			}
		}
	}
}

glm::vec3 chunk_coord(glm::vec3 coord) {
	glm::vec3 res;

	res.x = (int)(coord.x/16);
	res.z = (int)(coord.z/16);
	if(coord.x < 0)
		res.x -= 1;
	if(coord.z < 0)
		res.z -= 1;
	res.y = 0;
	return res;

}


World::World() {

}



void World::create(unsigned int seed) {
	chunks = (Chunk**)malloc(WORLD_SIZE*sizeof(Chunk*));
	for(int i = 0; i < WORLD_SIZE; i++) {
		chunks[i] = (Chunk*)malloc(WORLD_SIZE*sizeof(Chunk));
		for(int j = 0; j < WORLD_SIZE; j++) {
			//printf("%d %d\n", i, j);
			chunks[i][j].create(glm::vec3(i*CHUNK_SIZE, 0.0f, j*CHUNK_SIZE));
			chunks[i][j].generate(seed);
		}
	}
	for (int i = 0; i < NB_TREE; i++) {
		int x = (rand() % (WORLD_SIZE*CHUNK_SIZE-10))+5;
		int z = (rand() % (WORLD_SIZE*CHUNK_SIZE-10))+5;
		siv::PerlinNoise Noise = siv::PerlinNoise(seed);
		int h = (int) (Noise.noise0_1((double)x/FREQ, (double)z/FREQ)*W_GROUND);
		update_block(glm::vec3(x  , h+1, z  ), WOOD);
		update_block(glm::vec3(x  , h+2, z  ), WOOD);
		update_block(glm::vec3(x  , h+3, z  ), WOOD);
		update_block(glm::vec3(x  , h+4, z  ), WOOD);
		update_block(glm::vec3(x  , h+5, z  ), WOOD);
		for(int k = -1; k <= 1; k++) {
			for(int j = -1; j <= 1; j++) {
				if(k*k != 1 || j*j != 1) {
					update_block(glm::vec3(x+k, h+6, z+j), LEAF);
				}
			}
		}
		for(int k = -2; k <= 2; k++) {
			for(int j = -2; j <= 2; j++) {
				if(k != 0 || j != 0) {
					update_block(glm::vec3(x+k, h+4, z+j), LEAF);
					if(k*k != 4 || j*j != 4) {
						update_block(glm::vec3(x+k, h+5, z+j), LEAF);
					}
				}
			}
		}
		//printf("trree %d %d %d\n",x, z, h);
	}
}

void World::update(glm::vec3 p_pos, glm::vec3 p_eye) {
	glm::vec3 c_pos = chunk_coord(p_pos);
	if(c_pos.x != player_cpos.x || c_pos.z != player_cpos.z) {
		player_cpos = c_pos;
		for(int i = -2; i <= 2; i++) {
			for(int j = -2; j <= 2; j++) {
				int x = player_cpos.x + i;
				int z = player_cpos.z + j;
				if(x >= 0 && x < WORLD_SIZE && z >= 0 && z < WORLD_SIZE) {
					if(i >= -1 && i <= 1 && j >= -1 && j <= 1) {
						chunks[x][z].load();
					} else {
						chunks[x][z].unload();
					}
				}
			}
		}
	}
	for(int i = 0; i < WORLD_SIZE; i++) {
		for(int j = 0; j < WORLD_SIZE; j++) {
			chunks[i][j].update(p_pos, p_eye, this);
		}
	}
}

bool World::vertical_colision(glm::vec3 pos) {
	glm::vec3 c_pos = chunk_coord(pos);
	Block b = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos-glm::vec3(0.0, 0.2, 0.0));
	return !b.is_air();
}

bool World::head_colision(glm::vec3 pos) {
	glm::vec3 c_pos = chunk_coord(pos);
	Block b = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos+glm::vec3(0.0, 1.9, 0.0));
	return !b.is_air();
}

bool World::horizontal_colision(glm::vec3 pos) {
	if(pos.x < 0 || pos.z < 0 || pos.z > WORLD_SIZE*CHUNK_SIZE || pos.x > WORLD_SIZE*CHUNK_SIZE)
		return true;
	glm::vec3 c_pos = chunk_coord(pos);
	Block b = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos+glm::vec3(0.0, 0.5, 0.0));
	Block t = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos+glm::vec3(0.0, 1.5, 0.0));
	return !b.is_air() || !t.is_air();
}

glm::vec3 World::collision(glm::vec3 pos, glm::vec3 d_pos) {
	glm::vec3 t_pos = pos+d_pos;
	if(t_pos.x < 0 || t_pos.z < 0 || t_pos.z > WORLD_SIZE*CHUNK_SIZE || t_pos.x > WORLD_SIZE*CHUNK_SIZE)
		return pos;


	glm::vec3 pos_x = pos + glm::vec3(d_pos.x, 0.0, 0.0);
	glm::vec3 c_pos = chunk_coord(pos_x);
	
	Block b = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos_x + glm::vec3(0.0, 0.0, 0.0));
	Block t = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos_x + glm::vec3(0.0, 1.8, 0.0));
	if(!b.is_air() || !t.is_air()) {
		if(d_pos.x > 0.01) {
			d_pos.x = (int)pos.x+0.9 - pos.x;
		} else if(d_pos.x < 0.01) {
			d_pos.x = (int)pos.x+0.1 - pos.x;
		} else {
			d_pos.x = 0;
		}
	}


	glm::vec3 pos_y = pos + glm::vec3(0.0, d_pos.y, 0.0);
	c_pos = chunk_coord(pos_y);

	b = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos_y + glm::vec3(0.0, 0.0, 0.0));
	t = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos_y + glm::vec3(0.0, 1.8, 0.0));
	if(!b.is_air()) {
		if(d_pos.y > 0) {
			//d_pos.y = 0;//(int)pos.y+0.9 - pos.y;
		} else if(d_pos.y < 0) {
			d_pos.y = (int)pos.y+0.01 - pos.y;
		} else {
			d_pos.y = 0;
		}
	}
	if(!t.is_air()) {
		if(d_pos.y > 0.1) {
			d_pos.y = 0.1;//(int)pos.y+0.9 - pos.y;
		} else if(d_pos.y < 0) {
			//d_pos.y = (int)pos.y+0.01 - pos.y;
		} else {
			d_pos.y = 0;
		}
	}


	glm::vec3 pos_z = pos + glm::vec3(0.0, 0.0, d_pos.z);
	c_pos = chunk_coord(pos_z);

	b = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos_z + glm::vec3(0.0, 0.0, 0.0));
	t = chunks[(int)c_pos.x][(int)c_pos.z].get_block(pos_z + glm::vec3(0.0, 1.8, 0.0));
	if(!b.is_air() || !t.is_air()) {
		if(d_pos.z > 0.01) {
			d_pos.z = (int)pos.z+0.9 - pos.z;
		} else if(d_pos.z < 0.01){
			d_pos.z = (int)pos.z+0.1 - pos.z;
		} else {
			d_pos.z = 0;
		}
	}
	return pos + d_pos;
}


Block World::get_block(glm::vec3 b_pos) {
	glm::vec3 c_coord = chunk_coord(b_pos);
	return chunks[(int)c_coord.x][(int)c_coord.z].get_block(b_pos);
}

bool World::is_block(glm::vec3 b_pos) {
	glm::vec3 c_coord = chunk_coord(b_pos);
	if(c_coord.x < WORLD_SIZE && c_coord.z < WORLD_SIZE && c_coord.x >= 0 && c_coord.z >= 0) {
		return true;
	} else {
		return false;
	}
}

Collision World::trace(glm::vec3 pos, glm::vec3 eye) {
	Collision c;
	c.happened = false;
	float min = 100.;
	//printf("player: %g %g %g\n", pos.x, pos.y, pos.z);
	for(int x = -5; x <= 5; x++) {
		for(int y = -6; y <= 5; y++) {
			for(int z = -5; z <= 5; z++) {
				if(is_block(pos+glm::vec3(x, y, z))) {
					Block b = get_block(pos+glm::vec3(x, y, z));
					if(!b.is_air()) {
						glm::vec3 b_center = b.get_pos() + glm::vec3(0.5, 0.5, 0.5);

						//top
						if(b.is_visible(TOP)) {
							glm::vec3 f_pos = b_center + glm::vec3(0.0, 0.5, 0.0);
							float d = glm::dot(eye, glm::vec3(0.0, 1.0, 0.0));
							if(abs(d) > 1e-6) { 
								float t = glm::dot(f_pos - pos, glm::vec3(0.0, 1.0, 0.0)) / d;
								if(		abs(f_pos.x - (pos + t*eye).x) <= 0.5
									&&	abs(f_pos.z - (pos + t*eye).z) <= 0.5
									&& t > 0) {
									if(t < min) {
										//printf("bloc: %g %g %g\n", b.get_pos().x, b.get_pos().y, b.get_pos().z);
										//printf("col: fac:TOP t:%g p:%g %g %g\n",t, (pos + t*eye).x, (pos + t*eye).y, (pos + t*eye).z );
										min = t;
										c.face = TOP;
										c.dist = t;
										c.bloc = b;
									}
								}
							}
						}

						//bot
						if(b.is_visible(BOT)) {
							glm::vec3 f_pos = b_center + glm::vec3(0.0, -0.5, 0.0);
							float d = glm::dot(eye, glm::vec3(0.0, -1.0, 0.0));
							if(abs(d) > 1e-6) { 
								float t = glm::dot(f_pos - pos, glm::vec3(0.0, -1.0, 0.0)) / d;
								if(		abs(f_pos.x - (pos + t*eye).x) <= 0.5
									&&	abs(f_pos.z - (pos + t*eye).z) <= 0.5
									&& t > 0) {
									if(t < min) {
										//printf("bloc: %g %g %g\n", b.get_pos().x, b.get_pos().y, b.get_pos().z);
										//printf("col: fac:BOT t:%g p:%g %g %g\n",t, (pos + t*eye).x, (pos + t*eye).y, (pos + t*eye).z );
										min = t;
										c.face = BOT;
										c.dist = t;
										c.bloc = b;
									}
								}
							}
						}


						//left
						if(b.is_visible(LEFT)) {
							glm::vec3 f_pos = b_center + glm::vec3(-0.5, 0.0, 0.0);
							float d = glm::dot(eye, glm::vec3(-1.0, 0.0, 0.0));
							if(abs(d) > 1e-6) { 
								float t = glm::dot(f_pos - pos, glm::vec3(-1.0, 0.0, 0.0)) / d;
								if(		abs(f_pos.z - (pos + t*eye).z) <= 0.5
									&&	abs(f_pos.y - (pos + t*eye).y) <= 0.5
									&& t > 0) {
									if(t < min) {
										//printf("bloc: %g %g %g\n", b.get_pos().x, b.get_pos().y, b.get_pos().z);
										//printf("col: fac:LEFT t:%g p:%g %g %g\n",t, (pos + t*eye).x, (pos + t*eye).y, (pos + t*eye).z );
										min = t;
										c.face = LEFT;
										c.dist = t;
										c.bloc = b;
									}
								}
							}
						}


						//right
						if(b.is_visible(RIGHT)) {
							glm::vec3 f_pos = b_center + glm::vec3(0.5, 0.0, 0.0);
							float d = glm::dot(eye, glm::vec3(1.0, 0.0, 0.0));
							if(abs(d) > 1e-6) { 
								float t = glm::dot(f_pos - pos, glm::vec3(1.0, 0.0, 0.0)) / d;
								if(		abs(f_pos.z - (pos + t*eye).z) <= 0.5
									&&	abs(f_pos.y - (pos + t*eye).y) <= 0.5
									&& t > 0) {
									if(t < min) {
										//printf("bloc: %g %g %g\n", b.get_pos().x, b.get_pos().y, b.get_pos().z);
										//printf("col: fac:RIGHT t:%g p:%g %g %g\n",t, (pos + t*eye).x, (pos + t*eye).y, (pos + t*eye).z );
										min = t;
										c.face = RIGHT;
										c.dist = t;
										c.bloc = b;
									}
								}
							}
						}


						//front
						if(b.is_visible(FRONT)) {
							glm::vec3 f_pos = b_center + glm::vec3(0.0, 0.0, 0.5);
							float d = glm::dot(eye, glm::vec3(0.0, 0.0, 1.0));
							if(abs(d) > 1e-6) { 
								float t = glm::dot(f_pos - pos, glm::vec3(0.0, 0.0, 1.0)) / d;
								if(		abs(f_pos.x - (pos + t*eye).x) <= 0.5
									&&	abs(f_pos.y - (pos + t*eye).y) <= 0.5
									&& t > 0) {
									if(t < min) {
										//printf("bloc: %g %g %g\n", b.get_pos().x, b.get_pos().y, b.get_pos().z);
										//printf("col: fac:FRONT t:%g p:%g %g %g\n",t, (pos + t*eye).x, (pos + t*eye).y, (pos + t*eye).z );
										min = t;
										c.face = FRONT;
										c.dist = t;
										c.bloc = b;
									}
								}
							}
						}

						//back
						if(b.is_visible(BACK)) {
							glm::vec3 f_pos = b_center + glm::vec3(0.0, 0.0, -0.5);
							float d = glm::dot(eye, glm::vec3(0.0, 0.0, -1.0));
							if(abs(d) > 1e-6) { 
								float t = glm::dot(f_pos - pos, glm::vec3(0.0, 0.0, -1.0)) / d;
								if(		abs(f_pos.x - (pos + t*eye).x) <= 0.5
									&&	abs(f_pos.y - (pos + t*eye).y) <= 0.5
									&& t > 0) {
									if(t < min) {
										//printf("bloc: %g %g %g\n", b.get_pos().x, b.get_pos().y, b.get_pos().z);
										//printf("col: fac:BACK t:%g p:%g %g %g\n",t, (pos + t*eye).x, (pos + t*eye).y, (pos + t*eye).z );
										min = t;
										c.face = BACK;
										c.dist = t;
										c.bloc = b;
									}
								}
							}
						}



					}
				}
			}
		}
	}
	if(min < 10) {
		printf("collision: %g %d\n", c.dist, c.face);
		c.happened = true;
	}
	return c;
}

void World::update_block(glm::vec3 pos, int type) {
	glm::vec3 c_coord = chunk_coord(pos);
	chunks[(int)c_coord.x][(int)c_coord.z].update_block(pos, type);
}



void World::draw(Shader shader, Solid faces[6], Texture tex[NB_TEX]) {
	for(int i = 0; i < WORLD_SIZE; i++) {
		for(int j = 0; j < WORLD_SIZE; j++) {
			chunks[i][j].draw(shader, faces, tex);
		}
	}
}







