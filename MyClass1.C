#define MyClass1_cxx
#include "MyClass1.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TSystem.h>
#include <TMath.h>


void MyClass1::Loop()
{ std::unique_ptr<TFile> myFile( TFile::Open(OutFileName.c_str(), "RECREATE"));
  
  //for Z Pdg Id
  //TCanvas *c1 = new TCanvas("ZPdgId","Z_PdgId",200,10,400,400); 
  //c1->SetGrid();
  TH1 *h_ZPdgId  = new TH1F("Z_Pdg_Id","Distribution for Z_Pdg_Id",10,20,30); 
  h_ZPdgId->SetMarkerStyle(21);
  h_ZPdgId->SetMarkerSize(0.7);

  //for Z_Px
  //TCanvas *c2 = new TCanvas("c2","Z_Px",200,10,400,400);
  //c2->SetGrid();
  TH1 *h_ZPx  = new TH1F("Z_Px","Distribution for Z_Px", 500,-500,500); 
  h_ZPx->SetMarkerStyle(21);
  h_ZPx->SetMarkerSize(0.7);

  //for Z_Py
  //TCanvas *c3= new TCanvas("c3","Z_Py",200,10,400,400); 
  //c3->SetGrid();
  TH1 *h_ZPy  = new TH1F("Z_Py","Distribution for Z_Py",500,-500,500); 
  h_ZPy->SetMarkerStyle(21);
  h_ZPy->SetMarkerSize(0.7);

  //for Z_Pz
  //TCanvas *c4 = new TCanvas("c4","Z_Pz",200,10,400,400); 
  //c4->SetGrid();
  TH1 *h_ZPz  = new TH1F("Z_Pz","Distribution for Z_Pz",500,-2000,2000); 
  h_ZPz->SetMarkerStyle(21);
  h_ZPz->SetMarkerSize(0.7);

  //for Z_E
  //TCanvas *c5 = new TCanvas("c4","Zenergy",200,10,600,400); 
  //c5->SetGrid();
  TH1 *h_Zenergy  = new TH1F("Z_Energy","Distribution for Z_E",500,0,4000);
  h_Zenergy->SetMarkerStyle(21);
  h_Zenergy->SetMarkerSize(0.7);

  //for Z mass
  // TCanvas *c6 = new TCanvas("c6","Zmass",200,10,600,400); 
  // c6->SetGrid();
  TH1 *h_Zmass  = new TH1F("Z_Mass","Distribution for Z_M",100,0,200);
  h_Zmass->SetMarkerStyle(21);
  h_Zmass->SetMarkerSize(0.7);

  //for p of Z
  TH1 *h_ZP  = new TH1F("Z_P","Distribution for Z_P",500,0,2000); 
  h_ZP->SetMarkerStyle(21);
  h_ZP->SetMarkerSize(0.7);
  h_ZP->SetXTitle("Z_P");
  h_ZP->SetLineColor(kRed);

  //for Z_M & Z_p
  TH1 *h_ZPM  = new TH2F("Z_MP","Distribution for Z_M & Z_P",500,0,2000,500,70,110); 
  h_ZPM->SetMarkerStyle(21);
  h_ZPM->SetMarkerSize(0.7);
  

  //for Pt of Z
  //TH1 *h_ZPt  = new TH1F("Z Pt","Distribution for Z_Pt",500,0,2000); 
  // h_ZPt->SetMarkerStyle(21);
  //h_ZPt->SetMarkerSize(0.7);

  // for Mass of Z v/s total Mass of Nutrinos
  TH1 *h_ZNuM  = new TH2F("Z_M_vs_NuNu1_M","Distribution for comparision of mass of Z and total Nutrino mass",100,80,100,100,80,100);
  h_Zmass->SetMarkerStyle(21);
  h_Zmass->SetMarkerSize(0.7);

  //for angle v/s p of z:
  TH1 *h_ptheta  = new TH2F("Z_P_vs_Nunu_theta","Distribution for variation of theta with Z_P",500,0,4000,100,0,4); 
  h_ptheta->SetMarkerStyle(21);
  h_ptheta->SetMarkerSize(0.7);
  h_ptheta->SetXTitle("Z_P");
  h_ptheta->SetYTitle("angle");

  //for pnu/pnu1 vs p of :
  TH1 *h_pzr  = new TH2F("Z_P_vs_Ratio","Distribution for variation of ratio of Nu_P with Z_P",500,-100,4000,100,0,10); 
  h_ptheta->SetMarkerStyle(21);
  h_ptheta->SetMarkerSize(0.7);

  //for Pdg Id of neutrino:
  TH1 *h_NuPdgId  = new TH1F("Nu_PdgId","Distribution for Nu_PdgId",20,0,20); 
  h_NuPdgId->SetMarkerStyle(21);
  h_NuPdgId->SetMarkerSize(0.7);

  //for px of neutrino:
  TH1 *h_NuPx  = new TH1F("Nu_Px","Distribution for Nu_Px",500,-500,500); 
  h_NuPx->SetMarkerStyle(21);
  h_NuPx->SetMarkerSize(0.7);

  //for py of neutrino:
  TH1 *h_NuPy  = new TH1F("Nu_Py","Distribution for Nu_Py",500,-500,500); 
  h_NuPy->SetMarkerStyle(21);
  h_NuPy->SetMarkerSize(0.7);

  //for pz of neutrino:
  TH1 *h_NuPz  = new TH1F("Nu_Pz","Distribution for Nu_Pz",500,-500,500); 
  h_NuPz->SetMarkerStyle(21);
  h_NuPz->SetMarkerSize(0.7);

  //for px of antineutrino:
  TH1 *h_Nu1Px  = new TH1F("Nu1_Px","Distribution for Nu1_Px",500,-500,500); 
  h_Nu1Px->SetMarkerStyle(21);
  h_Nu1Px->SetMarkerSize(0.7);

  //for py of antineutrino:
  TH1 *h_Nu1Py  = new TH1F("Nu1_Py","Distribution for Nu1_Py",500,-500,500); 
  h_Nu1Py->SetMarkerStyle(21);
  h_Nu1Py->SetMarkerSize(0.7);

  //for pz of antineutrino:
  TH1 *h_Nu1Pz  = new TH1F("Nu1_Pz","Distribution for Nu1_Pz",500,-500,500); 
  h_Nu1Pz->SetMarkerStyle(21);
  h_Nu1Pz->SetMarkerSize(0.7);

  //for Z_p & NuNu1_p
  TH1 *h_ZNuNu1P = new TH2F("Z_P_NuNu1_P","Distribution for Z_P & NuNu1_P",250,0,2000,250,0,2000); 
  h_ZNuNu1P->SetMarkerStyle(21);
  h_ZNuNu1P->SetMarkerSize(0.7);
  h_ZNuNu1P->SetXTitle("Z_P");
  h_ZNuNu1P->SetYTitle("NuNu1_P");

  //for angle in Z frame:
  TH1 *h_Ztheta = new TH2F("thetaZ", "Distribution of angle in Z frame",500,0,4000,400,0,4);
  h_Ztheta->SetMarkerStyle(21);
  h_Ztheta->SetMarkerSize(0.7);
  h_Ztheta->SetXTitle("Z_P");
  h_Ztheta->SetYTitle("angle");
  
  //for Nu_P1 Vs Nu_P
  TH1 *h_NuPP1 = new TH2F("Nu_P1_vs_Nu_P", "comparision of Nu momentum in Z and Lab frame",500,0,2000,100,0,100);
  h_NuPP1->SetMarkerStyle(21);
  h_NuPP1->SetMarkerSize(0.7);
  h_NuPP1->SetXTitle("Nu_P");
  h_NuPP1->SetYTitle("Nu_P1");

  //for Nu1_P1 Vs Nu1_P
  TH1 *h_Nu1PP1 = new TH2F("Nu1_P1_vs_Nu1_P", "comparision of two Lab frame momentum of Nu1",500,0,2000,500,0,2000);
  h_Nu1PP1->SetMarkerStyle(21);
  h_Nu1PP1->SetMarkerSize(0.7);
  h_Nu1PP1->SetXTitle("Nu1_P");
  h_Nu1PP1->SetYTitle("Nu1_P(boosted back)");

  //for Nu_P1/Nu1_P1 vs Z_P
  TH1 *h_rNuNu1P1 = new TH2F("ratio_of_NuP1_and_Nu1P1", "ratio of Nu momentum in Z v/s Z_P",500,0,2000,100,0,5);
  h_rNuNu1P1->SetMarkerStyle(21);
  h_rNuNu1P1->SetMarkerSize(0.7);
  h_rNuNu1P1->SetXTitle("Z_P");
  h_rNuNu1P1->SetYTitle("Nu_P1/Nu1_P1");

  //for Nu_P & Nu1_p in lab frame
  TH1 *h_LNuNu1P = new TH2F("Nu_P_vs_Nu1_P_lab","Distribution for Nu_P & Nu1_P (LAB)",100,0,2000,100,0,2000); 
  h_LNuNu1P->SetMarkerStyle(21);
  h_LNuNu1P->SetMarkerSize(0.7);
  h_LNuNu1P->SetXTitle("Nu_P(lab)");
  h_LNuNu1P->SetYTitle("Nu1_P(lab)");

  //for Nu_P1 & Nu1_P1 in rest frame
  TH1 *h_RNuNu1P = new TH2F("Nu_P1_Nu1_P1_rest","Distribution for Nu_P1 & Nu1_P1 (REST)",100,0,500,100,0,500); 
  h_RNuNu1P->SetMarkerStyle(21);
  h_RNuNu1P->SetMarkerSize(0.7);
  h_RNuNu1P->SetXTitle("Nu_P1(rest)");
  h_RNuNu1P->SetYTitle("Nu1_P1(rest)");
  
  //for angle betwn Z_P and Nu_P1:
  TH1 *h_ZPNuP1  = new TH1F("angle Z_P_vs_Nu_P1","angle Z_P & Nu_P1",400,-4,4 ); 
  h_ZPNuP1->SetMarkerStyle(21);
  h_ZPNuP1->SetMarkerSize(0.7);
  
  //for diff of Nu momenta vs Z_P:
  TH1 *h_dPZP = new TH2F("dP_vs_Z_P", "variation of dp with Z_P",500,0,2000,500,-2000,2000);
  h_dPZP->SetMarkerStyle(21);
  h_dPZP->SetMarkerSize(0.7);
  h_dPZP->SetYTitle("Nu_dP (lab)");
  h_dPZP->SetXTitle("Z_P(lab)");

  //for verifying statement about Nu momenta in lab frame
  TH1 *h_Stat = new TH2F("verify", "dP vs Projection of Nu_P1 on P_Z",500,-60,60,500,-3000,3000);
  h_Stat->SetMarkerStyle(21);
  h_Stat->SetMarkerSize(0.7);
  h_Stat->SetXTitle("Projection");
  h_Stat->SetYTitle("dP");

  //for transverse mass from z
  TH1 *h_Mt  = new TH1F("Z_Mt","Distribution for Mt from NuNu",250,0,200); 
  h_Mt->SetMarkerStyle(21);
  h_Mt->SetMarkerSize(0.7);
  h_Mt->SetXTitle("Transvese mass");
  //h_Mt->SetYTitle("TVector2");

  //for total transverse momentum of Z
  TH1 *h_ZPt  = new TH1F("Z_Pt","Distribution for Pt of Z",250,0,500); 
  h_ZPt->SetMarkerStyle(21);
  h_ZPt->SetMarkerSize(0.7);

  //for total transverse momentum of Nu
  TH1 *h_NuPt  = new TH1F("Nu_Pt","Distribution for Pt of Nu",250,0,500); 
  h_NuPt->SetMarkerStyle(21);
  h_NuPt->SetMarkerSize(0.7);

  //for total transverse momentum of Nu1
  TH1 *h_Nu1Pt  = new TH1F("Nu1_Pt","Distribution for Pt of Nu1",250,0,500); 
  h_Nu1Pt->SetMarkerStyle(21);
  h_Nu1Pt->SetMarkerSize(0.7);

  //for Pt of Nu in Lab vs rest
  TH1 *h_NuLRPt = new TH2F("Lab_vs_Rest NuPt", "Lab vs Rest NuPt",500,0,800,100,0,70 );
  h_NuLRPt -> SetMarkerStyle(21);
  h_NuLRPt -> SetMarkerSize(0.7);

  //for h_dPZP from 0 to 400
  TH1 *h_dPZP04  = new TH1F("dP_for_ZP_0_400","Distribution for ZP: 0-400",500,-2000,2000); 
  h_dPZP04 -> SetMarkerStyle(21);
  h_dPZP04 -> SetMarkerSize(0.7);
  h_dPZP04 -> SetXTitle("PNu-PNu1");

  //for h_dPZP from 4 to 800
  TH1 *h_dPZP48  = new TH1F("dP_for_ZP_400_800","Distribution for ZP: 400-800",500,-2000,2000); 
  h_dPZP48 -> SetMarkerStyle(21);
  h_dPZP48 -> SetMarkerSize(0.7);
  h_dPZP48 -> SetXTitle("PNu-PNu1");

  //for h_dPZP from 800 to 1200
  TH1 *h_dPZP812  = new TH1F("dP_for_ZP_800_1200","Distribution for ZP: 800-1200",500,-2000,2000); 
  h_dPZP812 -> SetMarkerStyle(21);
  h_dPZP812 -> SetMarkerSize(0.7);
  h_dPZP812 -> SetXTitle("PNu-PNu1");

  //for h_dPZP from 1200 to 1600
  TH1 *h_dPZP1216  = new TH1F("dP_for_ZP_1200_1600","Distribution for ZP: 1200-1600",250,-2000,2000); 
  h_dPZP1216 -> SetMarkerStyle(21);
  h_dPZP1216 -> SetMarkerSize(0.7);
  h_dPZP1216 -> SetXTitle("PNu-PNu1");

  // Z mass from total momentum of neutrino
  TH1 *h_ZMNuM  = new TH1F("ZM_from_NuM","Distribution for Z mass",100,0,200); 
  h_ZMNuM -> SetMarkerStyle(21);
  h_ZMNuM -> SetMarkerSize(0.7);

  //for Z mass from mu+ and mu-
  TH1 *h_ZMMu  = new TH1F("ZM_from_Mu","Distribution for Z mass",100,0,200); 
  h_ZMMu -> SetMarkerStyle(21);
  h_ZMMu -> SetMarkerSize(0.7);

  //for Z mass from e+ and e-
  TH1 *h_ZMe  = new TH1F("ZM_from_e","Distribution for Z mass",100,0,200); 
  h_ZMe -> SetMarkerStyle(21);
  h_ZMe -> SetMarkerSize(0.7);

  //for Z mass from tau+ and tau-
  TH1 *h_ZMTau  = new TH1F("ZM_from_tau","Distribution for Z mass",100,0,200); 
  h_ZMTau -> SetMarkerStyle(21);
  h_ZMTau -> SetMarkerSize(0.7);

  //for comparing transverse mass from TVector2 and TVector3
  TH1 *h_V2V3 = new TH2F("TVector2_vs_TVector3", "transverse mass from 2D and 3D Vector",500,0,200,500,0,200);
  h_V2V3->SetMarkerStyle(21);
  h_V2V3->SetMarkerSize(0.7);
  h_V2V3->SetXTitle("TVector3");
  h_V2V3->SetYTitle("TVector2");

  //for Nu Pt in lab vs rest
  TH1 *h_NuPtPt1 = new TH2F("NuPt_LabVsRest", "Neutrino Pt in lab Vs rest",500,0,200,500,0,200);
  h_NuPtPt1->SetMarkerStyle(21);
  h_NuPtPt1->SetMarkerSize(0.7);
  h_NuPtPt1->SetXTitle("NuPt (lab)");
  h_NuPtPt1->SetYTitle("NuPt (rest)");

  //for Nu1 pt in lab vs rest
  TH1 *h_Nu1PtPt1 = new TH2F("Nu1Pt_LabVsRest", "Antineutrino Pt in lab Vs rest",500,0,200,500,0,200);
  h_Nu1PtPt1->SetMarkerStyle(21);
  h_Nu1PtPt1->SetMarkerSize(0.7);
  h_Nu1PtPt1->SetXTitle("Nu1Pt (lab)");
  h_Nu1PtPt1->SetYTitle("Nu1Pt (rest)");

  //for deltaPhi in lab vs rest
  TH1 *h_DeltaPhi = new TH2F("deltaPhi_LabVsRest", "deltaPhi in lab Vs rest",320,-3.2,3.2,320,-3.2,3.2);
  h_DeltaPhi->SetMarkerStyle(21);
  h_DeltaPhi->SetMarkerSize(0.7);
  h_DeltaPhi->SetXTitle("deltaPhi (lab)");
  h_DeltaPhi->SetYTitle("deltaPhi (rest)");

  //Distribution for dP
  TH1 *h_DP  = new TH1F("dP_Distribution","Distribution for P_Nu-P_Nu1",1000,-5000,5000); 
  h_DP->SetMarkerStyle(21);
  h_DP->SetMarkerSize(0.7);
  h_DP->SetXTitle("PNu-PNu1");

  //for Mt in rest and lab for PZ>500
  TH1 *h_Mt500 = new TH2F("Mt_vs_Mt1_Zboost", "comparision of transverse mass for P_Z>500",50,0,150,50,0,150);
  h_Mt500->SetMarkerStyle(21);
  h_Mt500->SetMarkerSize(0.7);
  h_Mt500->SetXTitle("");
  h_Mt500->SetXTitle("");

  //Mt for ZP < 100
  TH1 *h_Mt100  = new TH1F("Mt_ZP_0_100","Distribution of Mt for ZP < 100",250,0,200); 
  h_Mt100->SetMarkerStyle(21);
  h_Mt100->SetMarkerSize(0.7);
  h_Mt100->SetXTitle ("Z_Mt");

  //Mt for ZP in 100 to 200
  TH1 *h_Mt200  = new TH1F("Mt_ZP_100_200","Distribution of Mt for 100<ZP<200",250,0,200); 
  h_Mt200->SetMarkerStyle(21);
  h_Mt200->SetMarkerSize(0.7);
  h_Mt200->SetXTitle ("Z_Mt");

  //Mt for ZP in 200 to 400
  TH1 *h_Mt400  = new TH1F("Mt_ZP_200_400","Distribution of Mt for 200<ZP<400",250,0,200); 
  h_Mt400->SetMarkerStyle(21);
  h_Mt400->SetMarkerSize(0.7);
  h_Mt400->SetXTitle ("Z_Mt");

  //Mt for ZP in 200 to 400
  TH1 *h_Mt400abv  = new TH1F("Mt_ZP(400 abv)","Distribution of Mt for above 400",250,0,200); 
  h_Mt400abv->SetMarkerStyle(21);
  h_Mt400abv->SetMarkerSize(0.7);
  h_Mt400abv->SetXTitle ("Z_Mt");

  //for checking invariece of Z.Mt in modified lab and rest
  TH1 *h_InvZMt = new TH2F("Invar_ZMt", "for invariance of Z.Mt()",100,0,200,100,0,200);
  h_InvZMt->SetMarkerStyle(21);
  h_InvZMt->SetMarkerSize(0.7);
  h_InvZMt->SetXTitle("Formula Mt rest");
  h_InvZMt->SetYTitle("Formula Mt lab");

  //for comparing Transverse mass obtained from formula
  TH1 *h_InvNu = new TH2F("Invar_NuNuMt", "for Invarience of NuNu Mt",100,0,200,100,0,200);
  h_InvNu->SetMarkerStyle(21);
  h_InvNu->SetMarkerSize(0.7);
  h_InvNu->SetXTitle("MtNuNu rest");
  h_InvNu->SetYTitle("MtNuNu lab1");


 


  
  //for comparing
  TH1 *h_Comp = new TH2F("Comparision", "for comparision only",1000,0,0.001,1000,0,0.001);
  h_Comp->SetMarkerStyle(21);
  h_Comp->SetMarkerSize(0.7);
  h_Comp->SetXTitle("MtNuNu rest");
  h_Comp->SetYTitle("MtNuNu lab1");
  
  //for Testing 1D histogram
  TH1 *h_Test  = new TH1F("Test","for testing 1D histogram",250,0,200); 
  h_Test->SetMarkerStyle(21);
  h_Test->SetMarkerSize(0.7);
  

  
//   In a ROOT session, you can do:
//      root> .L MyClass1.C
//      root> MyClass1 t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

  int i=0, j=0, k=0, l=0, m=0, n=0;

  if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++)
     {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
       if (Cut(ientry) < 0) continue;


       float M_Z = sqrt(pow((*Z_E)[0],2)-pow((*Z_Px)[0],2)-pow((*Z_Py)[0],2)-pow((*Z_Pz)[0],2));

       float Z_P = sqrt(((*Z_Px)[0]*(*Z_Px)[0])+((*Z_Py)[0]*(*Z_Py)[0])+((*Z_Pz)[0]*(*Z_Pz)[0]));

       float Z_Pt = sqrt(((*Z_Px)[0]*(*Z_Px)[0])+((*Z_Py)[0]*(*Z_Py)[0]));

       float P_nunu = sqrt((((*Nu_Px)[0]+(*Nu1_Px)[0])*((*Nu_Px)[0]+(*Nu1_Px)[0]))+(((*Nu_Py)[0]+(*Nu1_Py)[0])*((*Nu_Py)[0]+(*Nu1_Py)[0]))+(((*Nu_Pz)[0]+(*Nu1_Pz)[0])*((*Nu_Pz)[0]+(*Nu1_Pz)[0])));

       float M_nunu = sqrt((((*Nu_E)[0]+(*Nu1_E)[0])*((*Nu_E)[0]+(*Nu1_E)[0]))-(P_nunu * P_nunu));

       float Nu_P = sqrt(((*Nu_Px)[0]*(*Nu_Px)[0])+((*Nu_Py)[0]*(*Nu_Py)[0])+((*Nu_Pz)[0]*(*Nu_Pz)[0]));

       float Nu1_P = sqrt(((*Nu1_Px)[0]*(*Nu1_Px)[0])+((*Nu1_Py)[0]*(*Nu1_Py)[0])+((*Nu1_Pz)[0]*(*Nu1_Pz)[0]));

       float r = Nu_P/Nu1_P;

       float dP_Nu = Nu_P - Nu1_P;

       float NuNu1_P =sqrt((((*Nu1_Px)[0]+(*Nu_Px)[0])*((*Nu1_Px)[0]+(*Nu_Px)[0]))+(((*Nu1_Py)[0]+(*Nu_Py)[0])*((*Nu1_Py)[0]+(*Nu_Py)[0]))+(((*Nu1_Pz)[0]+(*Nu_Pz)[0])*((*Nu1_Pz)[0]+(*Nu_Pz)[0])));

       double c_theta = (((((*Nu_E)[0]+(*Nu1_E)[0])*((*Nu_E)[0]+(*Nu1_E)[0])-((*Z_E)[0]*(*Z_E)[0]))/(9*pow(10,16)))+(Z_P*Z_P)-(Nu_P*Nu_P)-(Nu1_P*Nu1_P))/(2*Nu_P*Nu1_P);

       double theta = acos(c_theta);

       TLorentzVector v_Z((*Z_Px)[0],(*Z_Py)[0],(*Z_Pz)[0],(*Z_E)[0]);
       TLorentzVector v_Nu((*Nu_Px)[0],(*Nu_Py)[0],(*Nu_Pz)[0],(*Nu_E)[0]);
       TLorentzVector v_Nu1((*Nu1_Px)[0],(*Nu1_Py)[0],(*Nu1_Pz)[0],(*Nu1_E)[0]);

       TLorentzVector v_Zcpy(v_Z.Px(),v_Z.Py(),v_Z.Pz(),v_Z.E());
       TLorentzVector v_Nucpy(v_Nu.Px(),v_Nu.Py(),v_Nu.Pz(),v_Nu.E());
       TLorentzVector v_Nu1cpy(v_Nu1.Px(),v_Nu1.Py(),v_Nu1.Pz(),v_Nu1.E());

       Double_t theta1 = (v_Nu.Vect()).Angle((v_Nu1.Vect()));
       Double_t M_Z1 = v_Z.M();

        TVector3 b;
        b = v_Zcpy.BoostVector();
        v_Nucpy.Boost(-b.Px(),-b.Py(),-b.Pz());
        v_Nu1cpy.Boost(-b.Px(),-b.Py(),-b.Pz());
        v_Zcpy.Boost(-b.Px(),-b.Py(),-b.Pz());

        
       Double_t theta2 = (v_Nucpy.Vect()).Angle((v_Nu1cpy.Vect()));
       float Nu_P1 = sqrt((v_Nucpy.Px()*v_Nucpy.Px())+(v_Nucpy.Py()*v_Nucpy.Py())+(v_Nucpy.Pz()*v_Nucpy.Pz()));
       float Nu1_P1 = sqrt((v_Nu1cpy.Px()*v_Nu1cpy.Px())+(v_Nu1cpy.Py()*v_Nu1cpy.Py())+(v_Nu1cpy.Pz()*v_Nu1cpy.Pz())); 

       
       TVector3 v1_Nu(v_Nucpy.Px(), v_Nucpy.Py(), v_Nucpy.Pz());
       float proj = (v1_Nu.Dot(v_Zcpy.Vect()))/(Z_P);
       

       //for Transverse mass in Lab frame given
       TVector3 v_NuPt((*Nu_Px)[0],(*Nu_Py)[0],0);
       TVector3 v_Nu1Pt((*Nu1_Px)[0],(*Nu1_Py)[0],0);
       TVector3 v_ZPt((*Z_Px)[0],(*Z_Py)[0],0);
       float NuPtMag = v_Nu.Pt();
       float Nu1PtMag = v_Nu1.Pt();
       float theta3 = v_NuPt.Angle(v_Nu1Pt);
       float MtvsNuNu = sqrt(2*NuPtMag*Nu1PtMag*(1-cos(theta3)));
       float MtvsZ = v_Z.Mt();
       
      

       //for Transverse mass in complete rest frame
       TVector3 v_NuPt1(v_Nucpy.Px(), v_Nucpy.Py(), 0);
       TVector3 v_Nu1Pt1(v_Nu1cpy.Px(), v_Nu1cpy.Py(), 0);
       TVector3 v_ZPt1((*Z_Px)[0],(*Z_Py)[0],0);
       float NuPtMag1 = v_Nucpy.Pt();
       float Nu1PtMag1 = v_Nu1cpy.Pt();
       float theta4 = v_NuPt1.Angle(v_Nu1Pt1);
       float Nu_eta1 = v_Nucpy.Eta();
       float Nu1_eta1 = v_Nu1cpy.Eta();
       float Delta_eta1 = Nu_eta1 - Nu1_eta1; 
       float MtvsNuNu1 = sqrt(2*NuPtMag1*Nu1PtMag1*(1-cos(theta4)));
       float MtvsZ1 = v_Zcpy.Mt();
       
       //For transverse mass in Modified lab frame (Z travelling only in one direction)
       TLorentzVector v_Znew = v_Z;             //definig new vectors
       TLorentzVector v_Nunew = v_Nu;
       TLorentzVector v_Nu1new = v_Nu1;

       TVector3 b1 = v_Znew.BoostVector();      //boosting to a frame, where Z is travelling only in z
       v_Znew.Boost(-b1.Px(),-b1.Py(),0);
       v_Nunew.Boost(-b1.Px(),-b1.Py(),0);
       v_Nu1new.Boost(-b1.Px(),-b1.Py(),0);

       TVector3 v_NuPtnew(v_Nunew.Px(), v_Nunew.Py(), 0);
       TVector3 v_Nu1Ptnew(v_Nu1new.Px(), v_Nu1new.Py(), 0);
       double NuPtMagnew = v_Nunew.Pt();
       double Nu1PtMagnew = v_Nu1new.Pt();
       float theta3new = v_NuPtnew.Angle(v_Nu1Ptnew);
       float Nu_etanew = v_Nunew.Eta();
       float Nu1_etanew = v_Nu1new.Eta();
       float Delta_etanew = Nu_etanew - Nu1_etanew;
       double MtvsNuNunew = sqrt(2*NuPtMagnew*Nu1PtMagnew*(1-cos(theta3new)));
       double MtvsZnew = v_Znew.Mt();

       //for counting events, having a specific flavour
       if ((*Nu_PdgId)[0] == 11) i++;
       if ((*Nu_PdgId)[0] == 12) j++;
       if ((*Nu_PdgId)[0] == 13) k++;
       if ((*Nu_PdgId)[0] == 14) l++;
       if ((*Nu_PdgId)[0] == 15) m++;
       if ((*Nu_PdgId)[0] == 16) n++;

       //for calculating transverse mass by formula without using any approximation
       float Nu_M2Nap = v_Nunew.Mag()*v_Nunew.Mag();       //modified lab frame
       float Nu1_M2Nap = v_Nu1new.Mag()*v_Nu1new.Mag();
       float Nu_EtNap = sqrt((Nu_M2Nap) + (NuPtMagnew * NuPtMagnew));
       float Nu1_EtNap = sqrt((Nu1_M2Nap) + (Nu1PtMagnew * Nu1PtMagnew));
       float MtvsNuNuNap = sqrt(((Nu_EtNap+Nu1_EtNap)*(Nu_EtNap+Nu1_EtNap))-((v_NuPtnew + v_Nu1Ptnew).Dot(v_NuPtnew + v_Nu1Ptnew)));
       

       float Nu_M2Nap1 = v_Nucpy.Mag()*v_Nucpy.Mag();      //rest frame
       float Nu1_M2Nap1 = v_Nu1cpy.Mag()*v_Nu1cpy.Mag();
       float Nu_EtNap1 = sqrt((Nu_M2Nap1) + (NuPtMag1 * NuPtMag1));
       float Nu1_EtNap1 = sqrt((Nu1_M2Nap1) + (Nu1PtMag1 * Nu1PtMag1));
       float MtvsNuNuNap1 = sqrt(((Nu_EtNap1+Nu1_EtNap1)*(Nu_EtNap1+Nu1_EtNap1))-((v_NuPt1 + v_Nu1Pt1).Dot(v_NuPt1 + v_Nu1Pt1)));
       

     



       h_Zenergy -> Fill ((*Z_E)[0]);
       h_ZPdgId -> Fill ((*Z_PdgId)[0]);
       h_Zmass -> Fill (M_Z);
       h_ZPx -> Fill ((*Z_Px)[0]);
       h_ZPy -> Fill ((*Z_Py)[0]);
       h_ZPz -> Fill ((*Z_Pz)[0]);
       h_ZP -> Fill (Z_P);
       h_ZPM -> Fill (Z_P,M_Z);
       h_ZNuM -> Fill (M_nunu, M_Z);
       h_ptheta -> Fill (Z_P,theta);
       h_pzr -> Fill (Z_P,r);
       h_NuPdgId -> Fill((*Nu_PdgId)[0]);
       h_NuPx -> Fill ((*Nu_Px)[0]);
       h_NuPy -> Fill ((*Nu_Py)[0]);
       h_NuPz -> Fill ((*Nu_Pz)[0]);
       h_Nu1Px -> Fill ((*Nu1_Px)[0]);
       h_Nu1Py -> Fill ((*Nu1_Py)[0]);
       h_Nu1Pz -> Fill ((*Nu1_Pz)[0]);
       h_ZNuNu1P -> Fill (Z_P,NuNu1_P);
       h_Ztheta -> Fill (Z_P,theta2);
       h_rNuNu1P1 -> Fill (Z_P,(Nu_P1/Nu1_P1));
       h_NuPP1 -> Fill (Nu_P,Nu_P1);
       h_Nu1PP1 -> Fill (Nu1_P,Nu1_P1);
       h_dPZP -> Fill (Z_P,dP_Nu);
       h_Stat -> Fill (proj,dP_Nu);
       h_ZMNuM -> Fill (M_nunu);
       h_DP -> Fill(dP_Nu);
       h_Mt -> Fill (MtvsNuNu);       
       h_ZPt -> Fill (v_ZPt.Mag());
       h_NuPt -> Fill (v_NuPt.Mag());
       h_Nu1Pt -> Fill (v_Nu1Pt.Mag());
       h_NuLRPt -> Fill (v_NuPt.Mag(),v_NuPt1.Mag());
       h_NuPtPt1 -> Fill(NuPtMag,NuPtMag1);
       h_Nu1PtPt1 -> Fill(v_Nucpy.E(),v_Nunew.E());
       h_InvZMt -> Fill(MtvsZ1,MtvsZ);
       h_InvNu-> Fill(MtvsNuNu1,MtvsNuNu);

       h_Comp -> Fill(v_Nunew.M(),v_Nu.M());
       h_Test -> Fill (MtvsZ);

       if (Z_P >= 500)
	 {h_LNuNu1P -> Fill (Nu_P,Nu1_P);
	  h_RNuNu1P -> Fill (Nu_P1,Nu1_P1);}
       if (Z_P <= 400) h_dPZP04 -> Fill(dP_Nu);
       if (Z_P > 400 && Z_P <= 800) h_dPZP48 -> Fill(dP_Nu);
       if (Z_P > 800 && Z_P <= 1200) h_dPZP812 -> Fill(dP_Nu);
       if (Z_P > 1200 && Z_P <= 1600) h_dPZP1216 -> Fill(dP_Nu);
       if ((*Nu_PdgId)[0]==13 && (*Nu1_PdgId)[0]==-13) h_ZMMu->Fill(M_nunu);
       if ((*Nu_PdgId)[0]==11 && (*Nu1_PdgId)[0]==-11) h_ZMe->Fill(M_nunu);
       if ((*Nu_PdgId)[0]==15 && (*Nu1_PdgId)[0]==-15) h_ZMTau->Fill(M_nunu);
       if (Z_P <=100 ) h_Mt100 -> Fill (MtvsNuNu);
       if (Z_P >100 && Z_P <=200 ) h_Mt200 -> Fill (MtvsNuNu);
       if (Z_P >200 && Z_P <=400 ) h_Mt400 -> Fill (MtvsNuNu);
       if (Z_P >400 ) h_Mt400abv -> Fill (MtvsNuNu);


   //counter:
   int decade;
   double progress = 10.0 * jentry / (1.0 * nentries);
   int k = int (progress);
      if (k > decade)
   cout << 10 * k << " %" << endl;
   decade = k;

   // cout << Nu_M2Nap << ",    " << Nu_M2Nap1 << '\n';
   // cout << Nu1_M2Nap << ",    " << Nu1_M2Nap1 << "\n\n";

   if (MtvsNuNuNap == MtvsNuNunew) l++;


     }

   //Writing the Histograms in root file
   myFile->cd();   
   h_ZPdgId -> Write();
   h_Zmass -> Write();
   h_Zenergy -> Write();
   h_ZPx -> Write();
   h_ZPy -> Write();
   h_ZPz -> Write();
   h_ZP -> Write();
   h_ZPM -> Write();
   h_ZNuM -> Write();
   h_ptheta -> Write();
   h_pzr -> Write();
   h_NuPdgId -> Write();
   h_NuPx -> Write();
   h_NuPy -> Write();
   h_NuPz -> Write();
   h_Nu1Px -> Write();
   h_Nu1Py -> Write();
   h_Nu1Pz -> Write();
   h_ZNuNu1P -> Write();
   h_Ztheta -> Write();
   h_NuPP1 -> Write();
   h_Nu1PP1 -> Write();
   h_rNuNu1P1 -> Write();
   h_LNuNu1P -> Write();
   h_RNuNu1P -> Write();
   h_dPZP -> Write();
   h_Stat -> Write();
   h_Mt -> Write();
   h_ZPt -> Write();
   h_NuPt -> Write();
   h_Nu1Pt -> Write();
   h_NuLRPt -> Write();
   h_dPZP04 -> Write();
   h_dPZP48 -> Write();
   h_dPZP812 -> Write();
   h_dPZP1216 -> Write();
   h_ZMNuM -> Write();
   h_ZMMu -> Write();
   h_ZMe -> Write();
   h_ZMTau -> Write();
   h_NuPtPt1 -> Write();
   h_Nu1PtPt1 -> Write();
   h_DP -> Write();
   h_Mt100 -> Write();
   h_Mt200 -> Write();
   h_Mt400 -> Write();
   h_Mt400abv -> Write();
   h_Comp -> Write();
   h_Test-> Write();
   h_InvZMt -> Write();
   h_InvNu-> Write();

   
}
   //h_ZPt -> Write();
   //h_DeltaPhi -> Write();
   //h_V2V3 -> Write();
   //auto legend = new TLegend(0.1,0.7,0.48,0.9);
   //legend->SetHeader("Input files","C"); // option "C" allows to center the header
   //legend->AddEntry(h_Zmass,"ZnunuJetsSimple.root","l");
   //legend->Draw();

   // cout << "Nu dominates in " << i << " events, Nu1 dominates in " << j << " and in " << k << " events both are equal." << '\n';

       
       //h_Zmpx -> Fill(sqrt(M2_Z),(*Z_Px)[0]);

       /* if (jentry && (jentry%kUPDATE) == 0) {
         if (jentry == kUPDATE) {
	   Zenergy->Draw();
	   c3->Update();}
	   }*/

   //auto legend = new TLegend(0.1,0.7,0.48,0.9);
   //legend->SetHeader("Input files","C"); // option "C" allows to center the header
   //legend->AddEntry(h_Zmass,"ZnunuJetsSimple.root","l");
  
   
   //cout << "in " << t << " transverse momenta are same " <<'\n';  

  

 
// float dp_Nu = Nu_P - Nu1_P;
       // if (dp_Nu > 0) i++;
       // if (dp_Nu < 0) j++;
       // if (dp_Nu == 0) k++;

       // double NuPtMagnew = v_Nu1cpy.Pt();
       // double Nu1PtMagnew = v_Nu1cpy.Pt();

       //v_Nu.Boost(b);  //boosting back to lab
       //v_Nu1.Boost(b);
       
       // Calculating Transvese mass form TLorentzVector in Lab Frame:
       // double Nu_Phi = v_Nu.Phi();
       // double Nu1_Phi = v_Nu1.Phi();
       
       // double deltaPhi = Nu_Phi-Nu1_Phi;
       // double NuPtMag = v_Nu.Pt();
       // double NuPtMagr = v_Nu.Pt(v_Z.Vect());
       // double Nu1PtMag = v_Nu1.Pt();

       // if (deltaPhi > M_PI) deltaPhi -= 2 * M_PI;
       // if (deltaPhi < -M_PI) deltaPhi += 2 * M_PI;
       
       // double DeltaPhi()
  //      {
  // double result = Nu_Phi - Nu1_Phi;
  // while (result > M_PI)    result -= 2 * M_PI;
  // while (result <= -M_PI)  result += 2 * M_PI;
  // return result};
       
       // float  Mtvs2NuNu = sqrt(2*NuPtMag*Nu1PtMag*(1-cos(deltaPhi)));

      // Calculating Transvese mass form TLorentzVector in Lab Frame:
       // double Nu_Phi1 = v_Nucpy.Phi();
       // double Nu1_Phi1 = v_Nu1cpy.Phi();
       // double deltaPhi1 = Nu_Phi1-Nu1_Phi1;
       // double NuPtMag1 = v_Nucpy.Pt();
       // double Nu1PtMag1 = v_Nu1cpy.Pt();

       // if (deltaPhi1 > M_PI) deltaPhi1 -= 2 * M_PI;
       // if (deltaPhi1 < -M_PI) deltaPhi1 += 2 * M_PI;

       //float theta3new = v_NunewPt.Angle(v_Nu1newPt);
       //float MtvsnewNuNu = sqrt(2*v_NunewPt.Mag()*v_Nu1newPt.Mag()*(1-cos(theta3new)));


       //double Mtnew = v_Znew.Mt();
        // double DeltaPhi1()
  // 	{
  // double result1 = Nu_Phi1 - Nu1_Phi1;
  // while (result1 > 3.14)    result1 -= 2 * 3.14;
  // while (result1 <= -3.14)  result1 += 2 * 3.14;
  // return result1}; 
       //float  Mtvs2NuNu1 = sqrt(2*NuPtMag1*Nu1PtMag1*(1-cos(deltaPhi1)));


       //cout << "delta phi: " << deltaPhi << '\n';
	//if (jentry <= 100) cout << "Z_Px: " << v_Zcpy.Px() << " Z_Py: " << v_Zcpy.Py() << " Z_Pz: " << v_Zcpy.Py() << '\n';

      //float check = v_NuPt.Dot(v_Z.Vect());
       //cout << check << "\n";

       //if (c_theta1 > 1||c_theta1<-1) cout <<"c_theta1  "<< c_theta1 << '\n';

       //if(jentry<1000)

          //double progress = 100.0 * jentry / (1.0 * nentries);
       //cout << progress << " %" << endl;
          
      
      
      //cout << Z[jentry] << '\n';
      //if (jentry<100)cout << "Nu PdgId: " << Nu1_PdgId->size() << '\n'; //"Z PdgId: "<< Z_PdgId->size() <<'\n';
       /* for (UInt_t ii = 0; ii < Z_PdgId->size(); ++ii)
      {float M2_Z;
        M2_Z = pow((*Z_E)[ii],2)-pow((*Z_Px)[ii],2)-pow((*Z_Py)[ii],2)-pow((*Z_Pz)[ii],2);
        if (jentry < 100) cout << "Z_PdgId: " << (*Z_PdgId)[ii] << ", Z_E: "<< (*Z_E)[ii] << ", Z_Px: " << (*Z_Px)[ii] << ", Z_Py: " << (*Z_Py)[ii] << ", Z_Pz: " << (*Z_Pz)[ii] << ", M_Z: " << sqrt(M2_Z) << '\n';
	}*/
	

	  //if (jentry < 50) cout << "M2: " << M2 << '\n';
	  //}
      //for (UInt_t ii = 0; ii < Z_Px->size(); ++ii)
      // {if (jentry < 100) cout << "Z_Px: " << (*Z_Px)[ii] << ", ";
      //}
      //for (UInt_t ii = 0; ii < Z_Py->size(); ++ii)
      //{if (jentry < 100) cout << "Z_Py: " << (*Z_Py)[ii] << ", ";
      //}
	  //}

      //for (UInt_t ii = 0; ii < Nu_PdgId->size(); ++ii)
      //{float M2_Nu;
      //  M2_Nu = pow((*Nu_E)[ii],2)-pow((*Nu_Px)[ii],2)-pow((*Nu_Py)[ii],2)-pow((*Nu_Pz)[ii],2);
      //  if (jentry < 10) cout << "Nu_PdgId: " << (*Nu_PdgId)[ii] << ", Nu_E: "<< (*Nu_E)[ii] << ", Nu_Px: " << (*Nu_Px)[ii] << ", Nu_Py: " << (*Nu_Py)[ii] << ", Nu_Pz: " << (*Nu_Pz)[ii] << ", M_Nu: " << sqrt(M2_Nu) << '\n';
      //}

      //for (UInt_t ii = 0; ii < Z_PdgId->size(); ++ii)
	// {float  M2_Nu1;
        //M2_Nu1 = pow((*Nu1_E)[ii],2)-pow((*Nu1_Px)[ii],2)-pow((*Nu1_Py)[ii],2)-pow((*Nu1_Pz)[ii],2);
        //if (jentry < 10) cout << "Nu1_PdgId: " << (*Nu1_PdgId)[ii] << ", Nu1_E: "<< (*Nu1_E)[ii] << ", Nu1_Px: " << (*Nu1_Px)[ii] << ", Nu1_Py: " << (*Nu1_Py)[ii] << ", Nu1_Pz: " << (*Nu1_Pz)[ii] << ", M_Nu1: " << sqrt(M2_Nu1) <<"\n";
	/*if (jentry < 10) cout << v_Nu1.E() << "  " << v_Nu1.Px() << "  " << v_Nu1.Py() << "  " << v_Nu1.Pz() << "\n";
	  if (jentry < 10) cout << (*Nu1_E)[0] << "  " << (*Nu1_Px)[0] << "  " << (*Nu1_Py)[0] << "  " << (*Nu1_Pz)[0] << "\n\n";}*/
   
      
	// printing total mass of Nu and Nu1
        //if (jentry < 50) cout << "Mass of Z: " << M_Z << ", Total mass of Nutrinos: " << M_nunu << '\n';
   //if (jentry < 10) cout << theta << '\n' << theta1 << "\n\n" ;
      // cout << c_theta << '\n';
       //cout << "Nu Pdg Id: " << (*Nu_PdgId)[0] << '\n';
     

   //h_ZPx -> Draw();
   //h_ZPy -> Draw();
   //h_ZPz -> Draw();
   //Zenergy -> Draw();
   //ZPdgId -> Draw();
   //h_Zmass -> Draw("hist");

   /*TLegend* legends = new TLegend(0.44, 0.8, 0.9, 0.9,"","brNDC"); // the numbers determine the position of the box 
   legends->SetFillColor(0); 
   //legends->SetHeader(inputs); 
   legends->AddEntry(h_Zmass,"jflsdkf","l");//(name of hist,what you want it called in legend, l=line, p=polymarker, f=boxy thing ) 
   legends->SetTextSize(0.04);
    legends->SetMarkerStyle(1);
    legends->Draw();*/
//h_V2V3 -> Fill (MtvsNuNu,Mtvs2NuNu);
       //h_DeltaPhi -> Fill(deltaPhi,deltaPhi1);

       
       //if ((*Z_Pz)[0]==0 && (*Z_Px)[0]==0 && (*Z_Py)[0]==0) t++;
       //if(v_NuPt.Mag() == v_NuPt1.Mag()) t++;
       ///cout << "pz in z frame: " << v_Zcpy.Vect().Mag() << "\n";
       //cout << "sum of pz: " << (*Nu_Pz)[0]+(*Nu1_Pz)[0] << "\n\n";      

       //Double_t theta3 = (v_Z.Vect()).Angle((v_Nu.Vect()));
       //h_ZPt -> Fill (Z_Pt);
       //if (jentry <= 10) cout << v_Nu.Px() << ", " << v_Nu.Py() << ", " << v_Nu.Pz() << '\n';
       //if (jentry <= 10000) cout << v_Nu.Px() << ", " << v_Nu.Py() << ", " << v_Nu.Pz() << "\n";
       //cout << b[0] << ", " << b[1] << ", " << b[2] << '\n';

       //if (Z_P >= 500)
       //h_Zmpx -> Fill(sqrt(M2_Z),(*Z_Px)[0]);

  //for Mt in rest and lab for PZ<100
  // TH1 *h_Mt100 = new TH2F("Mt vs Mt1 Zrest", "comparision of transverse mass for P_Z<100",50,0,150,50,0,150);
  // h_Mt100->SetMarkerStyle(21);
  // h_Mt100->SetMarkerSize(0.7);
  // h_Mt100->SetXTitle("");
  // h_Mt100->SetXTitle("");

// if (i != 0) cout << i << " events with electron." << endl;
   // if (j != 0) cout << j << " events with electron neutrino." << endl;
   // if (k != 0) cout << k << " events with Muon." << endl;
   // if (l != 0) cout << l << " events with Muon neutrino." << endl;
   // if (m != 0) cout << m << " events with tau." << endl;
   // if (n != 0) cout << n << " events with tau neutrino." << endl;

   
//if (FileName == "ZToNuNuJets.root") std::unique_ptr<TFile> myFile( TFile::Open("Z2.root", "RECREATE"));
  //if (FileName == "ZToLLJets.root") std::unique_ptr<TFile> myFile( TFile::Open("Z3.root", "RECREATE"));

  //const Int_t kUPDATE = 111500;
