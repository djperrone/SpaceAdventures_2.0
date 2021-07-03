#include "sapch.h"
#include "GamePlayManager.h"
#include "ObjectManager.h"

GamePlayManager::GamePlayManager()
{
}

GamePlayManager::GamePlayManager(InputController* inputController)
{
	m_ObjectManager = std::make_unique<ObjectManager>(inputController);
}

GamePlayManager::~GamePlayManager()
{
}

void GamePlayManager::Update()
{
	
	m_ObjectManager->Update();
}

void GamePlayManager::HandleEvents()
{

}

void GamePlayManager::Render(std::shared_ptr<Renderer>& renderer)
{
	m_ObjectManager->Render(renderer);
}

Player* GamePlayManager::GetPlayer()
{
	return m_ObjectManager->GetPlayer();
}
