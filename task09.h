#pragma once
#include <iostream>
#include <string>
#include <ctime> 
#include <algorithm>
#include <conio.h>
#include "utils.h"
using namespace std;
const int N = 50;
const char* names[] = {
	"Messi", "Ronaldo", "Dzyuba", "Kante", "Lukaku",
	"Neymar", "Mbappe", "Lewandowski", "Kane", "Salah",
	"Mane", "De Bruyne", "Griezmann", "Modric", "Ramos",
	"Van Dijk", "Alisson", "Neuer", "Pogba", "Sterling"
};
const char* positions[] = { "st","gk","cm","cdm","cb","cam","lb","rb","lw","rw" };
FootballPlayer genPlayer() {
	FootballPlayer player;
	player.name = names[rand() % 20];
	player.position = positions[rand() % 10];
	player.age = rand() % 23 + 18;
	player.games = rand() % 36 + 1;
	(player.position == "gk") ? player.goals = 0 : player.goals = rand() % 60;
	if (player.games == 1)
		player.lasts.goal = player.goals;
	else {
		if (player.goals == 0) player.lasts.goal = 0; 
		else
		player.lasts.goal = rand() % player.goals;
	}
	return player;
}
void showPlayers(FootballPlayer club[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << "name:\t" << club[i].name << "\nposition:\t" << club[i].position << "\nage:\t" << club[i].age << "\ngames is played:\t" << club[i].games << "\ngoals is scored:\t" << club[i].goals << "\ngoals at last 5 game:\t" << club[i].lasts.goal <<endl << endl;
	}
}
bool compareLasts(const FootballPlayer& a, const FootballPlayer& b) {
	return a.lasts.goal < b.lasts.goal;
}
void task09(string path) {
	srand(time(NULL));
	FootballPlayer club[N];
	FootballPlayer clubNew[N];
	for (int i = 0; i < N; ++i) {
		club[i] = genPlayer();
	}
	writeBin(path, club, N);
	readBin(path, clubNew, N);
	showPlayers(clubNew, N);
	sort(clubNew, clubNew + N, compareLasts);
	cout << "the best striker at 5 last games is\nname:\t" << clubNew[N-1].name << "\nposition:\t" << clubNew[N-1].position << "\nage:\t" << clubNew[N-1].age << "\ngames is played:\t" << clubNew[N-1].games << "\ngoals is scored:\t" << clubNew[N-1].goals << "\ngoals at last 5 game:\t" << clubNew[N-1].lasts.goal << endl << endl;
	cin.get(); cin.get();
}