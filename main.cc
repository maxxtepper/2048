#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdint>
#include <string>
#include <fstream>
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include "Global.h"
#include "Engine2048.h"

int chooseDirection0();

int main(int argc, char* argv[]) {
	//////////////////////////////////////////////////////
	////		Process Input Parameters
	//////////////////////////////////////////////////////
	if (argc != 4) {
		printf("Usage: ./main game_id mode agent\n\
				game_id: id for data set\n\
				mode:    0 = new; 	1 = load\n\
				agent:   0 = human; 1 = NN\n"); return -1;
	}
	std::string game_id = argv[1];
	int mode            = atoi(argv[2]);
	int agent           = atoi(argv[3]);

	gcycle_t cycle;
	
	//////////////////////////////////////////////////////
	////		Get pwd for File Saving
	//////////////////////////////////////////////////////
	std::string pwd;
	char cwd[1024];
	if (getcwd(cwd,sizeof(cwd)) != NULL)
		pwd = cwd;
	else {
		printf("ERROR: Could not find cwd!\n");
		return -1;
	}

	//////////////////////////////////////////////////////
	////		ROOT Setup
	//////////////////////////////////////////////////////
	std::string pref;
	std::string	fileName;
	pref = pwd + "/raw_player_data/";
	fileName = pref + "data_" + std::to_string(agent) + "_" + game_id;
	std::string fileNameR = fileName + ".root";

	//	Tree and branch strings
	std::string rT_id   = "game_cycle_tree";
	std::string rT_name = "Game Data - Board States and Direction Choices";
	std::string br_id = "cycle";

	//	Mode
	//	Create file
	TFile *outFile = TFile::Open(fileNameR.c_str(), "RECREATE");
	TTree *rawT = new TTree(rT_id.c_str(),rT_name.c_str());
	TBranch *cycleB = new TBranch();

	cycleB = rawT->Branch(br_id.c_str(), cycle.bstate,"cycle.bstate/I");

	//////////////////////////////////////////////////////
	////		Output Text File Setup
	//////////////////////////////////////////////////////
	std::fstream fout;
	std::string fileNameT = fileName + ".txt";
	fout.open(fileNameT, std::fstream::out);

	//////////////////////////////////////////////////////
	////		Create the 2048 Engine
	//////////////////////////////////////////////////////
	Engine2048 *engine2048;
	engine2048 = new Engine2048();

	//////////////////////////////////////////////////////
	////		Start the Engine
	//////////////////////////////////////////////////////
	//	Pre-Engine Process
	bool game_state=false;
	int direction;
	bool dir_success=false;
	std::string input;

	while (!game_state) {
		game_state = engine2048->beginningPhase();
		engine2048->printBoard();
		engine2048->holdBoardState();
		if (!game_state) {
			dir_success = false;
			while (!dir_success) {
				direction = chooseDirection0();
				dir_success = engine2048->mainPhase(direction);
			}
			cycle.bstate = engine2048->getHeldBoardState();
			cycle.direction = direction;

			//	Save the data to ROOT
			for (int i=0; i<16; i++)
				fout << cycle.bstate[i] << ",";
			fout << cycle.direction << std::endl;

			//	Save the data to ROOT
			rawT->Fill();

			engine2048->endPhase();
		} else {
			//	Game ends
		}
	}
	delete engine2048;
	rawT->Write();
	outFile->Close();
	fout.close();
	return 0;
}

int chooseDirection0() {
	char direction[1];
	std::cin >> direction[0];
	switch(direction[0]) {
		case 'w':
			return UP;
		case 's':
			return DOWN;
		case 'a':
			return LEFT;
		case 'd':
			return RIGHT;
	}
	return 0;
}
