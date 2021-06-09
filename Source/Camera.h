#pragma once
#include "Matrix.h"
#include <math.h>
class Camera
{
public:
	Camera(float xRotation, float yRotation, float zRotation, const Vertex& position);

	// Mutators
	void SetXRotation(const float xRotation);
	void SetYRotation(const float yRotation);
	void SetZRotation(const float zRotation);
	void SetPosition(const Vertex& position);
	Matrix GetCameraMatrix() const;

private:
	float _xRotation;
	float _yRotation;
	float _zRotation;

	Vertex _position;

	Matrix _xMatrix;
	Matrix _yMatrix;
	Matrix _zMatrix;

	Matrix _negativeMatrix;
	Matrix _cameraMatrix;
};

