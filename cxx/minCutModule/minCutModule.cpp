/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#include "minCutModule.hpp"
#include "keynodes/keynodes.hpp"
#include "agents/minCutAgent.hpp"


using namespace minCutModule;

SC_IMPLEMENT_MODULE(MinCutModule)

sc_result MinCutModule::InitializeImpl()
{
  if (!minCutModule::Keynodes::InitGlobal())
    return SC_RESULT_ERROR;

  SC_AGENT_REGISTER(minCutAgent)

  return SC_RESULT_OK;
}

sc_result MinCutModule::ShutdownImpl()
{
  SC_AGENT_UNREGISTER(minCutAgent)

  return SC_RESULT_OK;
}
