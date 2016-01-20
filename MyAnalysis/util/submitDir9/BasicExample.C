
#include "TH1F.h"
#include "TPad.h"
#include "TRandom.h"

#include "/afs/cern.ch/user/a/altaylor/atlasStyle/AtlasLabels.h"
#include "/afs/cern.ch/user/a/altaylor/atlasStyle/AtlasStyle.h"

void BasicExample()
{
  SetAtlasStyle();

  // generate some random data
  /* TH1F* hpx  = new TH1F("hpx","This is the px distribution",100,-4,4);
  gRandom->SetSeed();
  for (Int_t i = 0; i < 25000; i++) {
    hpx->Fill(gRandom->Gaus());
  }
  hpx->GetXaxis()->SetTitle("random variable [unit]");
  hpx->GetYaxis()->SetTitle("#frac{dN}{dr} [unit^{-1}]");
  hpx->SetMaximum(1000.); */

  // and plot it

  TH1D* histo1;

  TFile file("hist-truth_events1.root");
  file.GetObject("h_percentDiff", histo1);

  histo1->SetDirectory(0);

  
  histo1->Draw();

#ifdef __CINT__
  gROOT->LoadMacro("/afs/cern.ch/user/a/altaylor/atlasStyle/AtlasLabels.C");
#endif

  ATLASVersion("1.000000000");

  return;
}

#ifndef __CINT__
int main() { 
  BasicExample();
  gPad->Print("basic.png");
  return 0;
}
#endif
