//
//  ict_transaction.hpp
//  sipTransaction
//
//  Created by bracken on 15/1/23.
//  Copyright (c) 2015年 bracken. All rights reserved.
//

#ifndef ICT_TRANSACTION_H_
#define ICT_TRANSACTION_H_


#include "ict_state.hpp"
#include "stateType.hpp"

class Transaction
{
public:
    Transaction(){}
    virtual ~Transaction(){}
    
};

class Ict_Transaction : public Transaction
{
public:
    Ict_Transaction();
    ~Ict_Transaction(){}
    
    void setState(StateType type);
    void changeState(StateType type);
    
    Ict_State* getState();
    
private:
    Ict_State* m_state;
};



#endif