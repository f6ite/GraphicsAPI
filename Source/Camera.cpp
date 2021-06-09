#include "Camera.h"

Camera::Camera(float xRotation, float yRotation, float zRotation, const Vertex& position)
{
	_xRotation = xRotation;
	_yRotation = yRotation;
	_zRotation = zRotation;
	_position = position;


	_xMatrix = { 1, 0, 0, 0,
					0, cosf(xRotation), sinf(xRotation), 0,
					0, -sinf(xRotation), cosf(xRotation), 0,
					0, 0, 0, 1 };
	_yMatrix = { cosf(yRotation), 0, -sinf(yRotation), 0,
				0, 1, 0, 0,
				sinf(yRotation), 0, cosf(yRotation), 0,
				0, 0, 0, 1 };
	_zMatrix = { cosf(zRotation), sinf(zRotation), 0, 0,
				-sinf(zRotation), cosf(zRotation), 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1 };
	_negativeMatrix = { 1, 0, 0, -position.GetX(),
						0, 1, 0, -position.GetY(),
						0, 0, 1, -position.GetZ(),
						0, 0, 0, 1 };

	_cameraMatrix = _xMatrix * _yMatrix * _zMatrix * _negativeMatrix;
}

void Camera::SetPosition(const Vertex& position)
{
	_position = position;
	_negativeMatrix = { 1, 0, 0, -position.GetX(),
						0, 1, 0, -position.GetY(),
						0, 0, 1, -position.GetZ(),
						0, 0, 0, 1 };
	_cameraMatrix = _xMatrix * _yMatrix * _zMatrix * _negativeMatrix;
}

void Camera::SetXRotation(const float xRotation)
{
	_xRotation = xRotation;
	_xMatrix = { 1, 0, 0, 0,
					0, cosf(xRotation), sinf(xRotation), 0,
					0, -sinf(xRotation), cosf(xRotation), 0,
					0, 0, 0, 1 };
	_cameraMatrix = _xMatrix * _yMatrix * _zMatrix * _negativeMatrix;
}

void Camera::SetYRotation(const float yRotation)
{
	_yRotation = yRotation;
	_yMatrix = { cosf(yRotation), 0, -sinf(yRotation), 0,
				0, 1, 0, 0,
				sinf(yRotation), 0, cosf(yRotation), 0,
				0, 0, 0, 1 };
	_cameraMatrix = _xMatrix * _yMatrix * _zMatrix * _negativeMatrix;
}

void Camera::SetZRotation(const float zRotation)
{
	_zRotation = zRotation;
	_zMatrix = { cosf(zRotation), sinf(zRotation), 0, 0,
				-sinf(zRotation), cosf(zRotation), 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1 };
	_cameraMatrix = _xMatrix * _yMatrix * _zMatrix * _negativeMatrix;
}

Matrix Camera::GetCameraMatrix() const
{
	return _cameraMatrix;
}


