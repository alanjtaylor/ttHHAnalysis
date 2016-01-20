#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIaltaylordItthh_bbbb_smeardIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIUpgradePerformanceFunctionsdIobjdIUpgradePerformanceFunctionsCINT

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments

// Header files passed via #pragma extra_include

namespace {
  void TriggerDictionaryInitialization_UpgradePerformanceFunctionsCINT_Impl() {
    static const char* headers[] = {
0
    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/UpgradePerformanceFunctions/Root",
"/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/UpgradePerformanceFunctions",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/UpgradePerformanceFunctions/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef ROOTCORE
  #define ROOTCORE 1
#endif
#ifndef ROOTCORE_RELEASE_SERIES
  #define ROOTCORE_RELEASE_SERIES 23
#endif
#ifndef ROOTCORE_TEST_FILE
  #define ROOTCORE_TEST_FILE "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594/valid3.110401.PowhegPythia_P2012_ttbar_nonallhad.recon.AOD.e3099_s2578_r6594_tid05292824_00/AOD.05292824._000011.pool.root.1"
#endif
#ifndef ROOTCORE_TEST_DATA
  #define ROOTCORE_TEST_DATA "/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594"
#endif
#ifndef XAOD_STANDALONE
  #define XAOD_STANDALONE 1
#endif
#ifndef XAOD_ANALYSIS
  #define XAOD_ANALYSIS 1
#endif
#ifndef ASGTOOL_STANDALONE
  #define ASGTOOL_STANDALONE 1
#endif
#ifndef ROOTCORE_PACKAGE
  #define ROOTCORE_PACKAGE "UpgradePerformanceFunctions"
#endif

#define _BACKWARD_BACKWARD_WARNING_H

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("UpgradePerformanceFunctionsCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_UpgradePerformanceFunctionsCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_UpgradePerformanceFunctionsCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_UpgradePerformanceFunctionsCINT() {
  TriggerDictionaryInitialization_UpgradePerformanceFunctionsCINT_Impl();
}
