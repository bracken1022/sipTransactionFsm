//
//  ict_state.hpp
//  sipTransaction
//
//  Created by bracken on 15/1/23.
//  Copyright (c) 2015年 bracken. All rights reserved.
//

#ifndef ICT_STATE_H_
#define ICT_STATE_H_


class Ict_State
{
public:
    Ict_State(){}
    virtual ~Ict_State(){}
    
    virtual void receivedInviteFromTu();
    
    virtual void received1xx();
    virtual void received2xx();
    virtual void received3xx6xx();
    
};

class Ict_IdleState : public Ict_State
{
public:
    static Ict_State* instance();
    
    void receivedInviteFromTu();
    
private:
    static Ict_IdleState* m_state;
    
    Ict_IdleState(){}
    ~Ict_IdleState(){}
};

class Ict_CallingState : public Ict_State
{
public:
    static Ict_State* instance();
    
    void received2xx();
    void received3xx6xx();
    void received1xx();
    
private:
    static Ict_CallingState* m_state;
    
    Ict_CallingState(){}
    ~Ict_CallingState(){}
};

class Ict_PreceedingState : public Ict_State
{
public:
    static Ict_State* instance();
    
    void received1xx();
    void received2xx();
    void received3xx6xx();
    
private:
    static Ict_PreceedingState* m_state;
    
    Ict_PreceedingState(){}
    ~Ict_PreceedingState(){}
    
};

class Ict_CompletedState : public Ict_State
{
public:
    static Ict_State* instance();
    
    void received3xx6xx();
    
private:
    static Ict_CompletedState* m_state;
    
    Ict_CompletedState(){}
    ~Ict_CompletedState(){}
};

class Ict_TerminatedState : public Ict_State
{
public:
    static Ict_State* instance();
    
private:
    static Ict_TerminatedState* m_state;
    
    Ict_TerminatedState(){}
    ~Ict_TerminatedState(){}
    
};





#endif