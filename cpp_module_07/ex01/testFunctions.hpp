#ifndef TESTFUNCTIONS_HPP
#define TESTFUNCTIONS_HPP

template <typename T>
void addOne(T &var)
{
	var +=1;
}

template <typename T>
void addMean(const T &n)
{
	extern int meanSum;
	extern int meanSize;
	meanSum += static_cast<int>(n);
	meanSize++;
}

float getMean(void);
void resetMean(void);

#endif