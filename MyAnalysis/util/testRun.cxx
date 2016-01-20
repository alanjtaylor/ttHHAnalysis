#include "xAODRootAccess/Init.h"
#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/ScanDir.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "EventLoop/Job.h"
#include "EventLoop/DirectDriver.h"
#include "SampleHandler/DiskListLocal.h"
#include <TSystem.h>
#include "SampleHandler/ScanDir.h"

#include "MyAnalysis/MyxAODAnalysis.h"

int main( int argc, char* argv[] ) {

  // Take the submit directory from the input if provided:
  std::string submitDir = "submitDir";
  if( argc > 1 ) submitDir = argv[ 1 ];

  // Set up the job for xAOD access:
  xAOD::Init().ignore();

  // Construct the samples to run on:
  SH::SampleHandler sh;

  // use SampleHandler to scan all of the subdirectories of a directory for particular MC single file:
  //  const char* inputFilePath = gSystem->ExpandPathName ("/afs/cern.ch/atlas/project/PAT/tutorial/cern-may2015/r6630/");
  // SH::ScanDir().sampleDepth(1).samplePattern("AOD.05352803._000031.pool.root.1").scan(sh, inputFilePath);

  //  const char* inputFilePath = gSystem->ExpandPathName ("/afs/cern.ch/user/a/altaylor/first_events/generate_h_bbV3/truth_events");
  // SH::ScanDir().filePattern("DAOD_TRUTH3.h_bb_truth.root").scan(sh, inputFilePath);

  const char* inputFilePath = gSystem->ExpandPathName ("/afs/cern.ch/user/a/altaylor/first_events/tthh_bbbbV3/truth_events1");
  SH::ScanDir().filePattern("DAOD_TRUTH1.tthh.pool.root").scan(sh, inputFilePath);  

  // const char* inputFilePath = gSystem->ExpandPathName ("/afs/cern.ch/user/a/altaylor/first_events/generate_h_bbV3/truth_events");
  //  SH::ScanDir().filePattern("DAOD_TRUTH3.h_bb_truth.root").scan(sh, inputFilePath);

  // fileName = "/afs/cern.ch/user/a/altaylor/first_events/tthh_bbbbV3/truth_events1/DAOD_TRUTH1.tthh.pool.root"


  // Set the name of the input TTree. It's always "CollectionTree"
  // for xAOD files.
  sh.setMetaString( "nc_tree", "CollectionTree" );

  // Print what we found:
  sh.print();

  // Create an EventLoop job:
  EL::Job job;
  job.sampleHandler( sh );
  job.options()->setDouble (EL::Job::optMaxEvents, 1000);

  // Add our analysis to the job:
  MyxAODAnalysis* alg = new MyxAODAnalysis();
  // This is an example of how to set public variables that can be used
  //  to set up UpgradePerformanceFunctions
  alg->averageMuValue = 200.0;
  job.algsAdd( alg );

  // Run the job using the local/direct driver:
  EL::DirectDriver driver;
  driver.submit( job, submitDir );

  return 0;
}
