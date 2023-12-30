//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 16 18:28:49 2023 by ROOT version 6.28/04
// from TTree Pre_Selection1/variables for BDT training
// found on file: ZnunuJetsSimple.root
//////////////////////////////////////////////////////////

#ifndef MyClass1_h
#define MyClass1_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <string.h>
#include <vector>
// Header file for the classes stored in the TTree if any.
//#include "c++/11/vector"
//#include "c++/11/vector"

class MyClass1 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
  string InFileName, OutFileName;
// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<int>     *Z_PdgId;
   vector<int>     *Nu1_PdgId;
   vector<int>     *Nu_PdgId;
   vector<double>  *Z_Px;
   vector<double>  *Z_Py;
   vector<double>  *Z_E;
   vector<double>  *Z_Pz;
   vector<double>  *Nu_Px;
   vector<double>  *Nu_Py;
   vector<double>  *Nu_E;
   vector<double>  *Nu_Pz;
   vector<double>  *Nu1_Px;
   vector<double>  *Nu1_Py;
   vector<double>  *Nu1_E;
   vector<double>  *Nu1_Pz;

   // List of branches
   TBranch        *b_Z_PdgId;   //!
   TBranch        *b_Nu1_PdgId;   //!
   TBranch        *b_Nu_PdgId;   //!
   TBranch        *b_Z_Px;   //!
   TBranch        *b_Z_Py;   //!
   TBranch        *b_Z_E;   //!
   TBranch        *b_Z_Pz;   //!
   TBranch        *b_Nu_Px;   //!
   TBranch        *b_Nu_Py;   //!
   TBranch        *b_Nu_E;   //!
   TBranch        *b_Nu_Pz;   //!
   TBranch        *b_Nu1_Px;   //!
   TBranch        *b_Nu1_Py;   //!
   TBranch        *b_Nu1_E;   //!
   TBranch        *b_Nu1_Pz;   //!

  MyClass1(string InFile, string OutFile, TTree *tree=0);
   virtual ~MyClass1();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

  //MyClass1(string FileName);
};

#endif

#ifdef MyClass1_cxx
//MyClass1::MyClass1(string FileName){
//a=FileName;
  //cout << "enter file name: ";
  //getline(cin,FileName);
//}
MyClass1::MyClass1(string InFile, string OutFile, TTree *tree) : InFileName(InFile), OutFileName(OutFile), fChain(0) 
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
{   if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject(InFileName.c_str());
      if (!f || !f->IsOpen()) {
	f = new TFile(InFileName.c_str());
      }
      f->GetObject("Pre_Selection1",tree);

   }
   Init(tree);
}

MyClass1::~MyClass1()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MyClass1::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MyClass1::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MyClass1::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Z_PdgId = 0;
   Nu1_PdgId = 0;
   Nu_PdgId = 0;
   Z_Px = 0;
   Z_Py = 0;
   Z_E = 0;
   Z_Pz = 0;
   Nu_Px = 0;
   Nu_Py = 0;
   Nu_E = 0;
   Nu_Pz = 0;
   Nu1_Px = 0;
   Nu1_Py = 0;
   Nu1_E = 0;
   Nu1_Pz = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Z_PdgId", &Z_PdgId, &b_Z_PdgId);
   fChain->SetBranchAddress("Nu1_PdgId", &Nu1_PdgId, &b_Nu1_PdgId);
   fChain->SetBranchAddress("Nu_PdgId", &Nu_PdgId, &b_Nu_PdgId);
   fChain->SetBranchAddress("Z_Px", &Z_Px, &b_Z_Px);
   fChain->SetBranchAddress("Z_Py", &Z_Py, &b_Z_Py);
   fChain->SetBranchAddress("Z_E", &Z_E, &b_Z_E);
   fChain->SetBranchAddress("Z_Pz", &Z_Pz, &b_Z_Pz);
   fChain->SetBranchAddress("Nu_Px", &Nu_Px, &b_Nu_Px);
   fChain->SetBranchAddress("Nu_Py", &Nu_Py, &b_Nu_Py);
   fChain->SetBranchAddress("Nu_E", &Nu_E, &b_Nu_E);
   fChain->SetBranchAddress("Nu_Pz", &Nu_Pz, &b_Nu_Pz);
   fChain->SetBranchAddress("Nu1_Px", &Nu1_Px, &b_Nu1_Px);
   fChain->SetBranchAddress("Nu1_Py", &Nu1_Py, &b_Nu1_Py);
   fChain->SetBranchAddress("Nu1_E", &Nu1_E, &b_Nu1_E);
   fChain->SetBranchAddress("Nu1_Pz", &Nu1_Pz, &b_Nu1_Pz);
   Notify();
}

Bool_t MyClass1::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MyClass1::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MyClass1::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MyClass1_cxx 
