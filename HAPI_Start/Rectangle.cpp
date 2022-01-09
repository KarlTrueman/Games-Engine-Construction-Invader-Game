#include "Rectangle.h"

void Rectangle::Translate(int dx, int dy)
{
	left += dx;
	right += dx;
	top += dy;
	bottom += dy;
}

void Rectangle::ClipTo(const Rectangle& other)
{
	if (left < other.left)
		left = other.left;

	if (right > other.right)
		right = other.right;

	if (top < other.top)
		top = other.top;

	if (bottom > other.bottom)
		bottom = other.bottom;
}

bool Rectangle::Inside(const Rectangle& other)
{
	if (left < other.left) { return false; }
	if (top < other.top) { return false; }
	if (right > other.right) { return false; }
	if (bottom > other.bottom) { return false; }
	return false;
}

bool Rectangle::Outside(const Rectangle& other)
{
	if (left > other.right) { return true; }
	if (top > other.bottom) { return true; }
	if (right < other.left) { return true; }
	if (bottom < other.top) { return true; }
	return false;
}

Rectangle::~Rectangle()
{
}
