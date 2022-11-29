#include <iostream>

#include <sc-memory/sc_memory.hpp>
#include <sc-memory/sc_stream.hpp>
#include <sc-memory/sc_template_search.cpp>

#include <sc-agents-common/utils/IteratorUtils.hpp>
#include <sc-agents-common/utils/AgentUtils.hpp>
#include <sc-agents-common/utils/GenerationUtils.hpp>

#include "minCutAgent.hpp"
using namespace std;
using namespace utils;

namespace minCutModule {

SC_AGENT_IMPLEMENTATION(minCutAgent) {

SC_LOG_DEBUG("INIT Agent: MinCut");

ScAddr node = ms_context->GetEdgeTarget(edgeAddr);

ScIterator3Ptr it = ms_context->Iterator3(
    node,
    ScType::EdgeAccessConstPosPerm,
    ScType(0)
);
int minCut = INT_MAX;
while (it->Next()) {
node = it->Get(2);
int count = 0;
ScType type = ms_context->GetElementType(node);

if (type.IsNode()) {
ScAddr node2 = node;
ScIterator3Ptr it2 = ms_context->Iterator3(node2, ScType::EdgeDCommonConst, ScType(0));
while (it2->Next()) {
node2 = it2->Get(2);
ScType type2 = ms_context->GetElementType(node2);
if (type2.IsNode()) {
if (ms_context->HelperCheckEdge(node, node2, ScType::EdgeDCommonConst)) {
count++;
}
}
}

SC_LOG_DEBUG("Vertex:" + ms_context->HelperGetSystemIdtf(node) + " Edges: " + std::to_string(count));

if(minCut >= count){
minCut = count;
}
}
}
SC_LOG_DEBUG("Minimal cut: " + std::to_string(minCut));

ScAddr answer = ms_context->CreateNode(ScType::NodeConstStruct);
ms_context->CreateEdge(ScType::EdgeAccessConstPosPerm,
    node,
    answer);

return SC_RESULT_OK;
}

}