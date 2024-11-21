//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "hamsterTestApp.h"
#include "hamsterApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
hamsterTestApp::validParams()
{
  InputParameters params = hamsterApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

hamsterTestApp::hamsterTestApp(InputParameters parameters) : MooseApp(parameters)
{
  hamsterTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

hamsterTestApp::~hamsterTestApp() {}

void
hamsterTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  hamsterApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"hamsterTestApp"});
    Registry::registerActionsTo(af, {"hamsterTestApp"});
  }
}

void
hamsterTestApp::registerApps()
{
  registerApp(hamsterApp);
  registerApp(hamsterTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
hamsterTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  hamsterTestApp::registerAll(f, af, s);
}
extern "C" void
hamsterTestApp__registerApps()
{
  hamsterTestApp::registerApps();
}
