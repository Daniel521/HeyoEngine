#include "h_heyo.h"
#include "h_Graphics.h"
#include "h_Event.h"
#include "h_Sprite.h"
#include "h_Sound.h"
#include "h_Text.h"
#include <iostream>

//using namespace Heyo;
using namespace std;


//int main(int argc, char * argv[]) {
//	Heyo::initHeyo();
//	Heyo::Graphics graphics(900, 650, "Heyo");
//	Heyo::Sprite blah;
//	Heyo::Sprite sprite;
//	Heyo::Sprite title;
//	Heyo::Sprite heyo;
//	blah.loadSprite("Data/blah.png", graphics, 1018, 642);
//	if (sprite.loadSprite("Data/Greg.png", graphics, 32, 32, 7, 1) == false)
//		cout << "Damn!" << endl;
//	if (title.loadSprite("Data/gregtheflower.png", graphics, 85, 10, 1, 1) == false)
//		cout << "Damn!" << endl;
//	if (heyo.loadSprite("Data/HeyoEngine.png", graphics, 97, 24, 1, 1) == false)
//		cout << "Damn!" << endl;
//
//	Heyo::Text hi;
//	hi.loadFont("lazy.ttf");
//	hi.setText(graphics, "Heyo! How's life?");
//	//hi.setAlpha(255);
//	//hi.setColor(0, 255, 0);
//	Heyo::Rect hiR = { 0,0, hi.getWidth(), hi.getHeight() };
//
//
//
//	Heyo::Rect spriteR = { 350,200,200,200 };
//	Heyo::Rect titleR = { 200, 50, 500, 100 };
//	Heyo::Rect heyoR = { 250, 500, 400, 100 };
//	Heyo::Rect blahR = { 520, 290, 60, 35 };
//
//	Heyo::Sound clap;
//	clap.loadSound("Data/app.wav");
//
//	Heyo::Music song;
//	song.loadMusic("Data/music1.wav");
//	song.play();
//
//
//	Heyo::Event events;
//
//	//sprite.setColorPercent(100, 100, 100);
//
//
//	bool quit = false;
//
//	int divider = 12;
//	int count = 0;
//	int curFrame = 0;
//	bool show = false;
//	// LOOP
//	while (quit == false) {
//		graphics.clear();
//		if (count % divider == 0)
//			curFrame++;
//		curFrame %= 6;
//		count++;
//
//		graphics.update(hi, hiR);
//		graphics.update(sprite[curFrame], spriteR);
//		graphics.update(title[0], titleR);
//		graphics.update(heyo[0], heyoR);
//		if (show == true)
//			graphics.update(blah, blahR);
//		
//		graphics.render();
//
//		if (Heyo::processEvent(events)) {
//			if (events.quit())
//				quit = true;
//
//			if (events.type() == Heyo::Event::types::KEYDOWN)
//			{
//				if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
//				{
//					;
//				}
//				if (events.keyPressed() == Heyo::Event::keys::K_w)
//					;
//				if (events.keyPressed() == Heyo::Event::keys::K_s)
//					;
//				if (events.keyPressed() == Heyo::Event::keys::K_a)
//				{
//					;
//				}
//				if (events.keyPressed() == Heyo::Event::keys::K_d)
//				{
//					;
//				}
//			}
//
//			if (events.type() == Heyo::Event::types::KEYUP) {
//				if (events.keyPressed() == Heyo::Event::keys::K_SPACE)
//				{
//					;
//				}
//				if (events.keyPressed() == Heyo::Event::keys::K_w)
//				{
//					;
//				}
//			}
//		}
//
//
//	}
//
//	hi.~Text();
//	Heyo::closeHeyo();
//	return 0;
//}
//
// 