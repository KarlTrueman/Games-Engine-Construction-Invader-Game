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
	void Translate(int dx, int dy);

	void ClipTo(const Rectangle& other);

	bool Inside(const Rectangle& other);
	bool Outside(const Rectangle& other);

	~Rectangle();
};

