#pragma once
#include "../physics/vector2d.h"

#define UNIT_MASS 1.0f
#define GRAVITY 9.8f

class RigidBody
{
public:
	RigidBody() : m_Mass{ UNIT_MASS },
				  m_Gravity{ GRAVITY },
				  m_Force{ Vector2D{ 0,0 } },
				  m_Friction{ Vector2D{ 0,0 } },
				  m_Position{ Vector2D{ 0,0 } },
				  m_Velocity{ Vector2D{ 0,0 } },
				  m_Acceleration{ Vector2D{ 0,0 } } {}

	// setters 
	inline void SetMass(float a_mass) { m_Mass = a_mass; }
	inline void SetGravity(float a_g) { m_Gravity= a_g; }

	//force 
	inline void ApplyForce(Vector2D a_Force) { m_Force = a_Force; }
	inline void ApplyForceX(float a_ForceX) { m_Force.X = a_ForceX; }
	inline void ApplyForceY(float a_ForceY) { m_Force.Y = a_ForceY; }
	inline void ResetForce() { m_Force = Vector2D{ 0,0 }; }

	//friction 
	inline void ApplyFriction(Vector2D a_fric) { m_Friction = a_fric; }
	inline void ResetFriction() { m_Friction = Vector2D{ 0,0 }; }

	inline float Mass() { return m_Mass; };
	inline Vector2D Position() { return m_Position; };
	inline Vector2D Velocity() { return m_Velocity; };
	inline Vector2D Acceleration() { return m_Acceleration; };

	// update
	void Update(float dt)
	{
		// net force = ma 
		m_Acceleration.X = (m_Force.X + m_Friction.X) / m_Mass;
		m_Acceleration.Y = m_Gravity + m_Force.Y / m_Mass;
		// acc = dv / dt --> dv = acc * dt
		m_Velocity = m_Acceleration * dt;
		// dist = v * dt 
		m_Position = m_Velocity * dt;
	}

private:
	float m_Mass;
	float m_Gravity;

	Vector2D m_Force;
	Vector2D m_Friction;
	Vector2D m_Position;
	Vector2D m_Velocity;
	Vector2D m_Acceleration; 

};
