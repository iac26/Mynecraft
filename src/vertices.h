#ifndef VERTICES_H
#define VERTICES_H

const float tri_vertices[] = {
	-0.5f, -0.5f, 0.0f, 0.0f, 0.5f,
	 0.5f, -0.5f, 0.0f, 0.5f, 0.5f,
	 0.0f,  0.5f, 0.0f, 0.5f, 0.0f
};

const float quad_vertices[] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f,

		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
		
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f

};

float top_vert[] = {
	0.0f, 1.0f, 0.0f, 	 0.0f, 1.0f, 0.0f,	0.25f, 2.0f/3.0f,
	1.0f, 1.0f, 0.0f, 	 0.0f, 1.0f, 0.0f,	0.25f, 1.0f/3.0f,
	1.0f, 1.0f, 1.0f, 	 0.0f, 1.0f, 0.0f,	0.50f, 1.0f/3.0f,
	1.0f, 1.0f, 1.0f, 	 0.0f, 1.0f, 0.0f,	0.50f, 1.0f/3.0f,
	0.0f, 1.0f, 1.0f, 	 0.0f, 1.0f, 0.0f,	0.50f, 2.0f/3.0f,
	0.0f, 1.0f, 0.0f, 	 0.0f, 1.0f, 0.0f,	0.25f, 2.0f/3.0f
};

float bot_vert[] = {
	0.0f, 0.0f, 0.0f, 	 0.0f, -1.0f, 0.0f,	1.00f, 2.0f/3.0f,
	0.0f, 0.0f, 1.0f, 	 0.0f, -1.0f, 0.0f,	0.75f, 2.0f/3.0f,
	1.0f, 0.0f, 0.0f, 	 0.0f, -1.0f, 0.0f,	1.00f, 1.0f/3.0f,
	1.0f, 0.0f, 0.0f, 	 0.0f, -1.0f, 0.0f,	1.00f, 1.0f/3.0f,
	0.0f, 0.0f, 1.0f, 	 0.0f, -1.0f, 0.0f,	0.75f, 2.0f/3.0f,
	1.0f, 0.0f, 1.0f, 	 0.0f, -1.0f, 0.0f, 0.75f, 1.0f/3.0f
};

float left_vert[] = {
	0.0f, 0.0f, 1.0f, 	-1.0f, 0.0f, 0.0f,	0.50f, 1.00f,
	0.0f, 0.0f, 0.0f, 	-1.0f, 0.0f, 0.0f,	0.25f, 1.00f,
	0.0f, 1.0f, 0.0f, 	-1.0f, 0.0f, 0.0f,	0.25f, 2.0f/3.0f,
	0.0f, 1.0f, 0.0f, 	-1.0f, 0.0f, 0.0f,	0.25f, 2.0f/3.0f,
	0.0f, 1.0f, 1.0f, 	-1.0f, 0.0f, 0.0f,	0.50f, 2.0f/3.0f,
	0.0f, 0.0f, 1.0f, 	-1.0f, 0.0f, 0.0f,	0.50f, 1.00f
};

float right_vert[] = {
	1.0f, 0.0f, 0.0f, 	 1.0f, 0.0f, 0.0f,	0.25f, 0.00f,
	1.0f, 0.0f, 1.0f, 	 1.0f, 0.0f, 0.0f,	0.50f, 0.00f,
	1.0f, 1.0f, 1.0f, 	 1.0f, 0.0f, 0.0f,	0.50f, 1.0f/3.0f,
	1.0f, 1.0f, 1.0f, 	 1.0f, 0.0f, 0.0f,	0.50f, 1.0f/3.0f,
	1.0f, 1.0f, 0.0f, 	 1.0f, 0.0f, 0.0f,	0.25f, 1.0f/3.0f,
	1.0f, 0.0f, 0.0f, 	 1.0f, 0.0f, 0.0f,	0.25f, 0.00f
};

float front_vert[] = {
	0.0f, 0.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.75f, 2.0f/3.0f,
	0.0f, 1.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.50f, 2.0f/3.0f,
	1.0f, 1.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.50f, 1.0f/3.0f,
	1.0f, 1.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.50f, 1.0f/3.0f,
	1.0f, 0.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.75f, 1.0f/3.0f,
	0.0f, 0.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.75f, 2.0f/3.0f
};

float back_vert[] = {
	0.0f, 1.0f, 0.0f, 	 0.0f, 0.0f, -1.0f, 0.25f, 2.0f/3.0f,
	0.0f, 0.0f, 0.0f, 	 0.0f, 0.0f, -1.0f,	0.00f, 2.0f/3.0f,
	1.0f, 0.0f, 0.0f, 	 0.0f, 0.0f, -1.0f,	0.00f, 1.0f/3.0f,
	1.0f, 0.0f, 0.0f, 	 0.0f, 0.0f, -1.0f,	0.00f, 1.0f/3.0f,
	1.0f, 1.0f, 0.0f, 	 0.0f, 0.0f, -1.0f,	0.25f, 1.0f/3.0f,
	0.0f, 1.0f, 0.0f, 	 0.0f, 0.0f, -1.0f,	0.25f, 2.0f/3.0f
};

float cube_vertices[] = {
	    //back         
	   0.0f, 1.0f, 0.0f, 	 0.0f, 0.0f, 0.0f, 	0.25f, 2.0f/3.0f,
	  0.0f, 0.0f, 0.0f, 	 0.0f, 0.0f, 0.0f,	0.00f, 2.0f/3.0f,
	  1.0f, 0.0f, 0.0f, 	 0.0f, 0.0f, 0.0f,	0.00f, 1.0f/3.0f,
	  1.0f, 0.0f, 0.0f, 	 0.0f, 0.0f, 0.0f,	0.00f, 1.0f/3.0f,
	  1.0f, 1.0f, 0.0f, 	 0.0f, 0.0f, 0.0f,	0.25f, 1.0f/3.0f,
	  0.0f, 1.0f, 0.0f, 	 0.0f, 0.0f, 0.0f,	0.25f, 2.0f/3.0f,
	  //left 
	  0.0f, 0.0f, 1.0f, 	0.0f, 0.0f, 0.0f,	0.50f, 1.00f,
	  0.0f, 0.0f, 0.0f, 	0.0f, 0.0f, 0.0f,	0.25f, 1.00f,
	  0.0f, 1.0f, 0.0f, 	0.0f, 0.0f, 0.0f,	0.25f, 2.0f/3.0f,
	  0.0f, 1.0f, 0.0f, 	0.0f, 0.0f, 0.0f,	0.25f, 2.0f/3.0f,
	  0.0f, 1.0f, 1.0f, 	0.0f, 0.0f, 0.0f,	0.50f, 2.0f/3.0f,
	  0.0f, 0.0f, 1.0f, 	0.0f, 0.0f, 0.0f,	0.50f, 1.00f,
	  //right
	  1.0f, 0.0f, 0.0f, 	 1.0f, 0.0f, 0.0f,	0.25f, 0.00f,
	  1.0f, 0.0f, 1.0f, 	 1.0f, 0.0f, 0.0f,	0.50f, 0.00f,
	  1.0f, 1.0f, 1.0f, 	 1.0f, 0.0f, 0.0f,	0.50f, 1.0f/3.0f,
	  1.0f, 1.0f, 1.0f, 	 1.0f, 0.0f, 0.0f,	0.50f, 1.0f/3.0f,
	  1.0f, 1.0f, 0.0f, 	 1.0f, 0.0f, 0.0f,	0.25f, 1.0f/3.0f,
	  1.0f, 0.0f, 0.0f, 	 1.0f, 0.0f, 0.0f,	0.25f, 0.00f,
 		//front
	  0.0f, 0.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.75f, 2.0f/3.0f,
	  0.0f, 1.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.50f, 2.0f/3.0f,
	  1.0f, 1.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.50f, 1.0f/3.0f,
	  1.0f, 1.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.50f, 1.0f/3.0f,
	  1.0f, 0.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.75f, 1.0f/3.0f,
	  0.0f, 0.0f, 1.0f, 	 0.0f, 0.0f, 1.0f,	0.75f, 2.0f/3.0f,
  		//top
	  0.0f, 1.0f, 0.0f, 	 0.0f, 1.0f, 0.0f,	0.25f, 2.0f/3.0f,
	  1.0f, 1.0f, 0.0f, 	 0.0f, 1.0f, 0.0f,	0.25f, 1.0f/3.0f,
	  1.0f, 1.0f, 1.0f, 	 0.0f, 1.0f, 0.0f,	0.50f, 1.0f/3.0f,
	  1.0f, 1.0f, 1.0f, 	 0.0f, 1.0f, 0.0f,	0.50f, 1.0f/3.0f,
	  0.0f, 1.0f, 1.0f, 	 0.0f, 1.0f, 0.0f,	0.50f, 2.0f/3.0f,
	  0.0f, 1.0f, 0.0f, 	 0.0f, 1.0f, 0.0f,	0.25f, 2.0f/3.0f,
 		//bottom
	  0.0f, 0.0f, 0.0f, 	 0.0f, 0.0f, 0.0f,	1.00f, 2.0f/3.0f,
	  0.0f, 0.0f, 1.0f, 	 0.0f, 0.0f, 0.0f,	0.75f, 2.0f/3.0f,
	  1.0f, 0.0f, 0.0f, 	 0.0f, 0.0f, 0.0f,	1.00f, 1.0f/3.0f,
	  1.0f, 0.0f, 0.0f, 	 0.0f, 0.0f, 0.0f,	1.00f, 1.0f/3.0f,
	  0.0f, 0.0f, 1.0f, 	 0.0f, 0.0f, 0.0f,	0.75f, 2.0f/3.0f,
	  1.0f, 0.0f, 1.0f, 	 0.0f, 0.0f, 0.0f, 	0.75f, 1.0f/3.0f
	};

float skybox_vertices[] = {
	 //back
	 -1.0f,  1.0f, -1.0f, 
	  1.0f, -1.0f, -1.0f,
	 -1.0f, -1.0f, -1.0f, 
	  1.0f,  1.0f, -1.0f,
	  1.0f, -1.0f, -1.0f, 
	 -1.0f,  1.0f, -1.0f, 
	 //left 
	 -1.0f, -1.0f, -1.0f, 
	 -1.0f, -1.0f,  1.0f, 
	 -1.0f,  1.0f, -1.0f, 
	 -1.0f,  1.0f,  1.0f, 
	 -1.0f,  1.0f, -1.0f, 
	 -1.0f, -1.0f,  1.0f, 
	 //right
	  1.0f, -1.0f,  1.0f,
	  1.0f, -1.0f, -1.0f,  
	  1.0f,  1.0f,  1.0f, 
	  1.0f,  1.0f, -1.0f, 
	  1.0f,  1.0f,  1.0f, 
	  1.0f, -1.0f, -1.0f, 
	//front
	 
	 -1.0f,  1.0f,  1.0f, 
	 -1.0f, -1.0f,  1.0f, 
	  1.0f,  1.0f,  1.0f, 
	  1.0f, -1.0f,  1.0f, 
	  1.0f,  1.0f,  1.0f, 
	 -1.0f, -1.0f,  1.0f, 
	//top
	 
	  1.0f,  1.0f, -1.0f, 
	 -1.0f,  1.0f, -1.0f,
	  1.0f,  1.0f,  1.0f, 
	 -1.0f,  1.0f,  1.0f,
	  1.0f,  1.0f,  1.0f, 
	 -1.0f,  1.0f, -1.0f, 
	//bottom
	 -1.0f, -1.0f,  1.0f, 
	 -1.0f, -1.0f, -1.0f,
	  1.0f, -1.0f, -1.0f, 
	 -1.0f, -1.0f,  1.0f,
	  1.0f, -1.0f, -1.0f,  
	  1.0f, -1.0f,  1.0f
	};




#endif