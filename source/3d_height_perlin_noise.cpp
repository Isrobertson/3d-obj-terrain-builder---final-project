#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "header/classes/3d_object.h"
#include "header/3d_height_perlin_noise.h"

/*
	 this file determines the height of each vertice along the terrain to create formations

	 -- source file not working correctly but will keep for refactoring later --
*/

void determineVertexHeight(Vertexlist& vList)
{
	int id = 0;
	int randNum = 0;
	int perlinArray[100] = { 0 };

	std::vector<Vertex> *pVlist = vList.getVertexListByPointer();

	// create a perlin noise array for terrain generation

	srand(time(0));

	for (int i = 0; i < 100; i++)
	{
		perlinArray[i] = (rand() % 10) + 1;
	}

	int x = 0;
	for (Vertex v : *pVlist)
	{
		// generate height
		v.setY(perlinArray[(rand() % 100) + 1]);
	}

	int i = 0;
	// debug
	for (Vertex v : vList.getVertexList())
	{
		std::cout << "\nY: " << v.getY();
		if (i > 50)
		{
			break;
		}
		else
			i++;
	}
}
