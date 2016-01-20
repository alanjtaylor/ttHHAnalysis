RC_CXX       = g++
RC_LD        = g++
RC_CXXFLAGS  = -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/Root -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_RELEASE_SERIES=23 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594/valid3.110401.PowhegPythia_P2012_ttbar_nonallhad.recon.AOD.e3099_s2578_r6594_tid05292824_00/AOD.05292824._000011.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"MyAnalysis\" 
RC_DICTFLAGS = -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/Root -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_RELEASE_SERIES=23 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594/valid3.110401.PowhegPythia_P2012_ttbar_nonallhad.recon.AOD.e3099_s2578_r6594_tid05292824_00/AOD.05292824._000011.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"MyAnalysis\" 
RC_INCFLAGS  = -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/Root -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/include -DROOTCORE -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -DROOTCORE_RELEASE_SERIES=23 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594/valid3.110401.PowhegPythia_P2012_ttbar_nonallhad.recon.AOD.e3099_s2578_r6594_tid05292824_00/AOD.05292824._000011.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/user/a/asgbase/patspace/xAODs/r6594\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"MyAnalysis\"
RC_LIBFLAGS  = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic 
RC_BINFLAGS  = -L/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/lib -L/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/lib/x86_64-slc6-gcc48-opt -lMyAnalysis -lxAODEgamma -lxAODMuon -lxAODPrimitives -lMuonIdHelpers -lUpgradePerformanceFunctions -lPathResolver -lboost_filesystem -lHist -lAsgTools -lxAODMissingET -lboost_unit_test_framework -lxAODTruth -lTruthUtils -lxAODJet -lGenVector -lxAODPFlow -lGenVector -lxAODCaloEvent -lCaloGeoHelpers -lxAODBTagging -lxAODTracking -lxAODTrigger -lxAODBase -lPhysics -lxAODEventInfo -lEventLoop -lProofPlayer -lProof -lHist -lTree -lxAODRootAccess -lTree -lxAODEventFormat -lxAODCore -lRIO -lAthContainers -lAthLinks -lxAODRootAccessInterfaces -lCxxUtils -lboost_regex -lboost_system -lSampleHandler -lPyROOT -lProof -lTree -lRootCoreUtils -lTree -lHist -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic


all_MyAnalysis : dep_MyAnalysis package_MyAnalysis

package_MyAnalysis :  /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/lib/libMyAnalysis.so /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/bin/testRun postcompile_MyAnalysis

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/lib/libMyAnalysis.so :  /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyxAODAnalysis.o /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.o | /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/lib
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyxAODAnalysis.o /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.o $(RC_LIBFLAGS) -L/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/lib/x86_64-slc6-gcc48-opt -o $@

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/%.o : /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/Root/%.cxx | /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyxAODAnalysis.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc MyAnalysis $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/%.d : /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/Root/%.cxx | /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.o : /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/Root/LinkDef.h /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.headers | /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc MyAnalysis $@
	$(SILENT)rc --internal rootcint $(ROOTSYS)/bin/rootcint $(RC_INCFLAGS) /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/Root/LinkDef.h /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.cxx /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.headers /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/lib MyAnalysis
	$(SILENT)$(RC_CXX) $(RC_DICTFLAGS) $(INCLUDES) -c /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.cxx -o $@

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.headers : /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/Root/LinkDef.h | /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -D__CINT__ -D__MAKECINT__ -D__CLING__ -Wno-unknown-pragmas -- $@ $< 

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.d : /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/Root/LinkDef.h | /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/lib : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/bin/% : /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/%.o | /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/lib/libMyAnalysis.so /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/bin
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) -o $@ $< $(RC_BINFLAGS)

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/%.o : /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/util/%.cxx | /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/testRun.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc MyAnalysis $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/%.d : /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/MyAnalysis/util/%.cxx | /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/bin : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

postcompile_MyAnalysis :  /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/lib/libMyAnalysis.so /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/bin/testRun
	$(SILENT)rc --internal postcompile_pkg MyAnalysis


dep_MyAnalysis : /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyxAODAnalysis.d /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.d /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/testRun.d /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.headers


-include  /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyxAODAnalysis.d /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.d /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/testRun.d /afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/MyAnalysis/obj/MyAnalysisCINT.headers
