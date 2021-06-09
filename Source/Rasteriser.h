#pragma once
#include "Framework.h"
#include "Vertex.h"
#include "Matrix.h"
#include "MD2Loader.h"
#include "Camera.h"
#include "Model.h"
#include <math.h>

class Rasteriser : public Framework
{
public:
	bool Initialise();

	void Render(const Bitmap& bitmap);
	void Update(const Bitmap& bitmap);
	void GeneratePerspectiveMatrix(float x, float aspectRatio);
	void GenerateViewMatrix(float x, float width, float height);

	void DrawWireFrame(const Bitmap& bitmap);

private:
	double _x{ 0 };
	double _y{ 0 };

	Model _model;

	Matrix _PerspectiveMatrix;
	Matrix _ViewMatrix;
	Matrix _ModelTransformation;
};

