#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <MyAnalysis/MyxAODAnalysis.h>
// Infrastructure include(s):
#include "xAODRootAccess/Init.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODRootAccess/tools/Message.h"
// EDM includes:
#include "xAODEventInfo/EventInfo.h"
#include "xAODTruth/TruthParticle.h"
#include "xAODTruth/TruthParticleContainer.h"
#include "xAODMissingET/MissingETContainer.h"
#include "UpgradePerformanceFunctions/UpgradePerformanceFunctions.h"

#include "xAODMuon/MuonContainer.h"
#include "xAODEgamma/ElectronContainer.h"






#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

#include "xAODJet/JetContainer.h"
#include "xAODTruth/TruthEvent.h"
#include "xAODTruth/TruthEventContainer.h"

/// Helper macro for checking xAOD::TReturnCode return values
#define EL_RETURN_CHECK( CONTEXT, EXP )                 \
  do {                                                  \
    if( ! EXP.isSuccess() ) {			        \
      Error( CONTEXT,				        \
	     XAOD_MESSAGE( "Failed to execute: %s" ),	\
	     #EXP );					\
      return EL::StatusCode::FAILURE;			\
    }							\
  } while( false )


// this is needed to distribute the algorithm to the workers
ClassImp(MyxAODAnalysis)



MyxAODAnalysis :: MyxAODAnalysis ()
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().

  averageMuValue = 200.0;
}



EL::StatusCode MyxAODAnalysis :: setupJob (EL::Job& job)
{
  // Here you put code that sets up the job on the submission object
  // so that it is ready to work with your algorithm, e.g. you can
  // request the D3PDReader service or add output files.  Any code you
  // put here could instead also go into the submission script.  The
  // sole advantage of putting it here is that it gets automatically
  // activated/deactivated when you add/remove the algorithm from your
  // job, which may or may not be of value to you.
  // let's initialize the algorithm to use the xAODRootAccess package
  job.useXAOD ();
  //  xAOD::Init(); // call before opening first file
  EL_RETURN_CHECK( "setupJob()", xAOD::Init() ); // call before opening first file       

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: histInitialize ()
{
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.


  // here we create a counter for the semi lepton events
  //int semiLeptonCounter = 0;








  
  h_muonUnsmearedPt = new TH1F("h_muonUnsmearedPt", "Muon unsmeared p_{T} [GeV]", 100, 0., 200.);
  h_muonSmearedPt = new TH1F("h_muonSmearedPt", "Muon smeared p_{T} [GeV]", 100, 0., 200.);
  h_rawMETPhi = new TH1F("h_rawMETPhi", "Raw MET #phi direction", 100, -7., 7.);
  h_smearedMETPhi = new TH1F("h_smearedMETPhi", "Smeared MET #phi direction", 100, -7., 7.);
  
  h_jetUnsmearedE = new TH1F("h_jetUnsmearedE", "Unsmeared jet energy.. Entries/20GeV", 25, 0.0, 500.0);
  h_jetSmearedE = new TH1F("h_jetSmearedE", " Smeared jet energy.. Entries/20GeV", 25, 0.0, 500.0);
  h_percentDiff = new TH1F("h_percentDiff", " percent Diff.. Entries /2.5%", 80, -100.0, 100.0);

  h_nPileupB = new TH1F("h_nPileupB", " pile up jets Entries/Bin", 20, 0, 20);
    h_nPileupA = new TH1F("h_nPileupA", " pile up jets Entries/Bin", 20, 0, 20);

      h_nHSB = new TH1F("h_nHSB", " hard scatter before track Entries/Bin", 20, 0, 20);
    h_nHSA = new TH1F("h_nHSA", " hard scatter after track Entries/Bin", 20, 0, 20);

  h_nbjetsB = new TH1F("h_nbjetsB", " no. of bjets in an event Entries/Bin", 8, 0, 8);
    h_nbjetsA = new TH1F("h_nbjetsA", " no. of bjets in an event Entries/Bin", 8, 0, 8);

  h_eta0 = new TH1F("h_eta0", "jet energies / 4Gev", 20, 0, 80);
  h_eta1 = new TH1F("h_eta1", "jet energies / 4Gev", 20, 0, 80);
  h_eta2 = new TH1F("h_eta2", "jet energies / 4Gev", 20, 0, 80);
  h_eta3 = new TH1F("h_eta3", "jet energies / 4Gev", 20, 0, 80);
  h_eta4 = new TH1F("h_eta4", "jet energies / 4Gev", 20, 0, 80);







  

  h_tagEffP70 =new TH1F("h_tagEffP70", " tag efficiency for a pile up jet for working point 70 Entries/ 0.05 eff",20, 0, 1);
  h_tagEffP85 =new TH1F("h_tagEffP85", " tag efficiency for a pile up jet for working point 85 Entries/ 0.05 eff",20, 0, 1);

  h_tagEffB70 =new TH1F("h_tagEffB70", " tag efficiency for a b jet for working point 70 Entries/ 0.05 eff",20, 0, 1);
  h_tagEffB85 =new TH1F("h_tagEffB85", " tag efficiency for a b jet for working point 85 Entries/ 0.05 eff",20, 0, 1); 

  h_tagEffC70 =new TH1F("h_tagEffC70", " tag efficiency for a c jet for working point 70 Entries/ 0.05 eff",20, 0, 1);
  h_tagEffC85 =new TH1F("h_tagEffC85", " tag efficiency for a c jet for working point 85 Entries/ 0.05 eff",20, 0, 1); 

  h_tagEffL70 =new TH1F("h_tagEffL70", " tag efficiency for a l jet for working point 70 Entries/ 0.05 eff",20, 0, 1);
  h_tagEffL85 =new TH1F("h_tagEffL85", " tag efficiency for a l jet for working point 85 Entries/ 0.05 eff",20, 0, 1);

  h_muonTrig = new TH1F("h_muonTrig", "muon trigger efficiency / 0.05 eff",20, 0, 1);
  h_electronTrig =new TH1F("h_electronTrig", " electron trigger efficiency / 0.05 eff",20, 0, 1);

  h_rand =new TH1F("h_rand", " rand no / 0.1 ",10, 0, 1);

  h_trackEff =new TH1F("h_trackEff", " track Eff / 0.1 ",10, 0, 1);
  h_trackEffHS =new TH1F("h_trackEffHS", " track Eff HS / 0.1 ",10, 0, 1);

  
  h_recoHiggs = new TH1F("h_recoHiggs", " higgs Mass / 10 GeV ",25, 0, 250);
  h_recotHiggs = new TH1F("h_recotHiggs", " higgs Mass / 10 GeV ",20, 0, 200);


  h_recoHiggsB = new TH1F("h_recoHiggsB", " higgs Mass / 10 GeV ",25, 0, 250);
  
  h_slTop =new TH1F("h_slTop", " SemiLeptonic Top Mass / 10 GeV ",40, 0, 400);

  h_recoSLTop =new TH1F("h_recoSLTop", " SemiLeptonic Top Mass / 10 GeV ",40, 0, 400);
  h_hadronicTop =new TH1F("h_hadronicTop", " Hadronic Top Mass / 10 GeV ",40, 0, 400);
  h_rhadronicTop =new TH1F("h_rhadronicTop", " Hadronic Top Mass / 10 GeV ",40, 0, 400);
  


  
  outputTree = new TTree("outputTree", "Example output tree");
  outputTree->Branch("EventNumber", &outputEventNumber);
  outputTree->Branch("PileupJetSize", &outputPileupJetSize);


  wk()->addOutput(h_eta0);
  wk()->addOutput(h_eta1);
  wk()->addOutput(h_eta2);
  wk()->addOutput(h_eta3);
  wk()->addOutput(h_eta4);
  
  wk()->addOutput(h_slTop);
  wk()->addOutput(h_recoSLTop);
  wk()->addOutput(h_hadronicTop);
  wk()->addOutput(h_rhadronicTop);
  
  wk()->addOutput(h_jetUnsmearedE);
  wk()->addOutput(h_jetSmearedE);
  wk()->addOutput(h_percentDiff);
  
  wk()->addOutput(h_muonUnsmearedPt);
  wk()->addOutput(h_muonSmearedPt);
  wk()->addOutput(h_rawMETPhi);
  wk()->addOutput(h_smearedMETPhi);

  //  wk()->addOutput(h_nPileup);
  wk()->addOutput(h_nbjetsA);
    wk()->addOutput(h_nbjetsB);
  
  wk()->addOutput(h_tagEffP70);
  wk()->addOutput(h_tagEffP85);
  
  wk()->addOutput(h_tagEffL70);
  wk()->addOutput(h_tagEffL85);
  wk()->addOutput(h_tagEffC70);
  wk()->addOutput(h_tagEffC85);

  wk()->addOutput(h_tagEffB70);
  wk()->addOutput(h_tagEffB85);

  wk()->addOutput(h_muonTrig);
  wk()->addOutput(h_electronTrig);
  wk()->addOutput(h_electronTrig);


  // test

  wk()->addOutput(h_rand);

  wk()->addOutput(h_nPileupB);
  wk()->addOutput(h_nPileupA);

  wk()->addOutput(h_nHSB);
  wk()->addOutput(h_nHSA);

  
  wk()->addOutput(h_trackEff);
  wk()->addOutput(h_trackEffHS);

  wk()->addOutput(h_recoHiggs);
  wk()->addOutput(h_recoHiggsB);

  wk()->addOutput(h_recotHiggs);

  

  wk()->addOutput(outputTree);

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: changeInput (bool firstFile)
{
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  if (firstFile) {}
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: initialize ()
{
  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.
  xAOD::TEvent* event = wk()->xaodEvent();
  m_random3.SetSeed(1); // for local smearing
  //s
  Info("initialize()", "Setting up UpgradePerformanceFunctions with mu=%f", averageMuValue); 

  // Initializations specific to UpgradePerformanceFunctions
  m_upgrade = new UpgradePerformanceFunctions();
  m_upgrade->setLayout(UpgradePerformanceFunctions::gold);
  m_upgrade->setAvgMu(averageMuValue);
  m_upgrade->setElectronWorkingPoint(UpgradePerformanceFunctions::looseElectron);
  m_upgrade->setElectronRandomSeed(1);
  m_upgrade->setMuonWorkingPoint(UpgradePerformanceFunctions::tightMuon);
  m_upgrade->loadMETHistograms("/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/UpgradePerformanceFunctions/share/sumetPU_mu200_ttbar_gold.root");

  m_upgrade->setMETRandomSeed(1);
  //m_upgrade->loadMETHistograms("UpgradePerformanceFunctions/sumetPU_mu200_ttbar_gold.root");

  //m_upgrade->setFlavourTaggingCalibrationFilename("/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/UpgradePerformanceFunctions/share/flavor_tags_v0.3.root"); // OK for RootCore
  m_upgrade->setFlavourTaggingCalibrationFilename("/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/UpgradePerformanceFunctions/share/flavor_tags_v0.8.root"); // OK for RootCore

  m_upgrade->setJetRandomSeed(1);
  m_upgrade->setPileupUseTrackConf(true);

  
  m_upgrade->setPileupRandomSeed(1);
  //m_upgrade->setPileupRandomSeed(1);
  m_upgrade->setPileupJetPtThresholdMeV(30000.);
  m_upgrade->setPileupEfficiencyScheme(UpgradePerformanceFunctions::PileupEff::PU);
  //m_upgrade->setPileupEff(0.9);
  m_upgrade->setPileupEff(0.02);
  m_upgrade->setPileupTemplatesPath("/afs/cern.ch/atlas/groups/UpgradePhysics/PerformanceFunctions/");

  // as a check, let's see the number of events in our xAOD
  Info("initialize()", "Number of events = %lli", event->getEntries() ); // print long long int
  m_eventCounter = 0;

  semiLeptonCounter = 0;
  triggerCounter = 0;

  oneCutCounter = 0;
  twoCutCounter = 0;
  threeCutCounter = 0;
  fourCutCounter = 0;
  fiveCutCounter = 0;

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: execute ()
{
  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.
  xAOD::TEvent* event = wk()->xaodEvent();

  // print every 100 events, so we know where we are:
  if( (m_eventCounter % 100) == 0 ) 
    Info("execute()", "Event number = %i", m_eventCounter );
  m_eventCounter++;
  
  //----------------------------
  // Event information
  //--------------------------- 
  const xAOD::EventInfo* eventInfo = 0;
  EL_RETURN_CHECK("execute",event->retrieve( eventInfo, "EventInfo"));  
  outputEventNumber = eventInfo->eventNumber();





  
  
  // check if the event is data or MC
    bool isMC = false;
  if(eventInfo->eventType( xAOD::EventInfo::IS_SIMULATION ) ){
    isMC = true;
  }

  

      
    const xAOD::TruthParticleContainer* truthCont = 0;
    EL_RETURN_CHECK("execute", event->retrieve(truthCont, "TruthParticles"));
    Info("execute()", "number of truth particles = %lu", truthCont->size());

    const xAOD::TruthParticleContainer* truthMuons = 0;
    EL_RETURN_CHECK( "MyApp", event->retrieve( truthMuons, "TruthMuons" ) );

        const xAOD::TruthParticleContainer* truthElectrons = 0;
    EL_RETURN_CHECK( "MyApp", event->retrieve( truthElectrons, "TruthElectrons" ) );

        
    std::vector<TLorentzVector> lorentzMuons;
    std::vector<TLorentzVector> lorentzElectrons;
    std::vector<TLorentzVector> lorentzLeptons;

    // SMEARING FOR ELECTRONS AND MUONS
  

    // loop over the muons in the container
    xAOD::TruthParticleContainer::const_iterator muon_itr = truthMuons->begin();
    xAOD::TruthParticleContainer::const_iterator muon_end = truthMuons->end();
    for( ; muon_itr != muon_end; ++muon_itr ) {

      // cut on Pt and eta
      if ( (*muon_itr)->pt() > 25000 && (*muon_itr)->eta() < 4.5 ) {

	double muonUnsmearedPt = (*muon_itr)->pt();
	double muonPtResolution = m_upgrade->getMuonPtResolution((*muon_itr)->pt(), (*muon_itr)->eta() );
	double muonSmearedPt = muonUnsmearedPt + m_random3.Gaus(0., muonPtResolution);

	double muonSmearedE = ( muonSmearedPt/muonUnsmearedPt)*(*muon_itr)->e();
	     
	TLorentzVector muonHolder;
	muonHolder.SetPtEtaPhiE(muonSmearedPt, (*muon_itr)->eta(), (*muon_itr)->phi(), muonSmearedE);

	lorentzMuons.push_back(muonHolder);
	lorentzLeptons.push_back(muonHolder); 
      
      }
    }

    // loop over electrons in the container
    xAOD::TruthParticleContainer::const_iterator electron_itr = truthElectrons->begin();
    xAOD::TruthParticleContainer::const_iterator electron_end = truthElectrons->end();
    
    for( ; electron_itr != electron_end; ++electron_itr ) {

      // cut on Pt and eta
      if ( (*electron_itr)->pt() > 25000 && (*electron_itr)->eta() < 4.5 ) {

	double electronUnsmearedE = (*electron_itr)->e();
	double electronSmearedE = m_upgrade->getElectronSmearedEnergy(electronUnsmearedE,(*electron_itr)->eta());

	double electronUnsmearedPt = (*electron_itr)->pt();
	double electronPtResolution = m_upgrade->getElectronEnergyResolution((*electron_itr)->pt(),(*electron_itr)->eta());
	double electronSmearedPt = electronUnsmearedPt +  m_random3.Gaus(0., electronPtResolution);
      
	TLorentzVector electronHolder;
	electronHolder.SetPtEtaPhiE(electronSmearedPt, (*electron_itr)->eta(), (*electron_itr)->phi(), electronSmearedE);

	lorentzElectrons.push_back(electronHolder);
	lorentzLeptons.push_back(electronHolder); 
	
      }
    }

  // check if the event is a semileptonic event or not
    bool semiLeptonEvent = getEventType(truthCont);
  

  if (isMC && semiLeptonEvent) {

    semiLeptonCounter++;

    // flavLorentzJet is a struct declared in header. Includes a TLorentzVector and a string for flavour
    std::vector<flavLorentzJet> flavLorentzJets;
    std::vector<flavLorentzJet> trueLorentzJets;

    // returns true or false and checks if we trigger on electrons or muons

    /*
    // CUTS
    // test all cuts here 
    bool electronMuonTrigger = toTrigger(lorentzMuons, lorentzElectrons);
    
    if ( electronMuonTrigger == true ) {
      triggerCounter++;
    }

    */


    std::vector<TLorentzVector> pileupJets = m_upgrade->getPileupJets();
    std::vector<TLorentzVector> pileupJetsPass;
    std::vector<TLorentzVector> allLorentzJets;
    
    std::vector<TLorentzVector> truthLorentzJets;
    std::vector<TLorentzVector> smearedLorentzJets;

    // random number generator

    TRandom3 r(0);
    double etacut = 4.5;

    // PILE UP JETS

    for (int i=0; i < pileupJets.size(); i++ ) {
      
      if ( pileupJets[i].Pt() > m_upgrade->getPileupJetPtThresholdMeV() && abs(pileupJets[i].Eta()) < 4.5  ) {

	double tagEffP70(0);
	float tagEffP85(0);
	float trackEff(0);

	tagEffP70 = m_upgrade->getFlavourTagEfficiency(pileupJets[i].Pt(),pileupJets[i].Eta(), 'P', "mv1", 70, true);
	tagEffP85 = m_upgrade->getFlavourTagEfficiency(pileupJets[i].Pt(),pileupJets[i].Eta(), 'P', "mv1", 85, true);

	trackEff = m_upgrade->getTrackJetConfirmEff(pileupJets[i].Pt(),pileupJets[i].Eta(),"PU");
	
	h_trackEff->Fill(trackEff);
	h_tagEffP70->Fill(tagEffP70);
	h_tagEffP85->Fill(tagEffP85);

	// generate random number to accept/reject the track efficiency
	float x1 = r.Uniform(1);

	// if track eff is less than the rand no, throw away jet

       	if ( x1 > trackEff ) 
	  continue;

	//otherwise do this

	  pileupJetsPass.push_back(pileupJets[i]);
	  allLorentzJets.push_back(pileupJets[i]); 

      }
    }
    
  
    h_nPileupB->Fill(pileupJets.size());
    h_nPileupA->Fill(pileupJetsPass.size());

    // HARD SCATTER JETS

    const xAOD::JetContainer* jets = 0;
    EL_RETURN_CHECK("execute()",event->retrieve( jets, "AntiKt4TruthJets" ));
    Info("execute()", "  number of jets = %lu", jets->size());
    xAOD::JetContainer::const_iterator jet_itr = jets->begin();
    xAOD::JetContainer::const_iterator jet_end = jets->end();

    float trackEffHS(0);

    h_nHSB->Fill(jets->size());
    //float nJets(0);
    

    for( ; jet_itr != jet_end; ++jet_itr ) {

      TLorentzVector truthJetHolder;
      TLorentzVector smearedJetHolder;
      flavLorentzJet flavLorentzJetHolder;
      flavLorentzJet trueLorentzJetHolder;

      float jetPt = (*jet_itr)->pt();

      if ( (*jet_itr)->pt() < 20000 ) { std::cout << " hard cuts in runcard.dat dont work" << std::endl; }
      jetPt = m_upgrade->getJetSmearedEnergy((*jet_itr)->pt(), (*jet_itr)->eta(), true);
      
      // hold onto jets which have Pt > 30GeV 
      if ( jetPt > m_upgrade->getPileupJetPtThresholdMeV() && abs( (*jet_itr)->eta()  ) < 4.5 ) {

	// Get the no. of HS jets after Pt but before track confirmation
	//	nJets++;

	// smear the full jet energy
	float jetE = ( jetPt/(*jet_itr)->pt()   )*(*jet_itr)->e();

	truthJetHolder.SetPtEtaPhiE(  (*jet_itr)->pt(), (*jet_itr)->eta(), (*jet_itr)->phi(), (*jet_itr)->e()  );
	smearedJetHolder.SetPtEtaPhiE( jetPt, (*jet_itr)->eta(), (*jet_itr)->phi(), jetE );

	trackEffHS = m_upgrade->getTrackJetConfirmEff(smearedJetHolder.Pt(),smearedJetHolder.Eta(),"HS");
	float x2 = r.Uniform(1);

	h_trackEffHS->Fill(trackEffHS);

	trueLorentzJetHolder.vec = truthJetHolder;
	trueLorentzJets.push_back(trueLorentzJetHolder);

	// throw away jets that have track eff less than x2

	if ( x2 > trackEffHS )
	  
	  continue;

	// otherwise do this
	  
	  truthLorentzJets.push_back(truthJetHolder);
	  smearedLorentzJets.push_back(smearedJetHolder);
	  allLorentzJets.push_back(smearedJetHolder);

	  flavLorentzJetHolder.vec = smearedJetHolder;
	  flavLorentzJets.push_back(flavLorentzJetHolder);

	

      }
    }

    //h_nHSB->Fill(nJets);
    h_nHSA->Fill(flavLorentzJets.size());

    for ( int i=0; i < flavLorentzJets.size(); i++ ) {
      flavLorentzJets[i].flavour = getFlavour(flavLorentzJets[i].vec, truthCont);
    }

    
    // tack the pile up jets on to the flavour lorentz jets. this has to be done after the getFlavour. 
    TLorentzVector pileUpJetHolder;
    flavLorentzJet PULorentzJetHolder;

    
    for (int i=0; i < pileupJetsPass.size(); i++ ) {
      
      pileUpJetHolder = pileupJetsPass[i];
      PULorentzJetHolder.vec = pileUpJetHolder;
      PULorentzJetHolder.flavour = 'P';
      flavLorentzJets.push_back(PULorentzJetHolder);

	}      

    // jets are now smeared with a flavour attached to them..

    float bJetCounterB(0);
    float bJetCounterA(0);

    
    float tagEffB70(0);
    float tagEffB85(0);

    float tagEffC70(0);
    float tagEffC85(0);

    float tagEffL70(0);
    float tagEffL85(0);

    float tagEffP70(0);
    float tagEffP85(0);

    float x3(0);

    // here we decide what the flavours of the jets actually are:

    for ( int i=0; i < flavLorentzJets.size(); i++ ) {
      
      if ( flavLorentzJets[i].flavour == 'B' ) {

	bJetCounterB++;

	tagEffB70 = m_upgrade->getFlavourTagEfficiency(flavLorentzJets[i].vec.Pt(),flavLorentzJets[i].vec.Eta(), 'B', "mv1", 70, true);
	tagEffB85 = m_upgrade->getFlavourTagEfficiency(flavLorentzJets[i].vec.Pt(),flavLorentzJets[i].vec.Eta(), 'B', "mv1", 85, true);

	h_tagEffB70->Fill(tagEffB70);
	h_tagEffB85->Fill(tagEffB85);

	// throw a random number to decide whether jet is b-tagged or not
	// here we use the 85% bjet working point
	x3 = r.Uniform(1);
	
	if ( tagEffB85 > x3 ) {
	  flavLorentzJets[i].flavour = 'B';
	}

	else flavLorentzJets[i].flavour = 'L';


      }

      if ( flavLorentzJets[i].flavour == 'C' ) {
	      
	tagEffC70 = m_upgrade->getFlavourTagEfficiency(flavLorentzJets[i].vec.Pt(),flavLorentzJets[i].vec.Eta(), 'C', "mv1", 70, true);
	tagEffC85 = m_upgrade->getFlavourTagEfficiency(flavLorentzJets[i].vec.Pt(),flavLorentzJets[i].vec.Eta(), 'C', "mv1", 85, true);
	
	h_tagEffC70->Fill(tagEffC70);
	h_tagEffC85->Fill(tagEffC85);

	// throw rand number again
	x3 = r.Uniform(1);

		
	if ( tagEffC85 > x3 ) {
	  flavLorentzJets[i].flavour = 'B';
	}

	else flavLorentzJets[i].flavour = 'L';
	
      }

	    
      if ( flavLorentzJets[i].flavour == 'L' ) {

	tagEffL70 = m_upgrade->getFlavourTagEfficiency(flavLorentzJets[i].vec.Pt(),flavLorentzJets[i].vec.Eta(), 'L', "mv1", 70, true);
	tagEffL85 = m_upgrade->getFlavourTagEfficiency(flavLorentzJets[i].vec.Pt(),flavLorentzJets[i].vec.Eta(), 'L', "mv1", 85, true);

	h_tagEffL70->Fill(tagEffL70);
	h_tagEffL85->Fill(tagEffL85);

	x3 = r.Uniform(1);
			
	if ( tagEffL85 > x3 ) {
	  flavLorentzJets[i].flavour = 'B';
	}

	else flavLorentzJets[i].flavour = 'L';
	
	
      }

      	    
      if ( flavLorentzJets[i].flavour == 'P' ) {

	tagEffP70 = m_upgrade->getFlavourTagEfficiency(flavLorentzJets[i].vec.Pt(),flavLorentzJets[i].vec.Eta(), 'P', "mv1", 70, true);
	tagEffP85 = m_upgrade->getFlavourTagEfficiency(flavLorentzJets[i].vec.Pt(),flavLorentzJets[i].vec.Eta(), 'P', "mv1", 85, true);

	x3 = r.Uniform(1);
				
	if ( tagEffP85 > x3 ) {
	  flavLorentzJets[i].flavour = 'B';
	}

	else flavLorentzJets[i].flavour = 'L';
      	

      }
    }

    for ( int i=0; i < flavLorentzJets.size(); i++ ) {
      if ( flavLorentzJets[i].flavour == 'B' ) {
	bJetCounterA++;
      }
    }


    h_nbjetsA->Fill(bJetCounterA);
    h_nbjetsB->Fill(bJetCounterB);

    // declare jet indices that have already been used up. in first case we declare 'fake' indices.
    int jetIndexOne = 30;
    int jetIndexTwo = 30;


    // reco higgs takes a true/false in whether to demand all jets are b-tagged.
    std::vector<int> higgsOneIndices = recoHiggs(flavLorentzJets, jetIndexOne, jetIndexTwo, false);
    std::vector<int> higgsTwoIndices = recoHiggs(flavLorentzJets, higgsOneIndices[0], higgsOneIndices[1], false);

    double higgsMassOne = (flavLorentzJets[higgsOneIndices[0]].vec + flavLorentzJets[higgsOneIndices[1]].vec).M();
    double higgsMassTwo = (flavLorentzJets[higgsTwoIndices[0]].vec + flavLorentzJets[higgsTwoIndices[1]].vec).M();

    // investigate the truth higgs mass 
    // truthLorentzJets

    /*std::vector<int> thiggsOneIndices = recoHiggs(trueLorentzJets, jetIndexOne, jetIndexTwo);
    std::vector<int> thiggsTwoIndices = recoHiggs(trueLorentzJets, thiggsOneIndices[0], thiggsOneIndices[1]);
    
    double thiggsMassOne = (trueLorentzJets[thiggsOneIndices[0]].vec + trueLorentzJets[thiggsOneIndices[1]].vec).M();
    double thiggsMassTwo = (trueLorentzJets[thiggsTwoIndices[0]].vec + trueLorentzJets[thiggsTwoIndices[1]].vec).M(); */

    h_recoHiggs->Fill(higgsMassOne*0.001);
    h_recoHiggs->Fill(higgsMassTwo*0.001);

    /*h_recotHiggs->Fill(thiggsMassOne*0.001);
      h_recotHiggs->Fill(thiggsMassTwo*0.001); */

    
    

    const xAOD::MissingETContainer* METCont = 0;
    EL_RETURN_CHECK("execute", event->retrieve(METCont, "MET_Truth"));
    Info("execute()", "number of truth MET = %lu", METCont->size());
    const xAOD::MissingET* metTruth = 0;

    // NonInt = all non interacting particles (neutrinos and SUSY)
    //EtSum = Scalar Sum of transverse energies in calorimeters

    // sumet() and met() - the difference.
    //met = sqrt( pxMiss2 + pyMiss2).
    // sumet() is sum of et in the calorimeters. 

    
    if( METCont ) metTruth = (*METCont)["NonInt"];

     UpgradePerformanceFunctions::MET smearedMET = m_upgrade->getMETSmeared(metTruth->sumet(), metTruth->mpx(), metTruth->mpy());
     std::cout << " px of smeared met is " << smearedMET.first << " and the py of smeared met is... " << smearedMET.second << std::endl;

    bool sixJetsAndLepton = false;
    if ( flavLorentzJets.size() > 5 && lorentzLeptons.size() > 0 ) {
      sixJetsAndLepton = true;
    }
    
    bool electronMuonTrigger = toTrigger(lorentzMuons, lorentzElectrons);

    bool minfiveBtags = false;
    if ( bJetCounterB > 4 ) {
      
      minfiveBtags = true;

      // reconstruct the higgs boson using b-tagging since we have 5 b-tagged jets
      std::vector<int> higgsOneIndicesB = recoHiggs(flavLorentzJets, jetIndexOne, jetIndexTwo, true);
      std::vector<int> higgsTwoIndicesB = recoHiggs(flavLorentzJets, higgsOneIndicesB[0], higgsOneIndicesB[1], true);

      double higgsMassOneB = (flavLorentzJets[higgsOneIndicesB[0]].vec + flavLorentzJets[higgsOneIndicesB[1]].vec).M();
      double higgsMassTwoB = (flavLorentzJets[higgsTwoIndicesB[0]].vec + flavLorentzJets[higgsTwoIndicesB[1]].vec).M();

      std::cout << " higgs mass with btag? " << higgsMassOneB << std::endl;

      h_recoHiggsB->Fill(higgsMassOneB*0.001);
      h_recoHiggsB->Fill(higgsMassTwoB*0.001);

    }

    // bool for the higgs mass in some interval
    bool higgsMassCut = false;
    if ( (higgsMassOne*0.001) > 80.0 && (higgsMassOne*0.001) < 140.0 && (higgsMassTwo*0.001) > 80.0 && (higgsMassTwo*0.001) < 140.0 ) {
      higgsMassCut = true;
    }

    bool slTopMassCut = false;
    
    if ( electronMuonTrigger == true ) {
      triggerCounter++;
    }
    /*
    if ( sixJetsAndLepton == true ) { oneCutCounter++; }
    if ( sixJetsAndLepton == true && electronMuonTrigger == true  ) { twoCutCounter++; }
    if ( sixJetsAndLepton == true && electronMuonTrigger == true && minfiveBtags == true  ) { threeCutCounter++; }
    if ( sixJetsAndLepton == true && electronMuonTrigger == true && minfiveBtags == true && higgsMassCut == true  ) { fourCutCounter++; }
    if ( sixJetsAndLepton == true && electronMuonTrigger == true && minfiveBtags == true && higgsMassCut == true && slTopMassCut == true   ) { fiveCutCounter++; } */

    // if we do get five b tags... we can do the higgs reconstruction demanding that all jets are b-tagged..

          if ( lorentzLeptons.size() > 0 ) {

	    
	    // the truth met is used below:
	    /*double neutrinoPz = getNeutrinoPz(trueLorentzJets, lorentzLeptons[0], metTruth->mpx(), metTruth->mpy(), thiggsOneIndices, thiggsTwoIndices);
	    double neutrinoEnergy = sqrt( pow(metTruth->mpx(),2) + pow(metTruth->mpy(), 2) + pow(neutrinoPz,2) );
	    TLorentzVector neutrino;
	    neutrino.SetPxPyPzE(metTruth->mpx(),metTruth->mpy(), neutrinoPz, neutrinoEnergy);
	    int slTopIndex = recoSLTop(trueLorentzJets, lorentzLeptons[0], neutrino, thiggsOneIndices, thiggsTwoIndices);
	    TLorentzVector slTop = neutrino + lorentzLeptons[0] + trueLorentzJets[slTopIndex].vec;   */

	    
	    double neutrinoPzII =  getNeutrinoPz(flavLorentzJets, lorentzLeptons[0], smearedMET.first, smearedMET.second, higgsOneIndices, higgsTwoIndices);
	    TLorentzVector neutrinoII;
	    double neutrinoEnergyII = sqrt( pow(smearedMET.first,2) + pow(smearedMET.second, 2) + pow(neutrinoPzII,2) );
	    neutrinoII.SetPxPyPzE(smearedMET.first,smearedMET.second, neutrinoPzII, neutrinoEnergyII);

	    int slTopIndexII = recoSLTop(flavLorentzJets, lorentzLeptons[0], neutrinoII, higgsOneIndices, higgsTwoIndices);
	    TLorentzVector slTopV2 = neutrinoII + lorentzLeptons[0] + flavLorentzJets[slTopIndexII].vec; 
	    
	    h_recoSLTop->Fill(slTopV2.M()*0.001);
	    //h_slTop->Fill(slTop.M()*0.001);

	    if ( (slTopV2.M()*0.001) > 140.0 && (slTopV2.M()*0.001) < 210.0 ) {
      slTopMassCut = true;
      }

	  if ( flavLorentzJets.size() > 7 ) {

	    std::vector<int> hadronicTopIndices = recoHadronicTop(flavLorentzJets, higgsOneIndices, higgsTwoIndices, slTopIndexII);
	    TLorentzVector hadronicTop = flavLorentzJets[hadronicTopIndices[0]].vec + flavLorentzJets[hadronicTopIndices[1]].vec + flavLorentzJets[hadronicTopIndices[2]].vec;
	    std::cout << " whats the hadronic top ? " << hadronicTop.M() << std::endl;
	    h_rhadronicTop->Fill(hadronicTop.M()*0.001);

	  }
	  }

	      if ( sixJetsAndLepton == true ) { oneCutCounter++; }
    if ( sixJetsAndLepton == true && electronMuonTrigger == true  ) { twoCutCounter++; }
    if ( sixJetsAndLepton == true && electronMuonTrigger == true && minfiveBtags == true  ) { threeCutCounter++; }
    if ( sixJetsAndLepton == true && electronMuonTrigger == true && minfiveBtags == true && higgsMassCut == true  ) { fourCutCounter++; }
    if ( sixJetsAndLepton == true && electronMuonTrigger == true && minfiveBtags == true && higgsMassCut == true && slTopMassCut == true   ) { fiveCutCounter++; } 

	  


	  
  } 






	  
    //  outputTree->Fill();
  return EL::StatusCode::SUCCESS;




}  




EL::StatusCode MyxAODAnalysis :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTupleSvc.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: finalize ()
{
  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.  This is different from histFinalize() in that it only
  // gets called on worker nodes that processed input events.

  std::cout << " the total no. of semi lepton events is... " << semiLeptonCounter << std::endl;

  //  std::cout << " the total no. of SL events triggered on is... " << triggerCounter << std::endl;
  std::cout << " the no. surviving six j + 25gev lepton is.. " << oneCutCounter << std::endl;
  std::cout << " as a fraction that is.... " << (float)oneCutCounter/(float)semiLeptonCounter << std::endl;
  std::cout << " the no. surviving six j + 25gev lepton and trigger is.. " << twoCutCounter << std::endl;
  std::cout << " as a fraction that is.... " << (float)twoCutCounter/(float)semiLeptonCounter << std::endl;
    std::cout << " the no. surviving six j + 25gev lepton and trigger and 5 b tags is.. " << threeCutCounter << std::endl;
  std::cout << " as a fraction that is.... " << (float)threeCutCounter/(float)semiLeptonCounter << std::endl;


      std::cout << " the no. surviving six j + 25gev lepton and trigger and 5 b tags and higgs mass cut is.. " << fourCutCounter << std::endl;
  std::cout << " as a fraction that is.... " << (float)fourCutCounter/(float)semiLeptonCounter << std::endl;


      std::cout << " the no. surviving six j + 25gev lepton and trigger and 5 b tags and higgs mass cut and sl top mass cut is.. " << fiveCutCounter << std::endl;
  std::cout << " as a fraction that is.... " << (float)fiveCutCounter/(float)semiLeptonCounter << std::endl;



  

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode MyxAODAnalysis :: histFinalize ()
{
  // This method is the mirror image of histInitialize(), meaning it
  // gets called after the last event has been processed on the worker
  // node and allows you to finish up any objects you created in
  // histInitialize() before they are written to disk.  This is
  // actually fairly rare, since this happens separately for each
  // worker node.  Most of the time you want to do your
  // post-processing on the submission node after all your histogram
  // outputs have been merged.  This is different from finalize() in
  // that it gets called on all worker nodes regardless of whether
  // they processed input events.
  return EL::StatusCode::SUCCESS;
}

 int MyxAODAnalysis::recotSLTop(std::vector<TLorentzVector> lorentzJets, TLorentzVector lepton, TLorentzVector neutrino, std::vector<int> higgsIndicesI, std::vector<int> higgsIndicesII) {

   double chisqMin1 = 100000000;
   double tmass = 173300;

   double chisq1(0);
   int savedIndex(0);

   TLorentzVector top;

   for ( int i=0; i < lorentzJets.size(); i++) {
     if ( i != higgsIndicesI[0] && i != higgsIndicesI[1] && i != higgsIndicesII[0] && i != higgsIndicesII[1] ) { 

       top = neutrino + lepton + lorentzJets[i];

       chisq1 = pow( ( top.M() - tmass), 2);

       if ( chisq1 < chisqMin1 ) {
	 chisqMin1 = chisq1;
	 savedIndex = i;


       }

     }
   }

   return savedIndex;


 }


 std::vector<int> MyxAODAnalysis::recoHadronicTop(std::vector<flavLorentzJet> lorentzJets, std::vector<int> higgsIndicesI, std::vector<int> higgsIndicesII, int slTopIndex) {

   
   double chisqMin = 10000000000000000.0;
   double tmass = 173300;

   double chisq(0);
   std::vector<int> hadronicTopIndices;

   TLorentzVector top;
   int topIndex1(50);
   int topIndex2(50);
   int topIndex3(50); 


   for ( int i=0; i < lorentzJets.size(); i++) {
     if ( i != higgsIndicesI[0] && i != higgsIndicesI[1] && i != higgsIndicesII[0] && i != higgsIndicesII[1] && i != slTopIndex ) {
       for ( int j=0; j < lorentzJets.size(); j++) {
	 if ( j != higgsIndicesI[0] && j != higgsIndicesI[1] && j != higgsIndicesII[0] && j != higgsIndicesII[1] && j != slTopIndex && i != j ) {
	   for ( int k=0; k < lorentzJets.size(); k++) {
	     if ( k != higgsIndicesI[0] && k != higgsIndicesI[1] && k != higgsIndicesII[0] && k != higgsIndicesII[1] && k != slTopIndex && i !=k && j !=k ) {

	       top = lorentzJets[i].vec + lorentzJets[j].vec + lorentzJets[k].vec;
	       chisq = pow( ( top.M() - tmass),2);

	       if ( chisq < chisqMin ) {
	 
		 chisqMin = chisq;
		 topIndex1 = i;
		 topIndex2 = j;
		 topIndex3 = k;
		 

	 
	       }

	     }
	   }
	 }
       }
     }
   }

   		 hadronicTopIndices.push_back(topIndex1);
		 hadronicTopIndices.push_back(topIndex2);
		 hadronicTopIndices.push_back(topIndex3);

   return hadronicTopIndices;


 }


   

   

						


std::vector<int> MyxAODAnalysis::recotHiggs(std::vector<TLorentzVector> lorentzJets, int disIndex1, int disIndex2) {
   
  double minimum = 1000000000000000.0;
  double chiSq(0);
  double higgsMass = 125000.0;
  int jetIndex1 = 0;
  int jetIndex2 = 0;
  
  for (int i = 0; i < lorentzJets.size(); i++ ) {
    for (int j = 0; j < lorentzJets.size(); j++ ) {
       
      if ( i != j && i != disIndex1 && i != disIndex2 && j != disIndex1 && j != disIndex2 ) {

	double invarMass = (lorentzJets[i] + lorentzJets[j]).M();
	  chiSq = pow(invarMass - higgsMass, 2);

	  
	if ( chiSq < minimum ) {
	   
	  minimum = chiSq;
	  jetIndex1 = i;
	  jetIndex2 = j;

	}
      }
    }
  }

  std::vector<int> jetIndices;
  jetIndices.push_back(jetIndex1);
  jetIndices.push_back(jetIndex2);

  return jetIndices;

	   

}


 int MyxAODAnalysis::recoSLTop(std::vector<flavLorentzJet> lorentzJets, TLorentzVector lepton, TLorentzVector neutrino, std::vector<int> higgsIndicesI, std::vector<int> higgsIndicesII) {

   double chisqMin1 = 100000000;
   double tmass = 173300;

   double chisq1(0);
   int savedIndex(0);

   TLorentzVector top;

   for ( int i=0; i < lorentzJets.size(); i++) {
     if ( i != higgsIndicesI[0] && i != higgsIndicesI[1] && i != higgsIndicesII[0] && i != higgsIndicesII[1] ) { 

       top = neutrino + lepton + lorentzJets[i].vec;

       chisq1 = pow( ( top.M() - tmass), 2);

       if ( chisq1 < chisqMin1 ) {
	 chisqMin1 = chisq1;
	 savedIndex = i;


       }

     }
   }

   return savedIndex;


 }

 

double MyxAODAnalysis::getNeutrinoPz(std::vector<flavLorentzJet> lorentzJets, TLorentzVector lepton, double mpx, double mpy, std::vector<int> higgsIndicesI, std::vector<int> higgsIndicesII) {

         double Wmassconstraint = 80400;
        // useful quantities                                                                                                                                                  
        double PxPy = lepton.Px()*mpx + lepton.Py()*mpy;
        double invmass = 0.5*( pow( Wmassconstraint, 2) - pow( lepton.M(), 2) );

        // quadratic coefficients are here                                                                                                                                    
        double a = pow( lepton.Energy(), 2) - pow( lepton.Pz(), 2);
        double b =    ( -2.0*PxPy*lepton.Pz() - 2.0*invmass*lepton.Pz()  );
        double ci = -2.0*invmass*PxPy - pow( invmass, 2) - pow( PxPy, 2);
        double cii =   (  pow ( lepton.Energy(), 2) )*(  pow( mpx, 2) + pow( mpy, 2) );
        double c = ci + cii;

        double discrim = b*b - 4.0*a*c;

	TLorentzVector top1;
	TLorentzVector top2;

        if ( discrim > 0 ) {

                double root1 =  (  -b + sqrt(discrim)  )/ (2.0*a);
                double root2 =  (  -b - sqrt(discrim)  )/ (2.0*a);

                double tmass = 173300;
                TLorentzVector recNeutrinoROOT1;
                TLorentzVector recNeutrinoROOT2;
                double Eofneutrino1 = sqrt( pow(mpx,2) + pow( mpy, 2) + pow( root1, 2) );
                double Eofneutrino2 = sqrt( pow(mpx,2) + pow( mpy, 2) + pow( root2, 2) );
                recNeutrinoROOT1.SetPxPyPzE(mpx, mpy, root1, Eofneutrino1);
                recNeutrinoROOT2.SetPxPyPzE(mpx, mpy, root2, Eofneutrino2);

                double chisqMin1 = 100000000;
                double chisqMin2 = 100000000;

                double chisq1(0);
                double chisq2(0);

                for ( int i=0; i < lorentzJets.size(); i++) {
		  if ( i != higgsIndicesI[0] && i != higgsIndicesI[1] && i != higgsIndicesII[0] && i != higgsIndicesII[1] ) { 

                        top1 = recNeutrinoROOT1 + lepton + lorentzJets[i].vec;
                        top2 = recNeutrinoROOT2 + lepton + lorentzJets[i].vec;


                        chisq1 = pow( ( top1.M() - tmass), 2);
                        chisq2 = pow( ( top2.M() - tmass), 2);

                        if ( chisq1 < chisqMin1 ) {
                                chisqMin1 = chisq1; }

                        if ( chisq2 < chisqMin2 ) {
                                chisqMin2 = chisq2; }

		  }

                }

                if ( chisqMin1 < chisqMin2 ) { return root1; }
                if ( chisqMin2 < chisqMin1 ) { return root2; }

        }

        if ( discrim < 0 || discrim == 0) {

                // here we take the real part of the quadratic equation                                                                                                       
                double root3  = (-1.0*b)/(2.0*a);
                return root3;

        }

}



std::vector<int> MyxAODAnalysis::recoHiggs(std::vector<flavLorentzJet> lorentzJets, int disIndex1, int disIndex2, bool usebtag) {
   
  double minimum = 1000000000000000.0;
  double chiSq(0);
  double higgsMass = 125000.0;
  int jetIndex1 = 0;
  int jetIndex2 = 0;


  // decide whether to do the minimisation by demanding the jets are b-tagged
  
  for (int i = 0; i < lorentzJets.size(); i++ ) {
    for (int j = 0; j < lorentzJets.size(); j++ ) {
       
      if ( i != j && i != disIndex1 && i != disIndex2 && j != disIndex1 && j != disIndex2 ) {

	if ( usebtag == true ) {
	  if ( lorentzJets[i].flavour == 'B' && lorentzJets[j].flavour == 'B' ) {
	  
	    double invarMass = (lorentzJets[i].vec + lorentzJets[j].vec).M();
	    chiSq = pow(invarMass - higgsMass, 2);

	  }
	}

	if ( usebtag == false ) {

	    double invarMass = (lorentzJets[i].vec + lorentzJets[j].vec).M();
	    chiSq = pow(invarMass - higgsMass, 2);

	  }
      


	  
	if ( chiSq < minimum ) {
	   
	  minimum = chiSq;
	  jetIndex1 = i;
	  jetIndex2 = j;

	}
      }
    }
  }


  std::vector<int> jetIndices;
  jetIndices.push_back(jetIndex1);
  jetIndices.push_back(jetIndex2);

  return jetIndices;

	   

}

bool MyxAODAnalysis::toTrigger(std::vector<TLorentzVector> lorentzMuons, std::vector<TLorentzVector> lorentzElectrons) {

    TRandom3 r(0);
    int electronTrigCounter(0);
    int muonTrigCounter(0);
    bool trigger = false;
    
    //double x1 = r.Uniform(0,1);
    //h_rand->Fill(x1);

  
    // testing trigger...
    
    for (int i=0; i < lorentzElectrons.size(); i++ ) {

      // testing the electron trigger...
      float electronTrigEff = m_upgrade->getSingleElectronTriggerEfficiency(lorentzElectrons[i].Pt(),lorentzElectrons[i].Eta());

      // throw a random number
      float x1 = r.Uniform(1);

	if ( electronTrigEff > x1 ) {
	  electronTrigCounter++;
	}

       h_electronTrig->Fill(electronTrigEff);

    }

    for (int i=0; i < lorentzMuons.size(); i++ ) {

      // testing the muon trigger...
      float muonTrigEff = m_upgrade->getSingleMuonTriggerEfficiency(lorentzMuons[i].Pt(), lorentzMuons[i].Eta() );

      float x2 = r.Uniform(1);

      if ( muonTrigEff > x2 ) {
	muonTrigCounter++;
      }

      h_muonTrig->Fill(muonTrigEff);

    }

    if ( muonTrigCounter > 0 || electronTrigCounter > 0 ) {
      trigger = true;
    }

    return trigger;

    } 

 


 
/*
bool MyxAODAnalysis::toTrigger(std::vector<TLorentzVector> lorentzMuons, std::vector<TLorentzVector> lorentzElectrons) {

    TRandom3 r(0);
    int electronTrigCounter(0);
    int muonTrigCounter(0);
    bool trigger = false;
    
    //double x1 = r.Uniform(0,1);
    //h_rand->Fill(x1);

  
    // testing trigger...
    
    for (int i=0; i < lorentzElectrons.size(); i++ ) {

      float electronUnsmearedE = lorentzElectrons[i].E();
      float electronSmearedE = m_upgrade->getElectronSmearedEnergy(electronUnsmearedE,lorentzElectrons[i].Eta());

      // to test the electron trigger we need the transverse energy...
      float electronUnsmearedPt = lorentzElectrons[i].Pt();
      float electronPtResolution = m_upgrade->getElectronEnergyResolution(lorentzElectrons[i].Pt(), lorentzElectrons[i].Eta());
      float electronSmearedPt = electronUnsmearedPt +  m_random3.Gaus(0., electronPtResolution);

      // testing the electron trigger...
      float electronTrigEff = m_upgrade->getSingleElectronTriggerEfficiency(electronSmearedPt,lorentzElectrons[i].Eta());

      // throw a random number
      float x1 = r.Uniform(1);

	if ( electronTrigEff > x1 ) {
	  electronTrigCounter++;
	}

       h_electronTrig->Fill(electronTrigEff);

    }

    for (int i=0; i < lorentzMuons.size(); i++ ) {

      // float muonUnsmearedPt = (*part_itr)->pt();
      float muonUnsmearedPt = lorentzMuons[i].Pt();
      float muonPtResolution = m_upgrade->getMuonPtResolution(lorentzMuons[i].Pt(), lorentzMuons[i].Eta());
      float muonSmearedPt = muonUnsmearedPt + m_random3.Gaus(0., muonPtResolution);

      // testing the muon trigger...
      float muonTrigEff = m_upgrade->getSingleMuonTriggerEfficiency(muonSmearedPt, lorentzMuons[i].Eta() );

      float x2 = r.Uniform(1);

      if ( muonTrigEff > x2 ) {
	muonTrigCounter++;
      }

      h_muonTrig->Fill(muonTrigEff);

    }

    if ( muonTrigCounter > 0 || electronTrigCounter > 0 ) {
      trigger = true;
    }

    return trigger;

    } */



bool MyxAODAnalysis::getEventType(const xAOD::TruthParticleContainer* truthCont) {

  xAOD::TruthParticleContainer::const_iterator part_itr = truthCont->begin();
  xAOD::TruthParticleContainer::const_iterator part_end = truthCont->end();

  int leptonicW(0);
  int hadronicW(0);

  bool semiLeptonEvent = false;
  
  for (; part_itr != part_end; ++part_itr) {

    // checks if its a  w boson and then checks what the daughters of the w boson are

    if ( abs((*part_itr)->pdgId()) == 24 && (*part_itr)->nChildren() == 2 ) {
      
      if ( abs((*part_itr)->child(0)->pdgId()) == 11 || abs((*part_itr)->child(0)->pdgId()) == 13 || abs((*part_itr)->child(1)->pdgId()) == 11 || abs((*part_itr)->child(1)->pdgId()) == 13 ) {
	leptonicW++;
      }

      if ( abs((*part_itr)->child(0)->pdgId()) < 7 || abs((*part_itr)->child(1)->pdgId()) < 7) {
	hadronicW++;
      }

    }
  }

  if ( leptonicW == 1 && hadronicW == 1 ) {
    semiLeptonEvent = true;
  }

  return semiLeptonEvent;

}

  
      /*
            # w boson daughter particles                                                                                 
            wDaughter1 = truthParticle.child(0)
            wDaughter2 = truthParticle.child(1)

            #print ( " pdg of daughter 1 ... = %g" % wDaughter1.pdgId() )                                                
            #print ( " pdg of daughter 2.. = %g" % wDaughter2.pdgId() )                                                  

            # checking identity of w boson daughter particles...                                                         

            if abs(wDaughter1.pdgId()) == 11 or abs(wDaughter1.pdgId()) == 13 or abs(wDaughter2.pdgId()) == 11 or abs(wD\
aughter2.pdgId()) == 13:
                leptonicW += 1

            if abs(wDaughter1.pdgId()) < 7 or abs(wDaughter2.pdgId()) < 7:
	    hadronicW += 1 */ 



  
  


std::vector<TLorentzVector> MyxAODAnalysis::getbHadrons(const xAOD::TruthParticleContainer* truthCont) {
  
  // int noOfBHadrons = 0;
  int noOfBHadrons_23 = 0;

  int flowControl = 0;
  int flowControlV2 = 0;
  int flowControlV3 = 0;
  int higgsCounter = 0;

  std::vector<TLorentzVector> bHadrons(6);


  xAOD::TruthParticleContainer::const_iterator part_itr = truthCont->begin();
  xAOD::TruthParticleContainer::const_iterator part_end = truthCont->end();

  double pxHiggs = 0;

  /* the below loops over all truth particles, finds bhadrons with status23, checks the parents of the bhadrons
     if it isn't a higgs boson then it sets to indice 4 and 5. if it is a higgs boson, we find the px of the higgs then we check 
     the px of the parent of the bhadrons, if its the same then that bhadron is set to indice 1 and 2, if not then indice 3 and 4 */

  
  for (; part_itr != part_end; ++part_itr) {

    //std::cout << " testing " << abs( (*part_itr)->pdgId()  ) << std::endl;
    if ( isBhadron( abs( (*part_itr)->pdgId()  )  ) && (*part_itr)->status() == 23  ) {
      std::cout << " functions working " << std::endl; 

      noOfBHadrons_23++;
      TLorentzVector BHadron23;
      BHadron23.SetPxPyPzE((*part_itr)->px(),(*part_itr)->py(),(*part_itr)->pz(),(*part_itr)->e());

      // if the parent of the b hadron isnt a higgs boson then set it to indice 4/5
      if ( (*part_itr)->parent(0)->pdgId() != 25 ) {
	flowControlV3++;
	if ( flowControlV3 == 1 ) {
	  bHadrons[4] = BHadron23; }
	if ( flowControlV3 != 1 ) {
	  bHadrons[5] = BHadron23; }
      }

      if ( (*part_itr)->nParents() > 0 && (*part_itr)->parent(0)->pdgId() == 25 ) {
	higgsCounter++;
	if ( higgsCounter == 1 ) {
	  pxHiggs = (*part_itr)->parent(0)->px(); }


	if   ( (*part_itr)->parent(0)->px() == pxHiggs ) {
	  flowControl++;
	  if ( flowControl == 1 ) {
	    bHadrons[0] = BHadron23; }
	  if ( flowControl != 1 ) {
	    bHadrons[1] = BHadron23; }

	}

	if ( (*part_itr)->parent(0)->px() != pxHiggs ) {
	  flowControlV2 += 1;
	  if ( flowControlV2 == 1 ) {
	    bHadrons[2] = BHadron23; }
	  if ( flowControlV2 != 1 ) {
	    bHadrons[3] = BHadron23; }

	}

      }
    }
  }

	    
	    

  std::cout << " the invariant mass of the b hadrons pairs is.... " << std::endl; 
	    std::cout << (bHadrons[0] + bHadrons[1]).M() << std::endl;	  
	    std::cout <<  (bHadrons[2] + bHadrons[3]).M() << std::endl;
	    std::cout << " testing the energy of the other 2 bhadrons is working ... " << bHadrons[5].E() << " and... " << bHadrons[4].E() << std::endl;


	   
	    return bHadrons;

    }

bool MyxAODAnalysis::isBhadron(int abs_pdgId) {

  
    const int m_allBhadrons[76]={5,511,513,515,521,523,525,531,533,535,541,543,545,551,553,555,5101,5103,5112,5114,5122,5132,5142,5201,5203,5212,5214,5222,5224,5232,5242,5301,5303,5312,5314,5322,5324,5332,5334,5342,5401,5403,5412,5414,5422,5424,5432,5434,5442,5444,5503,5512,5514,5522,5524,5532,5534,5542,5544,5554,10511,10513,10521,10523,10531,10533,10541,10543,10551,10553,20513,20523,20533,20543,20553,100553};

           bool foundIT=false;
       unsigned int i, n = sizeof(m_allBhadrons)/sizeof(int);
       for(i=0;i<n;i++) if(m_allBhadrons[i] == abs_pdgId) foundIT=true;
	return foundIT;

}

bool MyxAODAnalysis::isChadron(int abs_pdgId) {


              const int m_allChadrons[81]={4,411,413,415,421,423,425,431,433,435,441,443,445,541,543,545,4101,4103,4122,4132,4201,4203,4212,4214,4222,4224,4232,4301,4303,4312,4314,4322,4324,4332,4334,4403,5401,5403,4412,4414,4422,4424,4432,4434,4444,5142,5242,5412,5422,5412,5424,5342,5432,5434,5442,5444,5542,5544,10411,10413,10421,10423,10431,10433,10441,10443,10541,10543,20413,20423,20443,20433,20543,20553,30443,100441,100443,9000443,9010443,9020443,9000445};

bool foundIT=false;
       unsigned int i, n = sizeof(m_allChadrons)/sizeof(int);
       for(i=0;i<n;i++) if(m_allChadrons[i] == abs_pdgId) foundIT=true;
return foundIT;

}


 std::string MyxAODAnalysis::getFlavour(TLorentzVector jet, const xAOD::TruthParticleContainer* truthCont) {

   std::string flav;

  
  xAOD::TruthParticleContainer::const_iterator part_itr = truthCont->begin();
  xAOD::TruthParticleContainer::const_iterator part_end = truthCont->end();

  for (; part_itr != part_end; ++part_itr) {

        if ( isBhadron( abs( (*part_itr)->pdgId()  )  ) && (*part_itr)->status() == 23  ) {
          TLorentzVector bHadron;
          bHadron.SetPxPyPzE((*part_itr)->px(),(*part_itr)->py(),(*part_itr)->pz(),(*part_itr)->e());

	  //std::cout << " what is delta r with each b hadron? " << jet.DeltaR(bHadron) << std::endl;

          //if ( jet.DeltaR(bHadron) < 0.3 ) {                                                                                                            
	  if ( jet.DeltaR(bHadron) < 0.3 ) {


            flav = 'B';
            //break;                                                                                                                                                     
	  }

        } 

	if ( flav != 'B' ) {

	  if ( isChadron( abs( (*part_itr)->pdgId()  )  )) {
            TLorentzVector cHadron;
            cHadron.SetPxPyPzE((*part_itr)->px(),(*part_itr)->py(),(*part_itr)->pz(),(*part_itr)->e());

            if ( jet.DeltaR(cHadron) < 0.3 ) {
              flav = 'C';
              //break;                                                                                                                                                   
            }
          }
        }

        if ( flav != 'B' && flav != 'C'  ) {

          flav = 'L';
        }
  }

  return flav;
 }
    //}                               
