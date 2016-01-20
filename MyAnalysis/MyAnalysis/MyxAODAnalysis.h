#ifndef MyAnalysis_MyxAODAnalysis_H
#define MyAnalysis_MyxAODAnalysis_H

#include <EventLoop/Algorithm.h>
#include <TH1.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

#include "TH1F.h"
#include "TTree.h"
#include "TRandom3.h"
#include "UpgradePerformanceFunctions/UpgradePerformanceFunctions.h"
#include "xAODTruth/TruthParticle.h"
#include "xAODTruth/TruthParticleContainer.h"



class MyxAODAnalysis : public EL::Algorithm
{
  // put your configuration variables here as public variables.
  // that way they can be set directly from CINT and python.
public:
  // float cutValue;


  float averageMuValue = 0.;

  // variables that don't get filled at submission time should be
  // protected from being send from the submission node to the worker
  // node (done by the //!)

  // int m_eventCounter; //!
  TH1 *myHist; //! 
  TH1 *h_jetPt; //!
  TH1 *h_tHiggsMass; //!
  TH1 *h_rHiggsMass; //! 

public:
  // Tree *myTree; //!
  // TH1 *myHist; //!

  // Tree *myTree; //!
  // TH1 *myHist; //!
TRandom3 m_random3; //!

 struct flavLorentzJet {
   TLorentzVector vec;
   std::string flavour; 

 };


 int semiLeptonCounter; //!
 int triggerCounter; //!

 int oneCutCounter; //!
 int twoCutCounter; //!
 int threeCutCounter; //!
 int fourCutCounter; //!
 int fiveCutCounter; //!


 TH1F *h_eta0; //!
 TH1F *h_eta1; //!
 TH1F *h_eta2; //!
 TH1F *h_eta3; //!
 TH1F *h_eta4; //!


 TH1F *h_muonUnsmearedPt; //!
 TH1F *h_muonSmearedPt; //!
 TH1F *h_rawMETPhi; //!
 TH1F *h_smearedMETPhi; //!

 TH1F *h_jetUnsmearedE; //!
 TH1F *h_jetSmearedE; //!
 TH1F *h_percentDiff; //!

 TH1F *h_nPileup; //!
 TH1F *h_tagEffP70; //!
 TH1F *h_tagEffP85; //!
 TH1F *h_tagEffB70; //!
 TH1F *h_tagEffB85; //!

 TH1F *h_tagEffC70; //!
 TH1F *h_tagEffC85; //!

 TH1F *h_tagEffL70; //!
 TH1F *h_tagEffL85; //!

 TH1F *h_muonTrig; //!
 TH1F *h_electronTrig; //!

 TH1F *h_nbjetsB; //!
  TH1F *h_nbjetsA; //!

 TH1F *h_rand; //!

 TH1F *h_nPileupB; //!
 TH1F *h_nPileupA; //!
 TH1F *h_slTop; //!
 TH1F *h_recoSLTop; //!

 TH1F *h_nHSB; //!
 TH1F *h_nHSA; //!

 TH1F *h_trackEff; //!
 TH1F *h_trackEffHS; //!

 TH1F *h_recoHiggs; //!
  TH1F *h_recoHiggsB; //!

 TH1F *h_recotHiggs; //!

 TH1F *h_hadronicTop; //!
  TH1F *h_rhadronicTop; //!
 

 
TTree *outputTree; //!
int outputEventNumber; //!
int outputPileupJetSize; //!
int m_eventCounter; //!
UpgradePerformanceFunctions *m_upgrade; //!

// double tester(double a, double b); //!
//ouble getbHadrons(const xAOD::TruthParticleContainer* truthCont); //!


 std::vector<TLorentzVector> getbHadrons(const xAOD::TruthParticleContainer* truthCont); //!

 std::vector<int> recoHiggs(std::vector<flavLorentzJet> lorentzJets, int jet1, int jet2, bool usebtag); //!

 std::vector<int> recotHiggs(std::vector<TLorentzVector> lorentzJets, int jet1, int jet2); //!

 
 bool getEventType(const xAOD::TruthParticleContainer* truthCont); //!

 bool toTrigger(std::vector<TLorentzVector> lorentzMuons, std::vector<TLorentzVector> lorentzElectrons); //!

 // float recoHiggs(std::vector<flavLorentzJet> lorentzJets); //!

 //float MyxAODAnalysis::recoHiggs(std::vector<flavLorentzJet> lorentzJets)

 //getNeutrinoPz(std::vector<flavLorentzJet> lorentzJets, TLorentzVector lepton, double mpx, double mpy)

 double getNeutrinoPz(std::vector<flavLorentzJet> lorentzJets, TLorentzVector lepton, double mpx, double mpy, std::vector<int> higgsI,  std::vector<int> higgsII); //!

 int recoSLTop(std::vector<flavLorentzJet> lorentzJets, TLorentzVector lepton, TLorentzVector neutrino, std::vector<int> higgsIndicesI, std::vector<int> higgsIndicesII); //!

 std::vector<int> recoHadronicTop(std::vector<flavLorentzJet> lorentzJets, std::vector<int> higgsIndicesI, std::vector<int> higgsIndicesII, int slTopIndex); //!


 int recotSLTop(std::vector<TLorentzVector> lorentzJets, TLorentzVector lepton, TLorentzVector neutrino, std::vector<int> higgsIndicesI, std::vector<int> higgsIndicesII); //!
 
 bool isBhadron(int abs_pdgId); //!
 bool isChadron(int abs_pdgId); //!

 // bool isChadron(int abs_pdgId); //!

  std::string getFlavour(TLorentzVector, const xAOD::TruthParticleContainer* truthCont); //!

  //   std::string MyxAODAnalysis::getFlavour(TLorentzVector jet, const xAOD::TruthParticleContainer* truthCont) {


 

  // this is a standard constructor
  MyxAODAnalysis ();

  // these are the functions inherited from Algorithm
  virtual EL::StatusCode setupJob (EL::Job& job);
  virtual EL::StatusCode fileExecute ();
  virtual EL::StatusCode histInitialize ();
  virtual EL::StatusCode changeInput (bool firstFile);
  virtual EL::StatusCode initialize ();
  virtual EL::StatusCode execute ();
  virtual EL::StatusCode postExecute ();
  virtual EL::StatusCode finalize ();
  virtual EL::StatusCode histFinalize ();

  //virtual EL::double tester(double a,double b);

  //  double tester(double a, double b);

  // this is needed to distribute the algorithm to the workers
  ClassDef(MyxAODAnalysis, 1);
};

#endif
