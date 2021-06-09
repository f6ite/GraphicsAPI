#include "Rasteriser.h"

Rasteriser app;

bool Rasteriser::Initialise()
{
	if (!MD2Loader::LoadModel("marvin.md2", _model,
		&Model::AddPolygon,
		&Model::AddVertex))
	{
		return false;
	}

	_ModelTransformation = Matrix{ 1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1 };

	return true;
}

void Rasteriser::Render(const Bitmap& bitmap)
{
	Camera camera(0, 0, 0, { 0.0f, 0.0f, -50.0f, 1.0f });

	bitmap.Clear(RGB(255, 255, 255));
	_model.ApplyTransformToLocalVertices(_ModelTransformation);
	_model.ApplyTransformToTransformedVertices(camera.GetCameraMatrix());
	_model.ApplyTransformToTransformedVertices(_PerspectiveMatrix);
	_model.ApplyTransformToTransformedVertices(_ViewMatrix);

	_model.Dehomogonize();
	DrawWireFrame(bitmap);
}

void Rasteriser::Update(const Bitmap& bitmap)
{
	_ModelTransformation = _ModelTransformation * Matrix{ cosf(0.1f), 0, sinf(0.1f), 0,
						 0, 1, 0, 0,
						 -sinf(0.1f), 0, cosf(0.1f), 0,
						 0, 0, 0, 1 };

	GeneratePerspectiveMatrix(1.0f, float(bitmap.GetWidth()) / float(bitmap.GetHeight()));
	GenerateViewMatrix(1.0f, float(bitmap.GetWidth()), float(bitmap.GetHeight()));
}

void Rasteriser::GeneratePerspectiveMatrix(float x, float aspectRatio)
{
	_PerspectiveMatrix = { x / aspectRatio, 0, 0, 0,
						  0,x,0,0,
						  0,0,x,0,
						  0,0,1,0 };

}

void Rasteriser::GenerateViewMatrix(float x, float width, float height)
{
	_ViewMatrix = { width / 2, 0, 0, width / 2,
					0, -height / 2, 0, height / 2,
					0, 0, x / 2, x / 2,
					0, 0, 0, 1 };
}

void Rasteriser::DrawWireFrame(const Bitmap& bitmap)
{
	HDC hdc = bitmap.GetDC();

	std::vector<Polygon3D> Polygons = _model.GetPolygons();
	std::vector<Vertex> Vertices = _model.GetTransformed();

	for (int i = 0; i < _model.GetPolygonCount(); i++) {
		MoveToEx(hdc, int(Vertices[Polygons[i].GetIndex(0)].GetX()), int(Vertices[Polygons[i].GetIndex(0)].GetY()), NULL);
		LineTo(hdc, int(Vertices[Polygons[i].GetIndex(1)].GetX()), int(Vertices[Polygons[i].GetIndex(1)].GetY()));
		LineTo(hdc, int(Vertices[Polygons[i].GetIndex(2)].GetX()), int(Vertices[Polygons[i].GetIndex(2)].GetY()));
		LineTo(hdc, int(Vertices[Polygons[i].GetIndex(0)].GetX()), int(Vertices[Polygons[i].GetIndex(0)].GetY()));
	}
}