#pragma once
#include "MyObjects/Projectile.h"

class Ship;

class ProjectileManager
{
public:

	ProjectileManager();
	~ProjectileManager() { std::cout << "destroyed porjctile manager\n"; };

	inline std::vector<std::shared_ptr<Projectile>> GetProjectileList()
	{
		return m_ProjectileList;
	}

	inline void ClearProjectileList()
	{
		m_ProjectileList.clear();
	}

	void LoadAllProjectiles(std::list <std::shared_ptr<Ship>>& shipList);

private:
	std::vector <std::shared_ptr<Projectile>> m_ProjectileList;

};

