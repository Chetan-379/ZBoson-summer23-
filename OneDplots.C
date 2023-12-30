#include <stdio.h>
#include<fstream>
#include <vector>
#include <string>
#include <map>
#include<iostream>
using namespace std;
void OneDplots(string filename3, string filename2, string filename1)
{
  //different character to assign a particular name to it
  char* hname1 = new char[200];
  char* hname2  = new char[200];
  char* hname3 = new char[200];
  char* hist_name1 = new char[200];
  char* hist_name2 = new char[200];
  char* hist_name3 = new char[200];
  char* hist_name5 = new char[200];
  char* hist_name6 = new char[200];
  char* hist_name7 = new char[200];
  char* hist_name8 = new char[200];
  char* hist_name9 = new char[200];
  char* hist_name10 = new char[200];
  char* hist_name11 = new char[200];
  char* hist_name12 = new char[200];
  char* hist_name13  = new char[200];
  char* hist_name14 = new char[200];
  char* hist_name15 = new char[200];
  char* hist_name16 = new char[200];
  char* hist_name17 = new char[200];
  char* hist_name18= new char[200];
  char* hist_name19= new char[200];  
  char* title=new char[2000];
  char* full_path = new char[2000];
  char* full_path1 = new char[2000];
  char* full_path2 = new char[2000];
  char* full_path3 = new char[2000];
  char* full_path4 = new char[2000];
  char* full_path5 = new char[2000];
  char* full_path6 = new char[2000];
  char* full_path7 = new char[2000];
  char* full_path8 = new char[2000];
  char* full_path9 = new char[2000];
  char* full_path10 = new char[2000];
  char* full_path11= new char[2000];
  char* full_path12 = new char[2000];
  char* full_path13 = new char[2000];
  char* full_path14 = new char[2000];
  char* full_path15 = new char[2000];
  char* full_path16 = new char[2000];
  char* full_path17= new char[2000];
  char* full_path18= new char[2000];
  char* full_path19 = new char[2000];
  char* full_path20= new char[2000];
  char* path2= new char[2000];

  sprintf(hname1,"%s",filename1.c_str()); //hname = input filename to read from
  sprintf(hname2,"%s",filename2.c_str());
  sprintf(hname3,"%s",filename3.c_str());
  
  //sprintf(path2,"./");//directory where you want to create your png file
  TFile * inputfile1 = new TFile(hname1,"READ");//open input root file
  TFile * inputfile2 = new TFile(hname2,"READ");
  TFile * inputfile3 = new TFile(hname3,"READ");
  sprintf(hist_name1,"Mt_ZP(400 abv)");
  sprintf(hist_name2,"Mt_ZP_0_100");
  sprintf(hist_name3,"Mt_ZP_100_200");
  // sprintf(full_path2,"%s/h_Zmass.png",path2);
  
  TH1F* resp1=(TH1F*)inputfile1->Get(hist_name1);                                                                TH1F* resp2=(TH1F*)inputfile2->Get(hist_name2);
  TH1F* resp3=(TH1F*)inputfile3->Get(hist_name3);
  
   TPaveStats *ptstats1 = new TPaveStats(0.75,0.75,0.9,0.9,"brNDC");
   ptstats1->SetBorderSize(1);
   ptstats1->SetFillColor(0);
   ptstats1->SetLineColor(kBlue);
   ptstats1->SetTextAlign(12);
   ptstats1->SetTextColor(kBlue);
   ptstats1->SetTextFont(42);
   ptstats1->SetOptStat(1111);
   ptstats1->SetOptFit(1);
   resp1->GetListOfFunctions()->Add(ptstats1);
   ptstats1->SetParent(resp1);
   resp1->Scale(1./resp1->Integral());

   TPaveStats *ptstats2 = new TPaveStats(0.6,0.75,0.75,0.9,"brNDC");
   ptstats2->SetBorderSize(1);
   ptstats2->SetFillColor(0);
   ptstats2->SetLineColor(kGreen);
   ptstats2->SetTextAlign(12);
   ptstats2->SetTextColor(kGreen);
   ptstats2->SetTextFont(42);
   ptstats2->SetOptStat(1111);
   ptstats2->SetOptFit(1);
   resp2->GetListOfFunctions()->Add(ptstats2);
   ptstats2->SetParent(resp2);
   resp2->Scale(1./resp2->Integral());

   TPaveStats *ptstats3 = new TPaveStats(0.45,0.75,0.6,0.9,"brNDC");
   ptstats3->SetBorderSize(1);
   ptstats3->SetFillColor(0);
   ptstats3->SetLineColor(kRed);
   ptstats3->SetTextAlign(12);
   ptstats3->SetTextColor(kRed);
   ptstats3->SetTextFont(42);
   ptstats3->SetOptStat(1111);
   ptstats3->SetOptFit(1);
   resp3->GetListOfFunctions()->Add(ptstats3);
   ptstats3->SetParent(resp3);
   resp3->Scale(1./resp3->Integral());

   auto legend = new TLegend(0.65,0.20,0.85,0.3);
   legend->SetHeader("","C");
   legend->AddEntry(resp1, "ZToLLJets.root","l");
   legend->AddEntry(resp2, "ZToNuNuJets.root","l");
   legend->AddEntry(resp3, "ZnunuJetsSimple.root","l");


  TCanvas *Canvas_n2 = new TCanvas(hist_name2, hist_name2,800,800,1400,1400);
  Canvas_n2->Range(-60.25,-0.625,562.25,0.625);
  Canvas_n2->SetFillColor(0);
  Canvas_n2->SetBorderMode(0);
  Canvas_n2->SetBorderSize(2);
  //  resp->GetXaxis()->SetRangeUser(0,2);//setting range
  resp1->Draw("hist"); //draw it on canvas
  resp2->Draw("hist sames");
  resp3->Draw("hist sames");
  legend->Draw("sames");
  Canvas_n2->Modified();
  Canvas_n2->cd();
  Canvas_n2->SetSelected(Canvas_n2);
  //Canvas_n2->SaveAs(full_path2); //save the file

}






