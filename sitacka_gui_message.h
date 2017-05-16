#ifndef SITACKA_GUI_MESSAGE_H
#define SITACKA_GUI_MESSAGE_H

#include "sitacka_server_event.h"

class GUIMessage {

public:
	virtual char* serialize();
	virtual void deserialize(char*);
}

class ToGUIMessage: public GUIMessage {
	EventData* data;
public:
	char* serialize();
	void deserialize(char*);
}

enum class KeyPressed {LEFT_KEY_DOWN, LEFT_KEY_UP, RIGHT_KEY_DOWN, RIGHT_KEY_UP}

class FromGUIMessage: public GUIMessage {
	KeyPressed keyPressed;
public:
	char* serialize();
	void deserialize(char*);
}

#endif // SITACKA_GUI_MESSAGE_H
