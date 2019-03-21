/// <summary>
/// Empty Project for SFML[2.4.2]
/// 
/// @mainpage Project - Larry and Karlton
/// @author Jamie Murphy and Sean Regan
/// @date Oct 25/10/17
/// @brief 2D platformer 
/// </summary>


#ifdef _DEBUG
#pragma comment (lib, "sfml-graphics-d.lib")
#pragma comment (lib, "sfml-audio-d.lib")
#pragma comment (lib, "sfml-system-d.lib")
#pragma comment (lib, "sfml-window-d.lib")
#pragma comment (lib, "sfml-main-d.lib")
#pragma comment (lib, "sfml-network-d.lib")
#pragma comment(lib,"Lib/libyaml-cppmdd")
#pragma comment(lib, "Lib/libyaml-cppmdd.lib")

#else
#pragma comment (lib, "sfml-graphics.lib")
#pragma comment (lib, "sfml-audio.lib")
#pragma comment (lib, "sfml-system.lib")
#pragma comment (lib, "sfml-window.lib")
#pragma comment (lib, "sfml-main.lib")
#pragma comment (lib, "sfml-network.lib")
#pragma comment(lib,"Lib/libyaml-cppmd") // NB –cppmd (not –cppmdd)
#endif
#pragma comment(lib, "Lib/libyaml-cppmdd.lib")

#include "../Header/Game.h"


/// <summary>
/// main enrtry point
/// </summary>
/// <returns>zero</returns>
int main()
{
	Game game;

	game.init();
	game.run();
	return 0;
}