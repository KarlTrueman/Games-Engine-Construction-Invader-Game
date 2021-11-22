#pragma once
class Rectangle
{
public:
	int left{ 0 }, right, top, bottom;

	Rectangle() = default;

	Rectangle(int l, int r, int t, int b) :
		left(l), right(r), top(t), bottom(b) {}

	int width() const { return right - left; }
	int height() const { return bottom - top; }
	void Translate(int dx, int dy)
	{
		left += dx;
		right += dx;
		top += dy;
		bottom += dy;
	}

	void ClipTo(const Rectangle& other)
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
};

