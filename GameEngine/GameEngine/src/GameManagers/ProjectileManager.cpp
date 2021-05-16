#include "ProjectileManager.h"
#include "MyObjects/Ship.h"


ProjectileManager::ProjectileManager()
{

}


void ProjectileManager::LoadAllProjectiles(std::list <std::shared_ptr<Ship>>& shipList)
{
	for (auto it = shipList.begin(); it != shipList.end(); it++ )
	{
		auto& list = it->get()->GetProjectileList();
		//std::cout << "pman ship proj list size " << list.size() << std::endl;

		m_ProjectileList.insert(m_ProjectileList.end(), list.begin(), list.end());
		list.clear();
	}
}
