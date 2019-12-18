#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));


	//MAP LIMITS

	//right wall
	CreateBox(0, { 0, 1, 0 }, { -20, 1, MAP_LENGHT/2 }, { 1,50,MAP_LENGHT +20}, Sky);
	//left wall
	CreateBox(0, { 0, 1, 0 }, { 20, 1, MAP_LENGHT/2 }, { 1,50,MAP_LENGHT +20}, Sky);
	//floor wall
	CreateBox(0, { 0, 1, 0 }, { 0, 1, MAP_LENGHT / 2 }, { 40,1,MAP_LENGHT +20}, Grass);
	//back start wall
	CreateBox(0, { 0, 1, 0 }, { 0, 1, -10}, { 40,50,1 }, Sky);
	//end wall
	CreateBox(0, { 0, 1, 0 }, { 0, 1, MAP_LENGHT }, { 40,50,1 }, Green);
	//.......................................................................

	//MAP OBSTACLES

	//ramps
	CreateBox(-10, { 1, 0, 0 }, { 0, 1, 100 }, { 40,1,20 }, Gray);
	CreateBox(-30, { 1, 0, 0 }, { 0, 1, 950 }, { 40,1,20 }, Gray);
	//trees
	for (float i = 0; i < 8; i++)
	{
		float distance = i * 100;
		CreateBox(0, { 0, 1, 0 }, { 10, 3, distance }, { 1,10,1 }, Brown);

		CreateBox(0, { 0, 1, 0 }, { -5, 3, distance +20 }, { 1,10,1 }, Brown);

		CreateBox(0, { 0, 1, 0 }, { -5, 3, distance +70 }, { 1,10,1 }, Brown);

		CreateBox(0, { 0, 1, 0 }, { 5, 3, distance +120 }, { 1,10,1 }, Brown);

		CreateBox(0, { 0, 1, 0 }, { -15, 3, distance +110 }, { 1,10,1 }, Brown);

		CreateBox(0, { 0, 1, 0 }, { 15, 3, distance + 140 }, { 1,10,1 }, Brown);

		CreateBox(0, { 0, 1, 0 }, { 0, 3, distance + 160 }, { 1,10,1 }, Brown);
	}



	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	//Plane p(0, 1, 0, 0);
	//p.axis = true;
	//p.Render();

	//MAP LIMITS

	//right wall
	RenderBox(0, { 0, 1, 0 }, { -20, 1, MAP_LENGHT / 2 }, { 1,50,MAP_LENGHT +20}, Sky);
	//left wall
	RenderBox(0, { 0, 1, 0 }, { 20, 1, MAP_LENGHT / 2 }, { 1,50,MAP_LENGHT +20}, Sky);
	//floor wall
	RenderBox(0, { 0, 1, 0 }, { 0, 1, MAP_LENGHT / 2 }, { 40,1,MAP_LENGHT +20}, Grass);
	//back start wall
	RenderBox(0, { 0, 1, 0 }, { 0, 1, -10}, { 40,50,1 }, Sky);
	//end wall
	RenderBox(0, { 0, 1, 0 }, { 0, 1, MAP_LENGHT }, { 40,50,1 }, Green);
	//.......................................................................

	//MAP OBSTACLES

	//ramps
	RenderBox(-10, { 1, 0, 0 }, { 0, 1, 100 }, { 40,1,20 }, Gray);
	RenderBox(-30, { 1, 0, 0 }, { 0, 1, 950 }, { 40,1,20 }, Gray);
	//trees
	for (float i = 0; i < 8; i++)
	{
		float distance = i * 100;
		RenderBox(0, { 0, 1, 0 }, { 10, 3, distance }, { 1,10,1 }, Brown);
		RenderBox(0, { 0, 1, 0 }, { 10, 9, distance }, { 6,6,6 }, Deep_Green);

		RenderBox(0, { 0, 1, 0 }, { -5, 3, distance + 20 }, { 1,10,1 }, Brown);
		RenderBox(0, { 0, 1, 0 }, { -5, 9, distance + 20 }, { 6,6,6 }, Deep_Green);

		RenderBox(0, { 0, 1, 0 }, { -5, 3, distance + 70 }, { 1,10,1 }, Brown);
		RenderBox(0, { 0, 1, 0 }, { -5, 9, distance + 70 }, { 6,6,6 }, Deep_Green);

		RenderBox(0, { 0, 1, 0 }, { 5, 3, distance + 120 }, { 1,10,1 }, Brown);
		RenderBox(0, { 0, 1, 0 }, { 5, 9, distance + 120 }, { 6,6,6 }, Deep_Green);

		RenderBox(0, { 0, 1, 0 }, { -15, 3, distance + 110 }, { 1,10,1 }, Brown);
		RenderBox(0, { 0, 1, 0 }, { -15, 9, distance + 110 }, { 6,6,6 }, Deep_Green);

		RenderBox(0, { 0, 1, 0 }, { 15, 3, distance + 140 }, { 1,10,1 }, Brown);
		RenderBox(0, { 0, 1, 0 }, { 15, 9, distance + 140 }, { 6,6,6 }, Deep_Green);

		RenderBox(0, { 0, 1, 0 }, { 0, 3, distance + 160 }, { 1,10,1 }, Brown);
		RenderBox(0, { 0, 1, 0 }, { 0, 9, distance + 160 }, { 6,6,6 }, Deep_Green);
	}
	




	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

void ModuleSceneIntro::CreateBox(int degrees, vec3 angle, vec3 offset, vec3 size, Color color) {

	Cube cube;
	cube.size = size;
	cube.SetPos(offset.x, offset.y, offset.z);
	cube.color = color;
	cube.SetRotation(degrees, angle);
	App->physics->AddBody(cube, 0);
	cube.Render();
}

void ModuleSceneIntro::RenderBox(int degrees, vec3 angle, vec3 offset, vec3 size, Color color) {

	Cube cube;
	cube.size = size;
	cube.SetPos(offset.x, offset.y, offset.z);
	cube.color = color;
	cube.SetRotation(degrees, angle);
	cube.Render();
}
