#pragma once
#include <vector>
#include "Polygon3D.h"
#include "Vertex.h"
#include "Matrix.h"
using namespace std;


class Model
{
public:
	Model();
	~Model();
	// Accessors
	const vector<Polygon3D>& GetPolygons();
	const vector<Vertex>& GetVertices();
	const std::vector<Vertex>& GetTransformed();

	size_t GetPolygonCount() const;
	size_t GetVertexCount() const;

	void AddVertex(float x, float y, float z);
	void AddPolygon(int i0, int i1, int i2);

	void ApplyTransformToLocalVertices(const Matrix& transform);
	void ApplyTransformToTransformedVertices(const Matrix& transform);

	void Dehomogonize();


private:
	vector<Polygon3D> _polygons;

	vector<Vertex> _vertices;
	vector<Vertex> _transformed;
	vector<Vertex> _updatedtranformed;

};

