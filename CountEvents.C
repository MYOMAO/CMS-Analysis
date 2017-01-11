#ifndef __CINT__
#include "TROOT.h"
#include "TH1.h"
#include "TTree.h"
#include "TH2.h"
#include "TF1.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TVector2.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TRandom.h"
#include <iostream>
#include <fstream>
using namespace std;

using std::cout;
using std::endl;
#endif



void CountEvents() {

int N = 1500;

char inputfile[512];

int num;

int sum = 0;



for(int i=0; i < N; i++){



sprintf(inputfile,"skim_HiForest_%d.root",i);



ifstream ifile(inputfile);



if(ifile){

	TFile *fin = new TFile(inputfile);

TTree *t = (TTree *)fin->Get("ntHlt");

t->Draw("Event>>h1");

num = h1->GetEntries();

sum = sum + num;


cout << num << endl;

}

if (!ifile) { 

	i = i + 1;

cout << "File  " << i << "does not exist" << endl; 

}

cout << sum << endl;

//cout << "index = " << i  << endl;

}

cout << "Totalevents = " << sum << endl;

}




