#pragma once

#include <any>
#include <functional>
#include <string>
#include <boost/signals2.hpp>
#include <Utils/TypeAliases.hpp>

class IHDLCCommunicator;

class ICommand
{
public:
   virtual ~ICommand() = default;

   virtual void execute() = 0;
   virtual std::string handleResponse() = 0;
   void registerResponseHandler(std::function<void(void)> responseHandler);

protected:
   ICommand() = default;
   explicit ICommand(IHDLCCommunicator& hdlcCommunicator);
   ICommand(Strings userInput, IHDLCCommunicator& hdlcCommunicator);

   using AlmagControllerInformer = boost::signals2::signal<void(void)>;
    
   Strings validatedUserInput_;
   IHDLCCommunicator& hdlcCommunicator_;
   AlmagControllerInformer informControllerAboutResult_;
};

