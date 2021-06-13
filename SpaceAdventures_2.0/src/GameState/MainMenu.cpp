#include "sapch.h"
#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Update()
{
	std::cout << "main menu update\n";
}

void MainMenu::Render(std::shared_ptr<Renderer>& renderer)
{
	std::cout << "main menu render\n";

}
