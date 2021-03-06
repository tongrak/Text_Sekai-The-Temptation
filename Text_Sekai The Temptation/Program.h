#pragma once
#ifndef ROOM_HPP
#define ROOM_HPP

#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<map>

/*
	Here, lay game program.
*/

//Structure of Room
struct Room
{
	std::string name;
	std::string des;
	std::string Neighbor[4];
	std::string eventID;

};
//Structure of Event
struct Event
{
	std::string event_name;
	std::string event_des;
	char event_typ;
	std::string event_opt;
	std::string event_outCome;
	std::string event_PosOutCome01;
	std::string event_PosOutCome02;
	bool event_check;
	bool event_act;
};
/*
	Data loading class, mainly doing loadind, storing, and returning string
	duties are...
	-	Loading and Storing(in map format, by key of map is that room id) Maps string;
	-	Loading and Storing(in map format, by key of map is that event id) Event string;
	-	Returning Name or Description of current stored room id;
	-	Returning Name or Description or Option or Condition or Checkpoint of current stored event id;
	-	Change current room or event id;
*/
class Data_loading {
public:
	//Loading function
	bool LoadMaps();
	bool LoadEvent();

	//Getting Var function 
	int GetCurrentID();
	std::string GetName();
	std::string GetDes();
	char GetEventType();
	std::string GetEventName();
	std::string GetEventDes();
	std::string GetEventOpt();
	std::string GetEventCon();
	std::string GetEventOutC();
	std::string GetEventPos1();
	std::string GetEventPos2();
	bool GetEventAct();
	bool GetEventCheck();
	bool IsCheck();
	int GetLastCheck();
	//Speacial getting var function
	std::string GetNeighbors(int dir, std::string &holder);
	bool ChecknGetEventId(std::string &holder);


	//Changing var
	void ChangeCurrentID(int);
	void ChangeEventID(int);
	void ChangeEventToInAct();
	void ChangeLastCheck();

	//ruler
	std::string Direction[4] = { "north", "east", "west", "south" };
	//tool's var
	std::string SplitedLine[4];

	//Sentence limiter tool
	void SentenceSpliter(std::string, std::string[]);

	//construtor and distrutor
	Data_loading();
	~Data_loading();

private:
	std::map<int, Room> roomStorage;
	std::map<int, Event> eventStorage;
	int* Current_id;
	int* Event_id;
	int* Last_check;

};

/*
	Checking class, mainly for checking and process input
*/
class Player
{
public:
	//Variable for checking
	bool Is_alive;

	//Checking Function
	bool CheckBasicCon();
	void CheckInputText(std::string , std::string);
	bool CheckInputDir(std::string);
	void CheckEvent();
	void CheckCheckPoint();
	void CheckCurrLook();
	//something special, yea no shi*
	void CheckSpecialEvent();

	//Design function
	void DeclareDead();

	//updating GUI
	void UpdatingTextInGen(std::string);
	
	//Setting function
	void SetGUIlook();
	void SetGUIhelp();
	void SetGUIstarting();
	void SetGUIclear();
	void setGUIdead();

	//GUI function
	void Hold();

	//Constructor and distructor
	Player();
	~Player();

	//Item oganization
	void AddItem(int );
	bool ChecknGetItemPosi(int ,int&);
	void RemoveItem(int );

private:
	//Item
	bool R_04, R_06, R_13, R_16, R_17, R_22, R_27,  R_43, R_51, R_53, R_33,  R_33_1, R_39, R_39_1, HoldCheck;
	std::vector<int>Inventory;
	int Coin;
};

#endif 