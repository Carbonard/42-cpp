#include "VectorBlock.hpp"
#include <iostream>

VectorBlock::VectorBlock()
{}

VectorBlock::VectorBlock(const VectorBlock &other): _v(other._v)
{}

VectorBlock &VectorBlock::operator=(const VectorBlock &other)
{
	this->_v.operator=(other._v);
	return *this;
}

VectorBlock::~VectorBlock()
{}

VectorBlock::VectorBlock(int* n): _v(1, n)
{}

VectorBlock::VectorBlock(const VectorBlock& a, const VectorBlock& b): _v(a._v)
{
	for (size_t i = 0; i < b._v.size(); i++)
		this->_v.push_back(b._v[i]);
}

void VectorBlock::push(int* n)
{
	_v.push_back(n);
}

size_t VectorBlock::size() const
{
	return _v.size();
}

int VectorBlock::getValue() const
{
	return *_v.back();
}

void VectorBlock::swap(VectorBlock& a, VectorBlock& b)
{
	if (a._v.size() != b._v.size())
		throw std::runtime_error("Sizes do not match");
	int aux;
	for (size_t i = 0; i < a._v.size(); i++)
	{
		aux = *a._v[i];
		*a._v[i] = *b._v[i];
		*b._v[i] = aux;
	}
}
