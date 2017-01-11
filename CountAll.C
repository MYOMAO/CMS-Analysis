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



void CountAll() {



int num;

int totalsum = 0;

const int Nfolder = 4;


int sum[Nfolder];
char inputfile[512];

int N[Nfolder];

N[0] = 0;
N[1] = 1500;
N[2] = 2500;
N[3] = 2000;


int FN[Nfolder];

FN[0] = 285090;
FN[1] = 285216;
FN[2] = 285244;
FN[3] = 285383;

for(int j=0; j < Nfolder; j++ ){

sum[j] =0;



for(int i=0; i < N[j]; i++){



sprintf(inputfile,"/afs/cern.ch/work/s/szhaozho/data/5TeV/%d/skim_HiForest_%d.root",FN[j],i);

//cout << inputfile << endl;


ifstream ifile(inputfile);



if(ifile){

	TFile *fin = TFile::Open(inputfile);

TTree *t = (TTree *)fin->Get("ntHlt");

t->Draw("Event>>h1");

num = h1->GetEntries();

sum[j] = sum[j] + num;


cout << num << endl;

}

if (!ifile) { 

	i = i + 1;

cout << "File  " << i << "does not exist" << endl; 

}

cout << sum[j] << endl;

//cout << "index = " << i  << endl;

}

cout << "folder  " << j <<  "   Totalevents = " << sum[j] << endl;




}

totalsum = totalsum + sum[j];

cout << "Run 2016 p - Pb Total  Events =  " << totalsum << endl;

}




