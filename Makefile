#Makefile

OFILES=src/main.o src/util.o src/player.o src/world.o src/glad.o
CFILES=src/main.cpp src/util.cpp src/player.cpp src/world.cpp src/glad.c
CC=gcc
CFLAGS=

LIB= -lglfw -lX11 -lGL -lm -ldl -lstdc++ 
LIBM= -lglfw3 -framework Cocoa -framework OpenGL -framework IOkit -framework corevideo -lm -ldl -lstdc++

all : mynecraft

mynecraft : $(OFILES)
	$(CC) $(OFILES) -o mynecraft.x $(LIB)
	@rm -f src/*.o

mac : $(OFILES)
	$(CC) $(OFILES) -o mynecraft.x $(LIBM)
	@rm -f src/*.o

	
clean : 
	@echo "CLEANING"
	@rm -f src/*.o
	
depend : 
	@echo "UPDATING DEPENDENCIES"
	@(sed '/^# DEPENDANCES/q' Makefile && \
	  $(CC) -MM $(CFLAGS) $(CFILES) | \
	  egrep -v "/usr/include" \
	 ) >Makefile.new
	@mv Makefile.new Makefile

# DEPENDANCES
main.o: src/main.cpp src/glad.h /usr/local/include/GLFW/glfw3.h \
  /usr/local/include/glm/glm.hpp \
  /usr/local/include/glm/detail/_fixes.hpp \
  /usr/local/include/glm/fwd.hpp \
  /usr/local/include/glm/detail/type_int.hpp \
  /usr/local/include/glm/detail/setup.hpp \
  /usr/local/include/glm/detail/../simd/platform.h \
  /usr/local/include/glm/detail/type_float.hpp \
  /usr/local/include/glm/detail/type_vec.hpp \
  /usr/local/include/glm/detail/precision.hpp \
  /usr/local/include/glm/detail/type_mat.hpp \
  /usr/local/include/glm/vec2.hpp \
  /usr/local/include/glm/detail/type_vec2.hpp \
  /usr/local/include/glm/detail/type_vec2.inl \
  /usr/local/include/glm/vec3.hpp \
  /usr/local/include/glm/detail/type_vec3.hpp \
  /usr/local/include/glm/detail/type_vec3.inl \
  /usr/local/include/glm/vec4.hpp \
  /usr/local/include/glm/detail/type_vec4.hpp \
  /usr/local/include/glm/detail/type_vec4.inl \
  /usr/local/include/glm/mat2x2.hpp \
  /usr/local/include/glm/detail/type_mat2x2.hpp \
  /usr/local/include/glm/detail/../fwd.hpp \
  /usr/local/include/glm/detail/type_mat2x2.inl \
  /usr/local/include/glm/detail/func_matrix.hpp \
  /usr/local/include/glm/detail/../detail/precision.hpp \
  /usr/local/include/glm/detail/../detail/setup.hpp \
  /usr/local/include/glm/detail/../detail/type_mat.hpp \
  /usr/local/include/glm/detail/../vec2.hpp \
  /usr/local/include/glm/detail/../vec3.hpp \
  /usr/local/include/glm/detail/../vec4.hpp \
  /usr/local/include/glm/detail/../mat2x2.hpp \
  /usr/local/include/glm/detail/../mat2x3.hpp \
  /usr/local/include/glm/detail/type_mat2x3.hpp \
  /usr/local/include/glm/detail/type_mat2x3.inl \
  /usr/local/include/glm/detail/../mat2x4.hpp \
  /usr/local/include/glm/detail/type_mat2x4.hpp \
  /usr/local/include/glm/detail/type_mat2x4.inl \
  /usr/local/include/glm/detail/../mat3x2.hpp \
  /usr/local/include/glm/detail/type_mat3x2.hpp \
  /usr/local/include/glm/detail/type_mat3x2.inl \
  /usr/local/include/glm/detail/../mat3x3.hpp \
  /usr/local/include/glm/detail/type_mat3x3.hpp \
  /usr/local/include/glm/detail/type_mat3x3.inl \
  /usr/local/include/glm/detail/../mat3x4.hpp \
  /usr/local/include/glm/detail/type_mat3x4.hpp \
  /usr/local/include/glm/detail/type_mat3x4.inl \
  /usr/local/include/glm/detail/../mat4x2.hpp \
  /usr/local/include/glm/detail/type_mat4x2.hpp \
  /usr/local/include/glm/detail/type_mat4x2.inl \
  /usr/local/include/glm/detail/../mat4x3.hpp \
  /usr/local/include/glm/detail/type_mat4x3.hpp \
  /usr/local/include/glm/detail/type_mat4x3.inl \
  /usr/local/include/glm/detail/../mat4x4.hpp \
  /usr/local/include/glm/detail/type_mat4x4.hpp \
  /usr/local/include/glm/detail/type_mat4x4.inl \
  /usr/local/include/glm/detail/type_mat4x4_simd.inl \
  /usr/local/include/glm/detail/func_matrix.inl \
  /usr/local/include/glm/detail/../geometric.hpp \
  /usr/local/include/glm/detail/func_geometric.hpp \
  /usr/local/include/glm/detail/func_geometric.inl \
  /usr/local/include/glm/detail/func_exponential.hpp \
  /usr/local/include/glm/detail/type_vec1.hpp \
  /usr/local/include/glm/detail/type_vec1.inl \
  /usr/local/include/glm/detail/func_exponential.inl \
  /usr/local/include/glm/detail/func_vector_relational.hpp \
  /usr/local/include/glm/detail/func_vector_relational.inl \
  /usr/local/include/glm/detail/_vectorize.hpp \
  /usr/local/include/glm/detail/func_common.hpp \
  /usr/local/include/glm/detail/func_common.inl \
  /usr/local/include/glm/mat2x3.hpp /usr/local/include/glm/mat2x4.hpp \
  /usr/local/include/glm/mat3x2.hpp /usr/local/include/glm/mat3x3.hpp \
  /usr/local/include/glm/mat3x4.hpp /usr/local/include/glm/mat4x2.hpp \
  /usr/local/include/glm/mat4x3.hpp /usr/local/include/glm/mat4x4.hpp \
  /usr/local/include/glm/trigonometric.hpp \
  /usr/local/include/glm/detail/func_trigonometric.hpp \
  /usr/local/include/glm/detail/func_trigonometric.inl \
  /usr/local/include/glm/exponential.hpp \
  /usr/local/include/glm/common.hpp /usr/local/include/glm/packing.hpp \
  /usr/local/include/glm/detail/func_packing.hpp \
  /usr/local/include/glm/detail/func_packing.inl \
  /usr/local/include/glm/detail/type_half.hpp \
  /usr/local/include/glm/detail/type_half.inl \
  /usr/local/include/glm/geometric.hpp /usr/local/include/glm/matrix.hpp \
  /usr/local/include/glm/vector_relational.hpp \
  /usr/local/include/glm/integer.hpp \
  /usr/local/include/glm/detail/func_integer.hpp \
  /usr/local/include/glm/detail/func_integer.inl \
  /usr/local/include/glm/gtc/matrix_transform.hpp \
  /usr/local/include/glm/gtc/../mat4x4.hpp \
  /usr/local/include/glm/gtc/../vec2.hpp \
  /usr/local/include/glm/gtc/../vec3.hpp \
  /usr/local/include/glm/gtc/../vec4.hpp \
  /usr/local/include/glm/gtc/../gtc/constants.hpp \
  /usr/local/include/glm/gtc/../detail/setup.hpp \
  /usr/local/include/glm/gtc/constants.inl \
  /usr/local/include/glm/gtc/matrix_transform.inl \
  /usr/local/include/glm/gtc/../geometric.hpp \
  /usr/local/include/glm/gtc/../trigonometric.hpp \
  /usr/local/include/glm/gtc/../matrix.hpp \
  /usr/local/include/glm/gtc/type_ptr.hpp \
  /usr/local/include/glm/gtc/../gtc/quaternion.hpp \
  /usr/local/include/glm/gtc/../mat3x3.hpp \
  /usr/local/include/glm/gtc/quaternion.inl \
  /usr/local/include/glm/gtc/../exponential.hpp \
  /usr/local/include/glm/gtc/../mat2x2.hpp \
  /usr/local/include/glm/gtc/../mat2x3.hpp \
  /usr/local/include/glm/gtc/../mat2x4.hpp \
  /usr/local/include/glm/gtc/../mat3x2.hpp \
  /usr/local/include/glm/gtc/../mat3x4.hpp \
  /usr/local/include/glm/gtc/../mat4x2.hpp \
  /usr/local/include/glm/gtc/../mat4x3.hpp \
  /usr/local/include/glm/gtc/type_ptr.inl src/util.hpp src/vertices.h \
  src/player.hpp src/world.hpp
util.o: src/util.cpp src/glad.h /usr/local/include/GLFW/glfw3.h \
  /usr/local/include/glm/glm.hpp \
  /usr/local/include/glm/detail/_fixes.hpp \
  /usr/local/include/glm/fwd.hpp \
  /usr/local/include/glm/detail/type_int.hpp \
  /usr/local/include/glm/detail/setup.hpp \
  /usr/local/include/glm/detail/../simd/platform.h \
  /usr/local/include/glm/detail/type_float.hpp \
  /usr/local/include/glm/detail/type_vec.hpp \
  /usr/local/include/glm/detail/precision.hpp \
  /usr/local/include/glm/detail/type_mat.hpp \
  /usr/local/include/glm/vec2.hpp \
  /usr/local/include/glm/detail/type_vec2.hpp \
  /usr/local/include/glm/detail/type_vec2.inl \
  /usr/local/include/glm/vec3.hpp \
  /usr/local/include/glm/detail/type_vec3.hpp \
  /usr/local/include/glm/detail/type_vec3.inl \
  /usr/local/include/glm/vec4.hpp \
  /usr/local/include/glm/detail/type_vec4.hpp \
  /usr/local/include/glm/detail/type_vec4.inl \
  /usr/local/include/glm/mat2x2.hpp \
  /usr/local/include/glm/detail/type_mat2x2.hpp \
  /usr/local/include/glm/detail/../fwd.hpp \
  /usr/local/include/glm/detail/type_mat2x2.inl \
  /usr/local/include/glm/detail/func_matrix.hpp \
  /usr/local/include/glm/detail/../detail/precision.hpp \
  /usr/local/include/glm/detail/../detail/setup.hpp \
  /usr/local/include/glm/detail/../detail/type_mat.hpp \
  /usr/local/include/glm/detail/../vec2.hpp \
  /usr/local/include/glm/detail/../vec3.hpp \
  /usr/local/include/glm/detail/../vec4.hpp \
  /usr/local/include/glm/detail/../mat2x2.hpp \
  /usr/local/include/glm/detail/../mat2x3.hpp \
  /usr/local/include/glm/detail/type_mat2x3.hpp \
  /usr/local/include/glm/detail/type_mat2x3.inl \
  /usr/local/include/glm/detail/../mat2x4.hpp \
  /usr/local/include/glm/detail/type_mat2x4.hpp \
  /usr/local/include/glm/detail/type_mat2x4.inl \
  /usr/local/include/glm/detail/../mat3x2.hpp \
  /usr/local/include/glm/detail/type_mat3x2.hpp \
  /usr/local/include/glm/detail/type_mat3x2.inl \
  /usr/local/include/glm/detail/../mat3x3.hpp \
  /usr/local/include/glm/detail/type_mat3x3.hpp \
  /usr/local/include/glm/detail/type_mat3x3.inl \
  /usr/local/include/glm/detail/../mat3x4.hpp \
  /usr/local/include/glm/detail/type_mat3x4.hpp \
  /usr/local/include/glm/detail/type_mat3x4.inl \
  /usr/local/include/glm/detail/../mat4x2.hpp \
  /usr/local/include/glm/detail/type_mat4x2.hpp \
  /usr/local/include/glm/detail/type_mat4x2.inl \
  /usr/local/include/glm/detail/../mat4x3.hpp \
  /usr/local/include/glm/detail/type_mat4x3.hpp \
  /usr/local/include/glm/detail/type_mat4x3.inl \
  /usr/local/include/glm/detail/../mat4x4.hpp \
  /usr/local/include/glm/detail/type_mat4x4.hpp \
  /usr/local/include/glm/detail/type_mat4x4.inl \
  /usr/local/include/glm/detail/type_mat4x4_simd.inl \
  /usr/local/include/glm/detail/func_matrix.inl \
  /usr/local/include/glm/detail/../geometric.hpp \
  /usr/local/include/glm/detail/func_geometric.hpp \
  /usr/local/include/glm/detail/func_geometric.inl \
  /usr/local/include/glm/detail/func_exponential.hpp \
  /usr/local/include/glm/detail/type_vec1.hpp \
  /usr/local/include/glm/detail/type_vec1.inl \
  /usr/local/include/glm/detail/func_exponential.inl \
  /usr/local/include/glm/detail/func_vector_relational.hpp \
  /usr/local/include/glm/detail/func_vector_relational.inl \
  /usr/local/include/glm/detail/_vectorize.hpp \
  /usr/local/include/glm/detail/func_common.hpp \
  /usr/local/include/glm/detail/func_common.inl \
  /usr/local/include/glm/mat2x3.hpp /usr/local/include/glm/mat2x4.hpp \
  /usr/local/include/glm/mat3x2.hpp /usr/local/include/glm/mat3x3.hpp \
  /usr/local/include/glm/mat3x4.hpp /usr/local/include/glm/mat4x2.hpp \
  /usr/local/include/glm/mat4x3.hpp /usr/local/include/glm/mat4x4.hpp \
  /usr/local/include/glm/trigonometric.hpp \
  /usr/local/include/glm/detail/func_trigonometric.hpp \
  /usr/local/include/glm/detail/func_trigonometric.inl \
  /usr/local/include/glm/exponential.hpp \
  /usr/local/include/glm/common.hpp /usr/local/include/glm/packing.hpp \
  /usr/local/include/glm/detail/func_packing.hpp \
  /usr/local/include/glm/detail/func_packing.inl \
  /usr/local/include/glm/detail/type_half.hpp \
  /usr/local/include/glm/detail/type_half.inl \
  /usr/local/include/glm/geometric.hpp /usr/local/include/glm/matrix.hpp \
  /usr/local/include/glm/vector_relational.hpp \
  /usr/local/include/glm/integer.hpp \
  /usr/local/include/glm/detail/func_integer.hpp \
  /usr/local/include/glm/detail/func_integer.inl \
  /usr/local/include/glm/gtc/matrix_transform.hpp \
  /usr/local/include/glm/gtc/../mat4x4.hpp \
  /usr/local/include/glm/gtc/../vec2.hpp \
  /usr/local/include/glm/gtc/../vec3.hpp \
  /usr/local/include/glm/gtc/../vec4.hpp \
  /usr/local/include/glm/gtc/../gtc/constants.hpp \
  /usr/local/include/glm/gtc/../detail/setup.hpp \
  /usr/local/include/glm/gtc/constants.inl \
  /usr/local/include/glm/gtc/matrix_transform.inl \
  /usr/local/include/glm/gtc/../geometric.hpp \
  /usr/local/include/glm/gtc/../trigonometric.hpp \
  /usr/local/include/glm/gtc/../matrix.hpp \
  /usr/local/include/glm/gtc/type_ptr.hpp \
  /usr/local/include/glm/gtc/../gtc/quaternion.hpp \
  /usr/local/include/glm/gtc/../mat3x3.hpp \
  /usr/local/include/glm/gtc/quaternion.inl \
  /usr/local/include/glm/gtc/../exponential.hpp \
  /usr/local/include/glm/gtc/../mat2x2.hpp \
  /usr/local/include/glm/gtc/../mat2x3.hpp \
  /usr/local/include/glm/gtc/../mat2x4.hpp \
  /usr/local/include/glm/gtc/../mat3x2.hpp \
  /usr/local/include/glm/gtc/../mat3x4.hpp \
  /usr/local/include/glm/gtc/../mat4x2.hpp \
  /usr/local/include/glm/gtc/../mat4x3.hpp \
  /usr/local/include/glm/gtc/type_ptr.inl src/util.hpp src/stb_image.h
player.o: src/player.cpp /usr/local/include/glm/glm.hpp \
  /usr/local/include/glm/detail/_fixes.hpp \
  /usr/local/include/glm/fwd.hpp \
  /usr/local/include/glm/detail/type_int.hpp \
  /usr/local/include/glm/detail/setup.hpp \
  /usr/local/include/glm/detail/../simd/platform.h \
  /usr/local/include/glm/detail/type_float.hpp \
  /usr/local/include/glm/detail/type_vec.hpp \
  /usr/local/include/glm/detail/precision.hpp \
  /usr/local/include/glm/detail/type_mat.hpp \
  /usr/local/include/glm/vec2.hpp \
  /usr/local/include/glm/detail/type_vec2.hpp \
  /usr/local/include/glm/detail/type_vec2.inl \
  /usr/local/include/glm/vec3.hpp \
  /usr/local/include/glm/detail/type_vec3.hpp \
  /usr/local/include/glm/detail/type_vec3.inl \
  /usr/local/include/glm/vec4.hpp \
  /usr/local/include/glm/detail/type_vec4.hpp \
  /usr/local/include/glm/detail/type_vec4.inl \
  /usr/local/include/glm/mat2x2.hpp \
  /usr/local/include/glm/detail/type_mat2x2.hpp \
  /usr/local/include/glm/detail/../fwd.hpp \
  /usr/local/include/glm/detail/type_mat2x2.inl \
  /usr/local/include/glm/detail/func_matrix.hpp \
  /usr/local/include/glm/detail/../detail/precision.hpp \
  /usr/local/include/glm/detail/../detail/setup.hpp \
  /usr/local/include/glm/detail/../detail/type_mat.hpp \
  /usr/local/include/glm/detail/../vec2.hpp \
  /usr/local/include/glm/detail/../vec3.hpp \
  /usr/local/include/glm/detail/../vec4.hpp \
  /usr/local/include/glm/detail/../mat2x2.hpp \
  /usr/local/include/glm/detail/../mat2x3.hpp \
  /usr/local/include/glm/detail/type_mat2x3.hpp \
  /usr/local/include/glm/detail/type_mat2x3.inl \
  /usr/local/include/glm/detail/../mat2x4.hpp \
  /usr/local/include/glm/detail/type_mat2x4.hpp \
  /usr/local/include/glm/detail/type_mat2x4.inl \
  /usr/local/include/glm/detail/../mat3x2.hpp \
  /usr/local/include/glm/detail/type_mat3x2.hpp \
  /usr/local/include/glm/detail/type_mat3x2.inl \
  /usr/local/include/glm/detail/../mat3x3.hpp \
  /usr/local/include/glm/detail/type_mat3x3.hpp \
  /usr/local/include/glm/detail/type_mat3x3.inl \
  /usr/local/include/glm/detail/../mat3x4.hpp \
  /usr/local/include/glm/detail/type_mat3x4.hpp \
  /usr/local/include/glm/detail/type_mat3x4.inl \
  /usr/local/include/glm/detail/../mat4x2.hpp \
  /usr/local/include/glm/detail/type_mat4x2.hpp \
  /usr/local/include/glm/detail/type_mat4x2.inl \
  /usr/local/include/glm/detail/../mat4x3.hpp \
  /usr/local/include/glm/detail/type_mat4x3.hpp \
  /usr/local/include/glm/detail/type_mat4x3.inl \
  /usr/local/include/glm/detail/../mat4x4.hpp \
  /usr/local/include/glm/detail/type_mat4x4.hpp \
  /usr/local/include/glm/detail/type_mat4x4.inl \
  /usr/local/include/glm/detail/type_mat4x4_simd.inl \
  /usr/local/include/glm/detail/func_matrix.inl \
  /usr/local/include/glm/detail/../geometric.hpp \
  /usr/local/include/glm/detail/func_geometric.hpp \
  /usr/local/include/glm/detail/func_geometric.inl \
  /usr/local/include/glm/detail/func_exponential.hpp \
  /usr/local/include/glm/detail/type_vec1.hpp \
  /usr/local/include/glm/detail/type_vec1.inl \
  /usr/local/include/glm/detail/func_exponential.inl \
  /usr/local/include/glm/detail/func_vector_relational.hpp \
  /usr/local/include/glm/detail/func_vector_relational.inl \
  /usr/local/include/glm/detail/_vectorize.hpp \
  /usr/local/include/glm/detail/func_common.hpp \
  /usr/local/include/glm/detail/func_common.inl \
  /usr/local/include/glm/mat2x3.hpp /usr/local/include/glm/mat2x4.hpp \
  /usr/local/include/glm/mat3x2.hpp /usr/local/include/glm/mat3x3.hpp \
  /usr/local/include/glm/mat3x4.hpp /usr/local/include/glm/mat4x2.hpp \
  /usr/local/include/glm/mat4x3.hpp /usr/local/include/glm/mat4x4.hpp \
  /usr/local/include/glm/trigonometric.hpp \
  /usr/local/include/glm/detail/func_trigonometric.hpp \
  /usr/local/include/glm/detail/func_trigonometric.inl \
  /usr/local/include/glm/exponential.hpp \
  /usr/local/include/glm/common.hpp /usr/local/include/glm/packing.hpp \
  /usr/local/include/glm/detail/func_packing.hpp \
  /usr/local/include/glm/detail/func_packing.inl \
  /usr/local/include/glm/detail/type_half.hpp \
  /usr/local/include/glm/detail/type_half.inl \
  /usr/local/include/glm/geometric.hpp /usr/local/include/glm/matrix.hpp \
  /usr/local/include/glm/vector_relational.hpp \
  /usr/local/include/glm/integer.hpp \
  /usr/local/include/glm/detail/func_integer.hpp \
  /usr/local/include/glm/detail/func_integer.inl \
  /usr/local/include/glm/gtc/matrix_transform.hpp \
  /usr/local/include/glm/gtc/../mat4x4.hpp \
  /usr/local/include/glm/gtc/../vec2.hpp \
  /usr/local/include/glm/gtc/../vec3.hpp \
  /usr/local/include/glm/gtc/../vec4.hpp \
  /usr/local/include/glm/gtc/../gtc/constants.hpp \
  /usr/local/include/glm/gtc/../detail/setup.hpp \
  /usr/local/include/glm/gtc/constants.inl \
  /usr/local/include/glm/gtc/matrix_transform.inl \
  /usr/local/include/glm/gtc/../geometric.hpp \
  /usr/local/include/glm/gtc/../trigonometric.hpp \
  /usr/local/include/glm/gtc/../matrix.hpp \
  /usr/local/include/glm/gtc/type_ptr.hpp \
  /usr/local/include/glm/gtc/../gtc/quaternion.hpp \
  /usr/local/include/glm/gtc/../mat3x3.hpp \
  /usr/local/include/glm/gtc/quaternion.inl \
  /usr/local/include/glm/gtc/../exponential.hpp \
  /usr/local/include/glm/gtc/../mat2x2.hpp \
  /usr/local/include/glm/gtc/../mat2x3.hpp \
  /usr/local/include/glm/gtc/../mat2x4.hpp \
  /usr/local/include/glm/gtc/../mat3x2.hpp \
  /usr/local/include/glm/gtc/../mat3x4.hpp \
  /usr/local/include/glm/gtc/../mat4x2.hpp \
  /usr/local/include/glm/gtc/../mat4x3.hpp \
  /usr/local/include/glm/gtc/type_ptr.inl src/player.hpp src/world.hpp \
  src/util.hpp
world.o: src/world.cpp src/world.hpp /usr/local/include/glm/glm.hpp \
  /usr/local/include/glm/detail/_fixes.hpp \
  /usr/local/include/glm/fwd.hpp \
  /usr/local/include/glm/detail/type_int.hpp \
  /usr/local/include/glm/detail/setup.hpp \
  /usr/local/include/glm/detail/../simd/platform.h \
  /usr/local/include/glm/detail/type_float.hpp \
  /usr/local/include/glm/detail/type_vec.hpp \
  /usr/local/include/glm/detail/precision.hpp \
  /usr/local/include/glm/detail/type_mat.hpp \
  /usr/local/include/glm/vec2.hpp \
  /usr/local/include/glm/detail/type_vec2.hpp \
  /usr/local/include/glm/detail/type_vec2.inl \
  /usr/local/include/glm/vec3.hpp \
  /usr/local/include/glm/detail/type_vec3.hpp \
  /usr/local/include/glm/detail/type_vec3.inl \
  /usr/local/include/glm/vec4.hpp \
  /usr/local/include/glm/detail/type_vec4.hpp \
  /usr/local/include/glm/detail/type_vec4.inl \
  /usr/local/include/glm/mat2x2.hpp \
  /usr/local/include/glm/detail/type_mat2x2.hpp \
  /usr/local/include/glm/detail/../fwd.hpp \
  /usr/local/include/glm/detail/type_mat2x2.inl \
  /usr/local/include/glm/detail/func_matrix.hpp \
  /usr/local/include/glm/detail/../detail/precision.hpp \
  /usr/local/include/glm/detail/../detail/setup.hpp \
  /usr/local/include/glm/detail/../detail/type_mat.hpp \
  /usr/local/include/glm/detail/../vec2.hpp \
  /usr/local/include/glm/detail/../vec3.hpp \
  /usr/local/include/glm/detail/../vec4.hpp \
  /usr/local/include/glm/detail/../mat2x2.hpp \
  /usr/local/include/glm/detail/../mat2x3.hpp \
  /usr/local/include/glm/detail/type_mat2x3.hpp \
  /usr/local/include/glm/detail/type_mat2x3.inl \
  /usr/local/include/glm/detail/../mat2x4.hpp \
  /usr/local/include/glm/detail/type_mat2x4.hpp \
  /usr/local/include/glm/detail/type_mat2x4.inl \
  /usr/local/include/glm/detail/../mat3x2.hpp \
  /usr/local/include/glm/detail/type_mat3x2.hpp \
  /usr/local/include/glm/detail/type_mat3x2.inl \
  /usr/local/include/glm/detail/../mat3x3.hpp \
  /usr/local/include/glm/detail/type_mat3x3.hpp \
  /usr/local/include/glm/detail/type_mat3x3.inl \
  /usr/local/include/glm/detail/../mat3x4.hpp \
  /usr/local/include/glm/detail/type_mat3x4.hpp \
  /usr/local/include/glm/detail/type_mat3x4.inl \
  /usr/local/include/glm/detail/../mat4x2.hpp \
  /usr/local/include/glm/detail/type_mat4x2.hpp \
  /usr/local/include/glm/detail/type_mat4x2.inl \
  /usr/local/include/glm/detail/../mat4x3.hpp \
  /usr/local/include/glm/detail/type_mat4x3.hpp \
  /usr/local/include/glm/detail/type_mat4x3.inl \
  /usr/local/include/glm/detail/../mat4x4.hpp \
  /usr/local/include/glm/detail/type_mat4x4.hpp \
  /usr/local/include/glm/detail/type_mat4x4.inl \
  /usr/local/include/glm/detail/type_mat4x4_simd.inl \
  /usr/local/include/glm/detail/func_matrix.inl \
  /usr/local/include/glm/detail/../geometric.hpp \
  /usr/local/include/glm/detail/func_geometric.hpp \
  /usr/local/include/glm/detail/func_geometric.inl \
  /usr/local/include/glm/detail/func_exponential.hpp \
  /usr/local/include/glm/detail/type_vec1.hpp \
  /usr/local/include/glm/detail/type_vec1.inl \
  /usr/local/include/glm/detail/func_exponential.inl \
  /usr/local/include/glm/detail/func_vector_relational.hpp \
  /usr/local/include/glm/detail/func_vector_relational.inl \
  /usr/local/include/glm/detail/_vectorize.hpp \
  /usr/local/include/glm/detail/func_common.hpp \
  /usr/local/include/glm/detail/func_common.inl \
  /usr/local/include/glm/mat2x3.hpp /usr/local/include/glm/mat2x4.hpp \
  /usr/local/include/glm/mat3x2.hpp /usr/local/include/glm/mat3x3.hpp \
  /usr/local/include/glm/mat3x4.hpp /usr/local/include/glm/mat4x2.hpp \
  /usr/local/include/glm/mat4x3.hpp /usr/local/include/glm/mat4x4.hpp \
  /usr/local/include/glm/trigonometric.hpp \
  /usr/local/include/glm/detail/func_trigonometric.hpp \
  /usr/local/include/glm/detail/func_trigonometric.inl \
  /usr/local/include/glm/exponential.hpp \
  /usr/local/include/glm/common.hpp /usr/local/include/glm/packing.hpp \
  /usr/local/include/glm/detail/func_packing.hpp \
  /usr/local/include/glm/detail/func_packing.inl \
  /usr/local/include/glm/detail/type_half.hpp \
  /usr/local/include/glm/detail/type_half.inl \
  /usr/local/include/glm/geometric.hpp /usr/local/include/glm/matrix.hpp \
  /usr/local/include/glm/vector_relational.hpp \
  /usr/local/include/glm/integer.hpp \
  /usr/local/include/glm/detail/func_integer.hpp \
  /usr/local/include/glm/detail/func_integer.inl \
  /usr/local/include/glm/gtc/matrix_transform.hpp \
  /usr/local/include/glm/gtc/../mat4x4.hpp \
  /usr/local/include/glm/gtc/../vec2.hpp \
  /usr/local/include/glm/gtc/../vec3.hpp \
  /usr/local/include/glm/gtc/../vec4.hpp \
  /usr/local/include/glm/gtc/../gtc/constants.hpp \
  /usr/local/include/glm/gtc/../detail/setup.hpp \
  /usr/local/include/glm/gtc/constants.inl \
  /usr/local/include/glm/gtc/matrix_transform.inl \
  /usr/local/include/glm/gtc/../geometric.hpp \
  /usr/local/include/glm/gtc/../trigonometric.hpp \
  /usr/local/include/glm/gtc/../matrix.hpp \
  /usr/local/include/glm/gtc/type_ptr.hpp \
  /usr/local/include/glm/gtc/../gtc/quaternion.hpp \
  /usr/local/include/glm/gtc/../mat3x3.hpp \
  /usr/local/include/glm/gtc/quaternion.inl \
  /usr/local/include/glm/gtc/../exponential.hpp \
  /usr/local/include/glm/gtc/../mat2x2.hpp \
  /usr/local/include/glm/gtc/../mat2x3.hpp \
  /usr/local/include/glm/gtc/../mat2x4.hpp \
  /usr/local/include/glm/gtc/../mat3x2.hpp \
  /usr/local/include/glm/gtc/../mat3x4.hpp \
  /usr/local/include/glm/gtc/../mat4x2.hpp \
  /usr/local/include/glm/gtc/../mat4x3.hpp \
  /usr/local/include/glm/gtc/type_ptr.inl src/util.hpp \
  src/PerlinNoise.hpp
glad.o: src/glad.c src/glad.h
