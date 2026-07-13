#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
public:
	Counter();
	Counter(int value);
	void increase1();
	void decrease1();
	int getValue();
private:
	int count;
};

#endif // !COUNTER_H