#ifndef VECTORBLOCK_HPP
#define VECTORBLOCK_HPP

#include <vector>
#include <cstdlib>

class VectorBlock
{
private:
	std::vector<int*>	_v;

public:
	VectorBlock();
	VectorBlock(int* a);
	VectorBlock(const VectorBlock& a, const VectorBlock& b);
	VectorBlock(const VectorBlock &other);
	VectorBlock &operator=(const VectorBlock &other);
	~VectorBlock();

	void push(int* n);
	size_t size() const;
	int getValue() const;
	static void swap(VectorBlock& a, VectorBlock& b);
};

#endif
