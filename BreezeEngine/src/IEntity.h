#pragma once

class IEntity
{
public:
	virtual void Render() = 0;
	virtual void Update() = 0;
	virtual void Clean() = 0;
};