//
//  ict_transaction.cpp
//  sipTransaction
//
//  Created by bracken on 15/1/23.
//  Copyright (c) 2015年 bracken. All rights reserved.
//



#include "ict_transaction.hpp"

#include "system_OS.hpp"

Ict_Transaction::Ict_Transaction()
{
    m_state = Ict_IdleState::instance();
}

void Ict_Transaction::setState(StateType type)
{
    switch (type) {
        case IDLE:
            m_state = Ict_IdleState::instance();
            break;
            
        case CALLING:
            m_state = Ict_CallingState::instance();
            break;
            
        case PRECEEDING:
            m_state = Ict_PreceedingState::instance();
            break;
            
        case COMPLETED:
            m_state = Ict_CompletedState::instance();
            break;
            
        case TERMINATED:
            m_state = Ict_TerminatedState::instance();
            break;
            
        default:
            m_state = 0;
            break;
    }
}

void Ict_Transaction::changeState(StateType type)
{
    setState(type);
}

Ict_State* Ict_Transaction::getState()
{
    return m_state;
}