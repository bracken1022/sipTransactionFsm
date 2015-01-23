
//
//  testTransaction.cpp
//  sipTransaction
//
//  Created by bracken on 15/1/23.
//  Copyright (c) 2015年 bracken. All rights reserved.
//

#include "testTransaction.hpp"
#include "ict_transaction.hpp"
#include "stateType.hpp"
#include "ict_state.hpp"

void TestTransaction()
{
    Ict_Transaction* itcTrans = new Ict_Transaction();
    
    (itcTrans->getState())->receivedInviteFromTu();
    
    itcTrans->changeState(CALLING);
    
    (itcTrans->getState())->received2xx();
    (itcTrans->getState())->received1xx();
    (itcTrans->getState())->received3xx6xx();
    
    itcTrans->changeState(PRECEEDING);
    
    
    (itcTrans->getState())->received2xx();
    (itcTrans->getState())->received1xx();
    (itcTrans->getState())->received3xx6xx();
    
    itcTrans->changeState(TERMINATED);
    
    (itcTrans->getState())->received2xx();
    (itcTrans->getState())->received1xx();
    (itcTrans->getState())->received3xx6xx();
    
    delete itcTrans;
    
}

void TestTransactionRegular()
{
    
    Ict_Transaction* itcTrans = new Ict_Transaction();
    
    (itcTrans->getState())->receivedInviteFromTu();
    
    itcTrans->changeState(CALLING);
    
    (itcTrans->getState())->received1xx();
    itcTrans->changeState(PRECEEDING);
    
    (itcTrans->getState())->received1xx();
    
    (itcTrans->getState())->received2xx();
    itcTrans->changeState(TERMINATED);
    
    (itcTrans->getState())->received2xx();
    
    
}



