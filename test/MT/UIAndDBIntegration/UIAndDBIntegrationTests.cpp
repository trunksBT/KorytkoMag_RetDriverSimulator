#include <Fixtures/BaseFixtureWithDBAndHDLC.hpp>

#include <UserInterface/CMenu.hpp>
#include <Database/Objects/IOPaths.hpp>
#include <CommandPattern/AlmagControllerNull.hpp>

#include <PluginSpecifics/CmdConstraints/DatabaseConstraints.hpp>
#include <UserInterface/CtrlCommandsValidators/AlmagCommandValidationManager.hpp>
#include <UserInterface/CtrlCommandsValidators/DatabaseCommandValidationManager.hpp>

#include <TestUtils/Hardcodes.hpp>
#include <TestUtils/ObjectTypes.hpp>
#include <TestUtils/UniqueKeys.hpp>
#include <TestUtils/HDLCCommunicators/RoundTripHDLCCommunicatorStub.hpp>

using namespace hardcodes::IOPaths;
using namespace constraints::database;

namespace mt
{

class UIAndDatabaseIntegrationShould : public BaseFixtureWithDBAndHDLC
{
protected:
   UIAndDatabaseIntegrationShould()
      : BaseFixtureWithDBAndHDLC({}, std::make_shared<test::RoundTripHDLCCommunicatorStub>())
      , ui_(std::make_unique<CMenu>(
         "AlmagRetDriverUI", "_", db_, std::make_shared<AlmagControllerNull>(),
         std::make_shared<AlmagCommandValidationManager>(db_),
         std::make_unique<DatabaseCommandValidationManager>(db_))
      )
   {
      ui_->setDatabaseCommandsConstraints({
          constraints::database::values.begin(), constraints::database::values.end()});
   };

   std::unique_ptr<CMenu> ui_;
};

TEST_F(UIAndDatabaseIntegrationShould, Put_IOPaths_ByOT_BufferToSend_Once)
{
	const auto& returnCode = ui_->runPredefinedCommands({
      {PUT, IOPATHS_OT, "bufferToSend", BUFFER_TO_SEND_VAL_1}
   });

   const auto& received = db_.getObj<IOPaths>(IOPATHS_1_UK);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(received);
   ASSERT_TRUE(received->bufferToSend);
   ASSERT_THAT(
      received->bufferToSend.value(),
      StrEq(BUFFER_TO_SEND_VAL_1));
}

TEST_F(UIAndDatabaseIntegrationShould, Put_IOPaths_ByOT_BufferToSend_Twice)
{
	const auto& returnCode = ui_->runPredefinedCommands({
      {PUT, IOPATHS_OT, "bufferToSend", BUFFER_TO_SEND_VAL_1},
      {PUT, IOPATHS_OT, "bufferToSend", BUFFER_TO_SEND_VAL_2}
   });

   const auto& IOPath1 = db_.getObj<IOPaths>(IOPATHS_1_UK);

   ASSERT_TRUE(IOPath1);
   ASSERT_TRUE(IOPath1->bufferToSend);
   ASSERT_THAT(
      IOPath1->bufferToSend.value(),
      StrEq(BUFFER_TO_SEND_VAL_1));

   const auto& IOPath2 = db_.getObj<IOPaths>(IOPATHS_2_UK);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(IOPath2);
   ASSERT_TRUE(IOPath2->bufferToSend);
   ASSERT_THAT(
      IOPath2->bufferToSend.value(),
      StrEq(BUFFER_TO_SEND_VAL_2));
}

TEST_F(UIAndDatabaseIntegrationShould, Put_IOPaths_ByUK_BufferToSend)
{
	const auto& returnCode = ui_->runPredefinedCommands({
      {PUT, IOPATHS_1_UK, "bufferToSend", BUFFER_TO_SEND_VAL_1}
   });

   const auto& received = db_.getObj<IOPaths>(IOPATHS_1_UK);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(received);
   ASSERT_TRUE(received->bufferToSend);
   ASSERT_THAT(
      received->bufferToSend.value(),
      StrEq(BUFFER_TO_SEND_VAL_1));
}

TEST_F(UIAndDatabaseIntegrationShould, Put_IOPaths_ByUK_BufferToSend_Twice_EqualKey)
{
	const auto& returnCode = ui_->runPredefinedCommands({
      {PUT, IOPATHS_1_UK, "bufferToSend", BUFFER_TO_SEND_VAL_1},
      {PUT, IOPATHS_1_UK, "bufferToSend", BUFFER_TO_SEND_VAL_2}
   });

   const auto& IOPath1 = db_.getObj<IOPaths>(IOPATHS_1_UK);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(IOPath1);
   ASSERT_TRUE(IOPath1->bufferToSend);
   ASSERT_THAT(
      IOPath1->bufferToSend.value(),
      StrEq(BUFFER_TO_SEND_VAL_2));

   const auto& IOPath2 = db_.getObj<IOPaths>(IOPATHS_2_UK);

   ASSERT_FALSE(IOPath2);
}

TEST_F(UIAndDatabaseIntegrationShould, Put_IOPaths_ByUK_BufferToSend_Twice_DifferentKey)
{
	const auto& returnCode = ui_->runPredefinedCommands({
      {PUT, IOPATHS_1_UK, "bufferToSend", BUFFER_TO_SEND_VAL_1},
      {PUT, IOPATHS_2_UK, "bufferToSend", BUFFER_TO_SEND_VAL_2}
   });

   const auto& IOPath1 = db_.getObj<IOPaths>(IOPATHS_1_UK);

   ASSERT_TRUE(IOPath1);
   ASSERT_TRUE(IOPath1->bufferToSend);
   ASSERT_THAT(
      IOPath1->bufferToSend.value(),
      StrEq(BUFFER_TO_SEND_VAL_1));

   const auto& IOPath2 = db_.getObj<IOPaths>(IOPATHS_2_UK);

   ASSERT_TRUE(returnCode);
   ASSERT_TRUE(IOPath2);
   ASSERT_TRUE(IOPath2->bufferToSend);
   ASSERT_THAT(
      IOPath2->bufferToSend.value(),
      StrEq(BUFFER_TO_SEND_VAL_2));
}

}  // namespace mt
