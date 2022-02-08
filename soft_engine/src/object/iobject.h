#pragma once

//abstract base class 
class IObject
{
public:
	IObject() {};
	virtual ~IObject() {};

	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
	virtual void Clean() = 0;

};