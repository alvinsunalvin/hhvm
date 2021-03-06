/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2017-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#include "hphp/runtime/ext/vsdebug/debugger.h"
#include "hphp/runtime/ext/vsdebug/command.h"

namespace HPHP {
namespace VSDEBUG {

ConfigurationDoneCommand::ConfigurationDoneCommand(
  Debugger* debugger,
  folly::dynamic message
) : VSCommand(debugger, message) {
}

ConfigurationDoneCommand::~ConfigurationDoneCommand() {
}

bool ConfigurationDoneCommand::executeImpl(DebuggerSession* /*session*/,
                                           folly::dynamic* /*responseMsg*/
) {
  m_debugger->setClientInitialized();

  // Configuration done means all loader breakpoints have been set, it's time
  // to resume the target.
  return true;
}

}
}
