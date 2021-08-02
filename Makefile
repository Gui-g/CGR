all:

run_snowman:
	gcc snowman.c -lglut -lGL -lGLU -lm -o snowman
	./snowman

run_castle:
	gcc castle.c -lglut -lGL -lGLU -lm -o castle
	./castle

run_robot:
	gcc robot.c -lglut -lGL -lGLU -lm -o robot
	./robot

run_final_form:
	g++ robot_h.cpp -o robot -lglut -lGL -lGLU -lm
	./robot