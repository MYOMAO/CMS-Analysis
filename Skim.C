#include <iostream>
#include <iomanip>
#include <utility>
#include <TFile.h>
#include <TDirectoryFile.h>
#include <TDirectory.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TH1D.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TLatex.h>
#include <TLegend.h>
#include <TLine.h>
#include <TBox.h>
#include <TCut.h>
#include <TMath.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TProfile.h>
#include <TChain.h>
using namespace std;

using std::cout;
using std::endl;

void Skim(const char* infile, const char* output){

//TString input="/afs/cern.ch/work/s/szhaozho/data/5TeV/285216";


 TChain *t1 = new TChain("hltanalysis/HltTree");
 TChain *t2 = new TChain("hiEvtAnalyzer/HiTree");



//sprintf(infile,"root://eoscms//eos/cms/store/group/phys_heavyions/dhangal/pr_forests/PAMinimumBias/v3/000/285/216/HiForest_%d.root",i);

//TFile* inf = TFile::Open(infile);

cout << infile << endl;
 t1->AddFile(infile); 
 t2->AddFile(infile); 


//sprintf(outfile,"skim%d-%d.root");


  TFile *fout = new TFile(output,"recreate");
        fout->cd();
cout << output << "  1  " << endl;

		t1->SetBranchStatus("*",0);
		//	t2->SetBranchStatus("*",0);
   t1->SetBranchStatus("Event",1);
   t1->SetBranchStatus("LumiBlock",1);
   t1->SetBranchStatus("Run",1);

   t1->SetBranchStatus("HLT_PADmeson*",1);
   t1->SetBranchStatus("HLT_PAL1MinimumBias*",1);
   t1->SetBranchStatus("HLT_PAZeroBias*",1);
   t1->SetBranchStatus("L1_SingleJet*",1);
   t1->SetBranchStatus("L1_MinimumBias*",1);

 cout << "  2" << endl;

TTree *t_new1 = (TTree*)t1->CloneTree(0);
 cout << "   3   " << endl;
TTree *t_new2 = (TTree*)t2->CloneTree(0);
 cout << "   4   " << endl;

t_new1->CopyEntries(t1);
t_new2->CopyEntries(t2);


t_new1->SetName("ntHlt");
t_new2->SetName("ntHi");

fout->Write();

   delete fout;



	}

int main(int argc, char *argv[])
{
  if(argc==3)
    {
      Skim(argv[1], argv[2]);
      return 1;
    }
  else
    {
      std::cout<<"Error: invalid parameter number."<<std::endl;
      return 0;
    }
}
