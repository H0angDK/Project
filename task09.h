#pragma once
#include <iostream>
#include <string>
#include <ctime> 
#include <conio.h>
#include "utils.h"
using namespace std;
const char* names[] = { "Messi", "Ronaldo", "Dzyuba", "Kante", "Hleb" };
const char* positions[] = { "st","gk","cm","cdm","cb","cam","lb","rb","lw","rw" };
FootballPlayer genPlayer() {
	FootballPlayer player;
	player.name = names[rand() % 5];
	player.position = positions[rand() % 10];
	player.age = rand() % 23 + 18;
	player.games = rand() % 36 + 1;
	player.goals = rand() % 60;
	return player;
}
void showPlayers(FootballPlayer club[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << "name:\t" << club[i].name << "\nposition:\t" << club[i].position << "\nage:\t" << club[i].age << "\ngames is played:\t" << club[i].games << "\ngoals is scored:\t" << club[i].goals << endl<<endl;
	}
}
void task09(string path) {
	srand(time(NULL));
	const int n = 5;
	FootballPlayer club[n];
	FootballPlayer clubNew[n];
	for (int i = 0; i < n; ++i) {
		club[i] = genPlayer();
	}
	writeBin(path, club,n);
	readBin(path, clubNew,n);
	showPlayers(clubNew, n);
	_getch();
}