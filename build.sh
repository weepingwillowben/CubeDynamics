#g++ -O3 -o bin/cl.exe -I "external\glm-0.9.7.1" -I "external\opencl-2.2" opencl_cell_update_main.cpp "C:/Windows/System32/OpenCL.dll"
#g++ -O3 -o bin/mygl.exe -I"external/glew-1.13.0/include" -I "external/glfw-3.1.2/include" -I "external\glm-0.9.7.1" -I "external\opencl-2.2" main.cpp cube_coords.cpp update.cpp display_ops.cpp  "C:/Windows/System32/OpenCL.dll" -L./lib64 -lglfw3 -lglew32 -lopengl32 -lgdi32
#g++ -O3 -Wno-deprecated-declarations -DOPENCL_ACCEL -o bin/run.exe -I"external/glew/" -I "external/glfw/"  -I "external/opencl-2.2" -I "external/" main.cpp opencl_cell_update_main.cpp cube_coords.cpp update.cpp display_ops.cpp "C:/Windows/System32/OpenCL.dll"  -L./lib -lglfw3 -lglew32 -lopengl32 -lgdi32
#g++ -O3 -Wno-deprecated-declarations -DOPENCL_ACCEL -DSAVE_TRIANGLES -o bin/save.exe -I "external/opencl-2.2" -I "external/" triangle_gen.cpp opencl_cell_update_main.cpp cube_coords.cpp update.cpp display_ops.cpp "C:/Windows/System32/OpenCL.dll"  -L./lib
g++ -O3 -flto -DSAVE_TRIANGLES -o bin/run.exe -I"external/glew/" -I "external/glfw/"  -I "external/opencl-2.2" -I "external/" main.cpp cube_coords.cpp  -L./lib -lglfw3 -lglew32 -lopengl32 -lgdi32
#g++ -O3 -D NO_GRAPHICS -o bin/cl.exe -I "external\glm-0.9.7.1" -I "external\opencl-2.2" opencl_cell_update_main.cpp cube_coords.cpp update.cpp display_ops.cpp  "C:/Windows/System32/OpenCL.dll"
