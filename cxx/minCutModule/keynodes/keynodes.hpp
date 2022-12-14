/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#pragma once

#include <sc-memory/sc_object.hpp>
#include <sc-memory/sc_addr.hpp>

#include "keynodes.generated.hpp"

namespace minCutModule
{

class Keynodes : public ScObject
{
  SC_CLASS()
  SC_GENERATED_BODY()

public:
  SC_PROPERTY(Keynode("nrel_answer"), ForceCreate)
  static ScAddr nrel_answer;

  SC_PROPERTY(Keynode("find_min_cut"), ForceCreate)
  static ScAddr find_min_cut;
};

} // namespace exampleModule
