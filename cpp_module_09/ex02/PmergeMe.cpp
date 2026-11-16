#include "PmergeMe.hpp"
#include "VectorBlock.hpp"
#include <cmath>

// void print(t_vector& v, int n, int step)
// {
// 	std::cout <<n<<'('<<step<<')';
// 	for (size_t i = 0; i < v.size(); i++)
// 	{
// 		std::cout << (i%n?" ":" | ") << v[i];
// 	}
// 	std::cout << std::endl;
// }

// static void sortPairs(t_vvb& v)
// {
// 	for (size_t i = 0; i < v.size() / 2; i++)
// 		if (v[2*i].getValue() > v[2*i+1].getValue())
// 			VectorBlock::swap(v[2*i], v[2*i+1]);
// 		// else
// 			// std::cout << "already sorted" << v[2*i].getValue() << "<" << v[2*i+1].getValue() << "\n";
// }

// static void sortContainerRecursive(t_vvb& v);

// static void sortGreaterNumbers(t_vvb& v)
// {
// 	t_vvb newBlocks;

// 	for (size_t i = 0; i < v.size() / 2; i++)
// 		newBlocks.push_back(VectorBlock(v[2*i], v[2*i+1]));
// 	if (newBlocks.size() > 1)
// 		sortContainerRecursive(newBlocks);
// }

// static void insert(t_vvb& v, size_t i, size_t n)
// {
// 	for (size_t j = n ; j > i; j--)
// 	{
// 		// todo: optimize this(?)
// 		VectorBlock::swap(v[j-1], v[j]);
// 	}
// 	std::cout << "inserted: " << (i>0 ? v[i-1].getValue() : -1) << " < " << v[i].getValue() << " < " << (i < v.size()-1? v[i+1].getValue() : -1) << std::endl;
	
// }

// static size_t reinsertSorted(t_vvb& v, size_t n)
// {
// 	size_t bot = 0, top = n;
// 	size_t i;
// 	while (top != bot)
// 	{
// 		i = (bot+top+1)/2;
// 		if (i && v[i-1].getValue() > v[n].getValue()) // here I'm comparing with elements that are not in the main chain
// 			top = i-1;
// 		else if (v[i].getValue() < v[n].getValue())
// 			bot = i;
// 		else
// 		{
// 			insert(v, i, n);
// 			return i;
// 		}
// 	}
// 	insert(v, top, n);
// 	return top;
// }

// static void sortLesserNumbers(t_vvb& v)
// {
// 	std::cout << "ord: ";
// 	for (size_t i = 0; i < v.size(); i++)
// 		std::cout << v[i].getValue() << " ";
// 	std::cout << '\n';
// 	//todo: change order of reinsertions
// 	std::vector<size_t> remainingIndex;
// 	for (size_t i = 0; i < v.size(); i+=2)
// 		remainingIndex.push_back(i);
// 	size_t k = 2;
// 	size_t t_k_prev = 1, t_k;// t=0 is already inserted by construction
// 	std::cout << remainingIndex.size() << ": ";
// 	do
// 	{
// 		t_k = std::pow(2, k) - t_k_prev;
// 		for (size_t i = std::min(t_k, remainingIndex.size()); i > t_k_prev; i--)
// 		{
// 			std::cout << i << ' ';
// 			size_t old_index = remainingIndex[i-1];
// 			size_t new_index = reinsertSorted(v, remainingIndex[i-1]);
// 			for (size_t aux = 0; aux < remainingIndex.size(); aux++)
// 			{
// 				// std::cout << t << "...";
// 				if (remainingIndex[aux] >= new_index && remainingIndex[aux] <= old_index)
// 				{
// 					remainingIndex[aux]++;
// 					// std::cout << index[k] << "/" << v.size() << '\n';
// 				}
// 			}
// 		}
// 		t_k_prev = t_k;
// 		k++;
// 	} while (t_k < remainingIndex.size());
// 	std::cout << '\n';
// 	return;
// 	// With just this everything works fine:
// 	for (size_t i = 0; i < v.size(); i+=2)
// 		reinsertSorted(v, i);
// }

// static void sortContainerRecursive(t_vvb& v)
// {
// 	// std::cout << "SCR: " << v.size() << '\n';
// 	if (v.size() == 1)
// 		return;
// 	print(*G, G->size() / v.size() * 2,  1);
// 	sortPairs(v);
// 	print(*G, G->size() / v.size() * 2, 2);
// 	// printContainer(*G);
// 	sortGreaterNumbers(v);
// 	print(*G, G->size() / v.size() * 2, 3);
// 	sortLesserNumbers(v);
// 	print(*G, G->size() / v.size() * 2, 4);
// }

// void sortContainer(t_vector& c)
// {
// 	t_vvb v;
// 	G=&c;
// 	for (size_t i = 0; i < c.size(); i++)
// 		v.push_back(VectorBlock(&c[i]));

// 	sortContainerRecursive(v);
// }


Link::Link(int a, int b)
{
	max_number = std::max(a, b);
	max_link = NULL;
	min_link = NULL;
}

Link::Link(Link* a, Link* b)
{
	if (a->max_number > b->max_number)
	{
		max_number = a->max_number;
		max_link = a;
		min_link = b;
	}
	else
	{
		max_number = b->max_number;
		max_link = b;
		min_link = a;
	}
}

Link::~Link()
{}

// typedef std::vector<Link*> t_vLinks;

// void print(Link *l)
// {
// 	if (l->min_link)
// 	{
// 		std::cout << "(";
// 		print(l->min_link);
// 		std::cout << "-";
// 	}
// 	if (l->max_link)
// 	{
// 		print(l->max_link);
// 		std::cout << ")";
// 	}
// 	else
// 		std::cout << " " << l->max_number << " ";
// }

// void print(t_vLinks v)
// {
// 	for (size_t i = 0; i < v.size(); i++)
// 	{
// 		print(v[i]);
// 	}
// 	std::cout << '\n';
// }

// void insert (t_vLinks& sorted, Link* toInsert, size_t top)
// {
// 	// change to binary search and limit bounds:
// 	// size_t top = sorted.size();
// 	size_t bottom = 0;
// 	do
// 	{
// 		size_t mid = (top+bottom)/2;
// 		// if (mid == bottom)
// 		// 	std::cout << bottom << ", " << mid << ", " << top << '\n';
// 			// std::cout << sorted[bottom]->max_number << ", " << toInsert->max_number << ", " << sorted[top]->max_number << '\n';
// 		if ((mid==0 || toInsert->max_number > sorted[mid-1]->max_number)
// 			&& toInsert->max_number < sorted[mid]->max_number)
// 		{
// 			sorted.insert(sorted.begin()+mid, toInsert);
// 			return;
// 		}
// 		else if (toInsert->max_number > sorted[mid]->max_number)
// 			bottom = mid+1;
// 		else
// 			top = mid;
// 	}
// 	while (bottom < top);
// 	sorted.insert(sorted.begin() + top, toInsert);
// 	return;
// 	// if (toInsert->max_number < sorted.front()->max_number)
// 	// {
// 	// 	sorted.insert(sorted.begin(), toInsert);
// 	// 	return;
// 	// }
// 	// size_t i = 0;
// 	// while (i+1 < sorted.size())
// 	// {
// 	// 	if (toInsert->max_number > sorted[i]->max_number && toInsert->max_number < sorted[i+1]->max_number)
// 	// 	{
// 	// 		sorted.insert(sorted.begin()+i+1, toInsert);
// 	// 		return;
// 	// 	}
// 	// 	i++;
// 	// }
// 	// sorted.push_back(toInsert);
// }

// size_t getIndex(t_vLinks& v, Link* l)
// {
// 	for (size_t i = 0; i < v.size(); i++)
// 	{
// 		if (v[i] == l)
// 			return i+1;
// 	}
// 	return 0;
// }

// t_vLinks merge(t_vLinks& a, Link* leftover) // a is sorted by its max
// {
// 	t_vLinks sorted;
// 	sorted.push_back(a[0]->min_link);
// 	for (size_t i = 0; i < a.size(); i++)
// 		sorted.push_back(a[i]->max_link);
// 	// Change order of insertion here:
// 	for (size_t i = 1; i < a.size(); i++)
// 		insert(sorted, a[i]->min_link, sorted.size());
// 	if (leftover)
// 		insert(sorted, leftover, sorted.size());
// 	return sorted;
// }

// static void sortLinks(t_vLinks& v)
// {
// 	if (v.size() == 1)
// 		return;
// 	t_vLinks	a;
// 	Link*		leftover = NULL;

// 	for (size_t i = 0; i + 1 < v.size(); i+=2)
// 	{
// 		a.push_back(new Link(v[i], v[i+1])); // Create sorted linked pairs
// 	}
// 	if (v.size()%2 != 0)
// 		leftover = v.back();
// 	sortLinks(a);
// 	v = merge(a, leftover);
// 	for (t_vLinks::iterator i = a.begin(); i != a.end(); i++)
// 		delete *i;
// }

// void sortContainer(t_vector& c)
// {
// 	t_vLinks a;

// 	for (size_t i = 0; i < c.size(); i++)
// 		a.push_back(new Link(c[i], c[i]));
// 	sortLinks(a);
// 	for (size_t i = 0; i < c.size(); i++)
// 	{
// 		c[i] = a[i]->max_number;
// 		delete a[i];
// 	}
// }





// size_t getIndex(t_vLinks& v, Link* l)
// {
// 	for (size_t i = 0; i < v.size(); i++)
// 	{
// 		if (v[i] == l)
// 			return i+1;
// 	}
// 	return 0;
// }




// void sortContainer(t_list& c)
// {
// 	(void) c;
// }