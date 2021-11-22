#pragma once
class Entity
{
public:
	Entity() = default;
	virtual ~Entity() = default;

	virtual void Update() = 0;
};

