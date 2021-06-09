#include "Polygon3D.h"

Polygon3D::Polygon3D()
{
	_indices[0] = 0;
	_indices[1] = 0;
	_indices[2] = 0;
}

Polygon3D::Polygon3D(int index0, int index1, int index2)
{
	_indices[0] = index0;
	_indices[1] = index1;
	_indices[2] = index2;
}

Polygon3D::~Polygon3D()
{
}

Polygon3D::Polygon3D(const Polygon3D& p)
{
	_indices[0] = p.GetIndex(0);
	_indices[1] = p.GetIndex(1);
	_indices[2] = p.GetIndex(2);
}

int Polygon3D::GetIndex(int variable) const
{
	return _indices[variable];
}

Polygon3D& Polygon3D::operator=(const Polygon3D& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 3; i++)
		{
			_indices[i] = rhs.GetIndex(i);
		}
	}
	return *this;
}
