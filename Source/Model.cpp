#include "Model.h"

Model::Model()
{
}

Model::~Model() noexcept
{
}

const std::vector<Polygon3D>& Model::GetPolygons()
{
	return _polygons;
}

const std::vector<Vertex>& Model::GetVertices()
{
	return _vertices;
}

const std::vector<Vertex>& Model::GetTransformed()
{
	return _transformed;
}

size_t Model::GetPolygonCount() const
{
	return _polygons.size();
}

size_t Model::GetVertexCount() const
{
	return _vertices.size();
}

void Model::AddVertex(float x, float y, float z)
{
	Vertex newVertex(x, y, z, 1);
	_vertices.push_back(newVertex);
}

void Model::AddPolygon(int i0, int i1, int i2)
{
	Polygon3D newPolygon(i0, i1, i2);
	_polygons.push_back(newPolygon);
}

void Model::ApplyTransformToLocalVertices(const Matrix& transform)
{

	_transformed.clear();
	for (int i = 0; i < _vertices.size(); i++) {
		_transformed.push_back(transform * _vertices[i]);
	}
}

void Model::ApplyTransformToTransformedVertices(const Matrix& transform)
{
	for (int i = 0; i < _transformed.size(); i++) {
		_transformed[i] = transform * _transformed[i];
	}
}

void Model::Dehomogonize()
{
	for (int i = 0; i < _transformed.size(); i++) {
		_transformed[i].SetX(_transformed[i].GetX() / _transformed[i].GetW());
		_transformed[i].SetY(_transformed[i].GetY() / _transformed[i].GetW());
		_transformed[i].SetZ(_transformed[i].GetZ() / _transformed[i].GetW());
		_transformed[i].SetW(_transformed[i].GetW() / _transformed[i].GetW());
	}
}
