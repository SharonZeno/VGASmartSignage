#include "stateMachineMgr.h"

CStateMachineMgr::CStateMachineMgr():m_systemState{NStateMachine::E_BOOT}
{}

NStateMachine::ESystemState CStateMachineMgr::getSystemState()
{
  return m_systemState;
}

void CStateMachineMgr::setSystemState(NStateMachine::ESystemState new_state)
{
  m_systemState = new_state;
}

void CStateMachineMgr::doSetup()
{

}

void CStateMachineMgr::doLoopLogic()
{
    
}