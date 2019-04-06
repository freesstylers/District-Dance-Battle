#include "PanelMap.h"


PanelMap::PanelMap(GameManager* gm, Vector2D panelPos, int photo, string description, int difficulty, string name): difficulty_(difficulty), name_(name) {
	fondo_ = EmptyObject(gm, panelPos, width, height, Resources::Point);
	for (int i = 0; i < 3; i++) {
		//switches[i] = EmptyObject(gm, Vector2D(((panelPos.getX() + width / 2) - width / 4), (panelPos.getY() + height / 2) + 2 * i*(height / 10)), width / 2, height / 10, Resources::Point);
	}
	photo_ = EmptyObject(gm, Vector2D(panelPos.getX() + width / 2, panelPos.getY() + height / 10), 2 * (width / 3), 7 * height / 10, photo);
}


PanelMap::PanelMap(): difficulty_(1), name_("") {
	fondo_ = EmptyObject(nullptr, { 0,0 }, 0, 0, Resources::Point);
	for (int i = 0; i < 3; i++) {
		//switches[i] = EmptyObject(nullptr, { 0,0 }, 0, 0, Resources::Point);
	}
	photo_ = EmptyObject(nullptr, { 0,0 }, 0, 0, Resources::Point);
}

void PanelMap::render(Uint32 time, bool beatHandler) {
	fondo_.render(time, beatHandler);
	for (int i = 0; i < 3; i++) {
		//switches[i].render(time, beatHandler);
	}
	photo_.render(time, beatHandler);
}


PanelMap::~PanelMap()
{

}
