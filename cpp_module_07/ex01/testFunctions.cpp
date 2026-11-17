int meanSum, meanSize;

float getMean(void)
{
	return (float)meanSum / meanSize;
}

void resetMean(void)
{
	meanSum = 0;
	meanSize = 0;
}
