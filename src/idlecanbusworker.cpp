#include "idlecanbusworker.h"

idleCanBusWorker::idleCanBusWorker(CanBusWorkerBasis *parentBasis) :
    basisptr(parentBasis)
{
    anIf(CanBusWorkerBasisDbgEn, anTrk("idleCanBusWorker Constructed"));
}

void idleCanBusWorker::onEntry(QEvent *)
{
    anIf(CanBusWorkerBasisDbgEn, anTrk("idleCanBusWorker Entered"));
    qApp->processEvents();
    if (basisptr->previousStateName.isEmpty() && !(basisptr->currentDev))
    {
        basisptr->initialize();
    }
}

void idleCanBusWorker::onExit(QEvent *)
{
    anIf(CanBusWorkerBasisDbgEn, anTrk("Leave idleCanBusWorker"));
}