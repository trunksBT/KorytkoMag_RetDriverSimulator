#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>
#include <TestUtils/HDLCCommunicators/RoundTripHDLCCommunicatorStub.hpp>
#include <TestUtils/HDLCCommunicators/ZMqReqRespCommunicator.hpp>

BaseFixtureWithDBAndHDLC::BaseFixtureWithDBAndHDLC(
        const Database::ValueType inDB, std::vector<IHDLCCommunicatorPtr> hdlcComm)
   : BaseFixtureWithDB(inDB)
   , hdlcCommunicators_{hdlcComm}
{}
