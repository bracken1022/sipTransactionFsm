//
//  ict_state.cpp
//  sipTransaction
//
//  Created by bracken on 15/1/23.
//  Copyright (c) 2015年 bracken. All rights reserved.
//


#include "ict_state.hpp"
#include "system_OS.hpp"


#define NULL 0

Ict_IdleState* Ict_IdleState::m_state = NULL;
Ict_CallingState* Ict_CallingState::m_state = NULL;
Ict_PreceedingState* Ict_PreceedingState::m_state = NULL;
Ict_CompletedState* Ict_CompletedState::m_state = NULL;
Ict_TerminatedState* Ict_TerminatedState::m_state = NULL;

void Ict_State::receivedInviteFromTu()
{
    debugPrintf("should not be here");
}

void Ict_State::received1xx()
{
    debugPrintf("should not be here");
}

void Ict_State::received2xx()
{
    debugPrintf("should not be here");    
}

void Ict_State::received3xx6xx()
{
    debugPrintf("should not be here");
}


Ict_State* Ict_IdleState::instance()
{
    if (NULL == m_state) {
        m_state = new Ict_IdleState();
    }
    
    return m_state;
}

void Ict_IdleState::receivedInviteFromTu()
{
    debugPrintf("send out invite");
}

Ict_State* Ict_CallingState::instance()
{
    if (NULL == m_state) {
        m_state = new Ict_CallingState();
    }
    
    return m_state;
}

void Ict_CallingState::received2xx()
{
    debugPrintf("send message to Tu");
}

void Ict_CallingState::received3xx6xx()
{
    debugPrintf("send out ACK Message");
    debugPrintf("send 3xx6xx to Tu");
}

void Ict_CallingState::received1xx()
{
    debugPrintf("send 1xx to Tu");
}

Ict_State* Ict_PreceedingState::instance()
{
    if (NULL == m_state) {
        m_state = new Ict_PreceedingState();
    }
    
    return m_state;
}

void Ict_PreceedingState::received1xx()
{
    debugPrintf("send 1xx to Tu in preceeding");
}

void Ict_PreceedingState::received2xx()
{
    debugPrintf("send 2xx to Tu in preceeding");
}

void Ict_PreceedingState::received3xx6xx()
{
    debugPrintf("send 3xx6xx to Tu in preceeding");
    debugPrintf("send ACK message in preceedikng");
}

Ict_State* Ict_CompletedState::instance()
{
    if (NULL == m_state) {
        m_state = new Ict_CompletedState();
    }
    
    return m_state;
}

void Ict_CompletedState::received3xx6xx()
{
    debugPrintf("send ACK message in CompleteState");
}

Ict_State* Ict_TerminatedState::instance()
{
    if (NULL == m_state) {
        m_state = new Ict_TerminatedState();
    }
    
    return m_state;
}







