#include "hamsterApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
hamsterApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

hamsterApp::hamsterApp(InputParameters parameters) : MooseApp(parameters)
{
  hamsterApp::registerAll(_factory, _action_factory, _syntax);
}

hamsterApp::~hamsterApp() {}

void
hamsterApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<hamsterApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"hamsterApp"});
  Registry::registerActionsTo(af, {"hamsterApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
hamsterApp::registerApps()
{
  registerApp(hamsterApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
hamsterApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  hamsterApp::registerAll(f, af, s);
}
extern "C" void
hamsterApp__registerApps()
{
  hamsterApp::registerApps();
}
