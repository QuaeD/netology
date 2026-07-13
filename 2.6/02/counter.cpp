#include "counter.h"

Counter::Counter() {
	count = 1;
}

Counter::Counter(int value) : count{ value }
{}

void Counter::increase1() {
	count++;
}

void Counter::decrease1() {
	count--;
}

int Counter::getValue() {
	return count;
}