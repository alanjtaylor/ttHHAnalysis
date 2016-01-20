RC_CXX       = g++
RC_LD        = g++
RC_CXXFLAGS  = -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.11/RootCore/Root -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.11/RootCore -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_PACKAGE=\"RootCore\" 
RC_DICTFLAGS = -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.11/RootCore/Root -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.11/RootCore -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -Wdeprecated-declarations -DROOTCORE_PACKAGE=\"RootCore\" 
RC_INCFLAGS  = -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.11/RootCore/Root -I/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.3.11/RootCore -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/include -DROOTCORE -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -DROOTCORE_PACKAGE=\"RootCore\"
RC_LIBFLAGS  = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic 
RC_BINFLAGS  = -L/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/obj/x86_64-slc6-gcc48-opt/RootCore/lib -L/afs/cern.ch/user/a/altaylor/tthh_bbbb_smear/RootCoreBin/lib/x86_64-slc6-gcc48-opt -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic


all_RootCore : dep_RootCore package_RootCore

package_RootCore :  postcompile_RootCore

postcompile_RootCore : 
	$(SILENT)rc --internal postcompile_pkg RootCore


dep_RootCore :
