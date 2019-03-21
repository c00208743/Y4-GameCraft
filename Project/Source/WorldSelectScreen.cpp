#include "../Header/WorldSelectScreen.h"

/// <summary>
/// @WorldSelectScreento be played after the main menu
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display 
/// </summary>


//constructs the splash screen
WorldSelectScreen::WorldSelectScreen(Game & game) : m_game(&game)
{
	m_currentSelect = 0;

	// Load from a font file on disk
	if (!myFont.loadFromFile("Asset/Fonts/powerful.ttf"))
	{
		// Error...
	}

	if (!myFont2.loadFromFile("Asset/Fonts/Batman.ttf"))
	{
		// Error...
	}
	if (!m_Texture.loadFromFile("Asset/Images/Background-Menu.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);
	m_Sprite.setScale(1.2, 1.2);

	
	m_title = new Label("WORLD SELECT ", 800.0f, 400.0f, "powerful.ttf");
	m_title->changeTextSize(100);
	m_gui.addLabel(m_title);

	m_worldOne = new Button("(World) (One)", 1000.0f, 600.0f, "Batman.ttf");
	m_worldOne->changeTextSize(100);
	m_worldOne->gainFocus();
	m_worldOne->Enter = std::bind(&WorldSelectScreen::goToGameScreen, this);
	m_gui.addButton(m_worldOne);

	m_worldTwo = new Button("(World) (Two)", 1000.0f, 800.0f, "Batman.ttf");
	m_worldTwo->changeTextSize(100);
	m_worldTwo->Enter = std::bind(&WorldSelectScreen::goToGameScreen, this);
	m_gui.addButton(m_worldTwo);


	m_worldThree = new Button("(World) (Three)", 1000.0f, 1000.0f, "Batman.ttf");
	m_worldThree->changeTextSize(100);
	m_worldThree->Enter = std::bind(&WorldSelectScreen::goToGameScreen, this);
	m_gui.addButton(m_worldThree);


	m_back = new Button("(Back)", 1000.0f, 1200.0f, "Batman.ttf");
	m_back->changeTextSize(100);
	m_back->Enter = std::bind(&WorldSelectScreen::goToMainMenu, this);
	m_gui.addButton(m_back);

	keys = KeyHandler();
}

//destructor
WorldSelectScreen::~WorldSelectScreen()
{
}

//updates screen
void WorldSelectScreen::update(sf::Time deltaTime)
{
	m_gui.update(m_currentSelect, 4);
}

//draws window
void WorldSelectScreen::render(sf::RenderWindow & window)
{
	window.draw(m_Sprite);
	for (int i = 0; i < sizeof(text) / sizeof(text[0]); i++)
	{
		window.draw(text[i]);
	}

	m_gui.draw(window);
}


void WorldSelectScreen::goToGameScreen()
{
	m_game->changeGameState(GameState::Gameplay);
}

void WorldSelectScreen::goToMainMenu()
{
	m_game->changeGameState(GameState::MainMenu);
}
