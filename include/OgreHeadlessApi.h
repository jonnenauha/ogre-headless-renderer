
/* Copyright 2013 Jonne Nauha / jonne@adminotech.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "OgrePrerequisites.h"

#if (OGRE_PLATFORM == OGRE_PLATFORM_WIN32) && !defined(__MINGW32__) && !defined(OGRE_STATIC_LIB)
#   ifdef RenderSystem_Headless_EXPORTS
#       define _OgreHeadlessExport __declspec(dllexport)
#   else
#       if defined(__MINGW32__)
#           define _OgreHeadlessExport
#       else
#           define _OgreHeadlessExport __declspec(dllimport)
#       endif
#   endif
#elif defined (OGRE_GCC_VISIBILITY)
#    define _OgreHeadlessExport  __attribute__ ((visibility("default")))
#else
#    define _OgreHeadlessExport
#endif
