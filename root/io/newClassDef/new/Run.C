void Run() {

   gSystem->Load("./namespace");
   gSystem->Load("./template");
   gSystem->Load("./nstemplate");
   gSystem->Load("./InheritMulti");

#ifdef ClingWorkAroundMissingDynamicScope
#ifdef ClingWorkAroundFunctionForwardDeclarations
   gROOT->ProcessLine("#include \"functionsFwdDeclarations.h\"");
#endif
   gROOT->ProcessLine(
   "namespace_driver();"
   "template_driver();"
   "nstemplate_driver();"

   "if (! InheritMulti_driver() ) exit(1);"
                      );
#else
#ifdef ClingWorkAroundFunctionForwardDeclarations
   #include "functionsFwdDeclarations.h"
#endif
   namespace_driver();
   template_driver();
   nstemplate_driver();
   
   if (! InheritMulti_driver() ) exit(1);
#endif   
}
