#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>

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

			//	Save the data to ROOT
			std::cout << "Here\n";
			rawT->Fill();

	rawT->Write();
	outFile->Close();
