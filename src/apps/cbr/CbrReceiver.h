#ifndef _CBRRECEIVER_H_
#define _CBRRECEIVER_H_

#include <string.h>
#include <omnetpp.h>

#include <inet/common/INETDefs.h>
//#include <inet/transportlayer/contract/udp/UDPSocket.h>
#include <inet4_compat/transportlayer/contract/udp/UDPSocket.h>
#include <inet/networklayer/common/L3AddressResolver.h>

#include "CbrPacket_m.h"

class CbrReceiver : public omnetpp::cSimpleModule
{
    inet::UDPSocket socket;

    ~CbrReceiver();

    int numReceived_;
    int totFrames_;

    int recvBytes_;


    bool mInit_;

    static omnetpp::simsignal_t cbrFrameLossSignal_;
    static omnetpp::simsignal_t cbrFrameDelaySignal_;
    static omnetpp::simsignal_t cbrJitterSignal_;
    static omnetpp::simsignal_t cbrReceivedThroughtput_;
//    static simsignal_t cbrReceivedThroughtput_rate_;

  protected:

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    void initialize(int stage) override;
    void handleMessage(omnetpp::cMessage *msg) override;
    virtual void finish() override;
};

#endif

