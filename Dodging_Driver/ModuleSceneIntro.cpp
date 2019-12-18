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
	CreateBox(0, { 0, 1, 0 }, { -20, 1, MAP_LENGHT/2 }, { 1,50,MAP_LENGHT +20}, White);
	//left wall
	CreateBox(0, { 0, 1, 0 }, { 20, 1, MAP_LENGHT/2 }, { 1,50,MAP_LENGHT +20}, White);
	//floor wall
	CreateBox(0, { 0, 1, 0 }, { 0, 1, MAP_LENGHT / 2 }, { 40,1,MAP_LENGHT +20}, White);
	//back start wall
	CreateBox(0, { 0, 1, 0 }, { 0, 1, -10}, { 40,50,1 }, White);
	//end wall
	CreateBox(0, { 0, 1, 0 }, { 0, 1, MAP_LENGHT }, { 40,50,1 }, Green);
	//.......................................................................

	//MAP OBSTACLES

	//ramp
	CreateBox(-10, { 1, 0, 0 }, { 0, 1, 100 }, { 40,1,20 }, Purple);


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
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	//MAP LIMITS

	//right wall
	RenderBox(0, { 0, 1, 0 }, { -20, 1, MAP_LENGHT / 2 }, { 1,50,MAP_LENGHT +20}, White);
	//left wall
	RenderBox(0, { 0, 1, 0 }, { 20, 1, MAP_LENGHT / 2 }, { 1,50,MAP_LENGHT +20}, White);
	//floor wall
	RenderBox(0, { 0, 1, 0 }, { 0, 1, MAP_LENGHT / 2 }, { 40,1,MAP_LENGHT +20}, White);
	//back start wall
	RenderBox(0, { 0, 1, 0 }, { 0, 1, -10}, { 40,50,1 }, White);
	//end wall
	RenderBox(0, { 0, 1, 0 }, { 0, 1, MAP_LENGHT }, { 40,50,1 }, Green);
	//.......................................................................

	//MAP OBSTACLES

	//ramp
	RenderBox(-10, { 1, 0, 0 }, { 0, 1, 100 }, { 40,1,20 }, Purple);


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
