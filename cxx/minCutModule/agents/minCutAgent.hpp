#pragma once

#include <sc-memory/kpm/sc_agent.hpp>

#include "keynodes/keynodes.hpp"
#include "minCutAgent.generated.hpp"

namespace minCutModule
{

class minCutAgent : public ScAgent
{
  SC_CLASS(Agent, Event(Keynodes::find_min_cut, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

} // namespace exampleModule
