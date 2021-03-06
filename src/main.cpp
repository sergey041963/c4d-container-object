/// Copyright (C) 2013-2015, Niklas Rosenstein
/// All rights reserved.
///
/// Licensed under the GNU Lesser General Public License.
///
/// \file main.cpp
/// \lastmodified 2015/05/06

#include <c4d.h>
#include "Utils/Misc.h"

extern Bool RegisterContainerObject(Bool prePass);
extern Bool RegisterCommands();

Bool PluginStart()
{
  RegisterContainerObject(false);
  RegisterCommands();
  return false;
}

Bool PluginMessage(LONG msgType, void* pData)
{
  switch (msgType)
  {
    case C4DPL_INIT_SYS:
      return ::resource.Init();
    case C4DPL_BUILDMENU:
      RegisterContainerObject(true);
      break;
    default:
      break;
  }
  return true;
}

void PluginEnd()
{
}

