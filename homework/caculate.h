#pragma once
#include <string>
class caculate
{
public:
	void reply(int);
	void solve();
	void getScore();
	void addToScore(int);
	void judge( int, int, int, int);
private:
	int score = 0;
};